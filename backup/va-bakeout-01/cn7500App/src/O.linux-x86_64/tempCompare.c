/* Generated with snc from ../tempCompare.stt */

/* Program "tempCompare" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 5 "../tempCompare.stt"
	int control;
# line 9 "../tempCompare.stt"
	int pause;
# line 13 "../tempCompare.stt"
	int t;
# line 17 "../tempCompare.stt"
	int compare;
};

/* C code definitions */
# line 3 "../tempCompare.stt"
#include <unistd.h> /* for sleep() */

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		0,
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "init" in state set "bakeout" ******/

/* Delay function for state "init" in state set "bakeout" */
static void D_bakeout_0_init(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "init" in state set "bakeout" */
static seqBool E_bakeout_0_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
	if (TRUE)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "bakeout" */
static void A_bakeout_0_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 26 "../tempCompare.stt"
			pVar->t = 0;
# line 27 "../tempCompare.stt"
			seq_pvPut(ssId, 2/*t*/, 0);
		}
		return;
	}
}

/****** Code for state "check" in state set "bakeout" ******/

/* Delay function for state "check" in state set "bakeout" */
static void D_bakeout_0_check(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "check" in state set "bakeout" */
static seqBool E_bakeout_0_check(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 32 "../tempCompare.stt"
	if (pVar->control == 1 && pVar->pause == 0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
# line 48 "../tempCompare.stt"
	if (pVar->control == 0 || pVar->pause == 1)
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "check" in state set "bakeout" */
static void A_bakeout_0_check(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 33 "../tempCompare.stt"
			if (pVar->compare == 1 && pVar->t < 300)
			{
# line 34 "../tempCompare.stt"
				pVar->t++;
# line 35 "../tempCompare.stt"
				seq_pvPut(ssId, 2/*t*/, 0);
# line 36 "../tempCompare.stt"
				sleep(1);
			}
# line 38 "../tempCompare.stt"
			if (pVar->compare == 0)
			{
# line 39 "../tempCompare.stt"
				pVar->t = 0;
# line 40 "../tempCompare.stt"
				seq_pvPut(ssId, 2/*t*/, 0);
			}
# line 42 "../tempCompare.stt"
			if (pVar->t >= 300)
			{
# line 43 "../tempCompare.stt"
				pVar->pause = 0;
# line 44 "../tempCompare.stt"
				seq_pvPut(ssId, 1/*pause*/, 0);
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{Sys}{Dev}Ctl-Cmd", offsetof(struct UserVar, control), "control", "int", 1, 1, 0, 1, 0, 0},
	{"{Sys}{Dev}PID-Cmd", offsetof(struct UserVar, pause), "pause", "int", 1, 2, 0, 1, 0, 0},
	{"{Sys}{Dev}K-I", offsetof(struct UserVar, t), "t", "int", 1, 3, 0, 1, 0, 0},
	{"{Sys}{Dev}T-Calc", offsetof(struct UserVar, compare), "compare", "int", 1, 4, 0, 1, 0, 0}
};

/* Event masks for state set "bakeout" */
static const seqMask	EM_bakeout_0_init[] = {
	0x00000000,
};
static const seqMask	EM_bakeout_0_check[] = {
	0x00000006,
};

/* State table for state set "bakeout" */
static seqState G_bakeout_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_bakeout_0_init,
	/* event function */    E_bakeout_0_init,
	/* delay function */    D_bakeout_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "check",
	/* action function */   A_bakeout_0_check,
	/* event function */    E_bakeout_0_check,
	/* delay function */    D_bakeout_0_check,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_check,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "bakeout",
	/* states */            G_bakeout_states,
	/* number of states */  2,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram tempCompare = {
	/* magic number */      2001012,
	/* program name */      "tempCompare",
	/* channels */          G_channels,
	/* num. channels */     4,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void tempCompareRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&tempCompare);
}
epicsExportRegistrar(tempCompareRegistrar);
