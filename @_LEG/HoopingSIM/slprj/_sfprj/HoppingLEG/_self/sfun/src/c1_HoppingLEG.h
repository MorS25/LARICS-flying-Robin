#ifndef __c1_HoppingLEG_h__
#define __c1_HoppingLEG_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  real_T c1_l0;
  real_T c1_lastMajorTime;
  real_T c1_mass;
  SimStruct *S;
  const mxArray *c1_setSimStateSideEffectsInfo;
  int32_T c1_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_isStable;
  boolean_T c1_stateChanged;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_active_c1_HoppingLEG;
  uint8_T c1_is_c1_HoppingLEG;
  uint8_T c1_tp_Stancedown;
  uint8_T c1_tp_Swing;
  ChartInfoStruct chartInfo;
} SFc1_HoppingLEGInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_HoppingLEG_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_HoppingLEG_get_check_sum(mxArray *plhs[]);
extern void c1_HoppingLEG_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
