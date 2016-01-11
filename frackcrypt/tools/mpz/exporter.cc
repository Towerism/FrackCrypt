//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "exporter.hh"

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

#include <cstdlib>

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
