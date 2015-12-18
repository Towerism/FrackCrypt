#include "gtest/gtest.h"

int sum(int a, int b) {
  return a + b;
}

TEST(Stub, Sum) {
  EXPECT_EQ(5, sum(2, 3));
}
