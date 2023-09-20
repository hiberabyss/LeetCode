#define BRACED_INIT_LIST(...) {__VA_ARGS__}

// Name Pattern: Verify_INPUT_OUTPUT
// V: vector
// I: int
#define Verify_I_VV(expect, input) { \
  auto res = SolFun(input); \
  EXPECT_EQ(s2vv(expect), res); \
}

#define Verify(expect, input) { \
  EXPECT_EQ(expect, SolFun(input)); \
}

#define Verify_V(expect, input) { \
  FunArg0Type vec_input = BRACED_INIT_LIST input; \
  auto res = SolFun(vec_input); \
  EXPECT_EQ(expect, res); \
}

// support verify list input and list return
#define Verify_L_L(expect, input) { \
  auto* l_in = s2l(input); \
  auto* res = SolFun(l_in); \
  EXPECT_EQ(expect, l2s(res)); \
}

// With _Ref means result also returned via input
#define Verify_V_I_Ref(expect, input) { \
  auto nums = s2v(input); \
  auto expect_vec = s2v(expect); \
  auto cnt = SolFun(nums); \
  EXPECT_EQ(expect_vec.size(), cnt); \
  nums.resize(cnt); \
  EXPECT_EQ(expect_vec, nums); \
}

