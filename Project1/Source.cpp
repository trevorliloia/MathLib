#include <iostream>
#include <list>
#include <cassert>

using namespace std;

/*
if (list.empty)
{
	return nullptr;
}

while (list.notSort)
{
	for (int i; i < list.size; i++)
	{
		if(Compare(list[i], list[i+1]))
		{
			int t = list[i];
			list[i] = list[i+1];
			list[i+1] = t;
		}
	}
}
*/
//
//void flushSTDIN()
//{
//	char c;
//	while ((c = getchar()) != '\n' && c = != EOF))
//	{ }
//}

class GameBoard
{
private:
	char * board;
	int size;
	int turnCount;

public:
	GameBoard(int a_size)
	{
		size = a_size;
		board = new char[size * size];
		turnCount = 0;
		for (int i = 0; i < size*size; ++i)
		{
			board[i] = ' ';
		}
	}

	~GameBoard()
	{

	}

	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				printf(" [%c]", board[size * j + i]);
			}
			printf("\n");
		}
	}
	void prompt(int& outX, int& outY)
	{
		
		printf("Where do you place your piece?\n");
		int coordX, coordY;
		while (scanf_s("%d,%d", &coordX, &coordY) != 2)
		{
			printf("Nope");
			
		}
		outX = coordX;
		outY = coordY;
		if ((((turnCount - 1) % 2) + 1) == 1)
		{
			
		}
	}

	int getWinner()
	{
		if (turnCount > (size*size))
		{
			return -1;
		}
		
		for (int i = 0; i < size; ++i)
		{
			bool winning = true;
			for (int j= 0; j < size; ++j)
			{
				winning = (board[size * j + i] == 'X')
				if (winning)
				{
					return break;
				}
			}
			if (winning)
			{
				return 1;
			}
		}


		return 0;
	}

	bool update()
	{

		int winner = getWinner();
		if (winner > 0)
		{
			printf("Player %d Has Won. Congrationans.\n", winner);
			return true;
		}
		else if (winner == -1)
		{
			printf("Game Draw.\n");
			return true;
		}
		printf("---- Turn %d ----\n", ++turnCount);
		print();

		int playerID = ((turnCount - 1) % 2) + 1;

		printf("---- Player %d ----\n", ((turnCount - 1) % 2) + 1);

		int inputX, inputY;
		bool turnComplete = false;
		while (!turnComplete)
		{
			prompt(inputX, inputY);
			char val = board[size * inputX + inputY];
			turnComplete = (val == ' ');

			if (!turnComplete)
			{
				printf("Space Invalid.\n");
			}
		}
		
		

		board[size * inputX + inputY] = (playerID == 1 ? 'X' : 'O');

		return false;
	}
};

int main()
{
	bool running = true;
	GameBoard board(3);
	while (!board.update());
	
	system("pause");
}