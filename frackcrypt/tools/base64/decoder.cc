#include "decoder.hh"

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

Decoder::Decoder() {
  fill_base64_index_hash();
}

void Decoder::fill_base64_index_hash() {
  for (size_t i = 0; i < 64; ++i)
    base64_index_hash.insert({base64_chars[i], i});
}

std::string Decoder::operator()(std::string to_decode) {
  reset();
  chunkify(to_decode, 4);
  decode_chunks();
  return output.str();
}

void Decoder::decode_chunks() {
  for (size_t i = 0; i < chunks.size(); ++i)
    decode_chunk(chunks[i]);
}

void Decoder::decode_chunk(std::string chunk) {
  working_chunk = chunk;
  recover_bytes();
  append_bytes();
}

void Decoder::recover_bytes() {
  recover_first_byte();
  if (working_chunk[2] != '=')
    recover_second_byte();
  if (working_chunk[3] != '=')
    recover_third_byte();
}

void Decoder::recover_first_byte() {
  byte1 = base64_index_hash[working_chunk[0]] << 2;
  byte1 |= base64_index_hash[working_chunk[1]] >> 4;
}

void Decoder::recover_second_byte() {
  byte2 = base64_index_hash[working_chunk[1]] << 4;
  byte2 |= base64_index_hash[working_chunk[2]] >> 2;
}

void Decoder::recover_third_byte() {
  byte3 = base64_index_hash[working_chunk[2]] << 6;
  byte3 |= base64_index_hash[working_chunk[3]];
}

void Decoder::append_bytes() {
  output << byte1;
  if (working_chunk[2] != '=')
    output << byte2;
  if (working_chunk[3] != '=')
    output << byte3;
}

}
}
}
