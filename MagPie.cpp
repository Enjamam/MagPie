// Restaurant App

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cwchar>
//#include <iostream>
//#include <string>
//#include <fstream>
using namespace std;

int total = 0; /// Store bill of a session
string MCN;    /// Store username of a session

class Manager
{
private:
    string name;
    string password;

public:
    void pot(string nam_put, string pass_put)
    {
        name = nam_put;
        password = pass_put;
    }
    string get_nam(string getnam)
    {
        getnam = name;
        return getnam;
    }
    string get_pass(string getpass)
    {
        getpass = password;
        return getpass;
    }
    void show_all_manager() /// Checking manager list while coding without opening the file
    {
        if (name == MCN)
            cout << "Name : " << name << endl
                 << "Password " << password << endl
                 << endl;
    }
};
//////////////////////// Customer
class Customer
{
private:
    string CName;
    string CPass;
    string CMobile;
    string CAddress;

public:
    void CPut(string nam_put, string pass_put, string mob_put, string adrs_put) /// Put Customer Data when need
    {
        CName = nam_put;
        CPass = pass_put;
        CMobile = mob_put;
        CAddress = adrs_put;
    }
    string get_CName(string getnam) /// Get Customer Data when needed
    {
        getnam = CName;
        return getnam;
    }
    string get_CPass(string getpass) /// Get Customer Data when needed
    {
        getpass = CPass;
        return getpass;
    }
    string get_CMobile(string getmob) /// Get Customer Data when needed          Test
    {
        getmob = CMobile;
        return getmob;
    }
    string get_CAddress(string getadrs) /// Get Customer Data when needed            Test
    {
        getadrs = CAddress;
        return getadrs;
    }
    int show_all_Customer() /// Checking manager list while coding without opening the file
    {
        int flag = 0;
        if (CName == MCN)
        {
            system("COLOR 2F");
            cout << "Name :    " << CName << endl
                 << "Password: " << CPass << endl
                 << "Mobile:   " << CMobile << endl
                 << "Address:  " << CAddress << endl
                 << endl;
            flag = 1;
            return 1;
        }
    }
};
/////////////////////

class Magpie : public Manager
{
private:
    int serial;
    int price;
    int amount;
    string name;

public:
    void put(int sr, string nm, int pc, int amt)
    {
        serial = sr;
        name = nm;
        price = pc;
        amount = amt;
    }

    void show() /// Show food details
    {
        cout << endl;
        cout << "   ===============================" << endl;
        cout << "   |  "
             << "#" << serial << setw(15) << endl;
        cout << "   |  "
             << "Name: " << name << setw(15) << endl;
        if (price == 0)
            cout << "   |  "
                 << "Price: "
                 << "Free" << setw(15) << endl;
        else if (price != 0)
            cout << "   |  "
                 << "Price: " << price << setw(15) << endl;
        cout << "   |  "
             << "Amount: " << amount << setw(15) << endl;
        cout << "   ===============================" << endl;
    }

