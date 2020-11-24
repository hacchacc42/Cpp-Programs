#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// Check Docs.txt for more clarification.

int main()
{
    // Setting the random time seed to NULL.
    srand(time(NULL));
    // randomNum is the main value that will decide which symbol will be generated.
    int randomNum;
    // Just for presentation purpose, there will be an additional loop that will make more levels.
    for (int levelsGenerated = 0; levelsGenerated < 10; levelsGenerated++) {
        // Initializing the "MAP" with a maxium rows of 15 and maximum collums of 20.
        char map[15][20];
        // player variable will track if the player starting location has been made.
        bool player = false;
        // exit variable will track if the level exit has been made.
        bool exit = false;
        // This for loop wil make the top and bottom borders of the level
        for (int collum = 0; collum < 20; collum++) {
            map[14][collum] = '#';
            map[0][collum] = '#';
        }
        // This is the start of the main for loops that will generate the whole map.
        // The first loop goes from row 13 to the row 1 , because the first (0) and the last (14) rows are already made by the previous loop.
        for (int row = 13; row >= 1; row--) {
            // This two line will make the sideways border of the level.
            map[row][0] = '#';
            map[row][19] = '#';
            // This second loop will go from collum 1 to the collum 18, because the first (0) and the last (19) collums are already made by the previous lines.
            for (int collum = 1; collum <= 18; collum++) {
                // On each element the "randomNum" variable will be assigned with a random value between 1 and 40.
                randomNum = rand() % 40 + 1;
                /* If: 
                -randomNUm is equal to 1 (1 in 40 chances)
                -there is no player starting location already made
                -the row value is bigger than 8 ( the rows are counting from down to up )
                --> The element will be assigned with a player starting location symbol (1) and that will be counted*/
                if (randomNum == 1 && !player && row > 8) {
                    map[row][collum] = '1';
                    player = true;
                }
                /* If:
                -randomNum is equal to 2 (1 in 40 chances)
                -there is no level exit location already made
                -the row value is smaller or equal than 8
                --> The element will be assigned with a exit location symbol (X) and the element bellow will became a platform and that will be counted*/
                else if (randomNum == 2 && !exit && row <= 8) {
                    map[row][collum] = 'X';
                    map[row + 1][collum] = '-';
                    exit = true;
                }
                // Else the element isn't assigned to be a player starting or exit level location the folowing code will apply
                else {
                    // One EVERY 3 rows can have a chance to recive a platform, starting from row 3 (it counts from 0).
                    // Also one IN 3 collum will be a platform. 
                    if (row % 3 == 2 && randomNum % 3 == 0) {
                        map[row][collum] = '-';
                    }
                    else {
                        map[row][collum] = ' ';
                    }
                }
            }
        }
        // Checking if there isn't a level exit location, if there isn't, than there will be generated one in a preset location with a platform unerneeth
        if (!exit) {
            map[2][17] = 'X';
            map[3][17] = '-';
        }
        // Checking if there isn't a player location, if there isn't, there will be generated one in a preset location.
        if (!player) {
            map[13][3] = '1';
        }
        //END OF THE MAP GENERATION CODE

        //This 2 loops will read every element of the MAP and will output it.
        cout << "Level " << levelsGenerated << endl;
        for (int row = 0; row < 15; row++) {
            for (int collum = 0; collum < 20; collum++) {
                cout << map[row][collum] << " ";
            }
            cout <<endl;
        }
        cout << endl;
    }

    return 0;
}