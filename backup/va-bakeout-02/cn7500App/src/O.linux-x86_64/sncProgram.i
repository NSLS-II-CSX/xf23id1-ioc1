# 1 "../sncProgram.st"
# 1 "<command-line>"
# 1 "../sncProgram.st"
# 1 "./../snccn7500.stt" 1
program snccn7500

%%#include <unistd.h>

int control;
assign control to "{Sys}{Dev}Ctl-Cmd";
monitor control;

int step;
assign step to "{Sys}{Dev}CurStep-I";
monitor step;

double pv_low;
assign pv_low to "{Sys}{Dev}T-I.LOW";

double pv_high;
assign pv_high to "{Sys}{Dev}T-I.HIGH";

double sp0;
assign sp0 to "{Sys}{Dev}Step0-RB";

double sp1;
assign sp1 to "{Sys}{Dev}Step1-RB";

double sp2;
assign sp2 to "{Sys}{Dev}Step2-RB";

double sp3;
assign sp3 to "{Sys}{Dev}Step3-RB";

double sp4;
assign sp4 to "{Sys}{Dev}Step4-RB";

double sp5;
assign sp5 to "{Sys}{Dev}Step5-RB";

double sp6;
assign sp6 to "{Sys}{Dev}Step6-RB";

double sp7;
assign sp7 to "{Sys}{Dev}Step7-RB";

double low;
assign low to "{Sys}{Dev}Alrm1:Lo-RB";

double high;
assign high to "{Sys}{Dev}Alrm1:Hi-RB";

option +r;

ss bakeout {
    state init {
 when () {
  pvGet(sp0);
  pvGet(sp1);
  pvGet(sp2);
  pvGet(sp3);
  pvGet(sp4);
  pvGet(sp5);
  pvGet(sp6);
  pvGet(sp7);
  pvGet(low);
  pvGet(high);
  pv_low = sp0-low;
  pv_high = sp0+high;
  pvPut(pv_low);
  pvPut(pv_high);
 } state check
    }

    state check {
 when ( control == 0 ) {
 } state init
 when ( control == 1 ) {
 } state sp0
    }

    state sp0 {
 when ( control == 1 && step == 0 ) {
  pv_low=sp0-low;
  pv_high=sp0+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(100);
 } state sp0
 when ( control == 1 && step == 1 ) {
 } state sp1
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp1 {
 when ( control == 1 && step == 1 ) {
  pv_low=sp1-low;
  pv_high=sp1+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp1
 when ( control == 1 && step == 2 ) {
 } state sp2
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp2 {
 when ( control == 1 && step == 2 ) {
  pv_low=sp2-low;
  pv_high=sp2+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp2
 when ( control == 1 && step == 3 ) {
 } state sp3
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp3 {
 when ( control == 1 && step == 3 ) {
  pv_low=sp3-low;
  pv_high=sp3+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp3
 when ( control == 1 && step == 4 ) {
 } state sp4
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp4 {
 when ( control == 1 && step == 4 ) {
  pv_low=sp4-low;
  pv_high=sp4+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp4
 when ( control == 1 && step == 5 ) {
 } state sp5
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp5 {
 when ( control == 1 && step == 5 ) {
  pv_low=sp5-low;
  pv_high=sp5+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp5
 when ( control == 1 && step == 6 ) {
 } state sp6
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp6 {
 when ( control == 1 && step == 6 ) {
  pv_low=sp6-low;
  pv_high=sp6+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp6
 when ( control == 1 && step == 7 ) {
 } state sp7
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }

    state sp7 {
 when ( control == 1 && step == 7 ) {
  pv_low=sp7-low;
  pv_high=sp7+high;
  pvPut(pv_low);
  pvPut(pv_high);
  sleep(10);
 } state sp7
 when ( control == 1 && step == 0 ) {
  control = 0;
  pvPut(control);
 } state init
    }
}
# 1 "../sncProgram.st" 2
