#ifndef BOARD_H__
#define BOARD_H__ 1

#include "header_files.h"
#include <vector>
#include <iostream>

namespace tictactoe
{
	const std::vector<std::vector<int>> PATHS({ {0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6} });

	class board
	{
	protected:
		std::vector<MARK> m_board;
	public:
// constructors

		board() : m_board(TOTAL_CELLS, EMPTY_SPACE) {}
		board(const board& other) : m_board(other.m_board) {} //copy
		board(board&& other) : m_board(std::move(other.m_board)) {} //move

		void operator=(const board& other)
		{
			m_board = other.m_board;
		}
		void operator=(board&& other) noexcept
		{
			m_board = std::move(other.m_board);
		}

// get and set cell

		void set_cell(int pos, MARK m)
		{
			m_board[pos] = m;
		}
		MARK& operator[](int pos) noexcept
		{
			return m_board[pos];
		}
		MARK get_cell(int pos) const noexcept
		{
			return m_board[pos];
		}

// print
		void display()
		{
			for (int i = 1; i < 12; i++)
			{
				for (int j = 1; j < 12; j++)
				{
					if (j == 4 || j == 8)
						std::cout << "|";
					else if (i == 4 || i == 8)
						std::cout << "_";
					else if ((i == 2 || i == 6 || i == 10) && (j == 2 || j == 6 || j == 10))
					{
						MARK mark = m_board[(3 * (i - 2) / 4) + ((j - 2) / 4)];
						GUI::ICON icon = (mark == PLAYER_1) ? GUI::ICON_PLAYER_1 : ((mark == PLAYER_2) ? GUI::ICON_PLAYER_2 : GUI::ICON_EMPTY_SPACE);
						//display icon
						std::cout << icon;
					}
					else
						std::cout << " ";
				}
				std::cout << std::endl;
			}
		}

//check
		MARK check()
		{
			for (auto path : PATHS)
			{
				// if the place is empty we can skip the path
				if (m_board[path[0]] == EMPTY_SPACE)
					continue;
				if (path[0] == path[1] && path[0] == path[2])
					return m_board[path[0]];
			}
			return EMPTY_SPACE;
		}

// reset
		void reset()
		{
			m_board = std::vector<MARK>(TOTAL_CELLS, EMPTY_SPACE);
		}

	};

}


#endif //BOARD_H__