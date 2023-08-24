#ifndef DECISION_TREE_H__
#define DECISION_TREE_H__ 1

#include "board.h"
#include <vector>

namespace tictactoe
{
	namespace engine
	{
		class decision_tree
		{
		public:
        //data
			board m_board;
			std::vector<decision_tree*> childs;
            int move_no;
            int pos;
        //func
		// initialize the decision tree

			decision_tree(board prev, int move_no, DIFFICULTY diff)
			{
				this->move_no = move_no + 1;
				this->m_board = prev;

                // while the board space are empty
                for (int i = 0; i < TOTAL_CELLS; i++)
                {
					// if the cell is empty fill the cell
					if (m_board[i] == EMPTY_SPACE)
					{
						m_board[i] = COMPUTER;
						//calculate if the game is over
						// mark = check(m_board)
						// if copmuter wins plus the priority
						// if the player wins minus the priority
						// if none wins and the depth is not 1 again call decision tree and assign child
						// reset the mark
					}
                }
			}
		};
	}
}


#endif // DECISION_TREE_H__