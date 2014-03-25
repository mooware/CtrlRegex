#ifndef _REGEXEXTERNHDL_H_
#define _REGEXEXTERNHDL_H_

#include <BaseExternHdl.hxx>
#include <BitVar.hxx>
#include <DynVar.hxx>

class RegexExternHdl : public BaseExternHdl
{
  public:
    RegexExternHdl(BaseExternHdl *nextHdl, PVSSulong funcCount, FunctionListRec fnList[])
      : BaseExternHdl(nextHdl, funcCount, fnList) {}

    // Execute user defined function
    virtual const Variable *execute(ExecuteParamRec &param);

  private:
    // Ctrl: bool reMatch(string pattern, string input)
    void reMatch(ExecuteParamRec &param, BitVar &result) const;
    // Ctrl: dyn_string reDynMatch(string pattern, dyn_string input)
    void reDynMatch(ExecuteParamRec &param, DynVar &result) const;
};

#endif
