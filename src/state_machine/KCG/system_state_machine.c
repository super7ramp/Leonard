/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config U:/Windows/Bureau/Drone_state_machine/KCG\kcg_s2c_config.txt
** Generation date: 2015-12-03T19:26:25
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "system_state_machine.h"

void system_state_machine_reset(outC_system_state_machine *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
}

/* system_state_machine */
void system_state_machine(
  inC_system_state_machine *inC,
  outC_system_state_machine *outC)
{
  /* system_state_machine::SM1::STATE_MANUAL::SM2 */ SSM_ST_SM2_SM1_STATE_MANUAL SM2_state_act_SM1_STATE_MANUAL;
  /* system_state_machine::SM1::STATE_MANUAL::SM2 */ SSM_ST_SM2_SM1_STATE_MANUAL SM2_state_sel_SM1_STATE_MANUAL;
  /* system_state_machine::SM1::FIRST_STAT */ kcg_bool br_3_guard_SM1_FIRST_STAT;
  /* system_state_machine::SM1::FIRST_STAT */ kcg_bool br_2_guard_SM1_FIRST_STAT;
  /* system_state_machine::SM1::FIRST_STAT */ kcg_bool br_1_guard_SM1_FIRST_STAT;
  /* system_state_machine::order_called */ kcg_int last_order_called;
  /* system_state_machine::SM1 */ SSM_ST_SM1 SM1_state_sel;
  /* system_state_machine::SM1 */ SSM_ST_SM1 SM1_state_act;
  /* system_state_machine::SM1 */ kcg_bool SM1_reset_act;
  
  if (outC->init1) {
    last_order_called = 1;
    SM1_state_sel = SSM_st_FIRST_STAT_SM1;
  }
  else {
    last_order_called = outC->order_called;
    SM1_state_sel = outC->SM1_state_nxt;
  }
  switch (SM1_state_sel) {
    case SSM_st_FIRST_STAT_SM1 :
      br_1_guard_SM1_FIRST_STAT = inC->flag_control_e == 0;
      br_2_guard_SM1_FIRST_STAT = (inC->flag_control_e == 1) &
        (inC->flag_control_s == 0);
      br_3_guard_SM1_FIRST_STAT = (inC->flag_control_e == 1) &
        (inC->flag_control_s == 1);
      if (br_1_guard_SM1_FIRST_STAT) {
        SM1_state_act = SSM_st_LAST_STATE_SM1;
        SM1_reset_act = kcg_true;
      }
      else if (br_2_guard_SM1_FIRST_STAT) {
        SM1_state_act = SSM_st_STATE_MANUAL_SM1;
        SM1_reset_act = kcg_true;
      }
      else {
        if (br_3_guard_SM1_FIRST_STAT) {
          SM1_state_act = SSM_st_STATE_MISSION_SM1;
        }
        else {
          SM1_state_act = SSM_st_FIRST_STAT_SM1;
        }
        SM1_reset_act = br_3_guard_SM1_FIRST_STAT;
      }
      break;
    case SSM_st_STATE_MANUAL_SM1 :
      SM1_state_act = SSM_st_LAST_STATE_SM1;
      SM1_reset_act = kcg_true;
      break;
    case SSM_st_STATE_MISSION_SM1 :
      SM1_state_act = SSM_st_LAST_STATE_SM1;
      SM1_reset_act = kcg_true;
      break;
    case SSM_st_LAST_STATE_SM1 :
      SM1_state_act = SSM_st_LAST_STATE_SM1;
      SM1_reset_act = kcg_false;
      break;
    
  }
  switch (SM1_state_act) {
    case SSM_st_FIRST_STAT_SM1 :
      outC->SM1_state_nxt = SSM_st_FIRST_STAT_SM1;
      outC->order_called = last_order_called;
      break;
    case SSM_st_STATE_MANUAL_SM1 :
      if (SM1_reset_act) {
        outC->init = kcg_true;
      }
      if (outC->init) {
        SM2_state_sel_SM1_STATE_MANUAL = SSM_st_Init_SM1_STATE_MANUAL_SM2;
      }
      else {
        SM2_state_sel_SM1_STATE_MANUAL = outC->SM2_state_nxt_SM1_STATE_MANUAL;
      }
      switch (SM2_state_sel_SM1_STATE_MANUAL) {
        case SSM_st_Init_SM1_STATE_MANUAL_SM2 :
          if (inC->flag_rollcalled == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_rollpitchcalled == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_land == 1) {
            SM2_state_act_SM1_STATE_MANUAL = SSM_st_LAND_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_takeoff == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_calibM == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_calibH == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_emergency == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_pitchcalled == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->falg_antiemergency == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2;
          }
          else if (inC->flag_yawcalled == 1) {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2;
          }
          else {
            SM2_state_act_SM1_STATE_MANUAL =
              SSM_st_State17_SM1_STATE_MANUAL_SM2;
          }
          break;
        case SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_LAND_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_State17_SM1_STATE_MANUAL_SM2 :
          SM2_state_act_SM1_STATE_MANUAL = SSM_st_State17_SM1_STATE_MANUAL_SM2;
          break;
        
      }
      switch (SM2_state_act_SM1_STATE_MANUAL) {
        case SSM_st_Init_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_Init_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_LAND_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_LAND_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2;
          break;
        case SSM_st_State17_SM1_STATE_MANUAL_SM2 :
          outC->SM2_state_nxt_SM1_STATE_MANUAL =
            SSM_st_State17_SM1_STATE_MANUAL_SM2;
          break;
        
      }
      outC->SM1_state_nxt = SSM_st_STATE_MANUAL_SM1;
      switch (SM2_state_act_SM1_STATE_MANUAL) {
        case SSM_st_Init_SM1_STATE_MANUAL_SM2 :
          outC->order_called = last_order_called;
          break;
        case SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2 :
          outC->order_called = last_order_called;
          break;
        case SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 6;
          break;
        case SSM_st_LAND_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 1;
          break;
        case SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 2;
          break;
        case SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 9;
          break;
        case SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 7;
          break;
        case SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 8;
          break;
        case SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 3;
          break;
        case SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 4;
          break;
        case SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 10;
          break;
        case SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 5;
          break;
        case SSM_st_State17_SM1_STATE_MANUAL_SM2 :
          outC->order_called = 0;
          break;
        
      }
      outC->init = kcg_false;
      break;
    case SSM_st_STATE_MISSION_SM1 :
      outC->SM1_state_nxt = SSM_st_STATE_MISSION_SM1;
      outC->order_called = 20;
      break;
    case SSM_st_LAST_STATE_SM1 :
      outC->SM1_state_nxt = SSM_st_LAST_STATE_SM1;
      outC->order_called = last_order_called;
      break;
    
  }
  outC->init1 = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** system_state_machine.c
** Generation date: 2015-12-03T19:26:25
*************************************************************$ */

