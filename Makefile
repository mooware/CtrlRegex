include $(API_ROOT)/CtrlExt.mk

OFILES = Regex2ExternHdl.o

CtrlRegex2: $(OFILES)
	@rm -f addVerInfo.o
	@$(MAKE) addVerInfo.o
	$(SHLIB) -o CtrlRegex2.so addVerInfo.o $(OFILES) $(LIBS)

clean:
	@rm -f *.o CtrlRegex2.so

addVerInfo.cxx: $(API_ROOT)/addVerInfo.cxx
	@cp -f $(API_ROOT)/addVerInfo.cxx addVerInfo.cxx

addVerInfo.o: $(OFILES) addVerInfo.cxx
