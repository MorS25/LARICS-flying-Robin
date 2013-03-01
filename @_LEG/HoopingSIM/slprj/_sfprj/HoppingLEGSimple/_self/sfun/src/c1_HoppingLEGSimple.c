/* Include files */

#include "blascompat32.h"
#include "HoppingLEGSimple_sfun.h"
#include "c1_HoppingLEGSimple.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HoppingLEGSimple_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0U)
#define c1_IN_Stancedown               (1U)
#define c1_const_k                     (30.0)
#define c1_const_mass                  (1.0)
#define c1_const_l0                    (0.0)
#define c1_const_c                     (1.0)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void initialize_params_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static void enable_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void disable_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static void set_sim_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static void finalize_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void sf_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void zeroCrossings_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static void derivatives_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance);
static void outputs_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void initSimStructsc1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_eml_ini_fcn_to_be_inlined_60(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance);
static void c1_eml_term_fcn_to_be_inlined_60(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static const mxArray *c1_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, int32_T c1_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier);
static int32_T c1_b_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, uint8_T c1_u);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_c_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_Stancedown, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, real_T c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_l, const char_T *c1_identifier);
static real_T c1_f_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);
static void c1_g_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_h_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_i_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  real_T *c1_l;
  real_T *c1_yv;
  real_T *c1_y;
  real_T *c1_lv;
  real_T *c1_y_out;
  c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_y = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_yv = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_Stancedown = 0U;
  chartInstance->c1_is_active_c1_HoppingLEGSimple = 0U;
  chartInstance->c1_is_c1_HoppingLEGSimple = 0U;
  *c1_l = 0.0;
  *c1_yv = 0.0;
  *c1_y = 0.0;
  *c1_lv = 0.0;
  chartInstance->c1_k = 30.0;
  chartInstance->c1_mass = 1.0;
  chartInstance->c1_l0 = 0.0;
  chartInstance->c1_c = 1.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_y_out = 0.0;
  }
}

static void initialize_params_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
}

static void enable_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c1_is_active_c1_HoppingLEGSimple == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_HoppingLEGSimple == c1_IN_Stancedown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_d_emlrt_marshallOut(chartInstance));
  return c1_st;
}

static void set_sim_state_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance, const mxArray *c1_st)
{
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_HoppingLEGSimple(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_HoppingLEGSimple == c1_IN_Stancedown) {
      chartInstance->c1_tp_Stancedown = 1U;
    } else {
      chartInstance->c1_tp_Stancedown = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  real_T *c1_l;
  real_T *c1_yv;
  real_T *c1_y_out;
  real_T *c1_y;
  real_T *c1_lv;
  real_T *c1_LA;
  real_T *c1_d_LA;
  c1_d_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_y = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_yv = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_set_sim_state_side_effects_c1_HoppingLEGSimple(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    chartInstance->c1_lastMajorTime = _sfTime_;
    chartInstance->c1_stateChanged = (boolean_T)0;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_DATA_RANGE_CHECK(*c1_l, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_yv, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_y_out, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_y, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_lv, 4U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_k, 5U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_mass, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_l0, 7U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_c, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_LA, 9U);
    _SFD_DATA_RANGE_CHECK(*c1_d_LA, 10U);
    chartInstance->c1_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if ((int16_T)chartInstance->c1_is_active_c1_HoppingLEGSimple == 0) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_stateChanged = TRUE;
      chartInstance->c1_is_active_c1_HoppingLEGSimple = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      *c1_l = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_l, 0U);
      *c1_lv = -7.0441;
      _SFD_DATA_RANGE_CHECK(*c1_lv, 4U);
      chartInstance->c1_stateChanged = TRUE;
      chartInstance->c1_is_c1_HoppingLEGSimple = c1_IN_Stancedown;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Stancedown = 1U;
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    if (chartInstance->c1_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_y_out = *c1_l;
  _SFD_DATA_RANGE_CHECK(*c1_y_out, 2U);
  sf_debug_check_for_state_inconsistency(_HoppingLEGSimpleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void zeroCrossings_c1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
  real_T *c1_zcVar;
  c1_zcVar = (real_T *)(ssGetNonsampledZCs(chartInstance->S) + 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (chartInstance->c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    chartInstance->c1_stateChanged = (boolean_T)0;
    if ((int16_T)chartInstance->c1_is_active_c1_HoppingLEGSimple == 0) {
      chartInstance->c1_stateChanged = TRUE;
    }

    if (chartInstance->c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance)
{
  real_T *c1_l_dot;
  real_T *c1_yv_dot;
  real_T *c1_y_dot;
  real_T *c1_lv_dot;
  real_T *c1_lv;
  real_T *c1_LA;
  real_T *c1_l;
  real_T *c1_d_LA;
  real_T *c1_y_out;
  c1_d_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_lv_dot = (real_T *)(ssGetdX(chartInstance->S) + 3);
  c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_y_dot = (real_T *)(ssGetdX(chartInstance->S) + 2);
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_yv_dot = (real_T *)(ssGetdX(chartInstance->S) + 1);
  c1_l_dot = (real_T *)(ssGetdX(chartInstance->S) + 0);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  *c1_l_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_l_dot, 0U);
  *c1_yv_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_yv_dot, 1U);
  *c1_y_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_y_dot, 3U);
  *c1_lv_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_lv_dot, 4U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_l_dot = *c1_lv;
  _SFD_DATA_RANGE_CHECK(*c1_l_dot, 0U);
  *c1_lv_dot = ((c1_const_k * (*c1_LA - *c1_l) - 9.81) - *c1_lv) + *c1_d_LA;
  _SFD_DATA_RANGE_CHECK(*c1_lv_dot, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_y_out, 2U);
}

static void outputs_c1_HoppingLEGSimple(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  real_T *c1_l;
  real_T *c1_y_out;
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_y_out = *c1_l;
  _SFD_DATA_RANGE_CHECK(*c1_y_out, 2U);
}

static void initSimStructsc1_HoppingLEGSimple
  (SFc1_HoppingLEGSimpleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_HoppingLEGSimple_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static void c1_eml_ini_fcn_to_be_inlined_60(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance)
{
}

static void c1_eml_term_fcn_to_be_inlined_60(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, int32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  return c1_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance,
    *(int32_T *)c1_inData));
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_b_sfEvent, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  return c1_y;
}

static int32_T c1_b_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c1_outData = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  return c1_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c1_inData));
  return c1_mxArrayOutData;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_Stancedown, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_Stancedown),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_Stancedown);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c1_outData = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, real_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_c_emlrt_marshallOut(chartInstance,
    *(real_T *)c1_inData));
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_l, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_l), &c1_thisId);
  sf_mex_destroy(&c1_l);
  return c1_y;
}

