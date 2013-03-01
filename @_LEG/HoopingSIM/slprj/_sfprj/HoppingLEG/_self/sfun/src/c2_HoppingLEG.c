/* Include files */

#include "blascompat32.h"
#include "HoppingLEG_sfun.h"
#include "c2_HoppingLEG.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HoppingLEG_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[13] = { "Td", "La", "TotalActionTime",
  "TotalJumpingTime", "TotalActionTick", "TotalJumpingTick", "nargin", "nargout",
  "u", "y", "tick", "started", "output" };

/* Function Declarations */
static void initialize_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance);
static void initialize_params_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance);
static void enable_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance);
static void disable_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *
  chartInstance);
static void set_sim_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance);
static void sf_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance);
static void initSimStructsc2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_output, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_started, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_tick, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier);
static real_T c2_h_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_HoppingLEG, const char_T
  *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_HoppingLEGInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_tick_not_empty = FALSE;
  chartInstance->c2_started_not_empty = FALSE;
  chartInstance->c2_output_not_empty = FALSE;
  chartInstance->c2_is_active_c2_HoppingLEG = 0U;
}

static void initialize_params_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance)
{
}

static void enable_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_g_y;
  c2_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5));
  c2_hoistedGlobal = *c2_g_y;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_output;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_output_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_started;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  if (!chartInstance->c2_started_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_tick;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  if (!chartInstance->c2_tick_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_HoppingLEG;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_output = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "output");
  chartInstance->c2_started = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "started");
  chartInstance->c2_tick = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "tick");
  chartInstance->c2_is_active_c2_HoppingLEG = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_c2_HoppingLEG");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_HoppingLEG(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance)
{
}

static void sf_c2_HoppingLEG(SFc2_HoppingLEGInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_u;
  uint32_T c2_debug_family_var_map[13];
  real_T c2_Td;
  real_T c2_La;
  real_T c2_TotalActionTime;
  real_T c2_TotalJumpingTime;
  real_T c2_TotalActionTick;
  real_T c2_TotalJumpingTick;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y;
  real_T c2_b_hoistedGlobal;
  real_T c2_a;
  real_T c2_b_y;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T *c2_b_u;
  real_T *c2_c_y;
  boolean_T guard1 = FALSE;
  c2_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_c_y, 1U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_u;
  c2_u = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_Td, 0U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_La, 1U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TotalActionTime, 2U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TotalJumpingTime, 3U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TotalActionTick, 4U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_TotalJumpingTick, 5U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 6U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 7U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_u, 8U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_y, 9U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_tick, 10U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_started, 11U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_output, 12U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_Td = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_La = 0.4;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_TotalActionTime = 0.08;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_TotalJumpingTime = 0.4;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_TotalActionTick = 80.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_TotalJumpingTick = 400.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  if (CV_EML_IF(0, 0, !chartInstance->c2_tick_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    chartInstance->c2_tick = 0.0;
    chartInstance->c2_tick_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    chartInstance->c2_started = 0.0;
    chartInstance->c2_started_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  if (CV_EML_IF(0, 1, c2_u == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    chartInstance->c2_started = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    chartInstance->c2_output = 0.0;
    chartInstance->c2_output_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  if (CV_EML_IF(0, 2, chartInstance->c2_started != 0.0) != 0.0) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    if (CV_EML_IF(0, 3, chartInstance->c2_tick < c2_TotalActionTick)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
      chartInstance->c2_tick++;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
      c2_b_hoistedGlobal = chartInstance->c2_tick;
      c2_a = c2_b_hoistedGlobal;
      c2_b_y = c2_a * 0.4;
      c2_A = c2_b_y;
      c2_x = c2_A;
      c2_b_x = c2_x;
      c2_c_x = c2_b_x;
      c2_y = c2_c_x / 80.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
      guard1 = FALSE;
      if (CV_EML_COND(0, 0, chartInstance->c2_tick >= c2_TotalActionTick)) {
        if (CV_EML_COND(0, 1, chartInstance->c2_tick < c2_TotalJumpingTick)) {
          CV_EML_MCDC(0, 0, TRUE);
          CV_EML_IF(0, 4, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
          chartInstance->c2_tick++;
          _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
          c2_y = 0.0;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(0, 0, FALSE);
        CV_EML_IF(0, 4, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
        chartInstance->c2_tick = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
        chartInstance->c2_started = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
        chartInstance->c2_output = 0.0;
        chartInstance->c2_output_not_empty = TRUE;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -33);
  sf_debug_symbol_scope_pop();
  *c2_c_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_HoppingLEGMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_HoppingLEG(SFc2_HoppingLEGInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_output_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_output, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_output),
    &c2_thisId);
  sf_mex_destroy(&c2_b_output);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_output_not_empty = FALSE;
  } else {
    chartInstance->c2_output_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_output;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_b_output = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_output),
    &c2_thisId);
  sf_mex_destroy(&c2_b_output);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_started_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_started, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_started),
    &c2_thisId);
  sf_mex_destroy(&c2_b_started);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_started_not_empty = FALSE;
  } else {
    chartInstance->c2_started_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_started;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_b_started = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_started),
    &c2_thisId);
  sf_mex_destroy(&c2_b_started);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_tick_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_b_tick, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tick), &c2_thisId);
  sf_mex_destroy(&c2_b_tick);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_tick_not_empty = FALSE;
  } else {
    chartInstance->c2_tick_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tick;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_b_tick = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tick), &c2_thisId);
  sf_mex_destroy(&c2_b_tick);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier)
{
  real_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static real_T c2_h_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_HoppingLEG_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[4];
  c2_ResolvedFunctionInfo (*c2_b_info)[4];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[4])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 2117098240U;
  (*c2_b_info)[0].fileTimeHi = 30130935U;
  (*c2_b_info)[0].mFileTimeLo = 3573034496U;
  (*c2_b_info)[0].mFileTimeHi = 30114299U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1847391744U;
  (*c2_b_info)[1].fileTimeHi = 30108011U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 387391744U;
  (*c2_b_info)[2].fileTimeHi = 30108011U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "mtimes";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[3].fileTimeLo = 3573034496U;
  (*c2_b_info)[3].fileTimeHi = 30114299U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_HoppingLEG, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_HoppingLEG), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_HoppingLEG);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_HoppingLEGInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_HoppingLEGInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_HoppingLEG_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(933120896U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1916743187U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2771295336U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3073786394U);
}

