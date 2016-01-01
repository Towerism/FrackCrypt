set(CONVERSION_SRCS
  mpz_to_base64.cc
  base64_to_mpz.cc
  )
add_library(conversion ${CONVERSION_SRCS})

set(CONVERSION_LIBS mpz base64)
target_link_libraries(conversion ${CONVERSION_LIBS})
