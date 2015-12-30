#include <frackcrypt/tools/mpz/exporter.hh>
#include <frackcrypt/tools/mpz/importer.hh>

#include <gtest/gtest.h>

class MPZ : public ::testing::Test {
protected:
  virtual void SetUp() override {
    mpz_init(z);
  }

  virtual void TearDown() override {
    mpz_clear(z);
  }

  mpz_t z;
};

class MPZExporter : public MPZ {
protected:
  FrackCrypt::Tools::MPZ::Exporter export_mpz;
};

class MPZImporter : public MPZ {
protected:
  FrackCrypt::Tools::MPZ::Importer import_mpz;
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

TEST_F(MPZImporter, ImportByte) {
  import_mpz(z, "\x40");

  EXPECT_EQ(64, mpz_get_ui(z));
}

TEST_F(MPZImporter, ImportTwoBytes) {
  import_mpz(z, "\x40\x40");

  EXPECT_EQ(16448, mpz_get_ui(z));
}

TEST_F(MPZImporter, ImportSeveralBytes) {
  import_mpz(z, "\x40\x40\x40\x40");

  EXPECT_EQ(1077952576, mpz_get_ui(z));
}
