#ifndef TOOLS_BASE64_DECODER_H
#define TOOLS_BASE64_DECODER_H

#include "agent.hh"

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
  void recover_first_byte();
  void recover_second_byte();
  void recover_third_byte();
  void append_bytes();

  std::unordered_map<char, uint8_t> base64_index_hash;
  char byte1, byte2, byte3;
};

}
}
}

#endif
