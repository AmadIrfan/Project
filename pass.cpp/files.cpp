#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
void user_checker();
string parse(string row, int column);
void user_pass_way();
string userpass, username, uname, password;
int main()
{
    user_pass_way();
}
void user_pass_way()
{

    cout << endl
         << endl;
    cout << "\t \t \t Enter your User Name ... " << endl;
    cout << endl
         << endl;
    cin >> uname;
    cout << "\t \t \t Enter your pasword ... " << endl;
    cout << endl
         << endl;
    cin >> password;
    cout << endl
         << endl;
    user_checker();
}
void user_checker()
{
    fstream file;
    file.open("new_user.txt", ios::in);
    while (!file.eof())
    {
        string row;
        getline(file, row);

        username = parse(row, 3);
        userpass = parse(row, 4);
        if (username == uname && password == userpass)
        {
            break;
            cout << "amad ";
        }
    }
}
string parse(string row, int column)
{

    int commansCount = 1;
    string item;
    int index = 0;
    while (true)
    {

        char ch = row[index];
        if (ch == '\0')
            return item;
        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == column)
        {
            item = item + ch;
        }
        index++;
    }

    return item;
}