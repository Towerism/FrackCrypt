#include "modulo.hh"

namespace FrackCrypt {
namespace Tools {
namespace Calculate {

Modulo::Modulo() {}

void Modulo::operator()(mpz_t result, mpz_t a, mpz_t b) {
  mpz_mod(result, a, b);
}

}
}
}
