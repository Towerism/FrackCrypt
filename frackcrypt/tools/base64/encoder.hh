#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Encoder {
public:
  Encoder();

  std::string operator()(std::string to_encode);

private:
  void reset();
  void chunkify(std::string to_encode);
  void encode_chunks();
  void encode_chunk(std::string chunk);
  void encode_bytes();
  void encode_first_byte();
  void encode_second_byte();
  void encode_third_byte();
  void append_codes();
  void add_padding();

  static const std::string base64_chars;

  std::ostringstream base64;
  std::vector<std::string> chunks;
  std::string working_chunk;
  uint8_t code1, code2, code3, code4;
};

}
}
}
