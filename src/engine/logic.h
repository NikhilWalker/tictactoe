#ifndef LOGIC_H__
#define LOGIC_H__ 1

#include <thread>
#include "gui.h"
#include "header_files.h"
#include "board.h"
#include "decision_tree.h"

namespace tictactoe
{
    /// <summary>
    /// instanciate a decision tree of given difficulty
    /// returns the max priority child
    /// </summary>
    /// <param name="cur_board">current board positions</param>
    /// <param name="diff">difficulty</param>
    /// <returns>returns the move of computer</returns>
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
    /// <summary>
    /// this function is used only if the difficulty is hacker
    /// </summary>
    /// <param name="m_board">board</param>
    /// <param name="path">winning path</param>
    /// <returns>returns the move at which the game will be draw or winning for computer</returns>
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
    /// <summary>
    /// iterates untill the game finishes or any intreppt
    /// get moves from computer and player
    /// print the board
    /// check the board
    /// </summary>
    /// <param name="diff">difficulty</param>
    /// <param name="mode">mode of the game i.e. with computer or another player</param>
    /// <returns>returns the mark of any player if wins else EMPTY_SPACE</returns>
    MARK logic(DIFFICULTY diff, MARK mode)
    {
        using namespace std::chrono_literals;
        CLS;
        std::cout << "Starting game";
        std::this_thread::sleep_for(1s);
        std::cout << ".";
        std::this_thread::sleep_for(1s);
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
                std::cout << "thinking...";
                std::this_thread::sleep_for(1s);
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
