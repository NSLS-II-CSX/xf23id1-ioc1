/* Generated with snc from sncProgram.i */

/* Program "snccn7500" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 5 "./../snccn7500.stt"
	int control;
# line 9 "./../snccn7500.stt"
	int step;
# line 13 "./../snccn7500.stt"
	double pv_low;
# line 16 "./../snccn7500.stt"
	double pv_high;
# line 19 "./../snccn7500.stt"
	double sp0;
# line 22 "./../snccn7500.stt"
	double sp1;
# line 25 "./../snccn7500.stt"
	double sp2;
# line 28 "./../snccn7500.stt"
	double sp3;
# line 31 "./../snccn7500.stt"
	double sp4;
# line 34 "./../snccn7500.stt"
	double sp5;
# line 37 "./../snccn7500.stt"
	double sp6;
# line 40 "./../snccn7500.stt"
	double sp7;
# line 43 "./../snccn7500.stt"
	double low;
# line 46 "./../snccn7500.stt"
	double high;
};

/* C code definitions */
# line 3 "./../snccn7500.stt"
#include <unistd.h>

/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
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
# line 54 "./../snccn7500.stt"
			seq_pvGet(ssId, 4/*sp0*/, 0);
# line 55 "./../snccn7500.stt"
			seq_pvGet(ssId, 5/*sp1*/, 0);
# line 56 "./../snccn7500.stt"
			seq_pvGet(ssId, 6/*sp2*/, 0);
# line 57 "./../snccn7500.stt"
			seq_pvGet(ssId, 7/*sp3*/, 0);
# line 58 "./../snccn7500.stt"
			seq_pvGet(ssId, 8/*sp4*/, 0);
# line 59 "./../snccn7500.stt"
			seq_pvGet(ssId, 9/*sp5*/, 0);
# line 60 "./../snccn7500.stt"
			seq_pvGet(ssId, 10/*sp6*/, 0);
# line 61 "./../snccn7500.stt"
			seq_pvGet(ssId, 11/*sp7*/, 0);
# line 62 "./../snccn7500.stt"
			seq_pvGet(ssId, 12/*low*/, 0);
# line 63 "./../snccn7500.stt"
			seq_pvGet(ssId, 13/*high*/, 0);
# line 64 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp0 - pVar->low;
# line 65 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp0 + pVar->high;
# line 66 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 67 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
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
# line 72 "./../snccn7500.stt"
	if (pVar->control == 0)
	{
		*pNextState = 0;
		*pTransNum = 0;
		return TRUE;
	}
