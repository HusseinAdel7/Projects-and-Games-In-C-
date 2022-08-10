#include <iostream>
#include<fstream>
#include<string>
using namespace std;
bool IsLoggedIn()
{
    string username, password, un, pw;
    cout << "Enter Your Username : "; cin >> username;
    cout << "Enter Your Password : "; cin >> password;
    ifstream read("E:\\Computer sceince\\ATM Logs" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password) { return true; }
    else { return false; }
}
int main()
{
    int choice;
    cout << "1- Register \n 2- Login \n choice : "; cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "Enter Your username :"; cin >> username;
        cout << "Enter Your Password : "; cin >> password;
        ofstream file;
        file.open("E:\\Computer sceince\\ATM Logs" + username + ".txt");
        file << username << endl << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();
        if (!status) { cout << "False Login \n"; system("pause "); return 0; }
        else { cout << "Successfully Login \n"; system("pause "); return 1; }
    }
}
