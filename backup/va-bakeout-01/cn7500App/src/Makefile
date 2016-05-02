TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build the IOC support library


#=============================
# Build the IOC application

PROD_IOC = cn7500
# cn7500.dbd will be created and installed
DBD += cn7500.dbd

# cn7500.dbd will be made up from these files:
cn7500_DBD += base.dbd
cn7500_DBD += asyn.dbd
cn7500_DBD += stream.dbd
cn7500_DBD += drvAsynIPPort.dbd
cn7500_DBD += drvAsynSerialPort.dbd

# cn7500_registerRecordDeviceDriver.cpp derives from cn7500.dbd
cn7500_SRCS += cn7500_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
cn7500_SRCS_DEFAULT += cn7500Main.cpp
cn7500_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#cn7500_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from the support library
cn7500_LIBS += asyn
cn7500_LIBS += stream

# NOTE: To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # This builds snccn7500 as a component of example
    cn7500_SNCFLAGS += +d
    cn7500_DBD += snccn7500.dbd
    cn7500_SRCS += snccn7500.stt
    cn7500_SRCS += tempCompare.stt
    cn7500_LIBS += seq pv
    # The following builds sncProgram as a standalone application
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link to the EPICS Base libraries
cn7500_LIBS += $(EPICS_BASE_IOC_LIBS)

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

