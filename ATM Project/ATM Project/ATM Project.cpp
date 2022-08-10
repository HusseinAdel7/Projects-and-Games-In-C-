#include <iostream>
#include<fstream>
#include<string>
using namespace std;
void IsLoggedIn()
{
    string username, password ,un, pw;
    int bl;
    cout << "Enter Your Username : "; cin >> username;
    cout << "Enter Your Password : "; cin >> password;
   
    ifstream read("E:\\Computer sceince\\ATMLOGS\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password) 
    {
        int x;
        cout << "*****************Menue*****************\n";
        cout << "1- Check Balance\n2- Deposit\n3- windrow\n";
        cout << "\n\n Enter Your Operation that you need : "; cin >> x;
        if (x == 1)
        {
            ifstream read("E:\\Computer sceince\\ATMLOGS\\" + username + ".txt");
            string s;
            for (int i = 0; i <= 2; i++)
            {
                getline(read, s);
            } 
            cout << "Your Balance is : " << s<<"\n";
        }
        else if (x == 3)
        { 
            string w,b;
            int m=0, e;
            cout << "Enter You Balance : ";
            cin >> b;
            ofstream file;
            ifstream g;
            file.open("E:\\Computer sceince\\ATMLOGS\\" + username + ".txt",ios::app);
            for (int i = 0; i <= 2; i++)
            {
                if (i == 2)
                {
                    g >> w;
                    cout << w;

                }
                
            }
        }
        else if (x == 3) { cout << "widrow\n"; }
        else { cout << "Invalid Operation\n"; }
        ifstream read("E:\\Computer sceince\\ATMLOGS\\" + username + ".txt");
    }

    else { cout << "Invalid Username Or Password\n"; }
}
int main()
{
    int choice;
    cout << "1- Register \n2- Login \nchoice : "; cin >> choice;
    if (choice == 1)
    {
        string name, password;
        int balance=0;
        cout << "Hello This is the first time please Enter Your Information :- \n";
        cout << "Enter Your Name  :"; cin >> name;
        cout << "Enter a Password : "; cin >> password;
        
        ofstream file;
        file.open("E:\\Computer sceince\\ATMLOGS\\" + name + ".txt");
        file << name << endl << password << endl << balance;
       
        file.close();
        main();
    }
    else if (choice == 2)
    {
        IsLoggedIn();
    }
}
