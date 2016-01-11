//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "base64.hh"

#include <array>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Encoder : private Base64 {
public:
  Encoder();

  virtual std::string operator()(std::string to_encode) override;

private:
  void encode_chunks();
  void encode_chunk(std::string chunk);
  void calculate_and_append_codes();
  void calculate_and_append_code(size_t i);
  void calculate_code(size_t i);
  void append_code(size_t i);
  void add_padding();

  static const uint8_t high_indeces[4];
  static const uint8_t low_indeces[4];
  static const uint8_t shifters[4];

  std::array<uint8_t, 4> codes;
};

}
}
}

