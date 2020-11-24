#include <iostream>
#include <string.h>
using namespace std;

char crack[9] = { '\0' };
string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string password;
bool crackP();

int main()
{
	char crack[2] = { '\0' };
	int i;

	bool goodPass;
	bool smallChar;
	bool bigChar;
	bool number;
	do {
		cout << "Enter your password (jus 3 characters)." << endl;
		cin >> password;
		if (password.length() ==3)
		{
			for (int i = 0; i < password.length(); i++)
			{
				goodPass = true;
				smallChar = false;
				bigChar = false;
				number = false;
				if ((int)password[i] <= 122 && (int)password[i] >= 97)
				{
					smallChar = true;
				}
				if ((int)password[i] <= 90 && (int)password[i] >= 65)
				{
					bigChar = true;
				}
				if ((int)password[i] <= 57 && (int)password[i] >= 48)
				{
					number = true;
				}
				if(!(smallChar || bigChar || number))
				{
					cout << "Invalid character on position " << i << endl;
					goodPass = false;
					break;
				}
			}
		}
		else
		{
			cout<<"Lenght is not correct ."<<endl;
			goodPass = false;
		}
	} while (!goodPass);
	if (crackP())
	{
		cout << "Password found." << endl;
	}
	else {
		cout << "Password not found";
	}
}
bool crackP()
{
	for (int i = 0; i < 62; i++)
	{
		crack[2] = alphabet[i];
		for (int j = 0; j < 62; j++)
		{
			crack[1] = alphabet[j];
			for (int k = 0; k < 62; k++)
			{
				crack[0] = alphabet[k];
				cout <<crack[0] << " " << crack[1] << " " <<  crack[2]<< endl;
				if (crack[0] == password[0] && crack[1] == password[1] && crack[2] == password[2])
				{
					return true;
				}
			}
		}
	}
	return false;
}