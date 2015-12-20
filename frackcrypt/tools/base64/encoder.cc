#include "encoder.hh"

#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Base64 {

Encoder::Encoder() {

}

std::string Encoder::operator()(std::string to_encode) {
  return to_encode;
}

}
}
}
