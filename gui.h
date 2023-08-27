#ifndef GUI_H__
#define GUI_H__ 1

#include <iostream>
#include "header_files.h"
#include "board.h"

// #define CLS (std::cout<<"\033[2J")

#define CLS system("cls");

#define LOCATE(r,c) (std::count<<"\033[" (r) <<';'<<(c)<<'H')

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define COLOR( f, b) (std::cout << "\033[1;3"<< (f)<<";4"<< (b) <<'m')
#define RESET() (std::cout<<"\033[1;3"<<WHITE<<";4"<<BLACK<<'m')


namespace tictactoe
{
	namespace GUI
	{
		int get_move(board b)
		{
			int move;
			std::cin >> move;
			while (move < 1 || move > 9 || b[move - 1] != EMPTY_SPACE)
				std::cin >> move;
			return move - 1;
		}
        bool outro(MARK mark, MARK mode)
        {
            char temp;
            switch (mark)
            {
            case tictactoe::PLAYER_1:
                if (mode == PLAYER_2)
                    std::cout << "\nPlayer 1 wins\n";
                else
                    std::cout << "\ncongrats you win!!!!!!!!!\n";
                break;
            case tictactoe::PLAYER_2:
                std::cout << "\nPlayer 2 wins\n";
                break;
            case tictactoe::COMPUTER:
                COLOR(BLUE, WHITE);
                std::cout << "\nyou lose try again\n";
                RESET();
                break;
            case tictactoe::EMPTY_SPACE:
                std::cout << "\nAn amazing game results in draw\n";
                break;
            default:
                std::cout << "error";
                break;
            }
            std::cout << "Want to play more (y)........\n";
            std::cin >> temp;
            return (temp == 'y') ? true : false;
        }
        MARK mode()
        {
            std::cout << "\nDo you want to play with 1. computer or 2. another player\n";
            int m;
            std::cin >> m;
            return (m == 1) ? COMPUTER : PLAYER_2;
        }
        void intro()
        {
            COLOR(GREEN, BLACK);
            std::cout << "welcome to my tictactoe game" << std::endl;
            std::cout << "..............................." << std::endl;
            RESET();
            std::cout << "\n Rules ==>\n1. Enter number from 1 to 9 to enter your choice\n2. Enter 0 to quit in middle\n";

        }
        DIFFICULTY difficulty()
        {
            std::cout << "\nEnter difficulty";
            std::wcout << "\n1.beginner";
            COLOR(GREEN, BLACK);
            std::cout << "\n2.easy";
            COLOR(YELLOW, BLACK);
            std::cout << "\n3.hard";
            COLOR(RED, BLACK);
            std::cout << "\n4.hacker\n";
            RESET();
            int d;
            std::cin >> d;
            switch (d)
            {
            case 1:
                return BEGINNER;
            case 2:
                return EASY;
            case 3:
                return HARD;
            case 4:
                return HACKER;
            default:
                return BEGINNER;
            }
        }

		// print
		void display_board(board m_board)
		{
			RESET();
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
						switch (mark)
						{
						case PLAYER_1:
							COLOR(CYAN, BLACK);
							std::cout << "X";
							RESET();
							break;
						case COMPUTER:
						case PLAYER_2:
							COLOR(MAGENTA, BLACK);
							std::cout << "O";
							RESET();
							break;
						default:
							std::cout << " ";
						}
					}
					else
						std::cout << " ";
				}
				std::cout << std::endl;
			}
		}

	}
}

#endif // GUI_H__