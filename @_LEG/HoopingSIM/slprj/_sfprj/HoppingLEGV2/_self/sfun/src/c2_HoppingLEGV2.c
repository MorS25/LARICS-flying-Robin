/* Include files */

#include "blascompat32.h"
#include "HoppingLEGV2_sfun.h"
#include "c2_HoppingLEGV2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HoppingLEGV2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[17] = { "nargin", "nargout", "u", "s",
  "state", "k", "ku", "y_BOOST", "y", "E_current", "E_added", "okidanje",
  "lastY", "Hout", "lastState", "last_E_current", "last_E_added" };

/* Function Declarations */
static void initialize_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void initialize_params_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void enable_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void disable_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_HoppingLEGV2
  (SFc2_HoppingLEGV2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_HoppingLEGV2
  (SFc2_HoppingLEGV2InstanceStruct *chartInstance);
static void set_sim_state_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void sf_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct *chartInstance);
static void initSimStructsc2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct *chartInstance,
  const mxArray *c2_b_last_E_added, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_last_E_current, const char_T
  *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_lastState, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_Hout, const char_T *c2_identifier);
static real_T c2_h_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_i_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_lastY, const char_T *c2_identifier);
static real_T c2_j_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_k_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_okidanje, const char_T *c2_identifier);
static real_T c2_l_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_m_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_E_added, const char_T *c2_identifier);
static real_T c2_n_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_mpower(SFc2_HoppingLEGV2InstanceStruct *chartInstance, real_T
  c2_a);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_o_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_p_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_HoppingLEGV2, const char_T
  *c2_identifier);
static uint8_T c2_q_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_HoppingLEGV2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_okidanje_not_empty = FALSE;
  chartInstance->c2_lastY_not_empty = FALSE;
  chartInstance->c2_Hout_not_empty = FALSE;
  chartInstance->c2_lastState_not_empty = FALSE;
  chartInstance->c2_last_E_current_not_empty = FALSE;
  chartInstance->c2_last_E_added_not_empty = FALSE;
  chartInstance->c2_is_active_c2_HoppingLEGV2 = 0U;
}

static void initialize_params_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance)
{
}

static void enable_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_HoppingLEGV2
  (SFc2_HoppingLEGV2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_HoppingLEGV2
  (SFc2_HoppingLEGV2InstanceStruct *chartInstance)
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
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  uint8_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T *c2_E_added;
  real_T *c2_E_current;
  real_T *c2_l_y;
  c2_E_added = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_E_current = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_l_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(10));
  c2_hoistedGlobal = *c2_E_added;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_E_current;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_l_y;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_Hout;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  if (!chartInstance->c2_Hout_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_lastState;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  if (!chartInstance->c2_lastState_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_lastY;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  if (!chartInstance->c2_lastY_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = chartInstance->c2_last_E_added;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  if (!chartInstance->c2_last_E_added_not_empty) {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = chartInstance->c2_last_E_current;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  if (!chartInstance->c2_last_E_current_not_empty) {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = chartInstance->c2_okidanje;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  if (!chartInstance->c2_okidanje_not_empty) {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = chartInstance->c2_is_active_c2_HoppingLEGV2;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 9, c2_k_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_E_added;
  real_T *c2_E_current;
  real_T *c2_y;
  c2_E_added = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_E_current = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_E_added = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "E_added");
  *c2_E_current = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "E_current");
  *c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "y");
  chartInstance->c2_Hout = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "Hout");
  chartInstance->c2_lastState = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "lastState");
  chartInstance->c2_lastY = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "lastY");
  chartInstance->c2_last_E_added = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 6)), "last_E_added");
  chartInstance->c2_last_E_current = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 7)), "last_E_current");
  chartInstance->c2_okidanje = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "okidanje");
  chartInstance->c2_is_active_c2_HoppingLEGV2 = c2_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 9)),
     "is_active_c2_HoppingLEGV2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_HoppingLEGV2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance)
{
}

