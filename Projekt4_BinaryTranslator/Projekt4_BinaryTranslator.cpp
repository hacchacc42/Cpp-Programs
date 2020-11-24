#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
ifstream inputFile("input.txt");
ofstream outputFile("output.txt");
int Hex();
int Text();
int Decimal();
bool isBit();
int main()
{
    int n;
    cout << "Convert binary to :" << endl << "1. Decimal    2. Text    3. Hex" << endl;
    cin >> n;
    if (n == 1)
    {
        //BINARY TO DECIMAL
        Decimal();
    }
    else if(n==2)
    {
        // BINARY TO TEXT
        Text();
    }
    else if (n == 3) 
    {
        //Binary To HEX
        Hex();
    }
    inputFile.close();
    outputFile.close();
    cout << "DONE";
    return 0;
}
bool isBit(string s)
{
    if (isdigit(atoi(s.c_str())))
    {
        cout << "ok";
        return true;
    }
    else
    {
        cout << "NOOO";
        return false;
    }
}

int Hex()
{
    int pos = 0, final = 0;
    long x;
    char y;
    int x1, x2;
    char hex1, hex2;
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        x1 = 0;
        x2 = 0;
        hex1 = 0;
        hex2 = 0;
        while (x > 0)
        {
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            if (pos < 4)
            {
                x1 += (x % 10) * pow(2, pos % 4);
            }
            else
            {
                x2 += (x % 10) * pow(2, pos % 4);
            }
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
            return 1;
        }
        if (x1 > 9)
        {
            switch (x1)
            {
            case 10:
                hex1 = 'A';
                break;
            case 11:
                hex1 = 'B';
                break;
            case 12:
                hex1 = 'C';
                break;
            case 13:
                hex1 = 'D';
                break;
            case 14:
                hex1 = 'E';
                break;
            case 15:
                hex1 = 'F';
                break;
            }
        }
        else
        {
            hex1 = x1 + 48;
        }
        if (x2 > 9)
        {
            switch (x2)
            {
            case 10:
                hex2 = 'A';
                break;
            case 11:
                hex2 = 'B';
                break;
            case 12:
                hex2 = 'C';
                break;
            case 13:
                hex2 = 'D';
                break;
            case 14:
                hex2 = 'E';
                break;
            case 15:
                hex2 = 'F';
                break;
            }
        }
        else
        {
            hex2 = x2 + 48;
        }
        inputFile >> y;
        outputFile << hex2 << hex1 << " ";
        return 0;
    }
}

int Text()
{
    int pos = 0, final = 0;
    long x;
    char y;
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        while (x > 0)
        {
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            final += (x % 10) * pow(2, pos);
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
            return 1;
        }
        cout << endl << (char)final << endl;
        inputFile >> y;
        outputFile << (char)final;
    }
}

int Decimal()
{
    int pos = 0, final = 0;
    long x;
    char y;
    while (!inputFile.eof())
    {
        inputFile >> x;
        pos = 0;
        final = 0;
        while (x > 0)
        {
            cout << "POS =" << pos << " Final= " << final << " x=" << x << endl;
            if (x % 10 != 0 && x % 10 != 1)
            {
                cout << "ERROR CODE 2 : Wrong input, the input is not binary." << endl;
                return 2;
            }
            final += (x % 10) * pow(2, pos);
            pos++;
            x /= 10;
        }
        if (pos > 8)
        {
            cout << "ERROR CODE 1: Wrong input, try using the 8 bit standard." << endl;
            return 1;
        }
        cout << endl << final << endl;
        inputFile >> y;
        outputFile << final << " ";
    }
}