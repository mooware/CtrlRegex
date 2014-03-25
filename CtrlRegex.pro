TEMPLATE = lib

TARGET = CtrlRegex

CONFIG += qt dll release
# no symlinks
CONFIG += plugin
# no lib* prefix
CONFIG += no_plugin_name_prefix

INCLUDEPATH += .
INCLUDEPATH += $$(API_ROOT)/include/Basics/DpBasics
INCLUDEPATH += $$(API_ROOT)/include/Basics/NoPosix
INCLUDEPATH += $$(API_ROOT)/include/Basics/Utilities
INCLUDEPATH += $$(API_ROOT)/include/Basics/Variables
INCLUDEPATH += $$(API_ROOT)/include/BCMNew
INCLUDEPATH += $$(API_ROOT)/include/ComDrv
INCLUDEPATH += $$(API_ROOT)/include/Configs
INCLUDEPATH += $$(API_ROOT)/include/Ctrl
INCLUDEPATH += $$(API_ROOT)/include/Datapoint
INCLUDEPATH += $$(API_ROOT)/include/EWO
INCLUDEPATH += $$(API_ROOT)/include/Manager
INCLUDEPATH += $$(API_ROOT)/include/Messages
INCLUDEPATH += $$(API_ROOT)/include/PVSSUtil
INCLUDEPATH += $$(API_ROOT)/include/V24

DEFINES += QT_NAMESPACE=WinCC_OA
DEFINES += DLLEXP_BASICS=
DEFINES += DLLEXP_CONFIGS=
DEFINES += DLLEXP_DATAPOINT=
DEFINES += DLLEXP_MESSAGES=
DEFINES += DLLEXP_MANAGER=
DEFINES += DLLEXP_CTRL=
DEFINES += PVSS_VERS_DLL=\\\"312000\\\"

unix: LIBS += -L$$(API_ROOT)/lib.$$(PLATFORM)
win32:LIBS += -L$$(API_ROOT)/lib.winnt

HEADERS = RegexExternHdl.hxx
SOURCES = RegexExternHdl.cxx
