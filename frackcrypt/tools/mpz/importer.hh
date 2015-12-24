#ifndef TOOLS_MPZ_IMPORTER_H
#define TOOLS_MPZ_IMPORTER_H

#include <cstddef>
#include <gmp.h>
#include <string>

namespace FrackCrypt {
namespace Tools {
namespace MPZ {

class Importer {
public:
  Importer();

  void operator()(mpz_t z, std::string bytes);
};

}
}
}

#endif