# line 74 "./../snccn7500.stt"
	if (pVar->control == 1)
	{
		*pNextState = 2;
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
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "sp0" in state set "bakeout" ******/

/* Delay function for state "sp0" in state set "bakeout" */
static void D_bakeout_0_sp0(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp0" in state set "bakeout" */
static seqBool E_bakeout_0_sp0(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 79 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
# line 86 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 1)
	{
		*pNextState = 3;
		*pTransNum = 1;
		return TRUE;
	}
# line 88 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp0" in state set "bakeout" */
static void A_bakeout_0_sp0(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 80 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp0 - pVar->low;
# line 81 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp0 + pVar->high;
# line 82 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 83 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 84 "./../snccn7500.stt"
			sleep(100);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 89 "./../snccn7500.stt"
			pVar->control = 0;
# line 90 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp1" in state set "bakeout" ******/

/* Delay function for state "sp1" in state set "bakeout" */
static void D_bakeout_0_sp1(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp1" in state set "bakeout" */
static seqBool E_bakeout_0_sp1(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 95 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 1)
	{
		*pNextState = 3;
		*pTransNum = 0;
		return TRUE;
	}
# line 102 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 2)
	{
		*pNextState = 4;
		*pTransNum = 1;
		return TRUE;
	}
# line 104 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp1" in state set "bakeout" */
static void A_bakeout_0_sp1(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 96 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp1 - pVar->low;
# line 97 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp1 + pVar->high;
# line 98 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 99 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 100 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 105 "./../snccn7500.stt"
			pVar->control = 0;
# line 106 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp2" in state set "bakeout" ******/

/* Delay function for state "sp2" in state set "bakeout" */
static void D_bakeout_0_sp2(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp2" in state set "bakeout" */
static seqBool E_bakeout_0_sp2(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 111 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 2)
	{
		*pNextState = 4;
		*pTransNum = 0;
		return TRUE;
	}
# line 118 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 3)
	{
		*pNextState = 5;
		*pTransNum = 1;
		return TRUE;
	}
# line 120 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp2" in state set "bakeout" */
static void A_bakeout_0_sp2(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 112 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp2 - pVar->low;
# line 113 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp2 + pVar->high;
# line 114 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 115 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 116 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 121 "./../snccn7500.stt"
			pVar->control = 0;
# line 122 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp3" in state set "bakeout" ******/

/* Delay function for state "sp3" in state set "bakeout" */
static void D_bakeout_0_sp3(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp3" in state set "bakeout" */
static seqBool E_bakeout_0_sp3(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 127 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 3)
	{
		*pNextState = 5;
		*pTransNum = 0;
		return TRUE;
	}
# line 134 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 4)
	{
		*pNextState = 6;
		*pTransNum = 1;
		return TRUE;
	}
# line 136 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp3" in state set "bakeout" */
static void A_bakeout_0_sp3(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 128 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp3 - pVar->low;
# line 129 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp3 + pVar->high;
# line 130 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 131 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 132 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 137 "./../snccn7500.stt"
			pVar->control = 0;
# line 138 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp4" in state set "bakeout" ******/

/* Delay function for state "sp4" in state set "bakeout" */
static void D_bakeout_0_sp4(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp4" in state set "bakeout" */
static seqBool E_bakeout_0_sp4(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 143 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 4)
	{
		*pNextState = 6;
		*pTransNum = 0;
		return TRUE;
	}
# line 150 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 5)
	{
		*pNextState = 7;
		*pTransNum = 1;
		return TRUE;
	}
# line 152 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp4" in state set "bakeout" */
static void A_bakeout_0_sp4(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 144 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp4 - pVar->low;
# line 145 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp4 + pVar->high;
# line 146 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 147 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 148 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 153 "./../snccn7500.stt"
			pVar->control = 0;
# line 154 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp5" in state set "bakeout" ******/

/* Delay function for state "sp5" in state set "bakeout" */
static void D_bakeout_0_sp5(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp5" in state set "bakeout" */
static seqBool E_bakeout_0_sp5(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 159 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 5)
	{
		*pNextState = 7;
		*pTransNum = 0;
		return TRUE;
	}
# line 166 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 6)
	{
		*pNextState = 8;
		*pTransNum = 1;
		return TRUE;
	}
# line 168 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp5" in state set "bakeout" */
static void A_bakeout_0_sp5(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 160 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp5 - pVar->low;
# line 161 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp5 + pVar->high;
# line 162 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 163 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 164 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 169 "./../snccn7500.stt"
			pVar->control = 0;
# line 170 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp6" in state set "bakeout" ******/

/* Delay function for state "sp6" in state set "bakeout" */
static void D_bakeout_0_sp6(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp6" in state set "bakeout" */
static seqBool E_bakeout_0_sp6(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 175 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 6)
	{
		*pNextState = 8;
		*pTransNum = 0;
		return TRUE;
	}
# line 182 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 7)
	{
		*pNextState = 9;
		*pTransNum = 1;
		return TRUE;
	}
# line 184 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp6" in state set "bakeout" */
static void A_bakeout_0_sp6(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 176 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp6 - pVar->low;
# line 177 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp6 + pVar->high;
# line 178 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 179 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 180 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 185 "./../snccn7500.stt"
			pVar->control = 0;
# line 186 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/****** Code for state "sp7" in state set "bakeout" ******/

/* Delay function for state "sp7" in state set "bakeout" */
static void D_bakeout_0_sp7(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "sp7" in state set "bakeout" */
static seqBool E_bakeout_0_sp7(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 191 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 7)
	{
		*pNextState = 9;
		*pTransNum = 0;
		return TRUE;
	}
# line 198 "./../snccn7500.stt"
	if (pVar->control == 1 && pVar->step == 0)
	{
		*pNextState = 0;
		*pTransNum = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "sp7" in state set "bakeout" */
static void A_bakeout_0_sp7(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 192 "./../snccn7500.stt"
			pVar->pv_low = pVar->sp7 - pVar->low;
# line 193 "./../snccn7500.stt"
			pVar->pv_high = pVar->sp7 + pVar->high;
# line 194 "./../snccn7500.stt"
			seq_pvPut(ssId, 2/*pv_low*/, 0);
# line 195 "./../snccn7500.stt"
			seq_pvPut(ssId, 3/*pv_high*/, 0);
# line 196 "./../snccn7500.stt"
			sleep(10);
		}
		return;
	case 1:
		{
# line 199 "./../snccn7500.stt"
			pVar->control = 0;
# line 200 "./../snccn7500.stt"
			seq_pvPut(ssId, 0/*control*/, 0);
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{Sys}{Dev}Ctl-Cmd", offsetof(struct UserVar, control), "control", "int", 1, 1, 0, 1, 0, 0},
	{"{Sys}{Dev}CurStep-I", offsetof(struct UserVar, step), "step", "int", 1, 2, 0, 1, 0, 0},
	{"{Sys}{Dev}T-I.LOW", offsetof(struct UserVar, pv_low), "pv_low", "double", 1, 3, 0, 0, 0, 0},
	{"{Sys}{Dev}T-I.HIGH", offsetof(struct UserVar, pv_high), "pv_high", "double", 1, 4, 0, 0, 0, 0},
	{"{Sys}{Dev}Step0-RB", offsetof(struct UserVar, sp0), "sp0", "double", 1, 5, 0, 0, 0, 0},
	{"{Sys}{Dev}Step1-RB", offsetof(struct UserVar, sp1), "sp1", "double", 1, 6, 0, 0, 0, 0},
	{"{Sys}{Dev}Step2-RB", offsetof(struct UserVar, sp2), "sp2", "double", 1, 7, 0, 0, 0, 0},
	{"{Sys}{Dev}Step3-RB", offsetof(struct UserVar, sp3), "sp3", "double", 1, 8, 0, 0, 0, 0},
	{"{Sys}{Dev}Step4-RB", offsetof(struct UserVar, sp4), "sp4", "double", 1, 9, 0, 0, 0, 0},
	{"{Sys}{Dev}Step5-RB", offsetof(struct UserVar, sp5), "sp5", "double", 1, 10, 0, 0, 0, 0},
	{"{Sys}{Dev}Step6-RB", offsetof(struct UserVar, sp6), "sp6", "double", 1, 11, 0, 0, 0, 0},
	{"{Sys}{Dev}Step7-RB", offsetof(struct UserVar, sp7), "sp7", "double", 1, 12, 0, 0, 0, 0},
	{"{Sys}{Dev}Alrm1:Lo-RB", offsetof(struct UserVar, low), "low", "double", 1, 13, 0, 0, 0, 0},
	{"{Sys}{Dev}Alrm1:Hi-RB", offsetof(struct UserVar, high), "high", "double", 1, 14, 0, 0, 0, 0}
};

/* Event masks for state set "bakeout" */
static const seqMask	EM_bakeout_0_init[] = {
	0x00000000,
};
static const seqMask	EM_bakeout_0_check[] = {
	0x00000002,
};
static const seqMask	EM_bakeout_0_sp0[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp1[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp2[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp3[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp4[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp5[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp6[] = {
	0x00000006,
};
static const seqMask	EM_bakeout_0_sp7[] = {
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
	{
	/* state name */        "sp0",
	/* action function */   A_bakeout_0_sp0,
	/* event function */    E_bakeout_0_sp0,
	/* delay function */    D_bakeout_0_sp0,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp0,
	/* state options */     (0)
	},
	{
	/* state name */        "sp1",
	/* action function */   A_bakeout_0_sp1,
	/* event function */    E_bakeout_0_sp1,
	/* delay function */    D_bakeout_0_sp1,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp1,
	/* state options */     (0)
	},
	{
	/* state name */        "sp2",
	/* action function */   A_bakeout_0_sp2,
	/* event function */    E_bakeout_0_sp2,
	/* delay function */    D_bakeout_0_sp2,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp2,
	/* state options */     (0)
	},
	{
	/* state name */        "sp3",
	/* action function */   A_bakeout_0_sp3,
	/* event function */    E_bakeout_0_sp3,
	/* delay function */    D_bakeout_0_sp3,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp3,
	/* state options */     (0)
	},
	{
	/* state name */        "sp4",
	/* action function */   A_bakeout_0_sp4,
	/* event function */    E_bakeout_0_sp4,
	/* delay function */    D_bakeout_0_sp4,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp4,
	/* state options */     (0)
	},
	{
	/* state name */        "sp5",
	/* action function */   A_bakeout_0_sp5,
	/* event function */    E_bakeout_0_sp5,
	/* delay function */    D_bakeout_0_sp5,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp5,
	/* state options */     (0)
	},
	{
	/* state name */        "sp6",
	/* action function */   A_bakeout_0_sp6,
	/* event function */    E_bakeout_0_sp6,
	/* delay function */    D_bakeout_0_sp6,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp6,
	/* state options */     (0)
	},
	{
	/* state name */        "sp7",
	/* action function */   A_bakeout_0_sp7,
	/* event function */    E_bakeout_0_sp7,
	/* delay function */    D_bakeout_0_sp7,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_bakeout_0_sp7,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "bakeout",
	/* states */            G_bakeout_states,
	/* number of states */  10,
	/* number of delays */  0
	},
};

/* Program table (global) */
seqProgram snccn7500 = {
	/* magic number */      2001012,
	/* program name */      "snccn7500",
	/* channels */          G_channels,
	/* num. channels */     14,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_MAIN),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

#define PROG_NAME snccn7500
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void snccn7500Registrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&snccn7500);
}
epicsExportRegistrar(snccn7500Registrar);
