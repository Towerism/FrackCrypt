//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#ifndef TOOLS_CALCULATE_GCD_H
#define TOOLS_CALCULATE_GCD_H

#include <cstddef>
#include <gmp.h>

namespace FrackCrypt {
namespace Tools {
namespace Calculate {

class GCD {
public:
  GCD();

  void operator()(mpz_t result, mpz_t a, mpz_t b);
};

}
}
}

#endif /* TOOLS_CALCULATE_GCD_H */
