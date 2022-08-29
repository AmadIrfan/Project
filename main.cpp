#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;
// functions
void manu_top1();
int main_manu();
int user_manu();
int existing_user_manu();
int admin_manu();
void add_admin();
void add_driver();
void customer();
void lines();
void sort_car_data();
void user_pass_way();
void admin_pass_way();
void newperson();
void user_checker();
void admin_checker();
void return_car_data();
void return_driver_data();
string parse(string row, int column);
string parse(string row, int column);
void privious_manu();
void in_condition_of_wrong_password();
void continues();
void add_cars();
void admin_load_data();
void user_load_data();
void save_continue();
void tearms();
void put_data();
void init_array();
void delete_admin_cars(int num_ad);
void load_data();
const int total = 100;
const int num_admin = 5;
// arrays
string driver_id[total], driver_cnic[total], driver_fname[total], driver_lname[total], driver_city[total], driver_age[total];
string car_brand_name[total], car_color[total], car_model[total], car_status[total], car_conditions[total], car_plate_number[total];
string user_fname[total], user_uname[total], user_lname[total], user_pass[total], user_gender[total], user_city[total], user_adress[total];
string ad_fname[num_admin], ad_id[num_admin], ad_uname[num_admin], ad_pass[num_admin], ad_lname[num_admin], ad_city[num_admin], ad_gender[num_admin];
string car_rpd[total];
int car_rpd_int[total];
// global variables
string id, uname, password, username, userpass;
int cars = 0, driver = 0, admin = 0, user = 0;
int main()
{

     // functions
     load_data();
         put_data();
     sort_car_data();
     return_car_data();
     init_array();
     // variable decleration inside main
     int input = 0, user_input = 0, user_internal_input = 0, admin_input = 0, cont, no;
     char press;
     system("cls");
     // main manu
     // (input < 4 ) condition is use to terminate program if user enter 5
     while (input < 4)
     {
          input = main_manu();
          load_data();
          if (input == 1) //  main manu condition 1 starts.
          {
               user_input = 0;
               while (user_input < 3)
               {
                    user_input = user_manu();
                    // user input 1 to creat account
                    if (user_input == 1)
                    {
                         manu_top1();
                         cout << "                              Are you sure " << endl;
                         cout << "\n                Press any key to Continue to create account ";
                         getch();
                         manu_top1();
                         newperson();
                         continues();
                    }
                    //  user input 2 for existing user
                    if (user_input == 2)
                    {
                         manu_top1();
                         continues();
                         user_pass_way();

                         // correct password
                         if (username == uname && password == userpass)
                         {
                              user_internal_input = 0;
                              while (user_internal_input < 5)
                              {
                                   user_internal_input = existing_user_manu();
                                   // user_input to watch all cars
                                   return_car_data();
                                   if (user_internal_input == 1)
                                   {
                                        manu_top1();
                                        cout << " Main Manu > User Manu > All cars" << endl;
                                        lines();
                                        cout << endl
                                             << endl;
                                        if (car_brand_name[0] == "\0")
                                        {
                                             cout << "you have no availabile cars "<<endl;
                                             continues();
                                        }
                                        else
                                        {
                                             cout << "Sr.No \t brand_name \t Color \t model \t Number plate \t Status \t RPD \t condition " << endl;
                                             for (int idx = 0; idx < cars; idx++)
                                             {
                                                  cout << (idx + 1) << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
                                             }
                                             cout << endl
                                                  << endl;
                                             continues();
                                        }
                                   }
                                   // user_input to book a cars
                                   if (user_internal_input == 2)
                                   {
                                        int day, total_payment;
                                        manu_top1();
                                        cout << " Main Manu > User Manu > Booking car" << endl;
                                        lines();
                                        cout << endl
                                             << endl;
                                        if (car_brand_name[1] == "\0")
                                        {
                                             cout << "you have no availible cars " << endl;
                                             continues();
                                        }
                                        else
                                        {
                                             cout << "Sr.No \t brand_name \t Color \t model \t number Plate \t status \t RPD \t condition" << endl;
                                             for (int idx = 0; idx < cars; idx++)
                                             {
                                                  cout << (idx + 1) << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
                                             }
                                             cout << endl
                                                  << endl;
                                             cout << "                   are you sure to book car" << endl;
                                             cout << "                   Press (y/Y) to Book a car" << endl;
                                             cout << "                   Press (N/n) to cancal Booking" << endl;
                                             cin >> press;
                                             if (press == 'y' || press == 'Y')
                                             {
                                                  cout << endl
                                                       << endl;
                                                  cout << "    Enter Sr.no to continue.... " << endl;
                                                  cin >> no;
                                                  cout << endl;
                                                  continues();
                                                  cout << endl;
                                                  if (car_status[no - 1] == "Booked" || car_status[no - 1] == "booked" || car_status[no - 1] == "BOOKED")
                                                  {
                                                       cout << "Your selected car is already booked please choose another cars..." << endl;
                                                  }
                                                  else
                                                  {
                                                       cout << "Sr.No \t brand_name \t Color \t model \t number Plate \t status \t RPD \t condition" << endl;
                                                       cout << no << "\t" << car_brand_name[no - 1] << "\t" << car_color[no - 1] << "\t" << car_model[no - 1] << "\t" << car_plate_number[no - 1] << "\t" << car_status[no - 1] << "\t" << car_rpd[no - 1] << "\t" << car_conditions[no - 1] << "\t" << endl;
                                                       cout << "Enter number of days you want to enter \n";
                                                       cin >> day;
                                                       total_payment = day * stoi(car_rpd[no - 1]);
                                                       cout << "You have to pay total " << total_payment << "/- rupees for booking this car ";
                                                  }
                                             }
                                             if (press == 'N' || press == 'n')
                                             {
                                                  cout << endl
                                                       << endl
                                                       << "                 Thank you ! to choose our servise..";
                                             }
                                             cout << endl;
                                             continues();
                                        }
                                   }
                                   // user_input to privious record
                                   if (user_internal_input == 3)
                                   {
                                        manu_top1();
                                        cout << "Main Manu > User Manu > Privious Record" << endl;
                                        lines();
                                        cout << endl
                                             << endl;
                                        cout << "Sr.No \t brand_name \t Color \t model \t number Plate \t status \t RPD \t condition" << endl;
                                        cout << no << "\t" << car_brand_name[no - 1] << "\t" << car_color[no - 1] << "\t" << car_model[no - 1] << "\t" << car_plate_number[no - 1] << "\t" << car_status[no - 1] << "\t" << car_rpd[no - 1] << "\t" << car_conditions[no - 1] << "\t" << endl;
                                        cout << endl
                                             << endl;
                                        cout << endl
                                             << endl;
                                        continues();
                                   }
                                   if (user_internal_input == 4)
                                   {
                                        int no;
                                        char press;
                                        manu_top1();
                                        cout << " Main Manu > User Manu > Booking car" << endl;
                                        lines();
                                        cout << "Sr.No  \t\t driver_id\t\tdriver_fname\t\tdriver_lnamet\tdriver_age\t\t driver_cnic \t\t driver_city" << endl;
                                        return_driver_data();
                                        cout << "                   are you sure to hire driver" << endl;
                                        cout << "                   Press (y/Y) to hire a driver" << endl;
                                        cout << "                   Press (N/n) to cancal hiring" << endl;
                                        cin >> press;
                                        if (press == 'y' || press == 'Y')
                                        {
                                             cout << endl
                                                  << endl;
                                             cout << "    Enter Sr.no to continue.... " << endl;
                                             cin >> no;
                                             cout << "Sr.No  \t\t driver_id\t\tdriver_fname\t\tdriver_lname\t\tdriver_age\t\t driver_cnic\t\t driver_city" << endl;
                                             cout << no << "\t\t" << driver_id[no] << "\t\t" << driver_fname[no] << "\t\t" << driver_lname[no] << "\t\t" << driver_age[no] << "\t\t" << driver_cnic[no] << "\t\t" << driver_city[no] << endl;
                                             cout << endl;
                                             cout << "thank you for Hiring a Driver \n";
                                             continues();
                                             cout << endl;
                                        }
                                        if (press == 'n' || press == 'N')
                                        {
                                             cout << endl
                                                  << endl;
                                             cout << endl;
                                             continues();
                                             cout << endl;
                                        }

                                        // user_input to log out user manu
                                        if (user_internal_input == 5)
                                        {
                                             manu_top1();
                                             cout << "                                  Are you sure to log out " << endl;
                                             // continues();
                                             getch();
                                        }
                                   }
                              }
                              // wrong password
                              if (username != uname && password != userpass)
                              {
                                   cout << endl
                                        << endl;
                                   cout << "                                       You Entered wrong ID or PASSWORD " << endl
                                        << endl;
                                   cout << "                                         Press any key to Continue ";
                                   getch();
                                   system("cls");
                                   manu_top1();
                                   cout << "Main Manu > user * " << endl;
                                   lines();
                                   user_pass_way();
                                   continues();
                              }
                         } // user_input to exit user module to main menu
                         if (user_input == 3)
                         {
                              manu_top1();
                              cout << "                    Are you sure " << endl;
                              continues();
                         }
                    }
               }
          }

          // user module condition end here
          // input 2 for admin modules condition start here
          if (input == 2)
          {
               manu_top1();
               cout << "Main Manu > admin login page  " << endl;
               lines();
               admin_pass_way();
               continues();
               // If User Enter correct Password
               if ((username == uname && password == userpass) || (uname == "uet" && password == "uet"))
               // if (uname == "uet" && password == "uet")
               {
                    admin_input = 0;
                    while (admin_input < 8)
                    {
                         admin_input = admin_manu();
                         // admin_input 1 for add admin
                         if (admin_input == 1)
                         {
                              manu_top1();
                              cout << "                    Are you sure " << endl;
                              continues();
                              manu_top1();
                              add_admin();

                              privious_manu();
                         }
                         // admin_input for add cars
                         if (admin_input == 2)
                         {
                              manu_top1();
                              cout << " Main Manu > Admin > add cars " << endl;
                              lines();
                              add_cars();
                              cout << endl
                                   << endl;
                              continues();
                         }
                         // admin_input
                         if (admin_input == 3)
                         {
                              manu_top1();
                              cout << " Main Manu > Admin > Delete cars" << endl;
                              lines();
                              cout << endl;
                              cout << "\n  Sr.No \t brand_name \t COLOR \t model \t number plate \t status \t RPD \t condition " << endl;
                              for (int idx = 0; idx < cars; idx++)
                              {
                                   cout << (idx + 1) << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
                              }
                              cout << endl
                                   << endl;
                              cout << "                   are you sure to delete car" << endl;
                              cout << "                   Press (y/Y) to delete a car" << endl;
                              cout << "                   Press (N/n) to cancal" << endl;
                              cin >> press;
                              if (press == 'y' || press == 'Y')
                              {
                                   int srno, num_ad;
                                   cout << "Enter sr no to delete car ";
                                   cin >> srno;
                                   num_ad = srno - 1;
                                   cout << srno << "\t" << car_brand_name[num_ad] << "\t" << car_color[num_ad] << "\t" << car_model[num_ad] << "\t" << car_plate_number[num_ad] << "\t" << car_status[num_ad] << "\t" << car_rpd[num_ad] << "\t" << car_conditions[num_ad] << "\t" << endl;
                                   car_color[num_ad] = "\0";
                                   car_model[num_ad] = "\0";
                                   car_plate_number[num_ad] = "\0";
                                   car_status[num_ad] = "\0";
                                   car_rpd[num_ad] = "\0";
                                   car_conditions[num_ad] = "\0";
                                   delete_admin_cars(num_ad);
                                   cout << endl;
                                   for (int idx = 0; idx < cars; idx++)
                                   {
                                        cout << (idx + 1) << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
                                   }
                                   // continues();
                              }
                              if (press == 'n' || press == 'N')
                              {
                                   continues();
                                   cout << endl;
                              }
                              privious_manu();
                         }
                         // admin_input
                         if (admin_input == 5)
                         {
                              add_driver();
                              privious_manu();
                         }
                         // admin_input to show user and admin
                         if (admin_input == 4)
                         {
                              manu_top1();
                              cout << " Main Manu > Admin > Users" << endl;
                              lines();
                              cout << "(No) \t first_name \t last_name \t user_name \t user_city \t user_gender \t user_adress "
                                   << endl;
                              user_load_data();
                              cout << endl
                                   << endl
                                   << endl;
                              cout << " Main Manu > Admin > Admin " << endl;
                              lines();
                              cout << endl
                                   << endl;
                              cout << "(NO)\t admin_ID \t admin_fname \t admin_lname \t admin_uname \t admin_gender \t admin_city \tAdd-date" << endl;
                              admin_load_data();
                              cout << endl
                                   << endl;
                              privious_manu();
                         }
                         // admin_input to show all cars
                         if (admin_input == 6)
                         {
                              manu_top1();
                              cout << " Main Manu > Admin > Show All Cars " << endl;
                              lines();
                              cout << "Sr.No \t brand_name \t COLOR \t model \t engin_number \t status \t RPD \t condition" << endl;
                              for (int idx = 0; idx < cars; idx++)
                              {
                                   cout << (idx + 1) << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
                              }
                              cout << endl
                                   << endl;
                              privious_manu();
                         }
                         if (admin_input == 7)
                         {
                              manu_top1();
                              cout << " Main Manu > Admin > generate report" << endl;
                              lines();
                              cout << "All cars >>" << endl;
                              lines();
                              cout << "Sr.No \t brand_name \t COLOR \t model \t engin_number \t status \t RPD \t condition" << endl;
                              for (int idx = 0; idx < (cars); idx++)
                              {
                                   cout << idx + 1
                                        << "\t"
                                        << car_brand_name[idx]
                                        << "\t"
                                        << car_color[idx]
                                        << "\t"
                                        << car_model[idx]
                                        << "\t"
                                        << car_plate_number[idx]
                                        << "\t"
                                        << car_status[idx]
                                        << "\t"
                                        << car_rpd[idx]
                                        << "\t"
                                        << car_conditions[idx]
                                        << endl;
                              }
                              cout << "All Users >>" << endl;
                              lines();
                              cout << "Sr.no\t first_name \t last_name \t user_name \t user_city \t user_gender \t user_adress "
                                   << endl;

                              user_load_data();
                              cout << endl
                                   << endl;
                              continues();
                              getch();
                         }

                         // admin_input 8 to exit from admin modules
                         if (admin_input == 8)
                         {
                              manu_top1();
                              cout << endl
                                   << endl
                                   << endl
                                   << endl;
                              cout << "                    Are you sure you want to log out" << endl;
                              continues();
                         }
                    }
               }
               // if user enter wrong password
               if (username != uname && password != userpass)
               {
                    manu_top1();
                    in_condition_of_wrong_password();
                    getch();
                    manu_top1();
                    cout << "Main Manu > admin login page  " << endl;
                    lines();
                    cout << endl
                         << endl;
                    admin_pass_way();
                    cout
                        << "\t \t Press any key to Continue  ";
                    getch();
                    cout << endl
                         << endl;
               }
          }
          // condition 3 ended here
          if (input == 4)
          { // if user press 4 condition 4 starts here  [(4) : Terms & Conditions]
               manu_top1();
               tearms();
               continues();
          } //  condition 4 ends here
     }
     put_data();
     sort_car_data();
}

