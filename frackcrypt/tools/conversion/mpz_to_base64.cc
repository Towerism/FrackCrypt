#include "mpz_to_base64.hh"

namespace FrackCrypt {
namespace Tools {
namespace Conversion {

MPZ_to_base64::MPZ_to_base64() {}

std::string MPZ_to_base64::operator()(mpz_t z) {
  bytes = export_mpz(z);
  base64 = encode(bytes);

  return base64;
}

}
}
}
