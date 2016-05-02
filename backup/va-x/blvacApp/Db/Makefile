TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

#----------------------------------------------------
# Create and install (or just install) into <top>/db
# databases, templates, substitutions like this
DB += vgc.db
DB += rga.db
DB += ipc.db
DB += asyn.db

#DB_INSTALLS += $(EPICS_BASE)/db/MPC.db
DB_INSTALLS += $(EPICS_BASE)/db/save_restoreStatus.db

### REQ_INSTALLS: analogous to DB_INSTALLS
#REQ_INSTALLS += $(EPICS_BASE)/as/req/MPC_settings.req
#REQ_INSTALLS += mpc_settings.req 

#REQ_INSTALLS_LOC=$(TOP)/as/req

#----------------------------------------------------
# If <anyname>.db template is not named <anyname>*.template add
# <anyname>_template = <templatename>

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

#ifndef T_A
#
#define REQ_INSTALLS_template
#install: $$(REQ_INSTALLS_LOC)/$$(notdir $(1))
#$$(REQ_INSTALLS_LOC)/$$(notdir $(1)) : $(1)
#	@[ -d $$(dir $$@) ] || install -d $$(dir $$@)
#	@echo "Installing $$@"
#	@install -m 644 $(1) $$@
#endef
#$(foreach file, $(REQ_INSTALLS), $(eval $(call REQ_INSTALLS_template,$(file))))
#
#endif

