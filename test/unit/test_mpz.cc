#include <frackcrypt/tools/mpz/exporter.hh>
#include <frackcrypt/tools/mpz/importer.hh>

#include <iostream>
#include <gtest/gtest.h>

using namespace FrackCrypt::Tools::MPZ;

class MPZ : public ::testing::Test {
protected:
  virtual void SetUp() override {
    mpz_init(z);
  }

  virtual void TearDown() override {
    mpz_clear(z);
  }

  FrackCrypt::Tools::MPZ::Exporter export_mpz;
  FrackCrypt::Tools::MPZ::Importer import_mpz;
  mpz_t z;
};

TEST_F(MPZ, ExportByte) {
  mpz_set_ui(z, 126);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x7E", bytes);
}

TEST_F(MPZ, ExportTwoBytes) {
  mpz_set_ui(z, 16448);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x40\x40", bytes);
}

TEST_F(MPZ, ExportSeveralBytes) {
  mpz_set_ui(z, 1077952576);
  std::string bytes = export_mpz(z);

  EXPECT_EQ("\x40\x40\x40\x40", bytes);
}

TEST_F(MPZ, ImportByte) {
  import_mpz(z, "\40");

  EXPECT_EQ(32, mpz_get_ui(z));
}

TEST_F(MPZ, ImportTwoBytes) {
  import_mpz(z, "\x40\x40");

  EXPECT_EQ(16448, mpz_get_ui(z));
}

TEST_F(MPZ, ImportSeveralBytes) {
  import_mpz(z, "\x40\x40\x40\x40");

  EXPECT_EQ(1077952576, mpz_get_ui(z));
}