static real_T c1_f_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)chartInstanceVoid;
  *(real_T *)c1_outData = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_emlrt_marshallOut(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
  const mxArray *c1_y;
  real_T *c1_y_out;
  real_T *c1_l;
  real_T *c1_lv;
  real_T *c1_b_y;
  real_T *c1_yv;
  c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_b_y = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_yv = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(7));
  sf_mex_setcell(c1_y, 0, c1_c_emlrt_marshallOut(chartInstance, *c1_y_out));
  sf_mex_setcell(c1_y, 1, c1_c_emlrt_marshallOut(chartInstance, *c1_l));
  sf_mex_setcell(c1_y, 2, c1_c_emlrt_marshallOut(chartInstance, *c1_lv));
  sf_mex_setcell(c1_y, 3, c1_c_emlrt_marshallOut(chartInstance, *c1_b_y));
  sf_mex_setcell(c1_y, 4, c1_c_emlrt_marshallOut(chartInstance, *c1_yv));
  sf_mex_setcell(c1_y, 5, c1_b_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_active_c1_HoppingLEGSimple));
  sf_mex_setcell(c1_y, 6, c1_b_emlrt_marshallOut(chartInstance,
    chartInstance->c1_is_c1_HoppingLEGSimple));
  return c1_y;
}

static void c1_g_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  real_T *c1_y_out;
  real_T *c1_l;
  real_T *c1_lv;
  real_T *c1_y;
  real_T *c1_yv;
  c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_y = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_yv = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  *c1_y_out = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "y_out");
  *c1_l = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "l");
  *c1_lv = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "lv");
  *c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "y");
  *c1_yv = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "yv");
  chartInstance->c1_is_active_c1_HoppingLEGSimple = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
     "is_active_c1_HoppingLEGSimple");
  chartInstance->c1_is_c1_HoppingLEGSimple = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "is_c1_HoppingLEGSimple");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 7)), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_h_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_i_emlrt_marshallIn(SFc1_HoppingLEGSimpleInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u));
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_HoppingLEGSimpleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_HoppingLEGSimple_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(864814434U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3598383301U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2823846990U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2594595274U);
}

