//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Base64 {
public:
  virtual std::string operator()(std::string input) = 0;

protected:
  ~Base64() = default;

  void reset();
  void chunkify(std::string input, unsigned chunk_size);

  static const std::string base64_chars;
  static const char pad_byte;

  std::ostringstream output;
  std::vector<std::string> chunks;
  std::string working_chunk;
};

}
}
}

