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

TEST(BoardTests, setState)
{
  // ARRANGE
  Board board(5, 5);

  // ACT 
  std::vector<std::string> state = { "00000", "00100", "00100", "00100", "00000" };
  board.setState(state);
  std::vector<std::string> rows = board.stateString();

  // ASSERT
  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 5) << "The height is not correct";
  EXPECT_EQ(rows.size(), 5) << "Number of rows is not correct";

  EXPECT_EQ(rows[0], "00000") << "Row has incorrect state";
  EXPECT_EQ(rows[1], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[2], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[3], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[4], "00000") << "Row has incorrect state";

}

TEST(BoardTests, iterate)
{
  // ARRANGE
  Board board(5, 5);

  // ACT 
  std::vector<std::string> state = { "00000", "00100", "00100", "00100", "00000" };
  board.setState(state);

  board.applyRules();

  std::vector<std::string> rows = board.stateString();

  // ASSERT
  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 5) << "The height is not correct";
  EXPECT_EQ(rows.size(), 5) << "Number of rows is not correct";

  EXPECT_EQ(rows[0], "00000") << "Row has incorrect state";
  EXPECT_EQ(rows[1], "00000") << "Row has incorrect state";
  EXPECT_EQ(rows[2], "01110") << "Row has incorrect state";
  EXPECT_EQ(rows[3], "00000") << "Row has incorrect state";
  EXPECT_EQ(rows[4], "00000") << "Row has incorrect state";

}