static void sf_c2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_u;
  real_T c2_s;
  real_T c2_state;
  real_T c2_k;
  real_T c2_ku;
  real_T c2_y_BOOST;
  uint32_T c2_debug_family_var_map[17];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 3.0;
  real_T c2_y;
  real_T c2_E_current;
  real_T c2_E_added;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_a;
  real_T c2_b_b;
  real_T c2_c_b;
  real_T c2_d_y;
  real_T c2_b_a;
  real_T c2_d_b;
  real_T *c2_b_u;
  real_T *c2_e_y;
  real_T *c2_b_s;
  real_T *c2_b_E_current;
  real_T *c2_b_state;
  real_T *c2_b_E_added;
  real_T *c2_b_k;
  real_T *c2_b_ku;
  real_T *c2_b_y_BOOST;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c2_b_y_BOOST = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_ku = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_E_added = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_state = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_E_current = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_s = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_e_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_e_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_s, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_E_current, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_state, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_E_added, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_k, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ku, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y_BOOST, 8U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_u;
  c2_b_hoistedGlobal = *c2_b_s;
  c2_c_hoistedGlobal = *c2_b_state;
  c2_d_hoistedGlobal = *c2_b_k;
  c2_e_hoistedGlobal = *c2_b_ku;
  c2_f_hoistedGlobal = *c2_b_y_BOOST;
  c2_u = c2_hoistedGlobal;
  c2_s = c2_b_hoistedGlobal;
  c2_state = c2_c_hoistedGlobal;
  c2_k = c2_d_hoistedGlobal;
  c2_ku = c2_e_hoistedGlobal;
  c2_y_BOOST = c2_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_u, 2U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_s, 3U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_state, 4U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_k, 5U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_ku, 6U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_y_BOOST, 7U, c2_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_y, 8U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_E_current, 9U,
    c2_g_sf_marshallOut, c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_E_added, 10U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_okidanje, 11U,
    c2_f_sf_marshallOut, c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_lastY, 12U,
    c2_e_sf_marshallOut, c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_Hout, 13U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_lastState, 14U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_last_E_current,
    15U, c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c2_last_E_added, 16U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  if (CV_EML_IF(0, 0, !chartInstance->c2_okidanje_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    chartInstance->c2_okidanje = 0.0;
    chartInstance->c2_okidanje_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    chartInstance->c2_lastY = 0.0;
    chartInstance->c2_lastY_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    chartInstance->c2_Hout = 0.0;
    chartInstance->c2_Hout_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    chartInstance->c2_lastState = c2_state;
    chartInstance->c2_lastState_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    chartInstance->c2_last_E_current = 0.0;
    chartInstance->c2_last_E_current_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
    chartInstance->c2_last_E_added = 0.0;
    chartInstance->c2_last_E_added_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  if (CV_EML_IF(0, 1, c2_u > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    c2_y = c2_y_BOOST;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    guard2 = FALSE;
    if (CV_EML_COND(0, 0, c2_y > 0.0)) {
      if (CV_EML_COND(0, 1, chartInstance->c2_lastY == 0.0)) {
        CV_EML_MCDC(0, 0, TRUE);
        CV_EML_IF(0, 2, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
        chartInstance->c2_okidanje = 1.0;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      CV_EML_MCDC(0, 0, FALSE);
      CV_EML_IF(0, 2, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
      chartInstance->c2_okidanje = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    chartInstance->c2_lastY = c2_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
    c2_y = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
    chartInstance->c2_lastY = c2_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  guard1 = FALSE;
  if (CV_EML_COND(0, 2, chartInstance->c2_lastState == 1.0)) {
    if (CV_EML_COND(0, 3, c2_state == 0.0)) {
      CV_EML_MCDC(0, 1, TRUE);
      CV_EML_IF(0, 3, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
      chartInstance->c2_Hout = 0.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, FALSE);
    CV_EML_IF(0, 3, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  chartInstance->c2_lastState = c2_state;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  if (CV_EML_IF(0, 4, chartInstance->c2_okidanje == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
    c2_x = 0.041 - c2_s;
    c2_b_x = c2_x;
    c2_b_y = muDoubleScalarAbs(c2_b_x);
    c2_b = c2_mpower(chartInstance, c2_b_y);
    c2_c_y = 0.5 * c2_b;
    c2_a = c2_c_y;
    c2_b_b = c2_k;
    chartInstance->c2_last_E_current = c2_a * c2_b_b;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_c_b = c2_mpower(chartInstance, c2_y_BOOST);
    c2_d_y = 0.5 * c2_c_b;
    c2_b_a = c2_d_y;
    c2_d_b = c2_ku;
    chartInstance->c2_last_E_added = c2_b_a * c2_d_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_E_current = chartInstance->c2_last_E_current;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  c2_E_added = chartInstance->c2_last_E_added;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -51);
  sf_debug_symbol_scope_pop();
  *c2_e_y = c2_y;
  *c2_b_E_current = c2_E_current;
  *c2_b_E_added = c2_E_added;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_HoppingLEGV2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_HoppingLEGV2(SFc2_HoppingLEGV2InstanceStruct
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
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_last_E_added_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct *chartInstance,
  const mxArray *c2_b_last_E_added, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_last_E_added),
    &c2_thisId);
  sf_mex_destroy(&c2_b_last_E_added);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_last_E_added_not_empty = FALSE;
  } else {
    chartInstance->c2_last_E_added_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_last_E_added;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_last_E_added = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_last_E_added),
    &c2_thisId);
  sf_mex_destroy(&c2_b_last_E_added);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_last_E_current_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_last_E_current, const char_T
  *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_last_E_current),
    &c2_thisId);
  sf_mex_destroy(&c2_b_last_E_current);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_last_E_current_not_empty = FALSE;
  } else {
    chartInstance->c2_last_E_current_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_last_E_current;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_last_E_current = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_last_E_current),
    &c2_thisId);
  sf_mex_destroy(&c2_b_last_E_current);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_lastState_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_lastState, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lastState),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lastState);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_lastState_not_empty = FALSE;
  } else {
    chartInstance->c2_lastState_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d2;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_lastState;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_lastState = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lastState),
    &c2_thisId);
  sf_mex_destroy(&c2_b_lastState);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_Hout_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_Hout, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Hout), &c2_thisId);
  sf_mex_destroy(&c2_b_Hout);
  return c2_y;
}

