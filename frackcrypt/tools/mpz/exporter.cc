#include "exporter.hh"

#include <cstdlib>

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

Exporter::Exporter() { }

std::string Exporter::operator()(mpz_t z) {
  extract_bytes(z);
  build_string_from_bytes();
  return str;
}

void Exporter::extract_bytes(mpz_t z) {
  bytes = (char*)mpz_export(NULL, &count, 1, 1, 1, 0, z);
}

void Exporter::build_string_from_bytes() {
  str = std::string(bytes, count);
  free(bytes);
}

}
}
}
