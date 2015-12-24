#include "importer.hh"

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

#include <cstdlib>

Importer::Importer() { }

void Importer::operator()(mpz_t z, std::string bytes) {
  mpz_import(z, bytes.length(), 1, 1, 1, 0, bytes.c_str());
}

}
}
}
