//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <frackcrypt/tools/base64/decoder.hh>
#include <frackcrypt/tools/mpz/importer.hh>

#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Conversion {

class Base64_to_MPZ {
public:
  Base64_to_MPZ();

  void operator()(mpz_t z, std::string base64);

private:
  std::string bytes;
  MPZ::Importer import_mpz;
  Base64::Decoder decode;
};

}
}
}

