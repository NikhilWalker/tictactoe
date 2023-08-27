#ifndef LOGIC_H__
#define LOGIC_H__ 1

#include <thread>
#include "gui.h"
#include "header_files.h"
#include "board.h"
#include "decision_tree.h"

namespace tictactoe
{
    int get_move(board cur_board, DIFFICULTY diff)
    {
        engine::decision_tree tree(cur_board);
        tree.initialise(COMPUTER, int(diff));
        if (tree.childs.size() == 0)
            return -1;
        // find max priority
        auto* max = tree.childs[0];
        for (auto child : tree.childs)
        {
            if (max->m_priority < child->m_priority)
                max = child;
        }
        return max->m_board.find_different(cur_board);
    }
    int hacker(board m_board, std::vector<int> path)
    {
        for (auto pos : path)
        {
            auto temp = m_board[pos];
            m_board[pos] = COMPUTER;
            if (m_board.check() == COMPUTER)
                return pos;
            m_board[pos] = temp;
        }
        return path[0];
    }

    MARK logic(DIFFICULTY diff, MARK mode)
    {
        std::cout << "Starting game .............\n";
        int cur_move = 0;
        int turn = 0;
        board cur_board;
        CLS;
        GUI::display_board(cur_board);

        while (1)
        {
            if ( turn == 0 )
            {
                cur_board[GUI::get_move(cur_board, mode, turn)] = PLAYER_1;
                cur_move++;
                turn = 1;
            }
            else if (mode == PLAYER_2)
            {
                cur_board[GUI::get_move(cur_board, mode, turn)] = PLAYER_2;
                cur_move++;
                turn = 0;
            }
            else
            {
                cur_board[get_move(cur_board, diff)] = COMPUTER;
                cur_move++;
                turn = 0;
            }

            CLS;
            GUI::display_board(cur_board);
            
            if (cur_board.check() != EMPTY_SPACE )
            {
                if( diff != HACKER )
                    return (turn == 1) ? PLAYER_1 : ((mode == PLAYER_2) ? PLAYER_2 : COMPUTER);
                if (diff == HACKER && cur_board.check() == PLAYER_1)
                {
                    cur_board[hacker(cur_board, cur_board.find_path())] = COMPUTER;
                    if (cur_board.check() != EMPTY_SPACE)
                    {
                        CLS;
                        GUI::display_board(cur_board);
                        return COMPUTER;
                    }
                    else
                        turn = 0;
                }
            }
            if (!cur_board.has_empty())
                return EMPTY_SPACE;
        }
    }
}

#endif // LOGIC_H__
