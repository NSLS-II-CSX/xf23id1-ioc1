TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = k2000
# k2000.dbd will be created and installed
DBD += k2000.dbd
DBD += menuScan.dbd

# k2000.dbd will be made up from these files:
k2000_DBD += base.dbd

# Include dbd files from all support applications:
k2000_DBD += stream.dbd
k2000_DBD += asyn.dbd
k2000_DBD += caPutLog.dbd
k2000_DBD += drvAsynIPPort.dbd
k2000_DBD += system.dbd
k2000_DBD += asSupport.dbd
k2000_DBD += devIocStats.dbd

# Add all the support libraries needed by this IOC
k2000_LIBS += asyn
k2000_LIBS += stream
k2000_LIBS += caPutLog
k2000_LIBS += autosave
k2000_LIBS += devIocStats

# k2000_registerRecordDeviceDriver.cpp derives from k2000.dbd
k2000_SRCS += k2000_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
k2000_SRCS_DEFAULT += k2000Main.cpp
k2000_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#k2000_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
k2000_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

