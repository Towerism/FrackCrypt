//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#ifndef TOOLS_BASE64_DECODER_H
#define TOOLS_BASE64_DECODER_H

#include "base64.hh"

#include <array>
#include <string>
#include <unordered_map>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Decoder : private Base64 {
public:
  Decoder();

  virtual std::string operator()(std::string to_decode) override;

private:
  void fill_base64_index_hash();
  void decode_chunks();
  void decode_chunk(std::string chunk);
  void recover_and_append_bytes();
  void recover_and_append_byte_if(size_t i, bool condition);
  void recover_and_append_byte(size_t i);
  void recover_byte(size_t i);
  void append_byte(size_t i);

  static std::unordered_map<char, uint8_t> base64_index_hash;

  std::array<char, 3> bytes;
  static const uint8_t shifters[3];
};

}
}
}

#endif /* TOOLS_BASE64_DECODER_H */
