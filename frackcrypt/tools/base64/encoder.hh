#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

class Encoder {
public:

  Encoder();

  std::string operator()(std::string to_encode);

private:

  static const std::string base64_chars;

};

}
}
}
