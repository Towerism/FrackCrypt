#ifndef TOOLS_CALCULATE_GCD_H
#define TOOLS_CALCULATE_GCD_H

#include <cstddef>
#include <gmp.h>

namespace FrackCrypt {
namespace Tools {
namespace Calculate {

class GCD {
public:
  GCD();

  void operator()(mpz_t result, mpz_t a, mpz_t b);
};

}
}
}

#endif
