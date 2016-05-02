#!../../bin/linux-x86_64/cn7500

## You may have to change cn7500 to something else
## everywhere it appears in this file

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("dbd/cn7500.dbd")
cn7500_registerRecordDeviceDriver(pdbbase)

epicsEnvSet("EPICS_CA_AUTO_ADDR_LIST", "NO")
epicsEnvSet("EPICS_CA_ADDR_LIST", "10.23.0.255")
epicsEnvSet "STREAM_PROTOCOL_PATH", "${TOP}/protocol"

drvAsynIPPortConfigure("P0","xf23id1-tsrv07:4001")
#asynSetTraceMask("P0",-1,"0x9")
#asynSetTraceIOMask("P0",-1,"0x2")

## Load record instances
dbLoadRecords("db/cn7500_set.db", "Sys=XF:23ID-VA:BC01,Dev={TC:01}")
dbLoadRecords("db/cn7500_controller.db","Sys=XF:23ID-VA:BC01,Dev={TC:01},HexAddr=01,PORT=P0")

dbLoadRecords("db/cn7500_set.db", "Sys=XF:23ID-VA:BC01,Dev={TC:04}")
dbLoadRecords("db/cn7500_controller.db","Sys=XF:23ID-VA:BC01,Dev={TC:04},HexAddr=04,PORT=P0")

dbLoadRecords("db/cn7500_set.db", "Sys=XF:23ID-VA:BC01,Dev={TC:05}")
dbLoadRecords("db/cn7500_controller.db","Sys=XF:23ID-VA:BC01,Dev={TC:05},HexAddr=05,PORT=P0")

dbLoadRecords("db/cn7500_set.db", "Sys=XF:23ID-VA:BC01,Dev={TC:09}")
dbLoadRecords("db/cn7500_controller.db","Sys=XF:23ID-VA:BC01,Dev={TC:09},HexAddr=09,PORT=P0")

dbLoadRecords("db/cn7500_set.db", "Sys=XF:23ID-VA:BC01,Dev={TC:0A}")
dbLoadRecords("db/cn7500_controller.db","Sys=XF:23ID-VA:BC01,Dev={TC:0A},HexAddr=0A,PORT=P0")

dbLoadRecords("db/asynRecord.db", "P=XF:23ID-VA:BC01,R={Dev:1}Asyn,PORT=P0,ADDR=0,OMAX=1000,IMAX=1000")

## Set this to see messages from mySub
#var mySubDebug 1

## Run this to trace the stages of iocInit
#traceIocInit

cd ${TOP}/iocBoot/${IOC}
iocInit

## Start any sequence programs
#seq snccn7500, "Sys=XF:23ID-VA:BC01,Dev={TC:01}"
#seq tempCompare, "Sys=XF:23ID-VA:BC01,Dev={TC:01}"
