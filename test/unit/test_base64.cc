#include <frackcrypt/tools/base64/encoder.hh>

#include <gtest/gtest.h>
#include <string>

class Base64 : public ::testing::Test {
protected:
  FrackCrypt::Tools::Base64::Encoder encode;
};

TEST_F(Base64, EncodeByte) {
  std::string base64 = encode("a");

  EXPECT_EQ("YQ==", base64);
}

TEST_F(Base64, EncodeTwoBytes) {
  std::string base64 = encode("ab");

  EXPECT_EQ("YWI=", base64);
}

TEST_F(Base64, EncodeThreeBytes) {
  std::string base64 = encode("abc");

  EXPECT_EQ("YWJj", base64);
}
