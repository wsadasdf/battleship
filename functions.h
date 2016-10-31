#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>

const int MIN= 1, MAX=15;

using namespace std;

int rand_num();
int rand_ship();
void disp_board();
void reset_board();
void rand_set();
bool run_game();

class allexceptions: public exception
{
	virtual const char* what() const throw()
	{
		return "an exception of \"you didn't listen\" has occurred.";
	}
}ex;

enum ship {big_ship = 5, med_ship = 3, small_ship = 2};

//all teh boardz for teh gaemz

char board[16][16] = {	  {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},	//where the ships are hidden
						  {'1','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'2','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'3','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'4','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'5','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'6','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'7','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'8','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'9','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'a','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'b','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'c','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'d','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'e','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						  {'f','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};

char inv_board[16][16] = {  {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'},
							{'1','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
/* the board the */			{'2','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
/* player sees */			{'3','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'4','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'5','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'6','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'7','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'8','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'9','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'a','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'b','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'c','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'d','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'e','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
							{'f','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};

int rand_num()
{
	int roll = 0;

		time_t seconds;
		time(&seconds);
		srand(static_cast<unsigned int> (seconds));
		roll =rand() % (MAX-MIN+1) + MIN;
		return roll;
}

int rand_ship()
{
	int roll=0, max=5, min=2;
	time_t seconds;
	time(&seconds);
	srand(static_cast<unsigned int> (seconds));
	roll =rand() % (max-min+1) + min;
	return roll;
}

void disp_board()
{
	cout << endl << endl;
	for(int x=0;x<16;x++)
	{
		if (x>0)
			cout << endl;

		for(int y=0;y<16;y++)
			cout << setw(3) << inv_board[x][y];
	}
	cout <<endl << endl;

}

void reset_board()
{
	for(int x=1;x<16;x++)
	{
		for(int y=1;y<16;y++)
		{
			inv_board[x][y]= '_';
			board[x][y]= '_';
		}
	}
}

void rand_set()
{
	int count = 1;
	ship place;
	while (count <=3)
	{
	 if(count == 1)
		 place = big_ship;
	 else if(count == 2)
		 place = med_ship;
	 else if(count == 3)
		 place = small_ship;

	 switch(place)
	 {
	 case big_ship:
		 {
			 int len = big_ship;
			 here: //here it is
			 int vert = rand_num()%2;
			 for(int start = rand_num(), size = 0; (size<len)&&(start<11); ++size)
			 {
				 for(int i= 0; i<len; ++i)
				 {
						if(((start + size)>15)&&(start-5) == 'X')
						{
							 cerr << "working...\n";
						 goto here;
						 }

						 if(board[(start + size)][start] == 'X')			//used to check if slots are open
						 {
							 cout << "working...\n";
							 goto here;
						 }
						 if(board[start][(start + size)] == 'X')			//^^
						 {
							 cout << "working...\n";
							 goto here;
						 }



				 }
				 if (vert==0)
					 board[((start + size)<16) ? (start + size) : ((start-5)+size)][start] = 'X';	//prints to the hidden board (verticle)
				 else
					 board[start][((start+ size)<16) ? (start + size) : 15] = 'X';  //prints to the hidden board (horizontal)
			 }
		 }

		 break;
	 case med_ship:
		 {
			 int len = med_ship;
			 there: //there they are
			 int vert = rand_num()%2;
			 for(int start = rand_num(), size = 0; (size<len)&&(start<16); ++size)
			 {
				 for(int i= 0; i<len; ++i)
				 {
					 if(((start + size)>15)&&(start-3) == 'X')
					{
							cerr << "working...\n";
							goto there;
					}
					 if(board[(start + size)][start] == 'X')			//used to check if slots are open
					 {
						 cout << "working...\n";
						 goto there;
					 }
					 if(board[start][(start + size)] == 'X')			//^^
					 {
						 cout << "working...\n";
						 goto there;
					 }
				 }
				 if (vert==0)
					 board[((start+ size)<16) ? (start + size) : 15][start] = 'X';	//prints to the hidden board (verticle)
				 else
					 board[start][((start+ size)<16) ? (start + size) : 15] = 'X';  //prints to the hidden board (horizontal)
			 }
		 }

		 break;
	 case small_ship:
		 {
			 int len = small_ship;
			 top:
			 int vert = rand_num()%2;
			 for(int start = rand_num(), size = 0; (size<len)&&(start<16); ++size)
			 {
				 for(int i= 0; i<len; ++i)
				 {
					 if(((start + size)>15)&&(start-5) == 'X')
						{
							cerr << "working...\n";
							goto top;
						 }
					 if(board[(start + size)][start] == 'X')			//used to check if slots are open
					 {
						 cout << "working...\n";
						 goto top;
					 }
					 if(board[start][(start + size)] == 'X')			//^^
					 {
						 cout << "working...\n";
						 goto top;
					 }
				 }
				 if (vert==0)
					 board[((start+ size)<16) ? (start + size) : 15][start] = 'X';	//prints to the hidden board (verticle)
				 else
					 board[start][((start+ size)<16) ? (start + size) : 15] = 'X';  //prints to the hidden board (horizontal)
			 }
		}
		 break;

	 default:
		 cout << "how did you reach this option? I am impressed.";
		 break;
	 }
	 ++count;
	}
	system("cls");
	cout << "\ndone.\n";
}

bool run_game()
{
	while (true)
	{
	int x=1, y=1;
top:
	disp_board();
	cout << endl;
	cout << "enter where to go(1-15): ";
	cin >> x;

	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\nbad input\n";
		goto top;
	}
	cin.ignore();
	cin >> y;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\nbad input\n";
		goto top;
	}
	try
	{
		if ((x>15)||(x<1)||(y>15)||(y<1))
		{
			cin.clear();
			throw ex;
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << "\n";
		system("pause");
		continue;
	}

	if(board[x][y]=='X')
	{
		inv_board[x][y]='X';
	}
	else
		inv_board[x][y] = 'O';
	for (int x=1;(x<16);++x)
	{
		for(int y=1;y<16;++y)
		{
			if (board[x][y] == '_')
				continue;
			if (inv_board[x][y] == '0')
				continue;
			if ((board[x][y] == 'X')&&(inv_board[x][y] == 'X'))
			{
				if ((x==15)&&(y==15))
					return true;
				else
					continue;
			}
			else
				continue;
		}
	}
	}
//	++turn_count;
	}

#endif