    int show_item(int qntt) /// Order handle and do the work of customer order part
    {
        int again, reset_or_new;

        if (qntt > amount || qntt < 1) /// If ordered amount greater or less than quantity, then...
        {
            cout << endl
                 << "\tSorry, Sir. Wrong amount selection." << endl;
            cout << "\tPlease select available quantity or try something else." << endl;
        reset_or_new:
            cout << endl
                 << "What do you want, sir?" << endl;
            cout << "-----------------------------" << endl;
            cout << "1.Want something else?" << endl;
            cout << "2.Reset Quantity." << endl;

            cin >> reset_or_new;
            if (reset_or_new == 1) /// Order another item
            {
                cout << "You have choosen to order something else" << endl;
                return 1;
            }
            if (reset_or_new == 2) /// Order same item with new quantity
            {
            quantity_handle:
                cout << endl
                     << "Please enter new quantity......." << endl;
                cin >> qntt;
                if (qntt > amount || qntt < 1)
                {
                    cout << "Out of range." << endl; /// If new amount greater than available or less then 1
                    goto quantity_handle;
                }
            }
        }

        ////////////////////////////
        ///  Amount Manage
        amount -= qntt;                           /// Romoved ordered amount from total amount
        cout << "Items left: " << amount << endl; /// Showing left amount of ordered product
        //////////////////////

        cout << endl;
        cout << endl
             << "You have selected: ";
        cout << "#" << serial << endl;
        cout << "\t\t"
             << "   Name: " << name << endl;
        cout << "\t\t"
             << "   Quantity: " << qntt << endl;
        cout << "\t\t"
             << "   Bill: " << price * qntt << " Taka" << endl;
        total += price * qntt;

        cout << endl
             << "Wanna pick more?\n";
        // again = YesNo();
        cout << "1.Yes!" << endl
             << "2.No.\n";
        cin >> again;

        if (again == 1)
        {
            return 1;
        }
        else
        {
            cout << endl
                 << " \t\t\t\t\t Billing Menu" << endl;
            cout << "\t\t\t\t\t==============" << endl;
            cout << endl
                 << "\t\t\t\tYour total bill is: " << total << " Taka" << endl;
            cout << endl
                 << "Thank You, Sir. "
                 << "\t\t\t\t\t\t\t\tHave a good day.\n";
            return 2;
        }
    }
    /////////////////////////////////// /// Get function for saving to file
    int get_ser(int sr)
    {
        sr = serial;
        return sr;
    }
    int get_price(int pri)
    {
        pri = price;
        return pri;
    }
    int get_amount(int am)
    {
        am = amount;
        return am;
    }
    string get_name(string nam)
    {
        nam = name;
        return nam;
    }
    ////////////////////////////////
};

/// Color and Alignment functions

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/// End of Color and Alignment Function

Magpie arr[1500];     /// Global Magpie array object
Manager mangr[500];   /// Global Magpie Manager array object
Customer custmr[500]; /// Global Magpie Customer array object

/// Read info Portion
int read_manager_info() // Reading Manager detailes from file
{
    int i = 0;
    string nam_man, pass_man;
    // Manager mangr[150];
    ifstream file;
    file.open("Manager.txt");

    while (file.eof() == 0)
    {
        file >> nam_man;
        file >> pass_man;
        mangr[i].pot(nam_man, pass_man);
        i++;
    }
    file.close();
    return i;
}

void owner_id_pass() /// Checking purpose, to check data available or not
{
    int f = 0;
    int x = read_manager_info() + 1; /// Available numbers of manager

    while (x--) /// reading numbers untill the end of file
    {
        mangr[f].show_all_manager();
        f++;
    }
}

int read_customer_info() // Reading Customer detailes from file
{
    int i = 0;
    string nam_custmr, pass_custmr, mob_custmr, adrs_custmr;
    // Manager custmr[150];
    ifstream file;
    file.open("Customer.txt");

    while (file.eof() == 0)
    {
        file >> nam_custmr;
        file >> pass_custmr;
        file >> mob_custmr;
        file >> adrs_custmr;
        custmr[i].CPut(nam_custmr, pass_custmr, mob_custmr, adrs_custmr);
        i++;
    }
    file.close();
    return i;
}

void customer_id_pass() /// Checking purpose, to check data available or not
{
    int f = 0;
    int x = read_customer_info(); /// Available numbers of customer

    while (x--) /// reading numbers untill the end of file
    {
        int flagRcv = custmr[f].show_all_Customer();
        f++;
        if (flagRcv == 1)
            break;
    }
}
/// End of Read info portion

