#include <frackcrypt/tools/conversion/mpz_to_base64.hh>

#include <gmp.h>
#include <gtest/gtest.h>

class ConvertMPZToBase64 : public ::testing::Test {
protected:
  virtual void SetUp() {
    mpz_init(z);
  }

  virtual void TearDown() {
    mpz_clear(z);
  }

  FrackCrypt::Tools::Conversion::MPZ_to_base64 convert;

  mpz_t z;
};

TEST_F(ConvertMPZToBase64, ConvertOneByte) {
  mpz_set_ui(z, 32);
  std::string base64 = convert(z);

  EXPECT_EQ("IA==", base64);
}

TEST_F(ConvertMPZToBase64, ConvertSeveralBytes) {
  mpz_set_ui(z, 1077952576);
  std::string base64 = convert(z);

  EXPECT_EQ("QEBAQA==", base64);
}
