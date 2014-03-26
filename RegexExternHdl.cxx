#include "RegexExternHdl.hxx"
#include <Controller.hxx>

#include <QString>

// List of user defined functions
enum
{
  F_reMatch = 0,
  F_reDynMatch
};

// Function description
FunctionListRec fnList[] =
{
  //  Return-Value    function name        parameter list               true == thread-safe
  //  -------------------------------------------------------------------------------------
    { BIT_VAR, "reMatch",    "(string pattern, string input)" , true},
    { DYN_VAR, "reDynMatch", "(string pattern, dyn_string input)", true}
  };

CTRL_EXTENSION(RegexExternHdl, fnList)

//------------------------------------------------------------------------------
RegexExternHdl::RegexExternHdl(BaseExternHdl *nextHdl, PVSSulong funcCount, FunctionListRec fnList[])
  : BaseExternHdl(nextHdl, funcCount, fnList)
{
  // register constants for syntax types
  struct { const char *name; int value; } globals[] = {
    { "RE_REGEX",         QRegExp::RegExp },
    { "RE_REGEXP",        QRegExp::RegExp },
    { "RE_REGEX2",        QRegExp::RegExp2 },
    { "RE_REGEXP2",       QRegExp::RegExp2 },
    { "RE_WILDCARD",      QRegExp::Wildcard },
    { "RE_WILDCARD_UNIX", QRegExp::WildcardUnix }
  };

  for (size_t i = 0; i < sizeof(globals) / sizeof(*globals); ++i)
  {
    CtrlVar *typeVar = new CtrlVar(new IntegerVar(globals[i].value));
    typeVar->setName(globals[i].name);
    Controller::thisPtr->addGlobal(typeVar);
  }
}

//------------------------------------------------------------------------------
const Variable *RegexExternHdl::execute(ExecuteParamRec &param)
{
  // We return a pointer to a static variable.
  static BitVar bitVar;
  static DynVar dynVar;

  // Forget all errors so far. We generate our own errors
  param.thread->clearLastError();

  // switch / case on function numbers
  switch (param.funcNum)
  {
    case F_reMatch:    reMatch(param, bitVar);    return &bitVar;
    case F_reDynMatch: reDynMatch(param, dynVar); return &dynVar;

    default:
      bitVar = PVSS_FALSE;
  }

  return &bitVar;
}

// -----------------------------------------------------------------------
void RegexExternHdl::reMatch(ExecuteParamRec &param, BitVar &result) const
{
  QRegExp regex;
  if (! parseParams(param, 1, regex))
  {
    result.setValue(PVSS_FALSE);
    return;
  }

  TextVar input;
  input = *(param.args->getFirst()->evaluate(param.thread));

  QString qinput = QString::fromUtf8(input.getValue());
  result.setValue(regex.exactMatch(qinput));
}

// -----------------------------------------------------------------------
void RegexExternHdl::reDynMatch(ExecuteParamRec &param, DynVar &result) const
{
  result.clear();

  QRegExp regex;
  if (! parseParams(param, 1, regex))
    return;

  DynVar input;
  input = *(param.args->getFirst()->evaluate(param.thread));

  TextVar *item = 0;
  for (unsigned int i = 1; i <= input.getNumberOfItems(); ++i)
  {
    // keep a previously allocated item if it wasn't used in the result
    if (!item)
      item = new TextVar();

    *item = *(input.getAt(i));
    QString qitem = QString::fromUtf8(item->getValue());

    if (regex.exactMatch(qitem))
    {
      result.append(item);
      item = 0;
    }
  }

  delete item;
}

// -----------------------------------------------------------------------
bool RegexExternHdl::parseParams(ExecuteParamRec &param, unsigned int startIdx, QRegExp &result) const
{
  unsigned int paramCount = param.args->getNumberOfItems();
  if (paramCount < (startIdx + 1) || paramCount > (startIdx + 3))
  {
    ErrHdl::error(ErrClass::PRIO_WARNING, ErrClass::ERR_CONTROL, ErrClass::ARG_MISSING,
                  param.thread->getLocation(), param.funcName);
    return false;
  }

  // skip the leading params
  param.args->getFirst();
  for (unsigned int i = 0; i < startIdx - 1; ++i)
    param.args->getNext();

  TextVar pattern;
  BitVar caseSensitive = PVSS_TRUE;
  IntegerVar syntaxType = QRegExp::RegExp;

  pattern = *(param.args->getNext()->evaluate(param.thread));

  if (paramCount > startIdx + 1)
    caseSensitive = *(param.args->getNext()->evaluate(param.thread));

  if (paramCount > startIdx + 2)
    syntaxType = *(param.args->getNext()->evaluate(param.thread));

  result.setPattern(QString::fromUtf8(pattern.getValue()));
  result.setCaseSensitivity(caseSensitive.isTrue() ? Qt::CaseSensitive : Qt::CaseInsensitive);
  result.setPatternSyntax((QRegExp::PatternSyntax) syntaxType.getValue());

  return true;
}
