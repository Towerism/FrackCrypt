#include <frackcrypt/tools/calculate/gcd.hh>

#include <gtest/gtest.h>

class Calculate : public ::testing::Test {
protected:
  virtual void SetUp() override {
    mpz_init(a);
    mpz_init(b);
    mpz_init(c);
  }

  virtual void TearDown() override {
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
  }

  mpz_t a;
  mpz_t b;
  mpz_t c;
};

TEST_F(Calculate, GCD) {
  FrackCrypt::Tools::Calculate::GCD gcd;
  mpz_set_ui(a, 500000);
  mpz_set_ui(b, 12341234);

  gcd(c, a, b);

  EXPECT_EQ(2, mpz_get_ui(c));
}