static real_T c2_h_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_Hout_not_empty = FALSE;
  } else {
    chartInstance->c2_Hout_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d3;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Hout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_Hout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Hout), &c2_thisId);
  sf_mex_destroy(&c2_b_Hout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_lastY_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_i_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_lastY, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lastY), &c2_thisId);
  sf_mex_destroy(&c2_b_lastY);
  return c2_y;
}

static real_T c2_j_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_lastY_not_empty = FALSE;
  } else {
    chartInstance->c2_lastY_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d4;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_lastY;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_lastY = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_lastY), &c2_thisId);
  sf_mex_destroy(&c2_b_lastY);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  if (!chartInstance->c2_okidanje_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0));
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_k_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_okidanje, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_okidanje),
    &c2_thisId);
  sf_mex_destroy(&c2_b_okidanje);
  return c2_y;
}

static real_T c2_l_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d5;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_okidanje_not_empty = FALSE;
  } else {
    chartInstance->c2_okidanje_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d5, 1, 0, 0U, 0, 0U, 0);
    c2_y = c2_d5;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_okidanje;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_okidanje = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_okidanje),
    &c2_thisId);
  sf_mex_destroy(&c2_b_okidanje);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_m_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_E_added, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_E_added), &c2_thisId);
  sf_mex_destroy(&c2_E_added);
  return c2_y;
}

