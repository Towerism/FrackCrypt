#include <frackcrypt/tools/mpz/exporter.hh>

#include <gtest/gtest.h>

using namespace FrackCrypt::Tools::MPZ;

class MPZExporter : public ::testing::Test {
protected:
  virtual void SetUp() override {
    mpz_init(z);
  }

  virtual void TearDown() override {
    mpz_clear(z);
  }

  FrackCrypt::Tools::MPZ::Exporter export_mpz;
  mpz_t z;
};

TEST_F(MPZExporter, ExportByte) {
  mpz_set_ui(z, 126);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x7E", bytes);
}

TEST_F(MPZExporter, ExportTwoBytes) {
  mpz_set_ui(z, 16448);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x40\x40", bytes);
}

TEST_F(MPZExporter, ExportSeveralBytes) {
  mpz_set_ui(z, 1077952576);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x40\x40\x40\x40", bytes);
}

