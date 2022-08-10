#include <iostream>
#include <ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;
enum direction { Top = 1, Down, Right,Left};  
// Struct for Map 
struct map
{ 
	int width, hight, fruitx, fruity; 
};
//-----------------------------------

// Struct for Snake
struct snake
{ 
	int headx, heady, taill; direction dir;
};
//-----------------------------------

// Struct for player
struct player 
{ 
	int score; bool lose; 
};
//-----------------------------------

// object from Struct
map map1; snake snake1; player player1;

// Function For Fruit (Randomly , Time)
void generate_fruit()
{
	srand(time(NULL));
	map1.fruitx = rand() % (map1.width - 2) + 1; // Create Fruit Inside Square (Width)
	map1.fruity = rand() % (map1.hight - 2) + 1; // Create Fruit Inside Square (Hight)
}

// Fuunction For Initialization Those Variable
void set()
{
	map1.width = 30;
	map1.hight = 20;
	generate_fruit();

	snake1.headx = map1.width / 2;    // the Snake Starts From The Middle  (Width)
	snake1.heady = map1.hight / 2;   //  the Snake Starts From The Middle  (Hight)
	snake1.taill = 0;

	player1.score = 0;            // Player's score First should be 0 and then it will increase
	player1.lose = false;
}

// Function For Drowing (Square , Fruit , Snake)
void draw()
{
	system("cls");              // To clear our screen and drow again

	cout << "  \n                        Directions\n ";
	cout << "                     ______________ \n\n   ";
	cout << "                      Top   = w \n                         Down  = s \n ";
	cout<<"                        Right = d \n                         Left  = a \n"; 
	cout << "                         Exit  = x \n\n";
	//This For Loop For Drowing The Square, Snake, and Fruit 
	for (int i = 0; i < map1.hight; i++)
    {
        for (int j = 0; j < map1.width; j++)
        {
			cout << " ";
			if (i == 0 || j == 0 || j == map1.width - 1 || i == map1.hight - 1) // Condition to drow Square Inside It Is Empty
				cout << "*";
			else if (i == snake1.heady && j == snake1.headx) cout << "o";  // drow Snake In The Middle Of Our Square
			else if (i == map1.fruity && j == map1.fruitx) cout << "0";   //  drow Fruit Randomly Inside Our Square
			else
                cout << " ";
        }
        cout << endl;
    }

}

// Function For Printing Player's Score
void print_score()
{
	cout << "\n                              GameOver\n\n";

	cout << "                        --------------------\n";
	cout << "                        | player score = " << player1.score <<" |" << "\n";
	cout << "                        --------------------\n\n";
}

// Function To move The Snake And the Fruit
void move()
{
	switch (snake1.dir)  // Check the Directions (W , S , D , A)
	{
	// If The Player Enter (W) The Snake will Decrease 1 From hight and move towords the Top Direction
	case Top:snake1.heady--; break;  
	// If The Player Enter (S) The Snake will Increase 1 From hight and move towords the Down Direction
	case Down:snake1.heady++; break;
	// If The Player Enter (D) The Snake will Increase 1 From Width and move towords the Right Direction
	case Right:snake1.headx++; break;
	// If The Player Enter (A) The Snake will Decrease 1 From Width and move towords the Left Direction
	case Left:snake1.headx--; break;
	}
	// Condition For Checking If the Snake Exceeds Our Squre The Player Will Lose
	if (snake1.heady >= map1.hight || snake1.heady <= 0 || snake1.headx >= map1.width || snake1.headx <= 0) player1.lose = true;
	// Condition For Checking If the Snake coordinates Match With The Fruit coordinates 
	// It Will Create Anthor Fruit And Increase The Player's Score By 1 
	if (snake1.heady == map1.fruity && snake1.headx == map1.fruitx) 
	{
		generate_fruit();
		player1.score += 1;
	}
}

// Function For Input The Direction (W , S, D , A)
void input()
{
	if (_kbhit())  // Condiction For Checking If The Player actually Enter The Char From The Keyboard 
	{
		char c = _getch(); // To Get The Char
		switch (c) // Check on our The Char (W , S , D , A)
		{
		case 'w': snake1.dir = Top; break;
		case 's': snake1.dir = Down; break;
		case 'd': snake1.dir = Right; break;
		case 'a': snake1.dir = Left; break;
		case 'x': exit(0);
		}
	}

}
void main()
{
	set();
	while (!player1.lose)
	{
		draw();
		input();
		move();
		Sleep(100);
	}
	print_score();
	system("pause");
}
