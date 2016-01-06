#ifndef TOOLS_CALCULATE_MODULO_H
#define TOOLS_CALCULATE_MODULO_H

#include <cstddef>
#include <gmp.h>

namespace FrackCrypt {
namespace Tools {
namespace Calculate {

class Modulo {
public:
  Modulo();

  void operator()(mpz_t result, mpz_t a, mpz_t b);
};

}
}
}

#endif
