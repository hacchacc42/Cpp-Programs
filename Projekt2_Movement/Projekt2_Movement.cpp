#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Room
    //Room size
    char space[100][100];
    //Room height and width
    int height;
    int width;

//Player
    //Player Positions
    int posx;
    int posy;
    //Player Inventory
    string inventory[10];

//Functions
    //Drawing the room and the enteties.
    void Draw();
    //Generate the room.
    void GenerateRoom();
    //Player move with inputs.
    void Move();
    //Select the dificulty of the game.
    void SelectDificulty();
    //Input the desired action.
    void Input();
    //Check the inventory
    void Inventory();

int main()
{
    bool playing = true;
    cout << "Welcome to RougeC" << endl;
    inventory[4] = "test4";
    SelectDificulty();
    GenerateRoom();
    //Starting position of the player
    posx = height/2;
    posy = width/2;
    while (playing)
    {
        Draw();
        Input();
    }
}

void Draw()
{
    //x is the player
    space[posx][posy] = 'x';
    //Clearing the screen
    system("cls");
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cout << space[i][j] << " ";
        }
        cout << endl;
    }
    //OPTIONAL: player positions
    cout << "Player possition [x:" << posx << "][y:" << posy << "]" << endl;
}

void GenerateRoom()
{
    //Generating the bot and top borders.
    for (int i = 0; i < width;i++)
    {
        space[0][i]='#';
        space[height - 1][i]='#';
    }
    for (int i = 1; i < height-1; i++)
    {
        //Generating the side borders.
        space[i][0] = '#';
        space[i][width - 1] = '#';
        for (int j = 1; j < width-1; j++)
        {
            space[i][j] = '.';
        }
    }
}

void Move()
{
    char choice;
    cout << "Where do you want to move ?" << endl;
    cout << "A.Left    W.Up    D.Right    S.Down" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'A':
    case 'a':
        if (posy > 1) 
        {
            space[posx][posy] = '.';
            posy--;
        }
        else
        {
            cout << "Out of bounds" << endl;
        }
        break;
    case 'W':
    case 'w':
        if (posx > 1)
        {
            space[posx][posy] = '.';
            posx--;
        }
        else
        {
            cout << "Out of bounds" << endl;
        }
        break;
    case 'D':
    case 'd':
        if (posy < width-2) 
        {
            space[posx][posy] = '.';
            posy++;
        }
        else
        {
            cout << "Out of bounds" << endl;
        }
        break;
    case 'S':
    case 's':
        if (posx < height-2)
        {
            space[posx][posy] = '.';
            posx++;
        }
        else
        {
            cout << "Out of bounds" << endl;
        }
        break;
    default:
        cout << "Bad Input" << endl;
        break;
    }
}

void SelectDificulty()
{
    char choice;
    bool goodChoice = false;
    do
    {
        cout << "Select Dificulty:" << endl;
        cout << "1.Easy    2.Medium    3.Hard" << endl;
        cin >> choice;
        if (choice == '1')
        {
            goodChoice = true;
            height = 7;
            width = 7;
        }
        else if (choice == '2')
        {
            goodChoice = true;
            height = 11;
            width = 11;
        }
        else if (choice == '3')
        {
            goodChoice = true;
            height = 15;
            width = 15;
        }
        else
        {
            goodChoice = false;
            cout << "Bad Input";
        }
    } 
    while (!goodChoice);
}

void Input()
{
    char choice;
    bool goodChoice = false;
    do
    {
        cout << "What do you want to do ?" << endl;
        cout << "1.Move    2.Inventory" << endl;
        cin >> choice;
        if (choice == '1')
        {
            Move();
            goodChoice = true;
        }
        else if (choice == '2')
        {
            Inventory();
            goodChoice = true;
        }
        else
        {
            cout << "Wrong Input" << endl;
            goodChoice = false;
        }
    } while (!goodChoice);
}

void Inventory()
{
    char choice;
    cout << "INVETORY:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "#" << i << ":" << inventory[i] << endl;
    }
    cout <<endl<< "What would you like to do ?" << endl;
    cout << "1.Drop item" << endl;
    cin >> choice;
    switch(choice)
    {
    case '1':
        cout << "TBC";
        break;
    deafult:
        cout << "Wrong Input";
        break;
    }

}