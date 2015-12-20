add_library(tools INTERFACE)

add_subdirectory(base64)

set(TOOLS_LIBS base64)
target_link_libraries(tools INTERFACE ${TOOLS_LIBS})
