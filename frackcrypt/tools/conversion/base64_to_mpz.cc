#include "base64_to_mpz.hh"

namespace FrackCrypt {
namespace Tools {
namespace Conversion {

Base64_to_MPZ::Base64_to_MPZ() {}

void Base64_to_MPZ::operator()(mpz_t z, std::string base64) {
  bytes = decode(base64);
  import_mpz(z, bytes);
}

}
}
}
