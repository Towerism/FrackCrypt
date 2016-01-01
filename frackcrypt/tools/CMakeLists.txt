add_library(tools INTERFACE)

add_subdirectory(base64)
add_subdirectory(mpz)
add_subdirectory(conversion)
add_subdirectory(calculate)

set(TOOLS_LIBS
  base64
  mpz
  conversion
  calculate
  )
target_link_libraries(tools INTERFACE ${TOOLS_LIBS})
