#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int a[50][50] = { 0 };
	int randN;
	//10 Levels
	for (int l = 0; l < 10; l++)
	{
		cout << "level " << l+1 <<" :"<< endl;
		//Genrating the map
		for (int i = 1; i < 49; i++)
		{
			for (int j = 1; j < 49; j++)
			{
				randN = rand() % 101;
				//Making the central point
				if (randN < 5 * pow(1.15, l))
				{
					a[i][j] = 1;
				}
				else
				{
					a[i][j] = 0;
				}
			}
		}
		//Making the adjestment points
		for (int i = 1; i < 49; i++)
		{
			for (int j = 1; j < 49; j++)
			{
				if (a[i + 1][j] == 1 || a[i - 1][j] == 1 || a[i][j + 1] == 1 || a[i][j - 1] == 1)
				{
					a[i][j] = 2;
				}
			}
		}
		//Displaying the map
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (a[i][j] == 0)
				{
					cout << "#";
				}
				else if (a[i][j] == 1)
				{
					cout << " ";
				}
				else
				{
					cout << " ";
				}
				cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
	}
}