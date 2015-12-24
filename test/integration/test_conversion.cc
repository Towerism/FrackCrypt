#include <frackcrypt/tools/conversion/mpz_to_base64.hh>
#include <frackcrypt/tools/conversion/base64_to_mpz.hh>

#include <gmp.h>
#include <gtest/gtest.h>

class ConvertBetweenMPZAndBase64 : public ::testing::Test {
protected:
  virtual void SetUp() {
    mpz_init(z);
  }

  virtual void TearDown() {
    mpz_clear(z);
  }

  FrackCrypt::Tools::Conversion::MPZ_to_base64 to_base64;
  FrackCrypt::Tools::Conversion::Base64_to_MPZ to_mpz;

  mpz_t z;
};

TEST_F(ConvertBetweenMPZAndBase64, ConvertOneByteToBase64) {
  mpz_set_ui(z, 32);
  std::string base64 = to_base64(z);

  EXPECT_EQ("IA==", base64);
}

TEST_F(ConvertBetweenMPZAndBase64, ConvertSeveralBytesToBase64) {
  mpz_set_ui(z, 1077952576);
  std::string base64 = to_base64(z);

  EXPECT_EQ("QEBAQA==", base64);
}

TEST_F(ConvertBetweenMPZAndBase64, ConvertOneByteToMPZ) {
  to_mpz(z, "IA==");

  EXPECT_EQ(32, mpz_get_ui(z));
}

TEST_F(ConvertBetweenMPZAndBase64, ConvertSeveralBytesToMPZ) {
  to_mpz(z, "QEBAQA==");

  EXPECT_EQ(1077952576, mpz_get_ui(z));
}
