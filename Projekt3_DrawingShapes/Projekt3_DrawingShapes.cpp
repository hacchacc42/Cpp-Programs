#include <iostream>
using namespace std;

int main()
{
	int x1,x2,y1,y2;
	cout << "x1:";
	cin >> x1;
	cout << "y1:";
	cin >> y1;
	cout << "x2:";
	cin >> x2;
	cout << "y2";
	cin >> y2;
	int temp;
	if (x1 > x2) 
	{
		temp = x1;
		x1 = x2;
		x2 = temp;	
	}
	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	for (int i = 0; i < 21; i++)
	{
		cout << "@@";
	}
	cout << endl;
	for (int i = 0; i < 20; i++) 
	{
		cout << "@";
		for (int j = 0; j < 20; j++)
		{
			if (i == x1 && j >= y1 && j <= y2 || i == x2 && j >= y1 && j <= y2
				|| j == y1 && i >= x1 && i <= x2 || j == y2 && i >= x1 && i <= x2)
			{
				cout << "#";
			}
			else {
				cout << " ";
			}
			cout << " ";

		}
		cout << "@";
		cout << endl;
	}
	for (int i = 0; i < 21; i++)
	{
		cout << "@@";
	}
	cout << endl;
}