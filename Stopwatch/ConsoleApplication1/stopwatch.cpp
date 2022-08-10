
#include <iostream>
#include <Windows.h> // in linux: sleep()

// #include <windows.h> // in windows: Sleep()


using namespace std;


void displayTime(int hours, int minutes, int seconds,int milesecond) {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "                                                    H    :   M    :    S    :    MS\n\n";
    cout <<"                                                    " << hours << "    :   " 
        << minutes << "    :    "
        << seconds << "    :    "
        << milesecond << endl;
}

int main() {
    int hour = 0;
    int min = 0;
    int sec = 0;
    int mils = 0;

    while (true)
    {
        Sleep(0.1);

        mils++;

        if (mils > 100) {
            sec++;
            mils = 0;
        }
         
        if (sec > 59) {
            min++;
            sec = 0;
            mils = 0;
        }
        if (min > 59) {
            hour++;
            sec = 0;
            min = 0;
            mils = 0;
        }


        displayTime(hour, min, sec,mils);
    }
}