// (input < 5 ) condition is use to terminate program if user enter 5
// function for main menu
int main_manu()
{
     manu_top1();
     int input;
     cout << endl
          << endl
          << endl;
     cout << "Main Manu > " << endl;
     lines();
     cout << endl
          << endl;
     cout << "(1) : Users Modules" << endl;
     cout << "(2) : Admin modules" << endl;
     cout << "(3) : Terms & Conditions" << endl;
     cout << "(4) : Exit";
     cout << endl
          << endl;
     cout << "INPUT : ";
     cin >> input;
     return input;
}
// function for admin_manu()
int admin_manu()
{
     int admin_input;
     manu_top1();
     cout << " Main Manu > Admin" << endl;
     lines();
     cout << "(1) : ADD Admin" << endl;
     cout << "(2) : Add Cars" << endl;
     cout << "(3) : Delete Cars" << endl;
     cout << "(4) : Show Users & Admin" << endl;
     cout << "(5) : Add Drivers." << endl;
     cout << "(6) : Show All Cars" << endl;
     cout << "(7) : Generate Reports" << endl;
     cout << "(8) : Log Out" << endl;
     cout << endl
          << endl;
     cout << "INPUT : ";
     cin >> admin_input;
     return admin_input;
}
// function for user menu
int user_manu()
{
     int user_input;
     manu_top1();
     cout << " Main Manu > user" << endl;
     lines();
     cout << "Main Manu > User" << endl;
     cout << "(1) : Create New Account" << endl;
     cout << "(2) : Existing" << endl;
     cout << "(3) : Main Manu" << endl;
     cout << endl
          << endl;
     cout << "INPUT : ";
     cin >> user_input;
     return user_input;
}
// function for existing user manu
int existing_user_manu()
{
     int user_internal_input;
     manu_top1();
     cout << "Main Manu > User * " << endl;
     lines();
     cout << " Dashbord :--- ";
     cout << endl
          << endl
          << "(1). Show all availbile cars " << endl;
     cout << "(2). Book a car " << endl;
     cout << "(3). Privious record " << endl;
     cout << "(4). Hire Driver " << endl;
     cout << "(5). Log out " << endl;
     cout << endl
          << endl
          << "    Enter your choise continue.... ";
     cin >> user_internal_input;
     return user_internal_input;
}
// function for menu header
void manu_top1()
{
     system("cls");
     cout << "                                                                                        ___                ___                               " << endl;
     cout << "                           _______ _______ ___________    __________________  _______  /  /____________ __/  /                               " << endl;
     cout << "                          /   ___ /  ____   /  ______/   /  ________/    _  \\/  ___  \\/   __/ /  _____   /  /                              " << endl;
     cout << "                         /  /___ /  /___/  /  /         /  /       /     __ /  /  /  /  /____/  /____/  /  /____                             " << endl;
     cout << "                         \\______ \\_____^__/__/         /__/        \\_______/  /  /  /\\______/\\______^__/\\______/                       " << endl;
     cout << "                                                                                                                                             " << endl;
     cout << "                                                                            ___                                                              " << endl;
     cout << "                                                __________     ___________ /  /__________________   ____                                     " << endl;
     cout << "                                               / ______/ /    / / ________/  ___/   __   /   /___ '  ___\\                                   " << endl;
     cout << "                                              ( ____  / /____/ ( ______  /  /__/ /_____ /   /   /   /   /                                    " << endl;
     cout << "                                             /_______/\\_______/_________/_____/\\_______/___/   /___/   /                                   " << endl;
     cout << "                                                      ______ /                                                                               " << endl;
     cout << "                                                     /______/                                                                                " << endl;
     cout << "                                                                                                                                             " << endl;
     cout << endl
          << endl
          << endl;
}
// function for  lines after logo
void lines()
{
     cout << "> ";
     for (int i = 0; i < 40; i++)
     {
          cout << "-";
     }
     cout << endl
          << endl;
}
// function for password to enter in admin driver and user menu
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
     file.open("user.txt", ios::in);
     while (!file.eof())
     {
          string row;
          getline(file, row);

          username = parse(row, 3);
          userpass = parse(row, 4);
          if (username == uname && password == userpass)
          {
               break;
          }
     }
}

