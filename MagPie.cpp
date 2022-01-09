/// Restaurant App
/// 09/01/2022

/// Task
/// 1. Only Owner can add manager
/// 2. Manager can ban customer
/// 3. 

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cwchar>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int total = 0;     /// Store bill of a session
int CPoint = 0;    /// Store point earned by customer purchasing items.
int FCnt = 0;      /// Store counter of purchased item
int FPrice[50];    /// Store total amount price of a session
int FAmount[50];   /// Store total amount of purchase of a session
string MCN;        /// Store username of a session
string FItems[50]; /// Store total amount of purchased items of a session

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
    int CustomerProfile() /// Checking manager list while coding without opening the file
    {
        int flag = 0;
        if (CName == MCN)
        {
            // color(14);
            system("COLOR 0F");
            cout << "  Name     : " << CName << endl
                 << "  Password : " << CPass << endl
                 << "  Mobile   : " << CMobile << endl
                 << "  Address  : " << CAddress << endl
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

    int shows(int SItem) /// Show food details only when select an item
    {
        if (SItem == serial)
        {
            system("cls");
            cout << "You have selected" << endl;
            cout << endl;
            cout << "   ===============================" << endl;
            cout << "   |  "
                 << "Food Code : " << serial << endl;
            cout << "   |  "
                 << "Name      : " << name << endl;
            if (price == 0)
                cout << "   |  "
                     << "Price      : "
                     << "Free" << endl;
            else if (price != 0)
                cout << "   |  "
                     << "Price     : " << price << endl;
            cout << "   |  "
                 << "Amount    : " << amount << endl;
            cout << "   ===============================" << endl
                 << endl;

            return 1;
        }
        else
            return 2;
    }

    void show() /// Show food details
    {
        cout << endl;
        cout << "   ===============================" << endl;
        cout << "   |  "
             << "Food Code : " << serial << endl;
        cout << "   |  "
             << "Name      : " << name << endl;
        if (price == 0)
            cout << "   |  "
                 << "Price     : "
                 << "Free" << endl;
        else if (price != 0)
            cout << "   |  "
                 << "Price     : " << price << endl;
        cout << "   |  "
             << "Amount    : " << amount << endl;
        cout << "   ===============================" << endl;
    }

    int show_item(int qntt) /// Order handle and do the work of customer order part
    {
        int again, reset_or_new;

        if (qntt > amount || qntt < 1) /// If ordered amount greater or less than quantity, then...
        {
            cout << endl
                 << "  Sorry, Sir. Wrong amount selection." << endl;
            cout << "  Please select available quantity or try something else." << endl;
        reset_or_new:
            cout << endl
                 << "What do you want, sir?" << endl;
            cout << "-----------------------------" << endl;
            cout << "1.Something Else. (Enter Key)" << endl;
            cout << "2.Reset Quantity. (Other Key)" << endl;

            reset_or_new = getch();
            // cin >> reset_or_new;
            if (reset_or_new == 13) /// Order another item
            {
                cout << "You have choosen to order something else" << endl;
                return 1;
            }
            // if (reset_or_new == 2) /// Order same item with new quantity
            else
            {
            quantity_handle:
                cout << endl
                     << "Please enter new quantity: ";
                cin >> qntt;
                if (qntt > amount || qntt < 1)
                {
                    cout << "Out of range! Check and Enter again." << endl; /// If new amount greater than available or less then 1
                    goto quantity_handle;
                }
            }
        }

        ////////////////////////////
        ///  Amount Manage
        amount -= qntt;                             /// Romoved ordered amount from total amount
        cout << "  Items left: " << amount << endl; /// Showing left amount of ordered product
        //////////////////////

        cout << endl;
        cout << endl
             << "You have selected: " << endl;
        cout << "\t\t   Food Code  : " << serial << endl;
        cout << "\t\t"
             << "   Name       : " << name << endl;
        FItems[FCnt] = name; /// Store ordered items name
        cout << "\t\t"
             << "   Quantity   : " << qntt << endl;
        FAmount[FCnt] = qntt; /// Store ordered items amount
        cout << "\t\t"
             << "   Total Bill : " << price * qntt << " Taka" << endl;
        FPrice[FCnt] = price; /// Store ordered items amount
        FCnt++;               /// After each order counter will increase
        total += price * qntt;

        cout << endl
             << "Do you want more, sir?" << endl;
        cout << "-----------------------------" << endl;
        cout << "1.Want More. (Enter Key)" << endl;
        cout << "2.Not Interested. (Other Key)" << endl;

        again = getch();
        // cin >> again;
        if (again == 13)
        {
            return 1;
        }
        else
        {
            /// Return and generate digital bill from another function
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

class Order_history
{
private:
    string Customer_Name;
    int Total_Amount;
    int Total_Point;

public:
    void CustomerPut(string name_put, int amount_put, int point_put) /// Put Customer Data when need
    {
        Customer_Name = name_put;
        Total_Amount = amount_put;
        Total_Point = point_put;
    }
    string get_CustomerName(string getnam) /// Get Customer Data when needed
    {
        getnam = Customer_Name;
        return getnam;
    }
    int get_Total_Amount(int get_tamount) /// Get Customer Data when needed
    {
        get_tamount = Total_Amount;
        return get_tamount;
    }
    void Update_Amount() /// Update Customer Data when needed
    {
        Total_Amount += total;
    }
    int get_Total_Point(int get_point) /// Get Customer Data when needed
    {
        get_point = Total_Point;
        return get_point;
    }
    void Update_Point() /// Update Customer Data when needed
    {
        Total_Point = 0;
        Total_Point += (total / 10);
    }

    void showhistory()
    {
        cout << "  Total Spend     : " << Total_Amount << endl
             << "  Available Point : " << Total_Point << endl
             << endl;
        cout << "  Note: Point coversion rate: 1 Point per 10 TK." << endl
             << "  It will reset after every order." << endl
             << "  You can use point for previous order in next order." << endl;
    }

    int History() /// Showing customer history with function
    {
        int flag = 0;
        if (Customer_Name == MCN)
        {
            // color(14);
            // system("COLOR 0F");
            cout << "  Total Spend :    " << Total_Amount << endl
                 << "  Available Point: " << Total_Point << endl
                 << endl;
            flag = 1;
            return 1;
        }
    }
};

Magpie arr[1500];           /// Global Magpie array object
Manager mangr[100];         /// Global Magpie Manager array object
Customer custmr[500];       /// Global Magpie Customer array object
Order_history history[500]; /// Global Magpie Customer_history array object

/// Color, Design and Alignment functions
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

void Exit() /// When user select exit it will be more attractive to see
{
    int i;
    string ExitMsg = "Exiting..............................";

    cout << endl
         << endl
         << endl;
    for (i = 0; i <= ExitMsg.size(); i++)
    {
        cout << ExitMsg[i];
        Sleep(20);
    }
    system("cls");
    exit(0);
}

void ShowBill()
{
    int TotalItems;
    int PointCalculate;
    int discount;
    string FoodName;

    system("cls");
    if (CPoint >= total)
    {
        PointCalculate = (CPoint - total); /// Calculate point usage
        // discount = CPoint - PointCalculate; /// Point will count as tk 1 as it converted before
        discount = 0;   /// Point will count as tk 1 as it converted before
        CPoint = total; /// To use point for discount
    }
    else if (CPoint <= total)
    {
        PointCalculate = 0;        /// Calculate point usage
        discount = total - CPoint; /// Point will count as tk 1 as it converted before
    }
    double vat = discount * 6 / 100.00;
    string date = "09 Jan 2022";
    // cout << "Enter Date: Format (05 Jan 2022)" << endl;
    // getline(cin, date);
    // cout << fixed << setprecision(2) << vat << endl;

    cout << endl;
    cout << "\t\t MagPie Restaurant" << endl;
    cout << "\t\t-------------------" << endl
         << endl;
    cout << "Date: " << date << endl;
    cout << "Invoice To: Mr. " << MCN << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Items                  Qty                   Total" << endl;
    cout << "----------------------------------------------------" << endl
         << endl;
    for (int i = 0; i < FCnt; i++)
    {
        int itemsize = FItems[i].size();
        int needspace = 25 - itemsize;
        cout << FItems[i] << setw(needspace) << FAmount[i] << "                    "
             << FAmount[i] * FPrice[i] << ".00" << endl;
        itemsize = 0;
    }
    //  cout << "Burhani                5                     500.00" << endl << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "Sub Total                                    " << total << ".00" << endl;
    cout << "Discount                                     " << CPoint << ".00" << endl;
    cout << "                                             -------" << endl;
    cout << "Net Total                                    " << discount << ".00" << endl;
    if (vat == 0)
    {
        cout << "VAT (6%)                                     "
             << "0.00" << endl;
    }
    else
        cout << "VAT (6%)                                     " << fixed << setprecision(2) << vat << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Grand Total                                  " << fixed << setprecision(0) << discount + vat << ".00" << endl;
    cout << "----------------------------------------------------" << endl
         << endl
         << endl
         << "Note: You may get additional round figure bonus on Grand Total!"
         << endl
         << endl
         << endl
         << endl;

    CPoint = PointCalculate;

    return;
}
/// End of Color, Design and Alignment Function

/// Read History
int read_history() // Reading Customer detailes from file
{
    int i = 0;
    string UName;
    int UAmount, UPoint;
    ifstream file;
    file.open("Order History.txt");

    while (file.eof() == 0)
    {
        file >> UName;
        file >> UAmount;
        file >> UPoint;
        history[i].CustomerPut(UName, UAmount, UPoint);
        i++;
    }
    file.close();
    return i;
}

int Get_Cpoint() /// Getting Point from user profile to use later
{
    int j = read_history() - 1;
    int k = 0;
    int point, g;
    string name;
    while (j--)
    {
        if (MCN == history[k].get_CustomerName(name))
        {
            g = history[k].get_Total_Point(point);
            break;
        }
        k++;
    }
    return g;
}

void NoteShow() /// Show note when login/Registration
{
    string RegNote = "Note: User Name and Password shouldn't contain any space.";
    gotoxy(0, 8);
    color(14);
    cout << "\t  ";
    for (int i = 0; i <= RegNote.size(); i++)
    {
        cout << RegNote[i];
        Sleep(1);
    }
    return;
}
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
        int flagRcv = custmr[f].CustomerProfile();
        f++;
        if (flagRcv == 1) /// Will check shown or not. If shown, it will terminate the proccess
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
         << "               User Name : ";
    color(14); /// Changing the color of Print
    cin >> name_inp;
    MCN = name_inp; // Taking name to use in profile show function
    color(10);      /// Changing the color of Print
    cout << "               Password  : ";
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
        cout << endl
             << endl
             << "Hola!!" << endl
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
             << endl
             << endl;
        system("pause");
        // sleep(2);
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
         << "               User Name : ";
    color(14); /// Changing the color of Print
    cin >> name_inp;
    MCN = name_inp; // Taking name to use in profile show function
    color(10);      /// Changing the color of Print
    cout << "               Password  : ";
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
        cout << endl
             << endl
             << "Hola!!" << endl
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
             << endl
             << endl;
        system("pause");
        // sleep(2);
        // customer_id_pass();  /// Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}
/// End of login portion

int UserNameCheck(string uname) /// Will check username previously available or not
{
    int l = read_history() - 1; /// Calling read_history to get total data number
    int y = 0;
    int flag = 0;
    string kl; /// kl will hold customer name from class
    while (l--)
    {
        if (uname == history[y].get_CustomerName(kl)) /// MCN is Cusomer user name stored globally
        {
            flag = 1; /// If name matched, show Spend and Point available
            break;
        }
        y++;
    }
    if (flag == 1)
        return 1;
    else
        return 2;
}
/// Registration portion

void manager_reg() /// Manager registration proccess function
{
    int total_man, run;
    string inp_name, inp_pass, nam, pass;

    system("cls"); /// Clear Console
    color(12);     /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;

    NoteShow();
    gotoxy(0, 3);
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "User Name : ";
    color(14); /// Changing the color of Print
    cin >> inp_name;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Password  : ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    cout << endl
         << endl
         << endl
         << endl
         << endl;

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

    cout << endl
         << endl
         << "Registration successfull.......!" << endl
         << endl;
    //  cout << "Going back to main menu........................................." << endl << endl;
    color(7);
    system("pause");
    // sleep(1.5);
    return;
}

void customer_reg() /// Customer registration proccess function
{
AnotherName:
    int total_custmr, run;
    string inp_name, inp_pass, inp_mob, inp_adrs, nam, pass, mob, adrs;

    system("cls"); /// Clear Console
    color(12);     /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;

    NoteShow();
    gotoxy(0, 3);
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "User Name : ";
    color(14); /// Changing the color of Print
    cin >> inp_name;

    int ExistORNot = UserNameCheck(inp_name); /// Return 1 indicates user name available already
    if (ExistORNot == 1)
    {
        color(12);
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << "          User Name already exist!" << endl
             << "          Please choice another User Name." << endl
             << endl;
        color(7);
        system("pause");
        goto AnotherName; /// Another login name because of existance
    }
    else
        color(10); /// Changing the color of Print
    cout << "\t  "
         << "Password  : ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Mobile    : ";
    color(14); /// Changing the color of Print
    cin >> inp_mob;
    color(10); /// Changing the color of Print
    cout << "\t  "
         << "Address   : ";
    color(14); /// Changing the color of Print
    // cin >> inp_adrs;
    cin.ignore();
    getline(cin, inp_adrs);
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

    string name;
    int amount;
    int point;
    int kl = read_history() - 1;
    ofstream p;
    p.open("Order History.txt");
    int op = 0;
    while (kl--)
    {
        p << history[op].get_CustomerName(name) << endl;
        p << history[op].get_Total_Amount(amount) << endl;
        p << history[op].get_Total_Point(point) << endl;
        op++;
    }
    p << inp_name << endl;
    p << 0 << endl;
    p << 0 << endl;
    p.close();

    cout << endl
         << endl
         << endl
         << "Registration successfull.......!" << endl
         << endl;
    //  cout << "Going back to main menu........................................." << endl << endl;
    color(7);
    system("pause");
    // sleep(1.5);
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
        gotoxy(11, 0);
        // system("Color 0A");
        color(2);
        cout << "What do you want....?" << endl;
        gotoxy(11, 1);
        // system("Color 0A");
        color(2);
        cout << "---------------------";

        gotoxy(12, 2);
        color(Set[0]);
        cout << "1. Existing Menu";

        gotoxy(12, 3);
        color(Set[1]);
        cout << "2. New Menu";

        gotoxy(12, 4);
        color(Set[2]);
        cout << "3. Update Menu";

        gotoxy(12, 5);
        color(Set[3]);
        cout << "4. Add Menu";

        gotoxy(12, 6);
        color(Set[4]);
        cout << "5. Delete Menu" << endl;

        gotoxy(12, 7);
        color(Set[5]);
        cout << "6. Skip" << endl;

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
        gotoxy(11.8, 0);
        cout << "Select an option:" << endl;
        gotoxy(11.8, 1);
        cout << "-----------------";

        gotoxy(12, 2);
        color(Set[0]);
        cout << "1. Main Menu";

        gotoxy(12, 3);
        color(Set[1]);
        cout << "2. Back";

        gotoxy(12, 4);
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
MainMenu:
    int Set[] = {2, 2, 2, 2}; /// DEFAULT COLORS
    int counter = 2;
    char key;

    system("cls");
    color(12); /// Changing the color of Print
               // cout << "   Main Menu:" << endl;
               // cout << "   ===============" << endl;
    cout << "           Select user type: " << endl;
    cout << "           -------------------" << endl;

    for (int i = 0;;)
    {
        gotoxy(12, 2);
        color(Set[0]);
        cout << "1. Manager";

        gotoxy(12, 3);
        color(Set[1]);
        cout << "2. Customer" << endl;

        gotoxy(12, 4);
        color(Set[2]);
        cout << "3. Developer Info" << endl;

        gotoxy(12, 5);
        color(Set[3]);
        cout << "4. Exit" << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 4))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 3))
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
                system("cls");
                color(12);
                // cout << "   Developers Info" << endl;
                // cout << "  =================" << endl
                //     << endl;
                // color(2);
                string Team = "     Team RunTime Terror";
                for (int i = 0; i <= Team.size(); i++)
                {
                    cout << Team[i];
                    Sleep(50);
                }
                // cout << " Team RunTime Terror" << endl;
                cout << endl
                     << "     --------------------" << endl;
                color(14);
                Sleep(150);
                cout << "      1. Emrus" << endl;
                Sleep(180);
                cout << "      2. Istiak" << endl;
                Sleep(180);
                cout << "      3. Minhaz" << endl;

                cout << endl
                     << endl;
                system("pause");
                goto MainMenu;
                // return 3;
            }
            if (counter == 4)
            {
                Exit();
                //  return 4;
            }
        }

        Set[0] = 2;
        Set[1] = 2;
        Set[2] = 2;
        Set[3] = 2;

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
    }
}