/// Login Portion
int manager_login() /// Login function for Manager
{
    int x, run, cnt;
    string name_inp, pass_inp, getnam, getpass, real_name, real_pass;

    run = 0;                     /// To continue looping proccess
    cnt = 0;                     /// Flag to check
    x = read_manager_info() + 1; /// Available numbers of manager

    system("cls");
    color(11); /// Changing the color of Print
    cout << "                 Log in Pannel:" << endl;
    cout << "             ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl
         << "               User name: ";
    color(14); /// Changing the color of Print
    cin >> name_inp;
    MCN = name_inp; // Taking name to use in profile show function
    color(10);      /// Changing the color of Print
    cout << endl
         << "               Password: ";
    color(14); /// Changing the color of Print
    cin >> pass_inp;
    cout << endl;

    while (x--) /// reading numbers untill the end of file
    {
        string real_name = mangr[run].get_nam(getnam);
        string real_pass = mangr[run].get_pass(getpass);
        if (real_name == name_inp)
        {
            if (real_pass == pass_inp)
            {
                cnt = 1;
                break;
            }
        }
        else if (real_name != name_inp)
        {
            cnt = 0;
        }
        run++;
    }

    if (cnt == 1)
    {
        system("cls");
        cout << "Hola!!" << endl
             << "Login succesfull!" << endl
             << endl;
        sleep(1);
        system("cls");
        return 2;
    }
    else if (cnt == 0)
    {
        cout << endl
             << "Login Unsuccessfull!" << endl
             << "Check your User name or Password." << endl
             << endl;
        sleep(2);
        // owner_id_pass();  /// Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}

int customer_login() /// Login function for customer
{
    int x, run, cnt;
    string name_inp, pass_inp, getnam, getpass, real_name, real_pass;

    run = 0;                      /// To continue looping proccess
    cnt = 0;                      /// Flag to check
    x = read_customer_info() + 1; /// Available numbers of manager

    system("cls");
    color(11); /// Changing the color of Print
    cout << "                 Log in Pannel:" << endl;
    cout << "             ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl
         << "               User name: ";
    color(14); /// Changing the color of Print
    cin >> name_inp;
    MCN = name_inp; // Taking name to use in profile show function
    color(10);      /// Changing the color of Print
    cout << endl
         << "               Password: ";
    color(14); /// Changing the color of Print
    cin >> pass_inp;
    cout << endl;

    while (x--) /// reading numbers untill the end of file
    {
        string real_name = custmr[run].get_CName(getnam);
        string real_pass = custmr[run].get_CPass(getpass);
        if (real_name == name_inp)
        {
            if (real_pass == pass_inp)
            {
                cnt = 1;
                break;
            }
        }
        else if (real_name != name_inp)
        {
            cnt = 0;
        }
        run++;
    }

    if (cnt == 1)
    {
        system("cls");
        cout << "Hola!!" << endl
             << "Login succesfull!" << endl
             << endl;
        sleep(1);
        system("cls");
        return 2;
    }
    else if (cnt == 0)
    {
        cout << endl
             << "Login Unsuccessfull!" << endl
             << "Check your User name or Password." << endl
             << endl;
        sleep(2);
        // customer_id_pass();  /// Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}
/// End of login portion

/// Registration portion

void manager_reg() /// Manager registration proccess function
{
    int total_man, run;
    string inp_name, inp_pass, nam, pass;

    system("cls"); /// Clear Console
    color(12);     /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl
         << "\t  "
         << "User name: ";
    color(14); /// Changing the color of Print
    cin >> inp_name;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Password: ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    cout << endl;

    total_man = read_manager_info() - 1;
    ofstream on;
    on.open("Manager.txt");

    run = 0;            /// To continue looping proccess
    while (total_man--) /// reading numbers untill the end of file
    {
        on << mangr[run].get_nam(nam) << endl;
        on << mangr[run].get_pass(pass) << endl;
        run++;
    }
    on << inp_name << endl;
    on << inp_pass << endl;
    on.close();

    cout << "Registration successfull.......!" << endl;
    cout << "Going back to main menu........................................." << endl;
    sleep(1.5);
    return;
}

void customer_reg() /// Customer registration proccess function
{
    int total_custmr, run;
    string inp_name, inp_pass, inp_mob, inp_adrs, nam, pass, mob, adrs;

    system("cls"); /// Clear Console
    color(12);     /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl
         << "\t  "
         << "User name: ";
    color(14); /// Changing the color of Print
    cin >> inp_name;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Password: ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Mobile: ";
    color(14); /// Changing the color of Print
    cin >> inp_mob;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Address: ";
    color(14); /// Changing the color of Print
    cin >> inp_adrs;
    // getline(cin, inp_adrs);
    cout << endl;

    total_custmr = read_customer_info() - 1;
    ofstream on;
    on.open("Customer.txt");

    run = 0;               /// To continue looping proccess
    while (total_custmr--) /// reading numbers untill the end of file
    {
        on << custmr[run].get_CName(nam) << endl;
        on << custmr[run].get_CPass(pass) << endl;
        on << custmr[run].get_CMobile(mob) << endl;
        on << custmr[run].get_CAddress(adrs) << endl;
        run++;
    }
    on << inp_name << endl;
    on << inp_pass << endl;
    on << inp_mob << endl;
    on << inp_adrs << endl;
    on.close();

    cout << "Registration successfull.......!" << endl;
    cout << "Going back to main menu........................................." << endl;
    sleep(1.5);
    return;
}
/// End of Registration Portion

/// Read all items using this command........
int readallitems()
{
    // Magpie arr[150];
    int items, sr, pc, amt;
    string nm;
    ifstream in;
    in.open("Food Menu.txt");
    items = 0;
    while (in.eof() == 0)
    {
        in >> sr;
        in.ignore();
        getline(in, nm);
        // cin>>nm;
        in >> pc;
        in >> amt;
        arr[items].put(sr, nm, pc, amt);
        items++;
    }
    in.close();

    return items;
}
/// End of Reading..........

/// Extra interactive features

int Menu() /// Menu for owner to give command as admin
{
    int Set[] = {3, 3, 3, 3, 3, 3}; /// DEFAULT COLORS
    int counter = 3;
    char key;

    for (int i = 0;;)
    {
        gotoxy(6, 0);
        // system("Color 0A");
        color(2);
        cout << "What do you want....?" << endl;
        gotoxy(6, 1);
        // system("Color 0A");
        color(2);
        cout << "---------------------";

        gotoxy(10, 3);
        color(Set[0]);
        cout << "1. Existing Menu";

        gotoxy(10, 4);
        color(Set[1]);
        cout << "2. New Menu";

        gotoxy(10, 5);
        color(Set[2]);
        cout << "3. Update Menu";

        gotoxy(10, 6);
        color(Set[3]);
        cout << "4. Add Menu";

        gotoxy(10, 7);
        color(Set[4]);
        cout << "5. Delete Menu" << endl;

        gotoxy(10, 8);
        color(Set[5]);
        cout << "6. Back" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 6))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 5))
        {
            counter++;
        }
        if (key == '\r') // carriage return
        {
            if (counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                // cout << "Menu 1 Opened";
                return 1;
            }
            if (counter == 2)
            {
                // cout << "Menu 2 Opened";
                return 2;
            }
            if (counter == 3)
            {
                // cout << "Menu 3 Opened";
                return 3;
            }
            if (counter == 4)
            {
                // cout << "Menu 4 Opened";
                return 4;
            }
            if (counter == 5)
            {
                // cout << "Menu 5 Opened";
                return 5;
            }
            if (counter == 6)
            {
                //  cout << "Menu 6 Opened";
                return 6;
            }
        }

        Set[0] = 3;
        Set[1] = 3;
        Set[2] = 3;
        Set[3] = 3;
        Set[4] = 3;
        Set[5] = 3;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
        if (counter == 3)
        {
            Set[2] = 14;
        }
        if (counter == 4)
        {
            Set[3] = 14;
        }
        if (counter == 5)
        {
            Set[4] = 14;
        }
        if (counter == 6)
        {
            Set[5] = 14;
        }
    }
}

