//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
