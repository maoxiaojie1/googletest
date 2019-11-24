#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sample.h"

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}