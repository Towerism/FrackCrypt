set(MPZ_SOURCES exporter.cc importer.cc)
add_library(mpz ${MPZ_SOURCES})

set(MPZ_LIBS gmp)
target_link_libraries(mpz ${MPZ_LIBS})
