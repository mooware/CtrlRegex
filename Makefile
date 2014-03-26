include $(API_ROOT)/CtrlExt.mk

INCLUDE += -I/usr/include/qt4 -I/usr/include/qt4/QtCore
OTHER_CXXFLAGS += -DQT_NAMESPACE=WinCC_OA
OFILES = RegexExternHdl.o

CtrlRegex: $(OFILES)
	$(SHLIB) -o CtrlRegex.so $(OFILES) $(LIBS)

clean:
	@rm -f *.o CtrlRegex.so
