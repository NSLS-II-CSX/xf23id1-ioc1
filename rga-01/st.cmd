#!/usr/lib/epics/bin/linux-x86_64/vactrl

## You may have to change blvac to something else
## everywhere it appears in this file
epicsEnvSet("EPICS_BASE", "/usr/lib/epics")

epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST", "NO")
epicsEnvSet("EPICS_CA_ADDR_LIST", "10.23.0.255")

epicsEnvSet("STREAM_PROTOCOL_PATH", "/usr/share/epics-vactrl-dev/protocol")

## Register all support components
dbLoadDatabase("$(EPICS_BASE)/dbd/vactrl.dbd",0,0)
vactrl_registerRecordDeviceDriver(pdbbase) 

############ Asyn Communication Config ############
# cfg comms for rga
drvAsynIPPortConfigure("tsrv1-P7","xf23id1-tsrv02:4007")

drvAsynIPPortConfigure("tsrv2-P7","xf23id1-tsrv03:4007")

###################################################


############ Load record instances ################

### RGA controller
dbLoadTemplate("rga.substitutions")

### Load asynTemplate for general comms to each PORT
dbLoadTemplate("asyn.substitutions")


###################################################

## autosave/restore machinery
save_restoreSet_Debug(0)
save_restoreSet_IncompleteSetsOk(1)
save_restoreSet_DatedBackupFiles(1)
save_restoreSet_status_prefix("XF:23ID1-VA{RGA}")

set_savefile_path("${TOP}/as","/save")
set_requestfile_path("${TOP}/as","/req")

dbLoadRecords("$(EPICS_BASE)/db/save_restoreStatus.db", "P=XF:23ID1-CT{IOC:VA_RGA}")

set_pass0_restoreFile("info_positions.sav")
set_pass1_restoreFile("info_positions.sav")


dbLoadRecords("$(EPICS_BASE)/db/iocAdminSoft.db", "IOC=XF:23ID1-CT{IOC:VA_RGA}")
dbLoadRecords("$(EPICS_BASE)/db/save_restoreStatus.db", "P=XF:23ID1-CT{IOC:VA_RGA}")

asSetSubstitutions("WS=csxws1")
asSetFilename("/epics/xf/23id/xf23id.acf")

iocInit()
caPutLogInit("xf23id-ca:7004", 0)

## more autosave/restore machinery
cd ${TOP}/as/req
makeAutosaveFiles()
create_monitor_set("info_positions.req", 15 , "")

## Start any sequence programs
seq sncDegas, "Sys=XF:23ID1-VA,Dev={Mir:3-RGA:1}"
seq sncDegas, "Sys=XF:23ID1-VA,Dev={Dif-RGA:1}"

# Dump out PVs

dbl("*") > "/cf-update/xf23id1-ioc1.rga-01.dbl"

