#ifndef TOOLS_BASE64_AGENT_H
#define TOOLS_BASE64_AGENT_H

#include <sstream>
#include <string>
#include <vector>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Base64 {
public:
  virtual std::string operator()(std::string input) = 0;

protected:
  void reset();
  void chunkify(std::string input, unsigned chunk_size);

  static const std::string base64_chars;
  static const char pad_byte;

  std::ostringstream output;
  std::vector<std::string> chunks;
  std::string working_chunk;
};

}
}
}

#endif
