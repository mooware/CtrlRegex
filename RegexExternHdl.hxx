#ifndef _REGEXEXTERNHDL_H_
#define _REGEXEXTERNHDL_H_

#include <BaseExternHdl.hxx>
#include <BitVar.hxx>
#include <DynVar.hxx>
#include <QRegExp>

class RegexExternHdl : public BaseExternHdl
{
  public:
    RegexExternHdl(BaseExternHdl *nextHdl, PVSSulong funcCount, FunctionListRec fnList[]);

    // Execute user defined function
    virtual const Variable *execute(ExecuteParamRec &param);

  private:
    // Ctrl: bool reMatch(string input, string pattern,
    //                    int syntax = RE_REGEX,
    //                    bool caseSensitive=true)
    void reMatch(ExecuteParamRec &param, BitVar &result) const;

    // Ctrl: dyn_string reDynMatch(dyn_string input, string pattern,
    //                             int syntax = RE_REGEX,
    //                             bool caseSensitive = true)
    void reDynMatch(ExecuteParamRec &param, DynVar &result) const;

    // make a QRegexp from the given params.
    // - first arg: pattern
    // - second arg, optional: syntax type
    // - third arg, optional: case sensitivity
    bool parseParams(ExecuteParamRec &param, unsigned int startIdx, QRegExp &result) const;
};

#endif
