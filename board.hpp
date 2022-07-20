#ifndef BOARD_HPP
#define BOARD_HPP
#include <cassert>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "board.hpp"

enum class WinningDirection { kHorizontal, kVertical, kRightDiag, kLeftDiag };
enum class DiskType { kPlayer1 = 82, kPlayer2 = 66, kEmpty = 32 };

struct Board {
  static constexpr int kBoardWidth = 7;
  static constexpr int kBoardHeight = 6;
  DiskType board[kBoardHeight][kBoardWidth];
};

void InitBoard(Board& b);
void DropDiskToBoard(Board& b, DiskType disk, int col);
bool CheckForWinner(Board& b, DiskType disk);
bool SearchForWinner(Board& b, DiskType disk, WinningDirection to_check);
bool BoardLocationInBounds(int row, int col);
bool SearchForWinnerHorizontal(Board& b,
                               DiskType disk,
                               WinningDirection to_check);
bool SearchForWinnerVertical(Board& b,
                             DiskType disk,
                             WinningDirection to_check);
bool SearchForWinnerLeftDiagonal(Board& b,
                                 DiskType disk,
                                 WinningDirection to_check);
bool SearchForWinnerRightDiagnol(Board& b,
                                 DiskType disk,
                                 WinningDirection to_check);

// provided
std::string BoardToStr(const Board& b);
std::string CenterStr(const std::string& str, int col_width);

#endif