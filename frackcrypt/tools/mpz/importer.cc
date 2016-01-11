//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
