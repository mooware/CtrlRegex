include $(API_ROOT)/CtrlExt.mk

QT_INCL_DIR = TODO_set_your_qt_header_dir_here
QT_INCL = -I$(QT_INCL_DIR) -I$(QT_INCL_DIR)/QtCore

INCLUDE += $(QT_INCL)
OTHER_CXXFLAGS += -DQT_NAMESPACE=WinCC_OA
OFILES = RegexExternHdl.o

CtrlRegex: $(OFILES)
	$(SHLIB) -o CtrlRegex.so $(OFILES) $(LIBS)

clean:
	@rm -f *.o CtrlRegex.so
