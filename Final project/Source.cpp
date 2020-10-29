#include <iostream>
#include <string>
using namespace std;
void drawboard(string Board[][7])
{
	for (int i = 0; i < 6; i++) // draws Board
	{
		for (int j = 0; j < 7; j++)
		{
			cout << "| ";
			cout << Board[i][j];
			cout << " |";
		}
		cout << endl;
		cout << "-----------------------------------" << endl;
	}

}
int main()
{
	string  currentturn = "X";
	int Playerchoice;
	string Board[6][7];

	for (int i = 0; i < 6; i++) // filling boardArray
	{
		for (int j = 0; j < 7; j++)
		{
			Board[i][j] = " ";
		}
	}
	bool playing = true;

	while (playing)
	{
		drawboard(Board);

		cout << " 1     2    3    4    5    6    7" << endl;
		if (currentturn == "X") {
			cout << "Player1 choose a number between 1-7 to put down your chip." << endl;
		}
		if (currentturn == "O") {

			cout << "Player2 choose a number between 1-7 to put down your chip." << endl;
		}
		cin >> Playerchoice;
			for (int i = 5; i >= 0; i--) // checking for empty spaces
			{
				if (Board[i][Playerchoice - 1] == " ")
				{
					Board[i][Playerchoice - 1] = currentturn;
					break;
				}
			}
		
			for (int i = 0; i < 6; i++) // horizontal check
			{
				for (int j = 0; j < 4; j++)
				{
					if (Board[i][j] == currentturn &&  Board[i][j + 1] == currentturn && Board[i][j + 2] == currentturn && Board[i][j + 3] == currentturn)
					{ 
						drawboard(Board);
						cout << "CONNECT 4! you win!" << endl;
						exit(0);
					}
				}

			}
			for (int i = 0; i < 7; i++) // vertical check
			{
				for (int j = 0; j < 3; j++)
				{
					if (Board[j][i] == currentturn &&  Board[j +1 ][i] == currentturn && Board[j + 2][i] == currentturn && Board[j + 3][i] == currentturn)
					{
						drawboard(Board);
						cout << "CONNECT 4! you win!" << endl;
						exit(0);
					}
				}

			}
			for (int i = 3; i < 6; i++) // diag check 1 Upwward
			{
				for (int j = 0; j < 3; j++)
				{
					if (Board[j][i] == currentturn &&  Board[j + 1][i - 1] == currentturn && Board[j + 2][i - 2] == currentturn && Board[j + 3][i - 3] == currentturn)
					{
						drawboard(Board);
						cout << "CONNECT 4! you win!" << endl;
						exit(0);
					}
				}

			}
			for (int i = 0; i < 4; i++) // diag check 2 Downward
			{
				for (int j = 0; j < 3; j++)
				{
					if (Board[j][i] == currentturn &&  Board[j + 1][i + 1] == currentturn && Board[j + 2][i + 2] == currentturn && Board[j + 3][i + 3] == currentturn)
					{
						drawboard(Board);
						cout << "CONNECT 4! you win!" << endl;
						exit(0);
					}
				}

			}
			if (currentturn == "O")
			{
				currentturn = "X";
			}

			else if (currentturn == "X")
			{
				currentturn = "O";
			}




			



	}
}
