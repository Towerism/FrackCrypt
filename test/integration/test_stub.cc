#include "gtest/gtest.h"

int difference(int a, int b) {
  return a - b;
}

TEST(Stub, Difference) {
  EXPECT_EQ(-1, difference(2, 3));
}
