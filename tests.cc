// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Michael R. Nowak                Environment : ubuntu:latest               //
//  Date ......: 2022/02/07                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}

/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Dropping Disk", "[Drop_Disk]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  REQUIRE_THROWS(DropDiskToBoard(student, DiskType::kPlayer1, 4));
  REQUIRE_THROWS(DropDiskToBoard(student, DiskType::kPlayer2, -3));
  REQUIRE_THROWS(DropDiskToBoard(student, DiskType::kPlayer2, 10));
}
TEST_CASE("Checking for Winner", "[Check_winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 0);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 1);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 2);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 3);
  SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal);
  SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical);
  // REQUIRE_FALSE(CheckForWinner(student, DiskType::kPlayer1));
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2));
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
  // REQUIRE(CheckForWinner(student, DiskType::kPlayer2));
}
TEST_CASE("Searching for Winner", "[Search_Winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, 0);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 1);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 2);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  DropDiskToBoard(student, DiskType::kPlayer1, 3);
  DropDiskToBoard(student, DiskType::kPlayer2, 4);
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kRightDiag));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer1, WinningDirection::kVertical));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kHorizontal));
  REQUIRE_FALSE(SearchForWinner(
      student, DiskType::kPlayer2, WinningDirection::kRightDiag));
}
TEST_CASE("Board Bounds", "[Boards_bounds]") {
  Board student;
  InitBoard(student);
  REQUIRE_FALSE(BoardLocationInBounds(-32, -6));
  REQUIRE_FALSE(BoardLocationInBounds(12, 10));
  // REQUIRE_FALSE(BoardLocationInBounds(-1, 5));
  // REQUIRE_FALSE(BoardLocationInBounds(4, -5));
  // REQUIRE_FALSE(BoardLocationInBounds(6, 9));
  // REQUIRE_FALSE(BoardLocationInBounds(4, -3));
  // REQUIRE_FALSE(BoardLocationInBounds(700, 2));
}
