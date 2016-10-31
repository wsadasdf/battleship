/*	hopefully a successful battleship console game
 *	made while I was board... so far no COM
 *	however functional, just 1 player
 */


#include "stdafx.h"
#include "functions.h"

using namespace std;



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
