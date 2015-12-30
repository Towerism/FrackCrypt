#include "gcd.hh"

namespace FrackCrypt {
namespace Tools {
namespace Calculate {

GCD::GCD() {}

void GCD::operator()(mpz_t result, mpz_t a, mpz_t b) {
  mpz_gcd(result, a, b);
}

}
}
}
