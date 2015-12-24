#include <frackcrypt/tools/base64/decoder.hh>
#include <frackcrypt/tools/mpz/importer.hh>

#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace Conversion {

class Base64_to_MPZ {
public:
  Base64_to_MPZ();

  void operator()(mpz_t z, std::string base64);

private:
  std::string bytes;
  MPZ::Importer import_mpz;
  Base64::Decoder decode;
};

}
}
}