static real_T c2_n_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d6;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d6, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d6;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_E_added;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_E_added = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_E_added), &c2_thisId);
  sf_mex_destroy(&c2_E_added);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_HoppingLEGV2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[12];
  c2_ResolvedFunctionInfo (*c2_b_info)[12];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[12])c2_info;
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
  (*c2_b_info)[3].name = "abs";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[3].fileTimeLo = 347391744U;
  (*c2_b_info)[3].fileTimeHi = 30108011U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c2_b_info)[4].name = "eml_scalar_abs";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c2_b_info)[4].fileTimeLo = 527391744U;
  (*c2_b_info)[4].fileTimeHi = 30108011U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context = "";
  (*c2_b_info)[5].name = "mpower";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c2_b_info)[5].fileTimeLo = 1827391744U;
  (*c2_b_info)[5].fileTimeHi = 30108011U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c2_b_info)[6].name = "power";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c2_b_info)[6].fileTimeLo = 1847391744U;
  (*c2_b_info)[6].fileTimeHi = 30108011U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c2_b_info)[7].name = "eml_scalar_eg";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c2_b_info)[7].fileTimeLo = 1367391744U;
  (*c2_b_info)[7].fileTimeHi = 30108011U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  (*c2_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c2_b_info)[8].name = "eml_scalexp_alloc";
  (*c2_b_info)[8].dominantType = "double";
  (*c2_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c2_b_info)[8].fileTimeLo = 1367391744U;
  (*c2_b_info)[8].fileTimeHi = 30108011U;
  (*c2_b_info)[8].mFileTimeLo = 0U;
  (*c2_b_info)[8].mFileTimeHi = 0U;
  (*c2_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c2_b_info)[9].name = "eml_scalar_floor";
  (*c2_b_info)[9].dominantType = "double";
  (*c2_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c2_b_info)[9].fileTimeLo = 667391744U;
  (*c2_b_info)[9].fileTimeHi = 30108011U;
  (*c2_b_info)[9].mFileTimeLo = 0U;
  (*c2_b_info)[9].mFileTimeHi = 0U;
  (*c2_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c2_b_info)[10].name = "eml_error";
  (*c2_b_info)[10].dominantType = "char";
  (*c2_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c2_b_info)[10].fileTimeLo = 407391744U;
  (*c2_b_info)[10].fileTimeHi = 30108011U;
  (*c2_b_info)[10].mFileTimeLo = 0U;
  (*c2_b_info)[10].mFileTimeHi = 0U;
  (*c2_b_info)[11].context = "";
  (*c2_b_info)[11].name = "mtimes";
  (*c2_b_info)[11].dominantType = "double";
  (*c2_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[11].fileTimeLo = 3573034496U;
  (*c2_b_info)[11].fileTimeHi = 30114299U;
  (*c2_b_info)[11].mFileTimeLo = 0U;
  (*c2_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
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

static real_T c2_mpower(SFc2_HoppingLEGV2InstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_o_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_p_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_HoppingLEGV2, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_HoppingLEGV2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_HoppingLEGV2);
  return c2_y;
}

static uint8_T c2_q_emlrt_marshallIn(SFc2_HoppingLEGV2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_HoppingLEGV2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_HoppingLEGV2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3912926911U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4026100073U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1344288758U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1919460662U);
}

