#ifndef TOOLS_MPZ_EXPORTER_H
#define TOOLS_MPZ_EXPORTER_H

#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

class Exporter {
public:
  Exporter();

  std::string operator()(mpz_t z);

private:
  void extract_bytes(mpz_t z);
  void build_string_from_bytes();

  std::string str;
  char* bytes;
  size_t count;
};

}
}
}

#endif
