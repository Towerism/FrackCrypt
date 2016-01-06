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
  for (size_t i = 0; i < chunks.size(); ++i)
    encode_chunk(chunks[i]);
}

void Encoder::encode_chunk(std::string chunk) {
  working_chunk = chunk;
  calculate_and_append_codes();
}

void Encoder::calculate_and_append_codes() {
  for (size_t i = 0; i < codes.size(); ++i)
    if (working_chunk.length() + 1 > i)
      calculate_and_append_code(i);
}

void Encoder::calculate_and_append_code(size_t i) {
  calculate_code(i);
  append_code(i);
}

void Encoder::calculate_code(size_t i) {
  codes[i] = working_chunk[high_indeces[i]] << (8 - shifters[i]);
  codes[i] |= working_chunk[low_indeces[i]] >> shifters[i];
  codes[i] &= 0x3F;
}

const uint8_t Encoder::high_indeces[4] = { 0, 0, 1, 2 };
const uint8_t Encoder::low_indeces[4] = { 0, 1, 2, 2 };
const uint8_t Encoder::shifters[4] = { 2, 4, 6, 0 };

void Encoder::append_code(size_t i) {
  output << base64_chars[codes[i]];
}

void Encoder::add_padding() {
  std::string last_chunk = chunks.back();
  size_t padding_amount = 3 - last_chunk.length();
  std::string padding(padding_amount, pad_byte);
  output << padding;
}

}
}
}
