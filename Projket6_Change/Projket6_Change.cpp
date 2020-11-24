//Program that will return the change .
//IM USING INTs AND OUTPUT AS FLOATS, BECAUSE THE OPERATION WITH FLOATS ARE DANGEROUS
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	float money = 0;
	int change = 0;
	int cost;
	//RANDOMISING THE COST
	for (int i = 0; i < 10; i++)
	{
		cost = rand() % 300000 + 1;
	}
	//There are 12 forms of money in UK ( papper and coins ) the element 0 is the 50 $  paper and the element 11 is the 1 cent.
	int changeMoney[12] = { 0 };
	int moneyValue[12] = { 5000 , 2000 , 1000 , 500 , 200 , 100 , 50 , 20 , 10 , 5 , 2 , 1 };
	cout << "The products you purchased costed : " <<(float)cost / 100 << endl;
	cout << "You pay ammount : ";
	cin >> money;
	int realMoney = money * 100;
	if (realMoney < cost)
	{
		cout << "Not enough money" << endl;
	}
	else
	{
		change = realMoney - cost;
		cout << "The machine must return you " << (float)change/100 << " $" << endl;
		while (change>0)
		{
			for (int i = 0; i < 12; i++)
			{
				while (change >= moneyValue[i])
				{
					change -= moneyValue[i];
					changeMoney[i]++;
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (changeMoney[i] != 0)
		{
			cout << changeMoney[i] << " - " << (float)moneyValue[i]/100 <<" $"<< endl;
		}
	}
}