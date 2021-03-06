
#ifndef _LATCHALL12_MTC_H_
#define _LATCHALL12_MTC_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  Result_MTC /* MTC::LATCHALL12::Output1 */ Output1;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* -----------------------  latch memories  ------------------------ */
  int mem;
} outC_LATCHALL12_MTC;

/* ===========  node initialization and cycle functions  =========== */
/* MTC::LATCHALL12 */
extern void LATCHALL12_MTC(
  kcg_bool Input1,
  kcg_bool Input2,
  kcg_bool Input3,
  kcg_bool Input4,
  kcg_bool Input5,
  kcg_bool Input6,
  kcg_bool Input7,
  kcg_bool Input8,
  kcg_bool Input9,
  kcg_bool Input10,
  kcg_bool Input11,
  kcg_bool Input12,
  outC_LATCHALL12_MTC *outC);

extern void LATCHALL12_MTC_reset(outC_LATCHALL12_MTC *outC);
extern void LATCHALL12_MTC_init(outC_LATCHALL12_MTC *outC);

/* ======================  state vector type  ====================== */
typedef struct {
  /* --------------------- no memorised outputs  --------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* -----------------------  latch memories  ------------------------ */
  int mem;
} SV_LATCHALL12_MTC;

extern void kcg_save_SV_LATCHALL12_MTC(
  SV_LATCHALL12_MTC *SV,
  outC_LATCHALL12_MTC *outC);
extern void kcg_load_SV_LATCHALL12_MTC(
  outC_LATCHALL12_MTC *outC,
  SV_LATCHALL12_MTC *SV);

#endif /* _LATCHALL12_MTC_H_ */