mxArray *sf_c1_HoppingLEGSimple_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(363052973U);
    pr[1] = (double)(1144054525U);
    pr[2] = (double)(2477988182U);
    pr[3] = (double)(2490397907U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_HoppingLEGSimple(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[11],T\"y_out\",},{M[5],M[6],T\"l\",},{M[5],M[59],T\"lv\",},{M[5],M[53],T\"y\",},{M[5],M[8],T\"yv\",},{M[8],M[0],T\"is_active_c1_HoppingLEGSimple\",},{M[9],M[0],T\"is_c1_HoppingLEGSimple\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_HoppingLEGSimple_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
    chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_HoppingLEGSimpleMachineNumber_,
           1,
           1,
           1,
           11,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_HoppingLEGSimpleMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_HoppingLEGSimpleMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_HoppingLEGSimpleMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"l");
          _SFD_SET_DATA_PROPS(1,0,0,0,"yv");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y_out");
          _SFD_SET_DATA_PROPS(3,0,0,0,"y");
          _SFD_SET_DATA_PROPS(4,0,0,0,"lv");
          _SFD_SET_DATA_PROPS(5,7,0,0,"k");
          _SFD_SET_DATA_PROPS(6,7,0,0,"mass");
          _SFD_SET_DATA_PROPS(7,7,0,0,"l0");
          _SFD_SET_DATA_PROPS(8,7,0,0,"c");
          _SFD_SET_DATA_PROPS(9,1,1,0,"LA");
          _SFD_SET_DATA_PROPS(10,1,1,0,"d_LA");
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_TRANS_COV_WTS(0,0,0,2,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_l;
          real_T *c1_yv;
          real_T *c1_y_out;
          real_T *c1_y;
          real_T *c1_lv;
          real_T *c1_LA;
          real_T *c1_d_LA;
          c1_d_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_LA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_lv = (real_T *)(ssGetContStates(chartInstance->S) + 3);
          c1_y = (real_T *)(ssGetContStates(chartInstance->S) + 2);
          c1_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_yv = (real_T *)(ssGetContStates(chartInstance->S) + 1);
          c1_l = (real_T *)(ssGetContStates(chartInstance->S) + 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_l);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_yv);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_y_out);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_lv);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_k);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_mass);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_l0);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_c);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_LA);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_d_LA);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_HoppingLEGSimpleMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
  initialize_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  enable_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  disable_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  zeroCrossings_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_outputs_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  outputs_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  derivatives_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  sf_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_HoppingLEGSimple(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_HoppingLEGSimple
    ((SFc1_HoppingLEGSimpleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_HoppingLEGSimple();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_HoppingLEGSimple(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_HoppingLEGSimple();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_HoppingLEGSimple(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_HoppingLEGSimple(S);
}

static void sf_opaque_set_sim_state_c1_HoppingLEGSimple(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_HoppingLEGSimple(S, st);
}

static void sf_opaque_terminate_c1_HoppingLEGSimple(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_HoppingLEGSimpleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_HoppingLEGSimple(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_HoppingLEGSimple((SFc1_HoppingLEGSimpleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_HoppingLEGSimple(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"HoppingLEGSimple","HoppingLEGSimple",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"HoppingLEGSimple","HoppingLEGSimple",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"HoppingLEGSimple",
      "HoppingLEGSimple",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"HoppingLEGSimple",
        "HoppingLEGSimple",1,2);
      sf_mark_chart_reusable_outputs(S,"HoppingLEGSimple","HoppingLEGSimple",1,1);
    }

    sf_set_rtw_dwork_info(S,"HoppingLEGSimple","HoppingLEGSimple",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4082670042U));
  ssSetChecksum1(S,(2869902345U));
  ssSetChecksum2(S,(3745731589U));
  ssSetChecksum3(S,(1317743988U));
  ssSetNumContStates(S,4);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_HoppingLEGSimple(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "HoppingLEGSimple", "HoppingLEGSimple",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_HoppingLEGSimple(SimStruct *S)
{
  SFc1_HoppingLEGSimpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_HoppingLEGSimpleInstanceStruct *)malloc(sizeof
    (SFc1_HoppingLEGSimpleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_HoppingLEGSimpleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_HoppingLEGSimple;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_HoppingLEGSimple;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_HoppingLEGSimple;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_HoppingLEGSimple;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_HoppingLEGSimple;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_HoppingLEGSimple;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_HoppingLEGSimple;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_HoppingLEGSimple;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c1_HoppingLEGSimple;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c1_HoppingLEGSimple;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c1_HoppingLEGSimple;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_HoppingLEGSimple;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_HoppingLEGSimple;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_HoppingLEGSimple;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_HoppingLEGSimple_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_HoppingLEGSimple(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_HoppingLEGSimple(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_HoppingLEGSimple(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_HoppingLEGSimple_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
