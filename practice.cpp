#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()
{
    int total = 10;
    string all_car_brand_name[total], all_car_color[total], all_car_model[total], all_car_status[total], all_car_conditions[total], all_car_plate_number[total];
    for (int i = 0; i < 8; i++)
    {
        all_car_brand_name[i] = "amad";
        all_car_color[i] = "amad";
        all_car_model[i] = "amad";
        all_car_status[i] = "amad";
        all_car_conditions[i] = "amad";
        all_car_plate_number[i] = "amad";
        all_car_brand_name[i] = "amad";
    }
    for (int i = 0; i < 8; i++)
    {
        cout << i << all_car_model[i];
        cout << endl
             << all_car_color[i];
        cout << endl
             << all_car_status[i];
        cout << endl
             << all_car_conditions[i];
        cout << endl
             << all_car_plate_number[i];
    }

    all_car_brand_name[5] = "\0";
    all_car_color[5] = "\0";
    all_car_model[5] = "\0";
    all_car_status[5] = "\0";
    all_car_conditions[5] = "\0";
    all_car_plate_number[5] = "\0";
    for (int i = 5; i < 7; i++)
    {
        all_car_brand_name[i] = all_car_brand_name[i + 1];
        all_car_color[i] = all_car_color[i + 1];
        all_car_model[i] = all_car_model[i + 1];
        all_car_status[i] = all_car_status[i + 1];
        all_car_conditions[i] = all_car_conditions[1 + i];
        all_car_plate_number[i] = all_car_plate_number[i + 1];
    }
    for (int i = 0; i < 7; i++)
    {
        cout << i << all_car_brand_name[i] << endl;
        cout << all_car_color[i] << endl;
        cout << all_car_model[i] << endl;
        cout << all_car_status[i] << endl;
        cout << all_car_conditions[i] << endl;
        cout << all_car_plate_number[i] << endl;
    }

    return 0;
}