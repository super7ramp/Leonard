/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config U:/Windows/Bureau/Drone_state_machine/KCG\kcg_s2c_config.txt
** Generation date: 2015-12-03T12:01:41
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#define KCG_MAPW_CPY

#include "./user_macros.h"

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif /* kcg_real */

#ifndef kcg_char
#define kcg_char kcg_char
typedef unsigned char kcg_char;
#endif /* kcg_char */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_assign
#include "include/kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* truthtables::TruthTableValues */
typedef enum {
  T_truthtables,
  F_truthtables,
  X_truthtables
} TruthTableValues_truthtables;
/* system_state_machine::SM1 */
typedef enum {
  SSM_TR_no_trans_SM1,
  SSM_TR_FIRST_STAT_1_SM1,
  SSM_TR_FIRST_STAT_2_SM1,
  SSM_TR_FIRST_STAT_3_SM1,
  SSM_TR_STATE_MANUAL_1_SM1,
  SSM_TR_STATE_MISSION_1_SM1
} SSM_TR_SM1;
/* system_state_machine::SM1 */
typedef enum {
  SSM_st_FIRST_STAT_SM1,
  SSM_st_STATE_MANUAL_SM1,
  SSM_st_STATE_MISSION_SM1,
  SSM_st_LAST_STATE_SM1
} SSM_ST_SM1;
/* system_state_machine::SM1::STATE_MANUAL::SM2 */
typedef enum {
  SSM_TR_no_trans_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_2_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_3_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_4_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_5_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_6_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_7_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_8_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_9_SM2_SM1_STATE_MANUAL,
  SSM_TR_Init_10_SM2_SM1_STATE_MANUAL,
  SSM_TR_MOVE_PITCHROLL_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_LAND_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_TAKE_OFF_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_EMERGENCY_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_SET_TRIM_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_SET_MAGN_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_MOVE_ROLL_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_MOVE_PITCH_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_ANTI_EMERGENCY_1_SM2_SM1_STATE_MANUAL,
  SSM_TR_MOVE_YAW_1_SM2_SM1_STATE_MANUAL
} SSM_TR_SM2_SM1_STATE_MANUAL;
/* system_state_machine::SM1::STATE_MANUAL::SM2 */
typedef enum {
  SSM_st_Init_SM1_STATE_MANUAL_SM2,
  SSM_st_LAST_STATE_SM1_STATE_MANUAL_SM2,
  SSM_st_MOVE_PITCHROLL_SM1_STATE_MANUAL_SM2,
  SSM_st_LAND_SM1_STATE_MANUAL_SM2,
  SSM_st_TAKE_OFF_SM1_STATE_MANUAL_SM2,
  SSM_st_EMERGENCY_SM1_STATE_MANUAL_SM2,
  SSM_st_SET_TRIM_SM1_STATE_MANUAL_SM2,
  SSM_st_SET_MAGN_SM1_STATE_MANUAL_SM2,
  SSM_st_MOVE_ROLL_SM1_STATE_MANUAL_SM2,
  SSM_st_MOVE_PITCH_SM1_STATE_MANUAL_SM2,
  SSM_st_ANTI_EMERGENCY_SM1_STATE_MANUAL_SM2,
  SSM_st_MOVE_YAW_SM1_STATE_MANUAL_SM2
} SSM_ST_SM2_SM1_STATE_MANUAL;
typedef struct { kcg_int k; kcg_real f; } struct__5293;

/* lut::LutIndex */
typedef struct__5293 LutIndex_lut;

#ifndef kcg_copy_struct__5293
#define kcg_copy_struct__5293(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__5293)))
#endif /* kcg_copy_struct__5293 */

#ifndef kcg_comp_struct__5293
extern kcg_bool kcg_comp_struct__5293(
  struct__5293 *kcg_c1,
  struct__5293 *kcg_c2);
#endif /* kcg_comp_struct__5293 */

#define kcg_comp_LutIndex_lut kcg_comp_struct__5293

#define kcg_copy_LutIndex_lut kcg_copy_struct__5293

#endif /* _KCG_TYPES_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** kcg_types.h
** Generation date: 2015-12-03T12:01:41
*************************************************************$ */

