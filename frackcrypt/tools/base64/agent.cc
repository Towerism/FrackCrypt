#include "agent.hh"

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

const std::string Agent::base64_chars =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void Agent::reset() {
  output.str("");
  chunks.clear();
}

void Agent::chunkify(std::string input, unsigned chunk_size) {
  for (size_t i = 0; i < input.length(); i += chunk_size)
    chunks.push_back(std::string(input, i, chunk_size));
}

}
}
}
