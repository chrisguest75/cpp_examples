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

TEST(BoardTests, neighbour_count)
{
  // ARRANGE
  Board board(5, 5);

  // ACT 
  std::vector<std::string> state = { "00000", "01110", "01010", "01110", "00000" };
  board.setState(state);

  std::vector<std::string> rows = board.stateString();

  // ASSERT
  /*
  "00000"
  "01110"
  "01010"
  "01110"
  "00000"
  */

  EXPECT_EQ(board.getWidth(), 5) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 5) << "The height is not correct";
  EXPECT_EQ(rows.size(), 5) << "Number of rows is not correct";

  EXPECT_EQ(board.countNeighbors(0,0), 1) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(1,0), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(2,0), 3) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(3,0), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(4,0), 1) << "Cell has incorrect neighbour count";

  EXPECT_EQ(board.countNeighbors(0,1), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(1,1), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(2,1), 4) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(3,1), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(4,1), 2) << "Cell has incorrect neighbour count";

  EXPECT_EQ(board.countNeighbors(0,2), 3) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(1,2), 4) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(2,2), 8) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(3,2), 4) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(4,2), 3) << "Cell has incorrect neighbour count";

  EXPECT_EQ(board.countNeighbors(0,3), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(1,3), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(2,3), 4) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(3,3), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(4,3), 2) << "Cell has incorrect neighbour count";

  EXPECT_EQ(board.countNeighbors(0,4), 1) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(1,4), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(2,4), 3) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(3,4), 2) << "Cell has incorrect neighbour count";
  EXPECT_EQ(board.countNeighbors(4,4), 1) << "Cell has incorrect neighbour count";
}


TEST(BoardTests, stilllife)
{
  // ARRANGE
  Board board(4, 4);

  // ACT 
  std::vector<std::string> state = { "0000", "0110", "0110", "0000" };
  board.setState(state);

  board.applyRules();

  std::vector<std::string> rows = board.stateString();

  // ASSERT
  EXPECT_EQ(board.getWidth(), 4) << "The width is not correct";
  EXPECT_EQ(board.getHeight(), 4) << "The height is not correct";
  EXPECT_EQ(rows.size(), 4) << "Number of rows is not correct";

  EXPECT_EQ(rows[0], "0000") << "Row has incorrect state";
  EXPECT_EQ(rows[1], "0110") << "Row has incorrect state";
  EXPECT_EQ(rows[2], "0110") << "Row has incorrect state";
  EXPECT_EQ(rows[3], "0000") << "Row has incorrect state";
}


TEST(BoardTests, oscillator)
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

  // ACT
  board.applyRules();
  rows = board.stateString();
  
  // ASSERT
  EXPECT_EQ(rows[0], "00000") << "Row has incorrect state";
  EXPECT_EQ(rows[1], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[2], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[3], "00100") << "Row has incorrect state";
  EXPECT_EQ(rows[4], "00000") << "Row has incorrect state";

}

