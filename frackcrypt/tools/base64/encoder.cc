#include "encoder.hh"

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

Encoder::Encoder() {}

std::string Encoder::operator()(std::string to_encode) {
  reset();
  chunkify(to_encode, 3);
  encode_chunks();
  add_padding();
  return output.str();
}

void Encoder::encode_chunks() {
  for (uint64_t i = 0; i < chunks.size(); ++i)
    encode_chunk(chunks[i]);
}

void Encoder::encode_chunk(std::string chunk) {
  working_chunk = chunk;
  encode_bytes();
  append_codes();
}

void Encoder::encode_bytes() {
  encode_first_byte();
  if (working_chunk.length() > 1)
    encode_second_byte();
  if (working_chunk.length() > 2)
    encode_third_byte();
}

void Encoder::encode_first_byte() {
  code1 = working_chunk[0] >> 2;
  code2 = (working_chunk[0] & 0x3) << 4;
}

void Encoder::encode_second_byte() {
  code2 |= (working_chunk[1] >> 4);
  code3 = (working_chunk[1] & 0xF) << 2;
}

void Encoder::encode_third_byte() {
  code3 |= working_chunk[2] >> 6;
  code4 = working_chunk[2] & 0x3F;
}

void Encoder::append_codes() {
  output << base64_chars[code1] << base64_chars[code2];
  if (working_chunk.length() > 1)
    output << base64_chars[code3];
  if (working_chunk.length() > 2)
    output << base64_chars[code4];
}

void Encoder::add_padding() {
  std::string last_chunk = chunks.back();
  size_t padding_amount = 3 - last_chunk.length();
  std::string padding(padding_amount, '=');
  output << padding;
}

}
}
}
