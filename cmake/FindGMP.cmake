# Simple script to locate the GNU Multiple Precision library
# Variables:
# - GMP_FOUND
# - GMP_INCLUDE_DIR
# - GMP_LIBRARIES
# - GMPXX_LIBRARIES

find_path(GMP_INCLUDE_DIR NAMES gmp.h )
find_library(GMP_LIBRARIES NAMES gmp libgmp )
find_library(GMPXX_LIBRARIES NAMES gmpxx libgmpxx )

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GMP DEFAULT_MSG GMP_INCLUDE_DIR GMP_LIBRARIES)
