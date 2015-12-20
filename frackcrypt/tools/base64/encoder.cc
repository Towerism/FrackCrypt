#include "encoder.hh"

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

const std::string Encoder::base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

Encoder::Encoder() {

}

std::string Encoder::operator()(std::string to_encode) {
  std::ostringstream base64;
  std::string padding;
  std::vector<std::string> chunks;
  uint8_t chunk1, chunk2, chunk3, chunk4;

  for (uint64_t i = 0; i < to_encode.length(); i += 3) {
    chunks.push_back(std::string(to_encode, i, 3));
  }

  for (uint64_t i = 0; i < chunks.size(); ++i) {
    const std::string& working_chunk = chunks[i];
    if (chunks[i].length() == 3) {
      chunk1 = working_chunk[0] >> 2;
      chunk2 = ((working_chunk[0] & 0x3) << 4) | (working_chunk[1] >> 4);
      chunk3 = ((working_chunk[1] & 0xF) << 2) | (working_chunk[2] >> 6);
      chunk4 = working_chunk[2] & 0x3F;
      base64 << (char)base64_chars[chunk1] << (char)base64_chars[chunk2] << (char)base64_chars[chunk3] << (char)base64_chars[chunk4];
    } else if (chunks[i].length() == 2) {
      chunk1 = working_chunk[0] >> 2;
      chunk2 = ((working_chunk[0] & 0x3) << 4) | (working_chunk[1] >> 4);
      chunk3 = (working_chunk[1] & 0xF) << 2;
      base64 << (char)base64_chars[chunk1] << (char)base64_chars[chunk2] << (char)base64_chars[chunk3];
      padding = "=";
    } else {
      chunk1 = to_encode[0] >> 2;
      chunk2 = (to_encode[0] & 0x3) << 4;
      base64 << (char)base64_chars[chunk1] << (char)base64_chars[chunk2];
      padding = "==";
    }
  }

  base64 << padding;
  return base64.str();
}

}
}
}
