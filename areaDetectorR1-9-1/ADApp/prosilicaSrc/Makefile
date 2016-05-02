TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

USR_CXXFLAGS_Linux += -D_LINUX -D_x86
USR_CXXFLAGS_Darwin += -D_OSX -D_x86

# The following is needed on win32-x86-debug because the Prosilica library 
# wants to use LIBCMT, and that conflicts with LIBCMTD
ifeq ($(T_A), win32-x86-debug)
USR_LDFLAGS += /NODEFAULTLIB:LIBCMT
endif
ifeq ($(T_A), windows-x64-debug)
USR_LDFLAGS += /NODEFAULTLIB:LIBCMT
endif

LIBRARY_IOC_WIN32 += prosilica
LIBRARY_IOC_Linux += prosilica
LIBRARY_IOC_Darwin += prosilica
LIB_SRCS += prosilica.cpp

PROD_NAME = prosilicaApp
PROD_IOC_WIN32 += $(PROD_NAME)
PROD_IOC_Linux += $(PROD_NAME)
PROD_IOC_Darwin += $(PROD_NAME)

# <name>.dbd will be created from <name>Include.dbd
DBD +=  $(PROD_NAME).dbd
$(PROD_NAME)_DBD += prosilicaSupport.dbd

#yhu: include iocStatus and autosave which are installed by epics Debian package
# /usr/lib/epics/dbd/
$(PROD_NAME)_DBD += base.dbd
$(PROD_NAME)_DBD += devIocStats.dbd
$(PROD_NAME)_DBD += asSupport.dbd
$(PROD_NAME)_DBD += system.dbd

DBD += prosilicaSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
PROD_SRCS += prosilicaApp_registerRecordDeviceDriver.cpp prosilicaAppMain.cpp

# Add locally compiled object code
PROD_LIBS += prosilica

#include autosave and devIocStats libraries which are installed by epics Debian
#package: /usr/lib/epics/lib/linux-x86
PROD_LIBS += $(EPICS_BASE_IOC_LIBS)
PROD_LIBS += autosave
PROD_LIBS += devIocStats

include $(TOP)/ADApp/commonDriverMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

