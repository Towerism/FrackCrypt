//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#ifndef TOOLS_MPZ_EXPORTER_H
#define TOOLS_MPZ_EXPORTER_H

#include <cstddef>
#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

class Exporter {
public:
  Exporter();

  std::string operator()(mpz_t z);

private:
  void extract_bytes(mpz_t z);
  void build_string_from_bytes();

  std::string str;
  char* bytes;
  size_t count;
};

}
}
}

#endif
