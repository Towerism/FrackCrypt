#ifndef TOOLS_BASE64_ENCODER_H
#define TOOLS_BASE64_ENCODER_H

#include "agent.hh"

#include <cstdint>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Encoder : protected Agent {
public:
  Encoder();

  virtual std::string operator()(std::string to_encode);

private:
  void encode_chunks();
  void encode_chunk(std::string chunk);
  void encode_bytes();
  void encode_first_byte();
  void encode_second_byte();
  void encode_third_byte();
  void append_codes();
  void add_padding();

  uint8_t code1, code2, code3, code4;
};

}
}
}

#endif
