//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