mxArray *sf_c2_HoppingLEGV2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1741534441U);
    pr[1] = (double)(2415820928U);
    pr[2] = (double)(3617744584U);
    pr[3] = (double)(4097544699U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_HoppingLEGV2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[9],T\"E_added\",},{M[1],M[7],T\"E_current\",},{M[1],M[5],T\"y\",},{M[4],M[0],T\"Hout\",S'l','i','p'{{M1x2[132 136],M[0],}}},{M[4],M[0],T\"lastState\",S'l','i','p'{{M1x2[170 179],M[0],}}},{M[4],M[0],T\"lastY\",S'l','i','p'{{M1x2[114 119],M[0],}}},{M[4],M[0],T\"last_E_added\",S'l','i','p'{{M1x2[219 231],M[0],}}},{M[4],M[0],T\"last_E_current\",S'l','i','p'{{M1x2[192 206],M[0],}}},{M[4],M[0],T\"okidanje\",S'l','i','p'{{M1x2[93 101],M[0],}}},{M[8],M[0],T\"is_active_c2_HoppingLEGV2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_HoppingLEGV2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_HoppingLEGV2InstanceStruct *chartInstance;
    chartInstance = (SFc2_HoppingLEGV2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_HoppingLEGV2MachineNumber_,
           2,
           1,
           1,
           9,
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
          init_script_number_translation(_HoppingLEGV2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_HoppingLEGV2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_HoppingLEGV2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"s");
          _SFD_SET_DATA_PROPS(3,2,0,1,"E_current");
          _SFD_SET_DATA_PROPS(4,1,1,0,"state");
          _SFD_SET_DATA_PROPS(5,2,0,1,"E_added");
          _SFD_SET_DATA_PROPS(6,1,1,0,"k");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ku");
          _SFD_SET_DATA_PROPS(8,1,1,0,"y_BOOST");
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
        _SFD_CV_INIT_EML(0,1,5,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,908);
        _SFD_CV_INIT_EML_IF(0,0,234,254,-1,368);
        _SFD_CV_INIT_EML_IF(0,1,370,378,494,525);
        _SFD_CV_INIT_EML_IF(0,2,398,417,443,475);
        _SFD_CV_INIT_EML_IF(0,3,527,555,-1,612);
        _SFD_CV_INIT_EML_IF(0,4,631,645,-1,858);

        {
          static int condStart[] = { 401, 408 };

          static int condEnd[] = { 404, 416 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,401,416,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 530, 546 };

          static int condEnd[] = { 542, 554 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,530,554,2,2,&(condStart[0]),&(condEnd[0]),3,
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
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)c2_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_u;
          real_T *c2_y;
          real_T *c2_s;
          real_T *c2_E_current;
          real_T *c2_state;
          real_T *c2_E_added;
          real_T *c2_k;
          real_T *c2_ku;
          real_T *c2_y_BOOST;
          c2_y_BOOST = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_ku = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_k = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_E_added = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_state = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_E_current = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_s = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_s);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_E_current);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_state);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_E_added);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_k);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_ku);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_y_BOOST);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_HoppingLEGV2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_HoppingLEGV2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_HoppingLEGV2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_HoppingLEGV2(void *chartInstanceVar)
{
  enable_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_HoppingLEGV2(void *chartInstanceVar)
{
  disable_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_HoppingLEGV2(void *chartInstanceVar)
{
  sf_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_HoppingLEGV2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_HoppingLEGV2
    ((SFc2_HoppingLEGV2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HoppingLEGV2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_HoppingLEGV2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_HoppingLEGV2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_HoppingLEGV2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_HoppingLEGV2(S);
}

static void sf_opaque_set_sim_state_c2_HoppingLEGV2(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_HoppingLEGV2(S, st);
}

static void sf_opaque_terminate_c2_HoppingLEGV2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_HoppingLEGV2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_HoppingLEGV2((SFc2_HoppingLEGV2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_HoppingLEGV2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"HoppingLEGV2","HoppingLEGV2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"HoppingLEGV2","HoppingLEGV2",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"HoppingLEGV2",
      "HoppingLEGV2",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"HoppingLEGV2","HoppingLEGV2",2,6);
      sf_mark_chart_reusable_outputs(S,"HoppingLEGV2","HoppingLEGV2",2,3);
    }

    sf_set_rtw_dwork_info(S,"HoppingLEGV2","HoppingLEGV2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1620228419U));
  ssSetChecksum1(S,(1867603294U));
  ssSetChecksum2(S,(1071170648U));
  ssSetChecksum3(S,(4017008912U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_HoppingLEGV2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "HoppingLEGV2", "HoppingLEGV2",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_HoppingLEGV2(SimStruct *S)
{
  SFc2_HoppingLEGV2InstanceStruct *chartInstance;
  chartInstance = (SFc2_HoppingLEGV2InstanceStruct *)malloc(sizeof
    (SFc2_HoppingLEGV2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_HoppingLEGV2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_HoppingLEGV2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_HoppingLEGV2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_HoppingLEGV2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_HoppingLEGV2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_HoppingLEGV2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_HoppingLEGV2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_HoppingLEGV2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_HoppingLEGV2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_HoppingLEGV2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_HoppingLEGV2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_HoppingLEGV2;
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

void c2_HoppingLEGV2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_HoppingLEGV2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_HoppingLEGV2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_HoppingLEGV2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_HoppingLEGV2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
