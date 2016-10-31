/*************************************************************************
*	hopefully a successful battleship console game
*	made while I was board... so far no COM
*	however functional, just 1 player
*	there is a lot of sloppy code in this.(my first self project)
 *************************************************************************/


#include "stdafx.h"//for visual studio
#include "functions.h"

using namespace std;//simple program, not an issue


int main()
{
	int x=1, y=1;
	cout << "ready to set ships...\n";
	system("pause");
	rand_set();
	disp_board();
	bool win = run_game();
	if (win == true)
		cout << "\nYou're win \n\n\n\n";
	system("pause");
	return 0;
}
