#ifndef HEADER_FILES_H__
#define HEADER_FILES_H__ 1

#define WIN 200
#define LOSE 201

namespace tictactoe
{
	enum DIFFICULTY {EASY=3, HARD=10};
}

namespace tictactoe
{
	namespace GUI
	{
		enum ICON { ICON_PLAYER_1 = 'X', ICON_PLAYER_2 = 'O', ICON_COMPUTER = 'O', ICON_EMPTY_SPACE = ' ' };
	}
}
namespace tictactoe
{
	// player2 == computer
	enum MARK { PLAYER_1 = 100, PLAYER_2 = 101 , COMPUTER = 101, EMPTY_SPACE = 102 };
}

#define CLS (std::cout<<"\033[2J")

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



#define TOTAL_CELLS 9


#endif //HEADER_FILES_H__
