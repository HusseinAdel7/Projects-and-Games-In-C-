#include <iostream>
#include <windows.h> // This Lib For  ====>      Beep();  |and|  system("cls");
#include <conio.h>  //  This Lib For  ====>     _getch();
using namespace std;
int main()
{
    while (true) {
        cout << "Input note: ";
        char note = _getch(); // This Function To get the char from user 
                             //  But it don't show us our char on the screan 
        // First Row
        if (note == 'q' || note == 'Q') { Beep(200, 100); Sleep(20); }  // Beep(x,y);
        if (note == 'w' || note == 'W') { Beep(277, 100); Sleep(0); } //  x=Frequency of our sound 
        if (note == 'e' || note == 'E') { Beep(311, 100); Sleep(120); }//   Y= duration 
        if (note == 'r' || note == 'R') { Beep(340, 100); Sleep(90); }
        if (note == 't' || note == 'T') { Beep(370, 100); Sleep(160); }
        if (note == 'y' || note == 'Y') { Beep(415, 100); Sleep(240); }// Sleep(time in milsoc)
        if (note == 'u' || note == 'U') { Beep(466, 100); Sleep(270); }
        if (note == 'o' || note == 'O') { Beep(554, 100); Sleep(190); }
        if (note == 'i' || note == 'I') { Beep(590, 100); Sleep(120); }
        if (note == 'p' || note == 'P') { Beep(622, 100); Sleep(30); }
        if (note == '[') { Beep(740, 100); Sleep(130); }
        if (note == ']') { Beep(800, 100); Sleep(20); }

        // Second Row
        if (note == 'a' || note == 'A') { Beep(261, 100); Sleep(300); }
        if (note == 's' || note == 'S') { Beep(293, 100); Sleep(100); }
        if (note == 'd' || note == 'D') { Beep(329, 100); Sleep(40); }
        if (note == 'f' || note == 'F') { Beep(349, 100); Sleep(70); }
        if (note == 'g' || note == 'G') { Beep(392, 100); Sleep(120); }
        if (note == 'h' || note == 'H') { Beep(440, 100); Sleep(60); }
        if (note == 'j' || note == 'J') { Beep(493, 100); Sleep(90); }
        if (note == 'k' || note == 'K') { Beep(523, 100); Sleep(50); }
        if (note == 'l' || note == 'L') { Beep(587, 100); Sleep(80); }
        if (note == ';') { Beep(659, 100); Sleep(30); }
        if (note == '\'') { Beep(698, 100); Sleep(20); }
        if (note == '\\') { Beep(784, 100); Sleep(10); }

        // Third Row 
        if (note == 'z' || note == 'Z') { Beep(1000, 100); Sleep(300); }
        if (note == 'x' || note == 'X') { Beep(1300, 100); Sleep(100); }
        if (note == 'c' || note == 'C') { Beep(1400, 100); Sleep(40); }
        if (note == 'v' || note == 'V') { Beep(1500, 100); Sleep(70); }
        if (note == 'b' || note == 'B') { Beep(1800, 100); Sleep(120); }
        if (note == 'n' || note == 'N') { Beep(2000, 100); Sleep(60); }
        if (note == 'm' || note == 'M') { Beep(2200, 100); Sleep(90); }
        if (note == ',') { Beep(2400, 100); Sleep(50); }
        if (note == '.') { Beep(2700, 100); Sleep(80); }
        if (note == '/') { Beep(3000, 100); Sleep(30); }

        system("cls");               // This Function To clear our screen
    }
}