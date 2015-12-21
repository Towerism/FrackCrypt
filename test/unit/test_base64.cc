#include <frackcrypt/tools/base64/encoder.hh>
#include <frackcrypt/tools/base64/decoder.hh>

#include <gtest/gtest.h>
#include <string>

class Base64Encoder : public ::testing::Test {
protected:
  FrackCrypt::Tools::Base64::Encoder encode;
};

class Base64Decoder : public ::testing::Test {
protected:
  FrackCrypt::Tools::Base64::Decoder decode;
};

TEST_F(Base64Encoder, EncodeByte) {
  std::string base64 = encode("a");

  EXPECT_EQ("YQ==", base64);
}

TEST_F(Base64Encoder, EncodeTwoBytes) {
  std::string base64 = encode("ab");

  EXPECT_EQ("YWI=", base64);
}

TEST_F(Base64Encoder, EncodeThreeBytes) {
  std::string base64 = encode("abc");

  EXPECT_EQ("YWJj", base64);
}

TEST_F(Base64Encoder, EncodeTwice) {
  std::string first_encoding = encode("I am a banana.");
  std::string second_encoding = encode("Well, you're not a banana.");

  EXPECT_EQ("SSBhbSBhIGJhbmFuYS4=", first_encoding);
  EXPECT_EQ("V2VsbCwgeW91J3JlIG5vdCBhIGJhbmFuYS4=", second_encoding);
}

TEST_F(Base64Decoder, DecodeByte) {
  std::string decoded = decode("YQ==");

  EXPECT_EQ("a", decoded);
}

TEST_F(Base64Decoder, DecodeTwoBytes) {
  std::string decoded = decode("YWI=");

  EXPECT_EQ("ab", decoded);
}

TEST_F(Base64Decoder, DecodeThreeBytes) {
  std::string decoded = decode("YWJj");

  EXPECT_EQ("abc", decoded);
}

TEST_F(Base64Decoder, DecodeTwice) {
  std::string first_decoded = decode("SSBhbSBhIGJhbmFuYS4=");
  std::string second_decoded = decode("V2VsbCwgeW91J3JlIG5vdCBhIGJhbmFuYS4=");

  EXPECT_EQ("I am a banana.", first_decoded);
  EXPECT_EQ("Well, you're not a banana.", second_decoded);
}
