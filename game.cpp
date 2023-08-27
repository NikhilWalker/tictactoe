#include <iostream>
#include "header_files.h"
#include "logic.h"

using namespace tictactoe;

int main()
{
	tictactoe::DIFFICULTY diff = tictactoe::NONE;
	tictactoe::GUI::intro();
	tictactoe::MARK player = tictactoe::GUI::mode();
	if (player == COMPUTER)
		diff = tictactoe::GUI::difficulty();

	while(1)
	{
		tictactoe::MARK mark = tictactoe::logic(diff, player);
		if (!tictactoe::GUI::outro(mark, player))
			break;
	}
	
	return 0;
}