add_library(tools INTERFACE)

add_subdirectory(base64)
add_subdirectory(mpz)

set(TOOLS_LIBS base64)
target_link_libraries(tools INTERFACE ${TOOLS_LIBS})