int DSide() /// DSide function
{
    int Set[] = {2, 2, 2}; // DEFAULT COLORS
    int counter = 2;
    char key;

    for (int i = 0;;)
    {
        color(4);
        gotoxy(6, 0);
        cout << "Select an option:";
        gotoxy(6, 1);
        cout << "=================";

        gotoxy(10, 3);
        color(Set[0]);
        cout << "1. Main Menu";

        gotoxy(10, 4);
        color(Set[1]);
        cout << "2. Back";

        gotoxy(10, 5);
        color(Set[2]);
        cout << "3. Exit" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            counter++;
        }
        if (key == '\r') /// carriage return
        {
            if (counter == 1)
            {
                /// if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if (counter == 2)
            {
                return 2;
            }
            if (counter == 3)
            {
                return 3;
            }
        }

        Set[0] = 2;
        Set[1] = 2;
        Set[2] = 2;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
        if (counter == 3)
        {
            Set[2] = 14;
        }
    }
}

int MainManu() /// Main Menu interactive
{
    int Set[] = {2, 2}; /// DEFAULT COLORS
    int counter = 2;
    char key;

    system("cls");
    color(12); /// Changing the color of Print
    cout << "   Main Menu:" << endl;
    cout << "   ===============" << endl;
    cout << "           Select user type: " << endl;
    cout << "           -------------------" << endl;

    for (int i = 0;;)
    {
        gotoxy(12, 4);
        color(Set[0]);
        cout << "1. Owner";

        gotoxy(12, 5);
        color(Set[1]);
        cout << "2. Customer" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 2))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 1))
        {
            counter++;
        }
        if (key == '\r') /// carriage return
        {
            if (counter == 1)
            {
                /// if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if (counter == 2)
            {
                return 2;
            }
        }

        Set[0] = 2;
        Set[1] = 2;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
    }
}

