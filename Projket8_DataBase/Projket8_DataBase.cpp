#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <iomanip>
struct account
{
	int id;
	std::string name;
	float balance;
}account[1000];

void LoadDataBase();
void OutputDataBase();
void AddToDataBase();
void Sorting();
void Swap(int j);

std::fstream dataFile;
int maxAcc = 0;

int main()
{
	char ch, repeat;
	do
	{
		LoadDataBase();
		system("CLS");
		std::cout << "What do you want to do ?" << std::endl << "1. Show data base." << std::endl << "2. Add to data base" << std::endl << "3. Sort" << std::endl;
		std::cin >> ch;
		if (ch == '1')
		{
			OutputDataBase();
		}
		else if (ch == '2')
		{
			AddToDataBase();
		}
		else if (ch == '3')
		{
			Sorting();
		}
		else
		{
			std::cout << "Invalid input ." << std::endl;
		}
		std::cout << "Do you want to do other transaction ?(Y/N)" << std::endl;
		std::cin >> repeat;
	}
	while (toupper(repeat) == 'Y');
}

void LoadDataBase()
{
	int accnum = 0;
	dataFile.open("Database.txt", std::ios::in);
	if (dataFile.is_open())
	{
		while (dataFile >> account[accnum].id >> account[accnum].name >> account[accnum].balance)
		{
			accnum++;
		}
		maxAcc = accnum;
	}
	else
	{
		std::cout << "Error while loading file" << std::endl;
	}
	dataFile.close();
}

void OutputDataBase()
{
	std::cout << "ID  NAME           BALANCE" << std::endl;
	for (int i = 0; i< maxAcc; i++)
	{
		std::cout <<std::setw(4)<<std::left<< account[i].id << std::setw(15) << std::left << account[i].name << account[i].balance << std::endl;
	}
}

void AddToDataBase() 
{
	dataFile.open("Database.txt", std::ios::app);
	std::cout << "Enter your name :";
	std::cin >> account[++maxAcc].name;
	std::cout << "Enter your balance :";
	std::cin >> account[maxAcc].balance;
	dataFile << std::endl << maxAcc << " "<<account[maxAcc].name<<" "<<account[maxAcc].balance;
	dataFile.close();
}

void Sorting()
{
	std::cout << "1. Ascending  2. Descending  3. By Name Ascending  4. By Name Descending" << std::endl;
	char sort;
	std::cin >> sort;
	if (sort == '1' || sort == '2' || sort == '3' || sort == '4')
	{
		for (int i = 0; i < maxAcc - 1; i++)
		{
			for (int j = 0; j < maxAcc - 1 - i; j++)
			{
				if (sort == '1')
				{
					if (account[j].balance > account[j + 1].balance)
					{
						Swap(j);
					}
				}
				else if (sort=='2')
				{
					if (account[j].balance < account[j + 1].balance)
					{
						Swap(j);
					}
				}
				else if (sort == '3')
				{
					if (account[j].name[0] > account[j + 1].name[0])
					{
						Swap(j);
					}
				}
				else if(sort=='4')
				{
					if (account[j].name[0] < account[j + 1].name[0])
					{
						Swap(j);
					}
				}
			}
		}
	}
	else
	{
		std::cout << "Invalid output, Displaying default database" << std::endl << std::endl;
	}
	OutputDataBase();
}


void Swap(int j)
{
	int tempI;
	float tempF;
	std::string tempS;
	tempF = account[j].balance;
	account[j].balance = account[j + 1].balance;
	account[j + 1].balance = tempF;

	tempS = account[j].name;
	account[j].name = account[j + 1].name;
	account[j + 1].name = tempS;

	tempI = account[j].id;
	account[j].id = account[j + 1].id;
	account[j + 1].id = tempI;
}