int LogOrReg() /// Login or Registration interactive function
{
    int Set[] = {2, 2}; /// DEFAULT COLORS
    int counter = 2;
    char key;

    system("cls");
    color(12); /// Changing the color of Print
    cout << "           Log in or Registration:" << endl;
    cout << "           ------------------------" << endl;

    for (int i = 0;;)
    {
        gotoxy(12, 2);
        color(Set[0]);
        cout << "1. Log in";

        gotoxy(12, 3);
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

int YesNo() /// Confirmation Menu to select Yes or No (Not Used till now)
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
        cout << "   -----------------";

        gotoxy(12, 2);
        color(Set[0]);
        cout << "1. Profile";

        gotoxy(12, 3);
        color(Set[1]);
        cout << "2. Order";

        gotoxy(12, 4);
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
            color(2);
            cout << endl
                 << "          Available Menu:" << endl; /// Willl shhow available food menu
            cout << "         -----------------" << endl;
            color(14);
            for (int t = 0; t < counter - 1; t++)
            {
                arr[t].show();
            }
            cout << endl;
            system("pause");
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
                Exit();
                // goto Save;
            }
        }

        else if (select_owner == 2) /// If Owner seect to create a new menu deleting entire menu
        {
            system("cls");

            //***************************//
            ofstream out;
            out.open("Food Menu.txt");
            color(11);
            cout << "       How Many Items? " << endl;
            cout << "     ------------------- " << endl;
            color(2);
            cout << "       Enter Number: ";
            color(14);
            cin >> n;
            int i;
            for (i = 0; i < n; i++)
            {
                system("cls");
                color(4);
                cout << "            Item #" << i + 1 << endl;
                cout << "      --------------------- " << endl;
                color(2);
                cout << "        Enter Food Code: ";
                color(14);
                cin >> sr;
                out << sr << endl;
                cin.ignore();
                color(2);
                cout << "        Enter Food Name: ";
                color(14);
                getline(cin, nm);
                out << nm << endl;
            // cin>>nm;
            NewPrice:
                color(2);
                cout << "        Enter Food Price: ";
                color(14);
                cin >> pc;
                if (pc < 0)
                {
                    color(11);
                    cout << "        Price Cann't be negative. Enter again" << endl;
                    goto NewPrice;
                }
                else
                    out << pc << endl;
            NewAmount:
                color(2);
                cout << "        Enter Available Quantity: ";
                color(14);
                cin >> amt;
                if (amt < 0)
                {
                    color(11);
                    cout << "        Quantity Cann't be negative. Enter again" << endl;
                    goto NewAmount;
                }

                out << amt << endl;
                arr[i].put(sr, nm, pc, amt);
            }
            out.close();

            color(14); /// Changing the color of Print
            cout << endl
                 << "        Menu Added Successfully!" << endl;
            sleep(1.5);
            system("cls");
            goto Decide;
        }

        /// Update and Add item

        else if (select_owner == 3) /// Manager will update previous menu
        {
        Update:
            system("cls");
            // Reading From File//
            //***************************//
            counter = readallitems(); /// Counter will store total items counted from Food Menu.txt
                                      //***************************//

            color(2);
            cout << endl
                 << "          Available Menu:" << endl; /// Willl shhow available food menu
            cout << "         -----------------" << endl;
            color(14);
            for (int t = 0; t < counter - 1; t++)
            {
                arr[t].show();
            }
            ////////////////////////////////////////////////
            color(2);
            cout << endl
                 << "Which item you want to update?" << endl;
            cout << "------------------------------" << endl;
            color(14);
            int chkcode; /// Check items with input
            cout << "Enter Food Code: ";
            cin >> chkcode;
            int sr = chkcode;
            int returns;

            // int chkcodeflag = 0;
            for (int t = 0; t < counter - 1; t++)
            {
                returns = arr[t].shows(chkcode);
                if (returns == 1)
                    //  chkcodeflag = 1;
                    break;
            }

            if (returns == 2)
            {
                color(7);
                cout << "Item not available!" << endl
                     << "Please check again" << endl;
                sleep(2);
                goto Update;
            }
            else
                color(2);
            cout << endl
                 << "   Please Enter Data Correctly" << endl;
            cout << "   ----------------------------" << endl
                 << endl;
            color(14);
            int upser; /// Update serial with input (Up means Update)
            cout << "   Enter New Food Code: ";
            cin >> upser;
            // sr = upser;
            cout << "   Enter New Name: ";
            cin.ignore();
            getline(cin, nm);
        // cin>>nam;
        UpPrice:
            cout << "   Enter New Price: ";
            cin >> pc;
            if (pc < 0)
            {
                color(11);
                cout << "   Price Cann't be negative. Enter again" << endl;
                color(14);
                goto UpPrice;
            }
            else
            UpAmount:
                cout << "   Enter New Amount: ";
            cin >> amt;
            if (amt < 0)
            {
                color(11);
                cout << "  Amount Cann't be negative. Enter again" << endl;
                goto UpAmount;
            }

            int run = 0; /// Run array/Loop incrementing variable
            int p = counter - 1;
            while (p--)
            {
                if (arr[run].get_ser(sr) == (chkcode))
                {
                    arr[run].put(upser, nm, pc, amt);
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
                save << arr[run].get_ser(upser) << endl;
                save << arr[run].get_name(nm) << endl;
                save << arr[run].get_price(pc) << endl;
                save << arr[run].get_amount(amt) << endl;
                run++;
            }
            save.close();
            color(14);
            cout << endl
                 << "  Updated Successfully!" << endl;
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
            color(2);
            cout << "  How many items you want to add?" << endl
                 << "  -------------------------------" << endl;
            color(14);
            int new_add, l;
            int itemsr = 1;
            cout << "  Enter the number: ";
            color(4);
            cin >> new_add;

            for (l = counter - 1; l < new_add + counter - 1; l++)
            {
                system("cls");
                color(4);
                cout << "            Item #" << itemsr << endl;
                cout << "      --------------------- " << endl;
                color(2);
                cout << "      Enter Food Code: ";
                color(14);
                cin >> sr;
                color(2);
                cout << "      Enter Name: ";
                color(14);
                cin.ignore();
                getline(cin, nm);
            // cin>>nam;
            AddPrice:
                color(2);
                cout << "      Enter Price: ";
                color(14);
                cin >> pc;
                if (pc < 0)
                {
                    color(11);
                    cout << "      Price Cann't be negative. Enter again" << endl;
                    goto AddPrice;
                }
                else
                AddAmount:
                    color(2);
                cout << "      Enter Amount: ";
                color(14);
                cin >> amt;
                if (amt < 0)
                {
                    color(11);
                    cout << "      Amount Cann't be negative. Enter again" << endl;
                    goto AddAmount;
                }
                arr[l].put(sr, nm, pc, amt);
                itemsr++; /// Increasing serial to show header
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
                 << "      Added Successfully." << endl;
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
                 << "          Available Menu:" << endl; /// Will show available menu so that manager can decide which one to delete
            cout << "         -----------------" << endl;
            color(14);
            for (int t = 0; t < counter; t++)
            {
                arr[t].show();
            }
            ////////////////////////////////////////////////

            cout << endl
                 << "  Which items you want to delete?" << endl
                 << "  -------------------------------" << endl
                 << endl;
            int new_delete, l;
            cout << "  Enter the number: ";
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
                cout << "  Invalid Food Code!" << endl;
            }
            else if (check > 0)
            {
                color(13);
                cout << "  Successfully deleted!" << endl;
            }
            sleep(2);
            system("cls");
            goto Decide;
        }

        if (select_owner == 6) /// Select skip to go back
        {
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
                color(2);
                cout << "    Your Profile" << endl;
                cout << "  ================" << endl;
                // CPoint = Get_Cpoint();
                customer_id_pass(); // Customer profile show using this function
                color(6);
                int l = read_history() - 1; /// Calling read_history to get total data number
                int y = 0;
                string kl; /// kl will hold customer name from class
                while (l--)
                {
                    if (MCN == history[y].get_CustomerName(kl)) /// MCN is Cusomer user name stored globally
                    {
                        history[y].showhistory(); /// If name matched, show Spend and Point available
                        break;
                    }
                    y++;
                }

                color(7);
                // system("COLOR 0F");
                cout << endl
                     << endl;
                system("pause");
                system("cls");
                goto CMenu; /// Going to customer menu (back)
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
                     << "          Available Menu:" << endl; /// Showing available menu
                cout << "         -----------------" << endl;
                color(14);
                for (int t = 0; t < counter - 1; t++)
                {
                    arr[t].show();
                }
                /////////////////////////////////////
                // confirmation = YesNo();
                color(2);
                cout << endl
                     << "  What do you want, sir?" << endl;
                cout << "  --------------------------" << endl;
                color(14);
                cout << "  1. Press Enter to Order" << endl;
                cout << "  2. Press Other to Cancel" << endl;
                confirmation = getch();
                // cin >> confirmation;
                // confirmation = 1;
                if (confirmation == 13)
                {
                More:
                    color(14);
                    cout << endl
                         << "  Please select a menu: ";
                select_menu:     // Level for jumping if wrong selection
                    cin >> menu; /// Food code actually
                    /// Searching menu with food code
                    int run = 0;
                    int check_code = 0;
                    int p = counter - 1;
                    while (p--)
                    {
                        if (arr[run].get_ser(sr) == (menu))
                        {
                            cout << "  Quantity: ";
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
                        CPoint = Get_Cpoint(); // Calling Previous available point
                        ShowBill();            /// Showing bill after ordering
                        system("pause");

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

                        /// Point and spend will save here
                        int hj = read_history() - 1;
                        int gh = 0;
                        string name;
                        int point, amount;
                        ofstream ve;
                        ve.open("Order History.txt");

                        while (hj--)
                        {
                            if (MCN == history[gh].get_CustomerName(name))
                            {
                                ve << history[gh].get_CustomerName(name) << endl;
                                ve << history[gh].get_Total_Amount(amount) + total << endl;
                                ve << (CPoint + (total / 10)) << endl;
                            }
                            else
                            {
                                ve << history[gh].get_CustomerName(name) << endl;
                                ve << history[gh].get_Total_Amount(amount) << endl;
                                ve << history[gh].get_Total_Point(point) << endl;
                            }
                            gh++;
                        }
                        ve.close();

                        total = 0;                                        /// resetting value
                        FCnt = 0;                                         /// resetting value
                        cout << "\n\n\t\t\t\tMenu Saved Successfully!\n"; /// Confirmation message of saving

                        // sleep(2);
                        system("cls");
                        int Decide = DSide(); /// Decide next step
                        if (Decide == 1)
                        {
                            system("cls");
                            goto Main;
                        }
                        else if (Decide == 2)
                        {
                            system("cls");
                            goto CMenu;
                        }
                        else if (Decide == 3)
                            Exit();
                    }
                }
                else
                {
                    system("cls");
                    int Decide = DSide(); /// Decide next step
                    if (Decide == 1)
                    {
                        system("cls");
                        goto Main;
                    }
                    else if (Decide == 2)
                    {
                        system("cls");
                        goto CMenu;
                    }
                    else if (Decide == 3)
                        Exit();
                }
            }
        }
    }

    return 0;
}