mxArray *sf_c2_HoppingLEG_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2051428077U);
    pr[1] = (double)(2436396364U);
    pr[2] = (double)(876857596U);
    pr[3] = (double)(2351487343U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c2_HoppingLEG(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"output\",S'l','i','p'{{M1x2[321 327],M[0],}}},{M[4],M[0],T\"started\",S'l','i','p'{{M1x2[302 309],M[0],}}},{M[4],M[0],T\"tick\",S'l','i','p'{{M1x2[297 301],M[0],}}},{M[8],M[0],T\"is_active_c2_HoppingLEG\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_HoppingLEG_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_HoppingLEGInstanceStruct *chartInstance;
    chartInstance = (SFc2_HoppingLEGInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_HoppingLEGMachineNumber_,
           2,
           1,
           1,
           2,
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
          init_script_number_translation(_HoppingLEGMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_HoppingLEGMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_HoppingLEGMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,5,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,697);
        _SFD_CV_INIT_EML_IF(0,0,328,344,-1,379);
        _SFD_CV_INIT_EML_IF(0,1,385,394,-1,429);
        _SFD_CV_INIT_EML_IF(0,2,430,440,-1,695);
        _SFD_CV_INIT_EML_IF(0,3,445,468,529,690);
        _SFD_CV_INIT_EML_IF(0,4,529,582,621,690);

        {
          static int condStart[] = { 536, 561 };

          static int condEnd[] = { 557, 582 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,536,582,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);

        {
          real_T *c2_u;
          real_T *c2_y;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_HoppingLEGMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_HoppingLEG(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*)
    chartInstanceVar);
  initialize_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_HoppingLEG(void *chartInstanceVar)
{
  enable_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_HoppingLEG(void *chartInstanceVar)
{
  disable_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_HoppingLEG(void *chartInstanceVar)
{
  sf_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_HoppingLEG(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_HoppingLEG
    ((SFc2_HoppingLEGInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HoppingLEG();/* state var info */
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

extern void sf_internal_set_sim_state_c2_HoppingLEG(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HoppingLEG();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_HoppingLEG(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_HoppingLEG(S);
}

static void sf_opaque_set_sim_state_c2_HoppingLEG(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_HoppingLEG(S, st);
}

static void sf_opaque_terminate_c2_HoppingLEG(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_HoppingLEG(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_HoppingLEG((SFc2_HoppingLEGInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_HoppingLEG(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"HoppingLEG","HoppingLEG",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"HoppingLEG","HoppingLEG",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"HoppingLEG",
      "HoppingLEG",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"HoppingLEG","HoppingLEG",2,1);
      sf_mark_chart_reusable_outputs(S,"HoppingLEG","HoppingLEG",2,1);
    }

    sf_set_rtw_dwork_info(S,"HoppingLEG","HoppingLEG",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3951611099U));
  ssSetChecksum1(S,(2115182686U));
  ssSetChecksum2(S,(2834402147U));
  ssSetChecksum3(S,(1149098113U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_HoppingLEG(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "HoppingLEG", "HoppingLEG",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_HoppingLEG(SimStruct *S)
{
  SFc2_HoppingLEGInstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGInstanceStruct *)malloc(sizeof
    (SFc2_HoppingLEGInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_HoppingLEGInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_HoppingLEG;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_HoppingLEG;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_HoppingLEG;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_HoppingLEG;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_HoppingLEG;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_HoppingLEG;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_HoppingLEG;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_HoppingLEG;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_HoppingLEG;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_HoppingLEG;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_HoppingLEG;
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

void c2_HoppingLEG_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_HoppingLEG(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_HoppingLEG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_HoppingLEG(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_HoppingLEG_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
