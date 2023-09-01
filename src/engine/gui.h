#ifndef GUI_H__
#define GUI_H__ 1

#include <iostream>
#include "header_files.h"
#include "board.h"

#ifdef _WIN32
#define CLS system("cls");
#else
#define CLS system("clear");
#endif // paltform

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
        std::string player_1("Player 1");
        std::string player_2("Player 2");

		int get_move(board b, MARK mode, int turn)
		{
            if (mode == COMPUTER)
                std::cout << "Your move : ";
            else if (turn == 0)
                std::cout << player_1 << "'s move : ";
            else
                std::cout << player_2 << "'s move : ";

			char move;
            while (1)
            {
                do
                {
                    std::cin >> move;
                    //see if valid
                    if (move <= '9' && move >= '1')
                    {
                        move = move - '1';
                        break;
                    }
                    else if (move == 'e')
                    {
                        std::cout << "\nBye";
                        exit(0);
                    }
                    else
                    {
                        std::cout << "invalid move enter number : ";
                    }
                } while (1);
                if (b[move] == EMPTY_SPACE)
                    break;
                else
                {
                    std::cout << "Enter valid number : ";
                }
            }
			return move;
		}
        bool outro(MARK mark, MARK mode)
        {

            if(mode == COMPUTER)
            {
                if(mark == COMPUTER)
                {
                    COLOR(MAGENTA, BLACK);
                    std::cout << "\nyou lose\n";
                    RESET();
                }
                else if(mark == PLAYER_1)
                {
                    COLOR(CYAN, BLACK);
                    std::cout << "\nyou win!\n";
                    RESET();
                }
                else
                {
                    COLOR(CYAN, BLACK);
                    std::cout << "\nAmazing game!\n";
                    RESET();
                }
            }
            else
            {
                if (mark == PLAYER_1)
                {
                    COLOR(CYAN, BLACK);
                    std::cout << player_1 << " wins!!!!!!!!!\n";
                    RESET();
                }
                else if(mark == PLAYER_2)
                {
                    COLOR(MAGENTA, BLACK);
                    std::cout << player_2 << " wins!!!!!!!!!!\n";
                    RESET();
                }
                else
                {
                    COLOR(MAGENTA, BLACK);
                    std::cout << "An Amazing game results in draw";
                    RESET();
                }
            }

            std::cout << "Want to play more (y/n)........\n";
            char temp;
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
            std::cout << "welcome to tictactoe game" << std::endl;
            std::cout << "..............................." << std::endl;
            RESET();
            std::cout << "\n Rules ==>\n1. Enter number from 1 to 9 to enter your choice\n2. Enter e to quit in middle\n";

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
        void get_names()
        {
            std::cout << "Default names are " << player_1 << " and " << player_2<<std::endl;
            std::cout << "Type c if you want to change names enter\t";
            char choice;
            std::cin >> choice;
            if (choice == 'c')
            {
                std::cout << std::endl;
                std::cout << "Enter Player 1 name : ";
                std::cin >> player_1;
                std::cout << "Enter Player 2 name : ";
                std::cin >> player_2;
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