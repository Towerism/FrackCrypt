#include "base64.hh"

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

const std::string Base64::base64_chars =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

const char Base64::pad_byte = '=';

void Base64::reset() {
  output.str("");
  chunks.clear();
}

void Base64::chunkify(std::string input, unsigned chunk_size) {
  for (size_t i = 0; i < input.length(); i += chunk_size)
    chunks.push_back(std::string(input, i, chunk_size));
}

}
}
}
