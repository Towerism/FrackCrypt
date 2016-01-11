//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackCrypt is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "decoder.hh"

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

std::unordered_map<char, uint8_t> Decoder::base64_index_hash;

Decoder::Decoder() {
  if (base64_index_hash.empty())
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
  recover_and_append_bytes();
}

void Decoder::recover_and_append_bytes() {
  for (size_t i = 0; i < bytes.size(); ++i)
    recover_and_append_byte_if(i, working_chunk[i + 1] != pad_byte);
}

void Decoder::recover_and_append_byte_if(size_t i, bool condition) {
  if (condition)
    recover_and_append_byte(i);
}

void Decoder::recover_and_append_byte(size_t i) {
  recover_byte(i);
  append_byte(i);
}

void Decoder::recover_byte(size_t i) {
  bytes[i] = base64_index_hash[working_chunk[i]] << shifters[i];
  bytes[i] |= base64_index_hash[working_chunk[i + 1]] >> (6 - shifters[i]);
}

const uint8_t Decoder::shifters[3] = { 2, 4, 6 };

void Decoder::append_byte(size_t i) {
  output << bytes[i];
}

}
}
}
