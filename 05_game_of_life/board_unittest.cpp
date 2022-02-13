#include <iostream>
#include <gtest/gtest.h>

#include "board.hpp"

//our first unit test
TEST(BoardTests, creation)
{
  // ARRANGE
  Board board(5, 6);

  // ACT 

  // ASSERT
  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 6) << "The height is not correct";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}