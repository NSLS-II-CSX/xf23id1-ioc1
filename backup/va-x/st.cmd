#!/usr/lib/epics/bin/linux-x86_64/blvac

## You may have to change blvac to something else
## everywhere it appears in this file
epicsEnvSet("EPICS_BASE", "/usr/lib/epics")

epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST", "NO")
epicsEnvSet("EPICS_CA_ADDR_LIST", "10.23.0.255")

epicsEnvSet("STREAM_PROTOCOL_PATH", "protocol")

## Register all support components
dbLoadDatabase("$(EPICS_BASE)/dbd/blvac.dbd",0,0)
blvac_registerRecordDeviceDriver(pdbbase) 

############ Asyn Communication Config ############
# cfg comms for gauge controllers
drvAsynIPPortConfigure("P0","tsrv-x1:4001")
#asynSetTraceMask("P0",-1,0x09)
#asynSetTraceIOMask("P0",-1,0x2)

# cfg comms for pump controllers
drvAsynIPPortConfigure("P1","tsrv-x1:4002")
#asynSetTraceMask("P1",-1,0x09)
#asynSetTraceIOMask("P1",-1,0x2)

###################################################



############ Load record instances ################
### gauge controller
dbLoadRecords("db/vgc.db")

### pump controller
dbLoadRecords("db/ipc.db")

### RGA controller
#dbLoadRecords("db/rga.db")

### Load asynRecords for general comms to each PORT
dbLoadRecords("db/asyn.db")

###################################################

## autosave/restore machinery
save_restoreSet_Debug(0)
save_restoreSet_IncompleteSetsOk(1)
save_restoreSet_DatedBackupFiles(1)
save_restoreSet_status_prefix("XF:23ID-VA:01{Dev}")

set_savefile_path("${TOP}/as","/save")
set_requestfile_path("${TOP}/as","/req")

dbLoadRecords("db/save_restoreStatus.db", "P=XF:23ID-VA:01{Dev}")

set_pass0_restoreFile("info_positions.sav")
set_pass1_restoreFile("info_positions.sav")

asSetFilename("/epics/xf/23id/xf23id.acf")
iocInit()
caPutLogInit("xf23id-ca:7004", 0)

## more autosave/restore machinery
cd ${TOP}/as/req
makeAutosaveFiles()
create_monitor_set("info_positions.req", 15 , "")


## Start any sequence programs
seq sncDegas, "Sys=XF:23ID-VA:01,Dev={RGA:01}"

