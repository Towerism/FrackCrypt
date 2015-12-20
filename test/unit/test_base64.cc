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

TEST_F(Base64, EncodeTwice) {
  std::string first_encoding = encode("I am a banana.");
  std::string second_encoding = encode("Well, you're not a banana.");

  EXPECT_EQ("SSBhbSBhIGJhbmFuYS4=", first_encoding);
  EXPECT_EQ("V2VsbCwgeW91J3JlIG5vdCBhIGJhbmFuYS4=", second_encoding);
}
