/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config U:/Windows/Bureau/Drone_state_machine/KCG\kcg_s2c_config.txt
** Generation date: 2015-12-03T12:01:41
*************************************************************$ */
#ifndef _system_state_machine_H_
#define _system_state_machine_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_int /* system_state_machine::flag_land */ flag_land;
  kcg_int /* system_state_machine::flag_takeoff */ flag_takeoff;
  kcg_int /* system_state_machine::flag_control_e */ flag_control_e;
  kcg_int /* system_state_machine::flag_emergency */ flag_emergency;
  kcg_int /* system_state_machine::flag_control_s */ flag_control_s;
  kcg_int /* system_state_machine::flag_calibM */ flag_calibM;
  kcg_int /* system_state_machine::flag_calibH */ flag_calibH;
  kcg_int /* system_state_machine::flag_rollcalled */ flag_rollcalled;
  kcg_int /* system_state_machine::flag_yawcalled */ flag_yawcalled;
  kcg_int /* system_state_machine::flag_rollpitchcalled */ flag_rollpitchcalled;
  kcg_int /* system_state_machine::flag_pitchcalled */ flag_pitchcalled;
  kcg_int /* system_state_machine::falg_antiemergency */ falg_antiemergency;
} inC_system_state_machine;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_int /* system_state_machine::order_called */ order_called;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init1;
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  SSM_ST_SM2_SM1_STATE_MANUAL /* system_state_machine::SM1::STATE_MANUAL::SM2 */ SM2_state_nxt_SM1_STATE_MANUAL;
  SSM_ST_SM1 /* system_state_machine::SM1 */ SM1_state_nxt;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_system_state_machine;

/* ===========  node initialization and cycle functions  =========== */
/* system_state_machine */
extern void system_state_machine(
  inC_system_state_machine *inC,
  outC_system_state_machine *outC);

extern void system_state_machine_reset(outC_system_state_machine *outC);

#endif /* _system_state_machine_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** system_state_machine.h
** Generation date: 2015-12-03T12:01:41
*************************************************************$ */

