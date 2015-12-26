#ifndef TOOLS_BASE64_DECODER_H
#define TOOLS_BASE64_DECODER_H

#include "agent.hh"

#include <array>
#include <string>
#include <unordered_map>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Decoder : protected Agent {
public:
  Decoder();

  virtual std::string operator()(std::string to_decode) override;

private:
  void fill_base64_index_hash();
  void decode_chunks();
  void decode_chunk(std::string chunk);
  void recover_bytes();
  void recover_and_append_byte(size_t i);
  void recover_byte(size_t i);
  void append_byte(size_t i);

  std::unordered_map<char, uint8_t> base64_index_hash;
  std::array<char, 3> bytes;
  const uint8_t shifters[3] = { 2, 4, 6 };
};

}
}
}

#endif
