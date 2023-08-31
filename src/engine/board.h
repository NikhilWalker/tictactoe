#ifndef BOARD_H__
#define BOARD_H__ 1

#include "header_files.h"

namespace tictactoe
{
	const std::vector<std::vector<int>> PATHS({ {0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6} });

	/// <summary>
	/// board for tictactoe game
	/// has a 9 consecutive cells for storing mark
	/// </summary>
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
		
		MARK& operator[](int pos) noexcept
		{
			return m_board[pos];
		}
//check

		/// <summary>
		/// check the board
		/// </summary>
		/// <returns>return EMPTY_SPCE if none wins otherwise returns the mark of whoever wins</returns>
		MARK check()
		{
			for (auto path : PATHS)
			{
				// if the place is empty we can skip the path
				if (m_board[path[0]] == EMPTY_SPACE)
					continue;
				if (m_board[path[0]] == m_board[path[1]] && m_board[path[0]] == m_board[path[2]])
					return m_board[path[0]];
			}
			return EMPTY_SPACE;
		}
		/// <summary>
		/// check for empty cells
		/// </summary>
		/// <returns>return true if any one cell is empty else return false</returns>
		bool has_empty()
		{
			for (int i = 0; i < TOTAL_CELLS; i++)
			{
				if (m_board[i] == EMPTY_SPACE)
					return true;
			}
			return false;
		}
		/// <summary>
		/// compare two boards
		/// </summary>
		/// <param name="other"></param>
		/// <returns>returns a different move in two boards if two boards are same returns -1</returns>
		int find_different(board &other)
		{
			for (int i = 0; i < TOTAL_CELLS; i++)
			{
				if (m_board[i] == EMPTY_SPACE && other.m_board[i] == EMPTY_SPACE)
					continue;
				if (other.m_board[i] != m_board[i])
					return i;
			}
			return -1;
		}
		/// <summary>
		/// search the path for which any player wins
		/// </summary>
		/// <returns>returns 3 indices else if nobody wins return empty vector</returns>
		std::vector<int> find_path()
		{
			for (auto path : PATHS)
			{
				// if the place is empty we can skip the path
				if (m_board[path[0]] == EMPTY_SPACE)
					continue;
				if (m_board[path[0]] == m_board[path[1]] && m_board[path[0]] == m_board[path[2]])
					return path;
			}
			return std::vector<int>();
		}
// reset
		void reset()
		{
			m_board = std::vector<MARK>(TOTAL_CELLS, EMPTY_SPACE);
		}

	};

}


#endif //BOARD_H__