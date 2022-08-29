#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
string parse(string row, int column);

void checker();
string car_brand_name[10], car_color[10], car_model[10], car_e_number[10], ad_uname[10], car_rpd[10], car_status[10], car_conditions[10];
int main()

{
    checker();
    return 0;
}
void checker()
{
    fstream file;

    int idx = 0;
    file.open("cars.txt", ios::in);
    while (!file.eof())
    {
        string row;
        getline(file, row);
        car_brand_name[idx] = parse(row, 1);
        car_color[idx] = parse(row, 2);
        car_model[idx] = parse(row, 3);
        car_e_number[idx] = parse(row, 4);
        car_rpd[idx] = parse(row, 5);
        car_status[idx] = parse(row, 6);
        car_conditions[idx] = parse(row, 7);
        cout << car_brand_name[idx] << car_color[idx] << car_model[idx] << car_e_number[idx] << ad_uname[idx] << car_rpd[idx] << car_status[idx] << car_conditions[idx];
        idx++;
    }
    file.close();
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