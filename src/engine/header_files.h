#ifndef HEADER_FILES_H__
#define HEADER_FILES_H__ 1

#include <iostream>
#include <vector>

#define TOTAL_MOVES 9
#define POWER 4

/// <summary>
/// difficulty set by player with computer
/// the number is related to depth of decision tree
/// </summary>
namespace tictactoe
{
	enum DIFFICULTY {NONE=0, BEGINNER=1, EASY=3, HARD=7, HACKER=10};
}

/// <summary>
/// mark on the board
/// </summary>
namespace tictactoe
{
	enum MARK { PLAYER_1 = 100, PLAYER_2 = 101 , COMPUTER = 102, EMPTY_SPACE = 103 };
}


#define TOTAL_CELLS 9


#endif //HEADER_FILES_H__
