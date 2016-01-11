//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <frackcrypt/tools/base64/encoder.hh>
#include <frackcrypt/tools/mpz/exporter.hh>

#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Conversion {

class MPZ_to_base64 {
public:
  MPZ_to_base64();

  std::string operator()(mpz_t z);

private:
  std::string base64;
  std::string bytes;
  MPZ::Exporter export_mpz;
  Base64::Encoder encode;
};

}
}
}
