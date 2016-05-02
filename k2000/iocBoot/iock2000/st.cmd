#!../../bin/linux-x86_64/k2000

## You may have to change k2000 to something else
## everywhere it appears in this file

< envPaths

epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST" , "NO")
epicsEnvSet("EPICS_CA_ADDR_LIST"      , "10.23.0.255")
epicsEnvSet("STREAM_PROTOCOL_PATH"    , "$(TOP)/proto")

## Register all support components
dbLoadDatabase("$(TOP)/dbd/k2000.dbd",0,0)
k2000_registerRecordDeviceDriver(pdbbase) 

drvAsynIPPortConfigure ("K1", "10.23.2.64:4002")
#asynSetTraceMask("K1", 0, 0x9)
#asynSetTraceIOMask("K1", 0, 0x2)

## Load record instances
dbLoadRecords("$(TOP)/db/meas.db","Sys=XF:23ID1-OP,Dev={Mon-Water},PORT=K1")

iocInit()

