#include <iostream>
#include <string>
using namespace std;

int main()
{
	string names[10] = { "Test","Mark","Joe","Buddy","Mickey","Bob","Alice","Charlie","Giu","Hi" };
	bool allowed[10] = { false };
	allowed[9] = true;
	cout << "What name you want to retrive from our data list? and what method do you want to use 1.GetName 2.Hacking" << endl;
	int ch1, ch2;
	cin >> ch1 >> ch2;
	if (ch2 == 1)
	{
		if (allowed[ch1 - 1] == false) {
			cout << "Name Unavelible";
		}
		else
		{
			cout << names[ch1 - 1];
		}
	}
	if (ch2 == 2)
	{
		//geting a name by using our only allowed name
		string* ptr = names + 9;
		cout << *(ptr-(10-ch1));
	}
}