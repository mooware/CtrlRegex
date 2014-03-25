#include "RegexExternHdl.hxx"

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
}

// -----------------------------------------------------------------------
void RegexExternHdl::reDynMatch(ExecuteParamRec &param, DynVar &result) const
{
}
