#include <iostream>
using namespace std;                                                                                        // 1    2    3
char num[3][3] = { '1','2','3','4','5','6','7','8','9' };   // Array two Diamition Array      ====>        //  4    5    6
char player = 'X';      // Default player = 'X' He starts playing first                                   //   7    8    9

// Function to print out Array (Shape for XO Game)
void print_num()
{
    system("cls");               // Function For Clear Screen              
    cout << "                                                       ______                                                               \n";
    cout << "                    \\    /       ________             |      |     _______             |____________       _______         \n"; 
    cout << "                     \\  /       /        \\            |______|    |       |            |     |      |     |       |       \n";
    cout << "                      \\/       /          \\                  |    |       |            |     |      |     |_______|       \n";
    cout << "                      /\\       \\          /                  |    |_______|            |     |      |     |               \n";
    cout << "                     /  \\       \\________/                   |            \\            |     |      |     \\             \n";
    cout << "                    /    \\                             ______|             \\_____      |     |      |      \\________     \n";
    cout << "\n                 =====================================================================================================";
    cout << "\n\n\n                                                    ___________________\n";
    for (int i = 0; i < 3; i++)
    { 
        cout <<"\n" << "                                                   ";
        for (int j = 0; j < 3; j++)
        {
            cout << "   " << num[i][j]<<"   "<<"";
        }
        cout << "\n\n";
    }
    cout << "                                                    ___________________\n";
}

// Fuction For Playing 
void play()
{
    char pos;                     //position in our Array
    cout << "\n You are Player (" << player << ") " << " Choose The Position : ";
    cin >> pos;
    for (int i = 0; i < 3; i++)
    {
         for (int j = 0; j < 3; j++)
         {
            if (num[i][j] == pos)        // if Position exists in Our Array Then Write 'X' or 'O' in this Position 
            {
                num[i][j] = player;
            }
         }
    }
    if (player == 'X')   // After He Enter Position and Write 'X' or 'O' in this Position then we should replace our players
    player = 'O';       // 'X' replaces with 'O'
    else
    player = 'X';      // 'O' replaces with 'X'
}
// Fnction for knowing Who won
char win()
{
    int xc=0 , oc=0 , count=0;                                              // X  X  X --> WON         1  2  3             1  2  3
    // these for loops for rows              ====>>                        //  4  5  6                 X  X  X --> WON     1  2  3
    for (int i = 0; i < 3; i++)                                           //   7  8  9                 7  8  9             X  X  X --> WON
    {
        for (int j = 0; j < 3; j++)
        {
            if (num[i][j] != 'X' && num[i][j] != 'O') count++;
            if (num[i][j] == 'X') xc++;
            else if(num[i][j] == 'O') oc++;
            if (xc == 3 || oc == 3) { return xc > oc ? 'X' : 'O'; }

        }
        xc = 0; oc = 0;
    }                                                                       // X  2  3 --> WON         1  X  3             1  2  X
    // these for loops for Columns           ====>>                        //  X  5  6                 4  X  6 --> WON     1  2  X
    for (int i = 0; i < 3; i++)                                           //   X  8  9                 7  X  9             7  8  X --> WON
    {                                                         
        for (int j = 0; j < 3; j++)                          
        {                                                   
            if (num[j][i] == 'X') xc++;
            else if (num[j][i] == 'O') oc++;
            if (xc == 3 || oc == 3) { return xc > oc ? 'X' : 'O'; }

        }
        xc = 0; oc = 0;
    }                                                                                  // X  2  3 --> WON         1  2  X             
    // these for loops for Diameters         ====>>                                   //  4  X  6                 4  X  6 --> WON     
    if (num[0][0] == 'X' && num[1][1] == 'X' && num[2][2] == 'X') return'X';         //   7  8  X                 X  8  9           
    else if (num[0][0] == 'O' && num[1][1] == 'O' && num[2][2] == 'O') return'O';
    else if (num[0][2] == 'X' && num[1][1] == 'X' && num[2][0] == 'X') return'X';
    else if (num[0][2] == 'O' && num[1][1] == 'O' && num[2][0] == 'O') return'O';
    if (count == 0) return 'F';    // IF Function win() Returns 'F' that means 'Game over and No one won'
    return 'W';                   //  IF Function win() Returns 'W' that means 'Gmae is running and You should enter'
}
int main()
{
    while (win() == 'W')          // Game is running 
    {
        print_num();             // Call Function print_num() to print our Array (shape for XO game)
        play();                 // Call Function play() to play 
    }
    print_num();
    if (win() == 'F')             // If function win() retuens 'F' That means 'Game over and No one won'
    {
        cout << "Game Over : No one Won \n";
    }
    else
    {
        cout << "\n";
        cout << "                                                              -----\n";
        cout << "                                  Congratulation For Player :|  " << win() << "  | You have won \n"; // funtion win() should return 'X' or 'O'
        cout << "                                                              -----\n";
    }
    system("pause");
}

