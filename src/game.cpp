#include <iostream>

#include "engine/header_files.h"
#include "engine/logic.h"

using namespace tictactoe;

int main()
{
	tictactoe::DIFFICULTY diff = tictactoe::NONE;
	tictactoe::GUI::intro();
	tictactoe::MARK player = tictactoe::GUI::mode();
	if (player == COMPUTER)
		diff = tictactoe::GUI::difficulty();
	else
		GUI::get_names();

	while(1)
	{
		tictactoe::MARK mark = tictactoe::logic(diff, player);
		if (!tictactoe::GUI::outro(mark, player))
			break;
	}
	
	return 0;
}