int LogOrReg() /// Login or Registration interactive function
{
    int Set[] = {2, 2}; /// DEFAULT COLORS
    int counter = 2;
    char key;

    system("cls");
    color(12); /// Changing the color of Print
    cout << "            Log in or Registration:" << endl;
    cout << "            ======================" << endl;

    for (int i = 0;;)
    {
        gotoxy(12, 2.5);
        color(Set[0]);
        cout << "1. Log in";

        gotoxy(12, 3.5);
        color(Set[1]);
        cout << "2. Registration" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 2))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 1))
        {
            counter++;
        }
        if (key == '\r') /// carriage return
        {
            if (counter == 1)
            {
                /// if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if (counter == 2)
            {
                return 2;
            }
        }

        Set[0] = 2;
        Set[1] = 2;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
    }
}

int YesNo() /// Confirmation Menu to selecy Yes or No
{
    int Set[] = {2, 2}; /// DEFAULT COLORS
    int counter = 2;
    char key;

    color(12); /// Changing the color of Print
    cout << endl
         << "             Confirm Your Action:" << endl;
    cout << "            ======================" << endl;

    for (int i = 0;;)
    {
        gotoxy(12, 2.5);
        color(Set[0]);
        cout << "1. Yes";

        gotoxy(1, 3.5);
        color(Set[1]);
        cout << "2. No" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 2))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 1))
        {
            counter++;
        }
        if (key == '\r') /// carriage return
        {
            if (counter == 1)
            {
                /// if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if (counter == 2)
            {
                return 2;
            }
        }

        Set[0] = 2;
        Set[1] = 2;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
    }
}

int CustomerMenu() /// Customer menu function, will be visible after login
{
    int Set[] = {2, 2, 2}; // DEFAULT COLORS
    int counter = 2;
    char key;

    for (int i = 0;;)
    {
        color(4);
        gotoxy(6, 0);
        cout << "   Select an option:";
        gotoxy(6, 1);
        cout << "   =================";

        gotoxy(10, 3);
        color(Set[0]);
        cout << "1. Profile";

        gotoxy(10, 4);
        color(Set[1]);
        cout << "2. Order";

        gotoxy(10, 5);
        color(Set[2]);
        cout << "3. Log out" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            counter++;
        }
        if (key == '\r') /// carriage return
        {
            if (counter == 1)
            {
                /// if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if (counter == 2)
            {
                return 2;
            }
            if (counter == 3)
            {
                return 3;
            }
        }

        Set[0] = 2;
        Set[1] = 2;
        Set[2] = 2;

        if (counter == 1)
        {
            Set[0] = 14;
        }
        if (counter == 2)
        {
            Set[1] = 14;
        }
        if (counter == 3)
        {
            Set[2] = 14;
        }
    }
}

/// End of Extra

void splash() /// Splash screen when need to show
{
    string MagPie = "Welcome to MagPie";

    // system("color 7A");
    system("cls");
    color(14);
    for (int i = 0; i < MagPie.size(); i++)
    {
        cout << MagPie[i];
        Sleep(80);
    }
    sleep(1.5);
}