void admin_pass_way()
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
     admin_checker();
}
void admin_checker()
{
     fstream file;
     file.open("admin.txt", ios::in);
     while (!file.eof())
     {
          string row;
          getline(file, row);

          username = parse(row, 4);
          userpass = parse(row, 5);
          if (username == uname && password == userpass)
          {
               break;
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
// function for create new user account
void newperson()
{
     fstream file;

     cout << "                                Enter your first name: (e.g is Ahmad)" << endl;
     cin >> user_fname[user];
     cout << "                                Enter your Last name: (e.g is Ahmad)" << endl;
     cin >> user_lname[user];
     cout << "                                Enter User name:(e.g is Amad123) " << endl;
     cin >> user_uname[user];
     cout << "                                Enter password (password consist on atleast 4)" << endl;
     cin >> user_pass[user];
     cout << "                                Enter your  Gender: (male/female)" << endl;
     cin >> user_gender[user];
     cout << "                                Enter your  city: " << endl;
     cin >> user_city[user];
     cout << "                                Enter your Adress: " << endl;
     cin >> user_adress[user];
     cout << endl
          << endl;

     file.open("user.txt", ios::app);
     file << user_fname[user] << "," << user_lname[user] << "," << user_uname[user] << "," << user_pass[user] << "," << user_gender[user] << "," << user_city[user] << "," << user_adress[user] << "," << endl;
     file.close();
     user++;
}

// function for add admin
void add_admin()
{
     fstream file;
     cout << " Main Manu > Admin >Add admin " << endl;
     lines();
     if (admin < 5)
     {
          cout << "Enter Admin ID " << endl;
          cin >> ad_id[admin];
          cout << "Enter Admin first Name " << endl;
          cin >> ad_fname[admin];
          cout << "Enter Admin last Name " << endl;
          cin >> ad_lname[admin];
          cout << "Enter Admin user Name " << endl;
          cin >> ad_uname[admin];
          cout << "Enter Admin Password " << endl;
          cin >> ad_pass[admin];
          cout << "Enter admin city " << endl;
          cin >> ad_city[admin];
          cout << "Enter Admin gender " << endl;
          cin >> ad_gender[admin];
          cout << endl
               << endl;
          file.open("admin.txt", ios::app);
          file << ad_id[admin] << "," << ad_fname[admin] << "," << ad_lname[admin] << "," << ad_uname[admin] << "," << ad_pass[admin] << "," << ad_city[admin] << "," << ad_gender[admin] << "," << endl;
          file.close();
          admin++;
     }
     else
     {
          cout << "You Entered 5 admins so you cannot add new admin ";
     }
}
// function for add driver
void add_driver()
{
     fstream file;
     cout << " Main Manu > Admin >Add Driver " << endl;
     lines();

     cout << "Enter driver ID " << endl;
     cin >> driver_id[driver];
     cout << "Enter driver first Name " << endl;
     cin >> driver_fname[driver];
     cout << "Enter driver last Name " << endl;
     cin >> driver_lname[driver];
     cout << "Enter driver age Name " << endl;
     cin >> driver_age[driver];
     cout << "Enter driver CNIC " << endl;
     cin >> driver_cnic[driver];
     cout << "Enter driver city " << endl;
     cin >> driver_city[driver];
     cout << endl
          << endl;
     file.open("driver.txt", ios::app);
     file << driver_id[driver] << "," << driver_fname[driver] << "," << driver_lname[driver] << "," << driver_age[driver] << "," << driver_cnic[driver] << "," << driver_city[driver] << "," << endl;
     file.close();
     driver++;
}
void return_driver_data()
{
     fstream file;
     int idx = 0, num;
     file.open("driver.txt", ios::in);
     if (!file)
     {
          return;
     }
     while (!file.eof())
     {
          num = idx + 1;
          string row;
          getline(file, row);
          driver_id[idx] = parse(row, 1);
          driver_fname[idx] = parse(row, 2);
          driver_lname[idx] = parse(row, 3);
          driver_age[idx] = parse(row, 4);
          driver_cnic[idx] = parse(row, 5);
          driver_city[idx] = (parse(row, 6));
          cout << num << "\t\t" << driver_id[idx] << "\t\t" << driver_fname[idx] << "\t\t" << driver_lname[idx] << "\t\t" << driver_age[idx] << "\t\t" << driver_cnic[idx] << "\t\t" << driver_city[idx] << endl;
          idx++;
     }
     file.close();
}

// function for add cars by user
void add_cars()
{
     fstream file;
     int num_cars;
     cout << " Main Manu > Admin >Add cars " << endl;
     cout << "Enter the number of cars you want to Enter ";
     cin >> num_cars;
     lines();
     for (int c = 0; c < num_cars; c++)
     {
          cout << "Enter brand name " << endl;
          cin >> car_brand_name[cars];
          cout << "Enter ar colour " << endl;
          cin >> car_color[cars];
          cout << "Enter car model " << endl;
          cin >> car_model[cars];
          cout << "Enter car number plate " << endl;
          cin >> car_plate_number[cars];
          cout << "Enter rate per days" << endl;
          cin >> car_rpd[cars];
          cout << "Enter Car status " << endl;
          cin >> car_status[cars];
          cout << "Enter car conditions " << endl;
          cin >> car_conditions[cars];
          cout << endl
               << endl;
          file.open("cars.txt", ios::app);
          file << car_brand_name[cars] << "," << car_color[cars] << "," << car_model[cars] << "," << car_plate_number[cars] << "," << car_rpd[cars] << "," << car_status[cars] << "," << car_conditions[cars] << "," << endl;
          file.close();
          cars++;
     }
}

// function for go to privious menu by using getch() function
void privious_manu()
{

     cout << "                                         Press any key for Privious manu ";
     getch();
}
// function for go to privious menu by using getch() function in condition of wrong password
void in_condition_of_wrong_password()
{
     cout << "                                       You Entered wrong ID or PASSWORD " << endl;
     cout << "                                         Press any key to Continue ";
     getch();
}
// function for continue
void continues()
{
     cout << "Press any key to Continue.....";
     getch();
}
// function for save and continue
void save_continue()
{
     cout << "Press any key to save and Continue...";
     getch();
}
// function for tearms and conditions
void tearms()
{
     cout << endl
          << endl
          << endl;
     cout << "Main Manu > Terms & Condition " << endl;
     lines();
     cout << endl
          << endl;
     cout << " Rental Terms and Conditions ";

     cout << "THESE TERMS AND CONDITIONS CONTAIN A BINDING ARBITRATION CLAUSE AND CLASS ACTION WAIVER THAT IMPACT YOUR RIGHTS ABOUT HOW TO RESOLVE DISPUTES. PLEASE READ THIS PROVISION CAREFULLY.\n";

     cout << "1. The Rental Agreement. These Rental Terms and Conditions, the rental document you receive when you are given access to the car you are renting (the  Rental Contract ) any additional agreement signed by you, any documents or agreements (or links to on-line documents or agreements) sent to you electronically in connection with your rental, the Privacy Notice, and the return receipt or record (the  Rental Receipt ) with computed rental charges together constitute the  Rental Agreement  between yourself and Avis Rent A Car System, LLC, or the independent Avis System Licensee identified on the Rental Contract (“Avis”).\n";

     cout << "2. Your Rental. You rent from Avis the car described on the Rental Contract, which rental is solely a transfer of possession, and not of drivership. You agree to the terms in the Rental Agreement provided any such term is not prohibited by the law of a jurisdiction covering this rental, in which case such law controls. “You” and “your” refer to the person who signs this agreement, “we”, “our” and “us” refer to Avis. You also agree that you are not our agent for any purpose; and that you cannot assign delegate  transfer your obligations under the Rental Agreement and any discrete part thereof.\n";

     cout
         << "  3. Changes.Any change in the Rental Agreement or our rights must be in writing and signed by an authorized Avis officer.You further agree that we have the unilateral right to change these Terms and Conditions from time to time either upon written notice to you, in paper or electronic form, or upon our posting such changes on the Avis web site.Such changes will apply to rentals that you reserve after such notice has been given, as indicated by the date of such notice, if sent in written form, or the date such changes are posted on the Avis web site, which date will be indicated therein, without any requirement by you to sign the changed Terms and Conditions.Changes to these Terms and Conditions will be posted as they occur on the Avis web site at www.Avis.com and will govern all rentals commencing after posting even if the terms provided at time of reserving the rental car are different.\n";
     cout << "4. Meaning of Car.The word car in the Rental Agreement means the vehicle rented to you or its replacement and includes tires,tools,keys,key fobs, equipment, included and optional accessories, plates, documents, and any other products or property provided by Avis with the vehicle and separately rented to you by Avis unless otherwise explicitly specified in the Rental Agreement.\n ";
}
void return_car_data()
{
     fstream file;
     int idx = 0, num;
     file.open("cars.txt", ios::in);
     if (!file)
     {
          return;
     }         

     while (!file.eof())
     {
          num = idx + 1;
          string row;
          getline(file, row);
          car_brand_name[idx] = parse(row, 1);
          car_color[idx] = parse(row, 2);
          car_model[idx] = parse(row, 3);
          car_plate_number[idx] = parse(row, 4);
          car_rpd[idx] = (parse(row, 5));
          car_status[idx] = parse(row, 6);
          car_conditions[idx] = parse(row, 7);
   //       cout << num << "\t\t" << car_brand_name[idx] << "\t\t" << car_color[idx] << "\t\t" << car_model[idx] << "\t\t" << car_plate_number[idx] << "\t\t" << car_rpd[idx] << "\t\t" << car_status[idx] << "\t\t" << car_conditions[idx] << "\t\t" << endl;
          idx++;
     }
     file.close();
}

void put_data()
{
     fstream file;
     file.open("number of cars.txt", ios::out);
     file << cars;
     file.close();
     file.open("number of admin.txt", ios::out);
     file << admin;
     file.close();
     file.open("number of users.txt", ios::in);
     file >> user;
     file.close();
     file.open("number of Drivers.txt", ios::in);
     file >> driver;
     file.close();
}
void load_data()
{
     fstream file;
     file.open("number of cars.txt", ios::in);
     file >> cars;
     file.close();
     file.open("number of admin.txt", ios::in);
     file >> admin;
     file.close();
     file.open("number of users.txt", ios::in);
     file >> user;
     file.close();
     file.open("number of Drivers.txt", ios::in);
     file >> driver;
     file.close();
}
void admin_load_data()
{
     int idx = 0, num;
     fstream file;
     file.open("admin.txt", ios::in);
     if (!file)
          return;
     while (!file.eof())
     {
          num = idx + 1;
          string row;
          getline(file, row);
          ad_id[idx] = parse(row, 1);
          ad_fname[idx] = parse(row, 2);
          ad_lname[idx] = parse(row, 3);
          ad_uname[idx] = parse(row, 4);
          ad_pass[idx] = parse(row, 5);
          ad_city[idx] = parse(row, 6);
          ad_gender[idx] = parse(row, 7);
          cout << num << "\t\t" << ad_id[idx] << "\t\t" << ad_fname[idx] << "\t\t" << ad_lname[idx] << "\t\t" << ad_uname[idx] << "\t\t" << ad_city[idx] << "\t\t" << ad_gender[idx] << endl;
          idx++;
     }
     file.close();
}
void user_load_data()
{
     int idx = 0, num;
     fstream file;
     file.open("user.txt", ios::in);
     if (!file)
          return;
     while (!file.eof())
     {
          num = idx + 1;
          string row;
          getline(file, row);
          user_fname[idx] = parse(row, 1);
          user_lname[idx] = parse(row, 2);
          user_uname[idx] = parse(row, 3);
          user_pass[idx] = parse(row, 4);
          user_city[idx] = parse(row, 5);
          user_gender[idx] = parse(row, 6);
          user_adress[idx] = parse(row, 7);
          cout << num << "\t" << user_fname[idx] << "\t\t" << user_lname[idx] << "\t\t" << user_uname[idx] << "\t\t" << user_gender[idx] << "\t\t" << user_city[idx] << "\t\t" << user_adress[idx] << endl;
          idx++;
     }
     file.close();
}
void init_array()
{
     for (int i = 0; i < total; i++)
     {
          car_brand_name[i] = "\0";
          car_color[i] = "\0";
          car_conditions[i] = "\0";
          car_status[i] = "\0";
          car_rpd[i] = "\0";
          car_model[i] = "\0";
          car_plate_number[i] = "\0";
     }
}
void delete_admin_cars(int num_ad)
{
     fstream file;
     for (int i = num_ad; i < cars; i++)
     {
          car_brand_name[i] = car_brand_name[i + 1];
          car_color[i] = car_color[i + 1];
          car_model[i] = car_model[i + 1];
          car_status[i] = car_status[i + 1];
          car_conditions[i] = car_conditions[1 + i];
          car_plate_number[i] = car_plate_number[i + 1];
     }
     cout << "Delete data seccesfully ";
     cars--;
     file.open("cars.txt", ios::out);
     file.clear();
     for (int i = 0; i < cars; i++)
     {
          file << car_brand_name[i] << "," << car_color[i] << "," << car_model[i] << "," << car_plate_number[i] << "," << car_status[i] << "," << car_rpd[i] << "," << car_conditions[i] << "," << endl;
     }
     file.close();
}
void sort_car_data()
{
     int large=-1;
     string temp;
     for (int i = 0; i < cars; i++)
     {
          for (int j = 0; j < cars; j++)
          {
               if ((car_rpd_int[i]) > (car_rpd_int[j]))
               {
                    temp = car_rpd[j];
                    car_rpd[j] = car_rpd[i];
                    car_rpd[j] = large;
                    temp = car_brand_name[j];
                    car_brand_name[j] = car_brand_name[i];
                    car_brand_name[j] = temp;
                    temp = car_status[j];
                    car_status[j] = car_status[i];
                    car_status[j] = temp;
                    temp = car_color[j];
                    car_color[j] = car_color[i];
                    car_color[j] = temp;
                    temp = car_conditions[j];
                    car_conditions[j] = car_conditions[i];
                    car_conditions[j] = temp;
                    temp = car_model[j];
                    car_model[j] = car_model[i];
                    car_model[j] = temp;
               }
          }
     }
}
void stg_to_int()
{
     for (int i = 0; i < cars; i++)
     {
          car_rpd[i] = car_rpd_int[i];
     }
}