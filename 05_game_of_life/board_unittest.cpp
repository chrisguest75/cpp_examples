#include <iostream>
#include <gtest/gtest.h>

#include "board.hpp"

TEST(BoardTests, creation)
{
  // ARRANGE
  Board board(5, 6);

  // ACT 

  // ASSERT
  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 6) << "The height is not correct";
}

TEST(BoardTests, print)
{
  // ARRANGE
  Board board(5, 5);

  // ACT 
  std::vector<std::string> rows = board.stateString();

  // ASSERT
  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 5) << "The height is not correct";
  EXPECT_EQ(rows.size(), 5) << "Number of rows is not correct";

  for(std::size_t i = 0; i < rows.size(); ++i) {
      EXPECT_EQ(rows[i], "00000") << "Row is not empty";
  }
}