int main() /// Main Function starts from here.......
{
    // Magpie arr[150];
    int n, i, counter, menu, check;
    int pc, amt, sr;
    int customer_select, user_select, select_owner, quantity, confirmation;
    string nm;

    splash();
    // Reading From File//
    //***************************//
    counter = readallitems(); /// Counter will store total items counted from Food Menu.txt
    //***************************//

    /// Dialogue Part:
Main: /// Main Menu starts from here

    user_select = MainManu(); /// User will Select either owner or customer via interactive system

    if (user_select == 1)
    {
        int log_reg;
        log_reg = LogOrReg(); /// A value will return from LogOrReg interactive function further will decide
        if (log_reg == 2)
        {
            manager_reg();
            goto Main;
        }
        int return_manager = manager_login(); /// Manager Log in function will return a value of 1 or 2
        if (return_manager == 1)              /// Unsuccessfull attempt
        {
            goto Main;
        }
        else   /// If ID Pass match, then continue
        Owner: /// Owner/Manager menu starts from here via interactive function

            select_owner = Menu(); /// Users selection will return from function here
        if (select_owner == 1)
        {
            system("cls");
            cout << endl
                 << "Available Menu:" << endl; /// Willl shhow available food menu
            cout << "===============" << endl;
            for (int t = 0; t < counter - 1; t++)
            {
                arr[t].show();
            }
            cout << endl
                 << "Press any key to Back:";
            getch();
            system("cls");
            goto Owner;

        Decide:
            // Reading From File//
            //***************************//
            counter = readallitems(); /// Counter will store total items counted from Food Menu.txt
            //***************************//

            int decide;
            decide = DSide(); /// call and store return data from Interactive Function
            if (decide == 1)
            {
                goto Main; /// Goto main menu
                system("cls");
            }
            else if (decide == 2)
            {
                system("cls");
                goto Owner; /// Goto owner part
            }
            else if (decide == 3) /// Exit from program
            {
                // system(Color 0B);
                color(8); /// Changing the color of Print
                cout << "Exiting..................................." << endl;
                color(7);
                exit(0);
                // goto Save;
            }
        }

        else if (select_owner == 2) /// If Owner seect to create a new menu deleting entire menu
        {
            system("cls");
            ofstream out;
            out.open("Food Menu.txt");
            cout << "How Many Item: " << endl;
            cout << "Enter Amount: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << endl
                     << "Enter Food Code: ";
                cin >> sr;
                out << sr << endl;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, nm);
                out << nm << endl;
                // cin>>nm;
                cout << "Enter Price: ";
                cin >> pc;
                out << pc << endl;
                cout << "Enter Available Quantity: ";
                cin >> amt;
                out << amt << endl;
                arr[i].put(sr, nm, pc, amt);
            }
            out.close();

            // ofstream file("Food Menu.txt"); /// Clearing file content  o get a fresh file
            ofstream save;
            save.open("Food Menu.txt");
            int cnt = counter - 1;
            int run = 0;

            while (cnt--)
            {
                save << arr[run].get_ser(sr) << endl;
                save << arr[run].get_name(nm) << endl;
                save << arr[run].get_price(pc) << endl;
                save << arr[run].get_amount(amt) << endl;
                run++;
            }
            save.close();
            color(14); /// Changing the color of Print
            cout << endl
                 << "\t\t\tMenu Added Successfully!" << endl;
            sleep(1.5);
            system("cls");
            goto Decide;
        }

        /// Update and Add item

        else if (select_owner == 3) /// Manager will update previous menu
        {
            system("cls");
            // Reading From File//
            //***************************//
            counter = readallitems(); /// Counter will store total items counted from Food Menu.txt
            //***************************//

            cout << endl
                 << "Available Menu:" << endl; /// Will show available menu so that manager can decide which one to delete
            cout << "===============" << endl;
            for (int t = 0; t < counter - 1; t++)
            {
                arr[t].show();
            }
            ////////////////////////////////////////////////
            cout << endl
                 << "Which item you want to update?" << endl;
            cout << "------------------------------" << endl;
            int upser; /// Update serial with input (Up means Update)
            cout << "Enter Food Code: ";
            cin >> upser;
            sr = upser;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, nm);
            // cin>>nam;
            cout << "Enter Price: ";
            cin >> pc;
            cout << "Enter Amount: ";
            cin >> amt;
            // arr[upser - 1].put(sr, nm, pc, amt);

            int run = 0; /// Run array/Loop incrementing variable
            int p = counter - 1;
            while (p--)
            {
                if (arr[run].get_ser(sr) == (upser))
                {
                    arr[run].put(sr, nm, pc, amt);
                }
                run++;
                if (p == 0)
                {
                    break;
                }
            }

            /// Save data
            // save_menu(counter);
            ofstream save;
            save.open("Food Menu.txt");
            int cnt = counter - 1;
            run = 0;

            while (cnt--)
            {
                save << arr[run].get_ser(sr) << endl;
                save << arr[run].get_name(nm) << endl;
                save << arr[run].get_price(pc) << endl;
                save << arr[run].get_amount(amt) << endl;
                run++;
            }
            save.close();
            color(14);
            cout << endl
                 << "\t\t\tUpdated Successfully." << endl;
            sleep(2);
            system("cls");
            goto Decide;
        }
        //////////////////////////////////////////////////////////////////////
        else if (select_owner == 4) /// Add new items merging old menu
        {
            system("cls");
            // Reading From File//
            //***************************//
            counter = readallitems(); /// Counter will store total items counted from Food Menu.txt
            //***************************//
            //   system("cls");
            cout << "How many items you want to add?" << endl;
            int new_add, l;
            cout << "Enter the number: ";
            cin >> new_add;

            for (l = counter - 1; l < new_add + counter - 1; l++)
            {
                cout << endl
                     << "Enter Food Code: ";
                cin >> sr;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, nm);
                // cin>>nam;
                cout << "Enter Price: ";
                cin >> pc;
                cout << "Enter Amount: ";
                cin >> amt;
                arr[l].put(sr, nm, pc, amt);
            }

            ofstream save;
            save.open("Food Menu.txt");
            int counter = l;
            int run = 0;

            while (counter--)
            {
                save << arr[run].get_ser(sr) << endl;
                save << arr[run].get_name(nm) << endl;
                save << arr[run].get_price(pc) << endl;
                save << arr[run].get_amount(amt) << endl;
                run++;
            }
            save.close();
            cout << endl
                 << "\t\t\tAdded Successfully." << endl;
            sleep(2);
            system("cls");
            goto Decide;
        }
        ///////////////////////////////// End of update and add item

        if (select_owner == 5) /// Select delete to delete an item
        {
            system("cls");
            counter = readallitems() - 1;

            cout << endl
                 << "Available Menu:" << endl; /// Will show available menu so that manager can decide which one to delete
            cout << "===============" << endl;
            for (int t = 0; t < counter; t++)
            {
                arr[t].show();
            }
            ////////////////////////////////////////////////

            cout << endl
                 << "Which items you want to delete?" << endl;
            int new_delete, l;
            cout << "Enter the number: ";
            cin >> new_delete;

            ofstream save;
            save.open("Food Menu.txt");
            int run = 0;
            int check = 0;
            while (counter--)
            {
                if (arr[run].get_ser(sr) == (new_delete))
                {
                    run++;
                    check++;
                }
                else
                {
                    save << arr[run].get_ser(sr) << endl;
                    save << arr[run].get_name(nm) << endl;
                    save << arr[run].get_price(pc) << endl;
                    save << arr[run].get_amount(amt) << endl;
                    run++;
                }
                if (counter == 0)
                {
                    break;
                }
            }
            save.close();
            if (check == 0)
            {
                cout << "\t\t\t\tInvalid Food Code" << endl;
            }
            else if (check > 0)
            {
                color(13);
                cout << "\t\t\t\tSuccessfully deleted" << endl;
            }
            sleep(2);
            system("cls");
            goto Decide;
        }

        if (select_owner == 6) /// Select skip to go back
        {
            //   cout << endl << "\t\t\tItem added Successfully." << endl;
            //   sleep(1.5);
            system("cls");
            goto Decide;
        }
    }
    //////////////////////////////////////////////////////////
    if (user_select == 2) /// When user is a customer
    {
        int CustmrCmd;                /// To use after login
        customer_select = LogOrReg(); /// Customer will decide whether Sign in or Sign up

        if (customer_select == 2)
        {
            system("cls");
            customer_reg(); /// Customer will register throw the function
            system("cls");
            goto Main;
        }
        ////////////////////////////////////////////////////////

        else if (customer_select == 1)
        {
        UserLogin: /// To use after unsuccessfull login attempt
            system("cls");
            int clogin = customer_login(); /// Login status Check
            if (clogin == 1)               /// If unseccessfull attempt try again
            {
                goto UserLogin;
            }
            else
            CMenu: /// Customer menu label to use as back function
                CustmrCmd = CustomerMenu();
            if (CustmrCmd == 1) /// If customer decided to show his profile
            {
                system("cls");
                cout << "  Your Profile" << endl;
                cout << "================" << endl;
                customer_id_pass(); //......................................................................
                color(6);
                cout << endl
                     << endl
                     << "Press any key to back" << endl;
                getch();
                system("cls");
                goto CMenu;
            }

            else if (CustmrCmd == 3)
            {
                color(4);
                cout << endl
                     << "Loged out!" << endl;
                sleep(1.5);
                goto Main;
            }

            else if (CustmrCmd == 2) /// If customer decided to Order
            {
                system("cls");
                //   system("Color 0A");
                color(9);
                cout << endl
                     << "Available Menu:" << endl; /// Showing available menu
                cout << "===============" << endl;
                color(14);
                for (int t = 0; t < counter - 1; t++)
                {
                    arr[t].show();
                }
                /////////////////////////////////////
            Confirmation:
                // confirmation = YesNo();
                cout << endl
                     << "Want something....?\n";
                cout << "1.Yes" << endl;
                cout << "2.No" << endl;

                cin >> confirmation;
                if (confirmation == 1)
                {
                More:
                    cout << endl
                         << "Please select a menu: ";
                select_menu: // Level for jumping if wrong selection
                    cin >> menu;
                    /*   if (menu <= counter)
                       {
                           cout << "Quantity: ";
                           cin >> quantity;
                           check = arr[menu - 1].show_item(quantity);  */

                    int run = 0;
                    int check_code = 0;
                    int p = counter - 1;
                    while (p--)
                    {
                        if (arr[run].get_ser(sr) == (menu))
                        {
                            cout << "Quantity: ";
                            cin >> quantity;
                            check = arr[run].show_item(quantity);
                            check_code = 1;
                        }
                        run++;
                        if (p == 0)
                        {
                            break;
                        }
                    }
                    if (check_code == 0)
                    {
                        cout << "<= Please select an item from the list =>" << endl;
                        goto select_menu;
                    }
                    // cout << "Checkpoint: " << check << endl;  //To take next step when command comes from function
                    if (check == 1)
                    {
                        goto More;
                    }
                    else
                    {
                    Save:
                        ofstream save;
                        save.open("Food Menu.txt");

                        int run = 0;
                        int cnt = counter - 1;
                        while (cnt--)
                        {
                            save << arr[run].get_ser(sr) << endl;
                            save << arr[run].get_name(nm) << endl;
                            save << arr[run].get_price(pc) << endl;
                            save << arr[run].get_amount(amt) << endl;
                            run++;
                        }
                        save.close();
                        cout << "\n\n\t\t\t\tMenu Saved Before Exiting Successfully!\n";
                        exit(0);
                    }
                }
            }
            if (confirmation == 2)
            {
                cout << endl
                     << endl
                     << "\n\n\nThank you for your interest.\n";
                cout << "\t\tHope, you will find something needy next time......\n";
                sleep(2);
                system("cls");
                int Decide = DSide();
                system("cls");
                if (Decide == 1)
                    goto Main;
                else if (Decide == 2)
                    goto CMenu;
                else if (Decide == 3)
                    exit(0);
            }
            else
                cout << "<Please select an option>" << endl;
            goto Confirmation;
        }
    }

    return 0;
}
