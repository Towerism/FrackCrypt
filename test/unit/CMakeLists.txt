set(UNIT_SRCS
  test_base64.cc
  test_mpz.cc
  test_calculate.cc
  )
add_library(unit OBJECT ${UNIT_SRCS})
