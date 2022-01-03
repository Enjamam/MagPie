// Restaurant App

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include <thread>
//#include <iostream>
//#include <string>
//#include <fstream>
using namespace std;

int total=0;

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
    void show_all_manager(int mark)   // Checking manager list while coding without opening the file
    {
        cout << mark << ".Name : " << name << endl
             << "  Password " << password << endl << endl;
    }
};
//////////////////////// Customer
class Customer
{
private:
    string CName;
    string CPass;

public:
    void CPut(string nam_put, string pass_put) ///Put Customer Data when input
    {
        CName = nam_put;
        CPass = pass_put;
    }
    string get_CName(string getnam)  ///Get Customer Data when needed
    {
        getnam = CName;
        return getnam;
    }
    string get_CPass(string getpass)  ///Get Customer Data when needed
    {
        getpass = CPass;
        return getpass;
    }
    void show_all_Customer(int mark)   /// Checking manager list while coding without opening the file
    {
        cout << mark << ".Name : " << CName << endl
             << "  Password " << CPass << endl << endl;
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

    void show()  // Show food details
    {
        cout << endl;
        cout << "   ===============================" << endl;
        cout << "   |  " << "#" << serial << setw(15) << "|" << endl;
        cout << "   |  " << "Name: " << name << setw(15) << "|" << endl;
        if(price==0)
            cout << "   |  " << "Price: " << "Free" << setw(15) << "|" << endl;
        else if(price!=0)
            cout << "   |  " << "Price: " << price << setw(15) << "|" << endl;
        cout << "   |  " << "Amount: " << amount << setw(15) << "|" << endl;
        cout << "   ===============================" << endl;
    }

    int show_item(int qntt)  // Order handle and do the work of customer order part
    {
        int again, reset_or_new;

        if(qntt > amount)  // If ordered amount greater than quantity, then...
        {
            cout << endl << "\tSorry, Sir. We don't have much Food." << endl;
            cout << "\tPlease select less quantity or try something else." << endl;
reset_or_new:
            cout << endl << "What do you want, sir?" << endl;
            cout << "-----------------------------" << endl;
            cout << "1.Want something else?" << endl;
            cout << "2.Reset Quantity." << endl;

            cin >> reset_or_new;
            if(reset_or_new==1) // Order another item
            {
                cout << "You have choosen to order something else" << endl;
                return 1;
            }
            if(reset_or_new==2) // Order sameity item with new quant
            {
quantity_handle:
                cout << endl << "Please enter new quantity......." << endl;
                cin >> qntt;
                if(qntt > amount)
                {
                    cout << "Out of range." << endl;  // If new amount greater than available
                    goto quantity_handle;
                }
            }
        }

////////////////////////////
//Amount Manage
        amount-=qntt;  //Romoved ordered amount from total amount
        cout<<"Items left: " << amount<<endl;  //Showing left amount of ordered product
//////////////////////

        cout << endl;
        cout << endl << "You have selected: ";
        cout << "#" << serial << endl;
        cout << "\t\t" << "   Name: " << name << endl;
        cout << "\t\t" << "   Bill: " << price*qntt << endl;
        total += price*qntt;

        cout << endl << "Wanna pick more?\n";
        cout << "1.Yes!" << endl << "2.No.\n";
        cin >> again;

        if(again==1)
        {
            return 1;
        }
        else
        {
            cout << endl << "\t\t\t\tYour total bill is: " << total << " Taka" << endl;
            cout << endl
                 << "Thank You, Sir. "
                 << "\t\t\t\t\t\t\t\tHave a good day.\n";
            return 2;
        }
    }
    /////////////////////////////////// //Get function for saving to file
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

// Color and Alignment functions

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

// End of Color and Alignment Function

Magpie arr[1500];  ///Global Magpie array object
Manager mangr[500]; ///Global Magpie Manager array object
Customer custmr[500]; ///Global Magpie Customer array object

/// Read info Portion
int read_manager_info()
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

void owner_id_pass()   ///Checking purpose, to check data available or not
{
    int f = 0;
    int x = read_manager_info() + 1;  // Available numbers of manager

    while (x--)  /// reading numbers untill the end of file
    {
        mangr[f].show_all_manager(f+1);
        f++;
    }
}

int read_customer_info()
{
    int i = 0;
    string nam_custmr, pass_custmr;
    // Manager custmr[150];
    ifstream file;
    file.open("Customer.txt");

    while (file.eof() == 0)
    {
        file >> nam_custmr;
        file >> pass_custmr;
        custmr[i].CPut(nam_custmr, pass_custmr);
        i++;
    }
    file.close();
    return i;
}

void customer_id_pass()   ///Checking purpose, to check data available or not
{
    int f = 0;
    int x = read_customer_info() + 1;  /// Available numbers of customer

    while (x--)  /// reading numbers untill the end of file
    {
        custmr[f].show_all_Customer(f+1);
        f++;
    }
}
/// End of Read info portion

/// Login Portion
int manager_login()
{
    int x, run, cnt;
    string name_inp, pass_inp, getnam, getpass, real_name, real_pass;

    run = 0;  //To continue looping proccess
    cnt = 0;  //Flag to check
    x = read_manager_info() + 1;  // Available numbers of manager

    system("cls");
    color(11); // Changing the color of Print
    cout << "             Log in Pannel:" << endl;
    cout << "             ======================" << endl;
    color(10); // Changing the color of Print
    cout << endl << "               User name: ";
    cin >> name_inp;
    cout << endl;
    cout << "               Password: ";
    cin >> pass_inp;
    cout << endl;

    while (x--) // reading numbers untill the end of file
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
             << "Login succesfull!" << endl << endl;
        sleep(1);
        system("cls");
        return 2;
    }
    else if (cnt == 0)
    {
        cout << endl << "Login Unsuccessfull!" << endl
             << "Check your command again." << endl << endl;
        sleep(2);
        // owner_id_pass();  //Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}

int customer_login()
{
    int x, run, cnt;
    string name_inp, pass_inp, getnam, getpass, real_name, real_pass;

    run = 0;  /// To continue looping proccess
    cnt = 0;  /// Flag to check
    x = read_customer_info() + 1;  // Available numbers of manager

    system("cls");
    color(11); // Changing the color of Print
    cout << "             Log in Pannel:" << endl;
    cout << "             ======================" << endl;
    color(10); // Changing the color of Print
    cout << endl << "               User name: ";
    cin >> name_inp;
    cout << endl;
    cout << "               Password: ";
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
             << "Login succesfull!" << endl << endl;
        sleep(1);
        system("cls");
        return 2;
    }
    else if (cnt == 0)
    {
        cout << endl << "Login Unsuccessfull!" << endl
             << "Check your command again." << endl << endl;
        sleep(2);
        // customer_id_pass();  //Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}
/// End of login portion

/// Registration portion

void manager_reg()  /// Manager registration proccess function
{
    int total_man, run;
    string inp_name, inp_pass, nam, pass;

    system("cls");  /// Clear Console
    color(12); /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl << "\t  " << "User name: ";
    color(14); /// Changing the color of Print
    cin >> inp_name;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  " << "Password: ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    cout << endl;

    total_man = read_manager_info()-1;
    ofstream on;
    on.open("Manager.txt");

    run = 0;  ///To continue looping proccess
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
    cout << "Going to main menu........................................." << endl;
    sleep(1.5);
    return;
}

void customer_reg()  /// Customer registration proccess function
{
    int total_custmr, run;
    string inp_name, inp_pass, nam, pass;

    system("cls");  /// Clear Console
    color(12); /// Changing the color of Print
    cout << "              Registration Panel" << endl;
    cout << "            ======================" << endl;
    color(10); /// Changing the color of Print
    cout << endl << "\t  " << "User name: ";
    color(14); /// Changing the color of Print
    cin >> inp_name;
    cout << endl;
    color(10); /// Changing the color of Print
    cout << "\t  " << "Password: ";
    color(14); /// Changing the color of Print
    cin >> inp_pass;
    cout << endl;

    total_custmr = read_customer_info()-1;
    ofstream on;
    on.open("Customer.txt");

    run = 0;  /// To continue looping proccess
    while (total_custmr--) /// reading numbers untill the end of file
    {
        on << custmr[run].get_CName(nam) << endl;
        on << custmr[run].get_CPass(pass) << endl;
        run++;
    }
    on << inp_name << endl;
    on << inp_pass << endl;
    on.close();

    cout << "Registration successfull.......!" << endl;
    cout << "Going to main menu........................................." << endl;
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
    items=0;
    while (in.eof() == 0)
    {
        in >> sr;
        in.ignore();
        getline(in, nm);
        //cin>>nm;
        in >> pc;
        in >> amt;
        arr[items].put(sr, nm, pc, amt);
        items++;
    }
    in.close();

    return items;
}
///End of Reading..........


/// Extra interactive features

int Menu()
{
    int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
    int counter = 3;
    char key;

    for(int i=0;;)
    {
        gotoxy(6,0);
        // system("Color 0A");
        color(2);
        cout << "What do you want....?" << endl;
        gotoxy(6,1);
        // system("Color 0A");
        color(2);
        cout << "---------------------";

        gotoxy(10,3);
        color(Set[0]);
        cout<<"1. Existing Menu";

        gotoxy(10,4);
        color(Set[1]);
        cout<<"2. New Menu";

        gotoxy(10,5);
        color(Set[2]);
        cout<<"3. Update Menu";

        gotoxy(10,6);
        color(Set[3]);
        cout<<"4. Add Menu";

        gotoxy(10,7);
        color(Set[4]);
        cout<<"5. Skip" << endl;

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 5))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 4))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if(counter == 2)
            {
                return 2;
            }
            if(counter == 3)
            {
                return 3;
            }
            if(counter == 4)
            {
                return 4;
            }
            if(counter == 5)
            {
                return 5;
            }
        }

        Set[0] = 3;
        Set[1] = 3;
        Set[2] = 3;
        Set[3] = 3;
        Set[4] = 3;

        if(counter == 1)
        {
            Set[0] = 14;
        }
        if(counter == 2)
        {
            Set[1] = 14;
        }
        if(counter == 3)
        {
            Set[2] = 14;
        }
        if(counter == 4)
        {
            Set[3] = 14;
        }
        if(counter == 5)
        {
            Set[4] = 14;
        }

    }
}

int DSide()  /// DSide function
{
    int Set[] = {7,7,7}; // DEFAULT COLORS
    int counter = 2;
    char key;

    for(int i=0;;)
    {
        color(4);
        gotoxy(6,0);
        cout << "Select an option:";
        gotoxy(6,1);
        cout << "=================";

        gotoxy(10,3);
        color(Set[0]);
        cout << "1. Main Menu";

        gotoxy(10,4);
        color(Set[1]);
        cout << "2. Back";

        gotoxy(10,5);
        color(Set[2]);
        cout << "3. Exit" << endl;


        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 3))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 2))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if(counter == 2)
            {
                return 2;
            }
            if(counter == 3)
            {
                return 3;
            }
        }

        Set[0] = 2;
        Set[1] = 2;
        Set[2] = 2;

        if(counter == 1)
        {
            Set[0] = 14;
        }
        if(counter == 2)
        {
            Set[1] = 14;
        }
        if(counter == 3)
        {
            Set[2] = 14;
        }
    }
}

int MainManu()  /// Main Menu interactive
{
    int Set[] = {2,2}; // DEFAULT COLORS
    int counter = 2;
    char key;


    system("cls");
    color(12); // Changing the color of Print
    cout << "   Main Menu:" << endl;
    cout << "   ===============" << endl;
    cout << "           Select user type: " << endl;
    cout << "           -------------------" << endl;


    for(int i=0;;)
    {
        gotoxy(12,4);
        color(Set[0]);
        cout<<"1. Owner";

        gotoxy(12,5);
        color(Set[1]);
        cout<<"2. Customer";



        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 2))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 1))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if(counter == 2)
            {
                return 2;
            }
        }

        Set[0] = 2;
        Set[1] = 2;

        if(counter == 1)
        {
            Set[0] = 14;
        }
        if(counter == 2)
        {
            Set[1] = 14;
        }

    }
}

int LogOrReg() /// Login or Registration interactive function
{
    int Set[] = {2,2}; // DEFAULT COLORS
    int counter = 2;
    char key;


    system("cls");
    color(12); // Changing the color of Print
    cout << "            Log in or Registration:" << endl;
    cout << "            ======================" << endl;


    for(int i=0;;)
    {
        gotoxy(12,2.5);
        color(Set[0]);
        cout<<"1. Log in";

        gotoxy(12,3.5);
        color(Set[1]);
        cout<<"2. Registration";



        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 2))
        {
            counter--;
        }
        if(key == 80 && (counter >=1 && counter <= 1))
        {
            counter++;
        }
        if(key == '\r')//carriage return
        {
            if(counter == 1)
            {
                // if enter is click and highlight is on 1 the program will run the code here
                return 1;
            }
            if(counter == 2)
            {
                return 2;
            }
        }

        Set[0] = 2;
        Set[1] = 2;

        if(counter == 1)
        {
            Set[0] = 14;
        }
        if(counter == 2)
        {
            Set[1] = 14;
        }

    }
}

// End of Extra


int main()
{
    // Magpie arr[150];
    int n, i, counter, menu, check;
    int pc, amt, sr;
    int customer_show, user_select, select_owner, quantity, confirmation;
    string nm;

//Reading From File//
//***************************//
    counter = readallitems();  //Counter will store total items counted from Food Menu.txt
//***************************//

    // Dialogue Part:
Main:   // Main Menu starts from here

    user_select = MainManu();  //User will Select either owner or customer via interactive system

    if(user_select==1)
    {
        int log_reg;
        log_reg = LogOrReg();  //A value will return from LogOrReg interactive function further will decide
        if(log_reg == 2)
        {
            manager_reg();
            goto Main;
        }
        int return_manager = manager_login();
        if(return_manager == 1)  //Unsuccessfull attempt
        {
            goto Main;
        }
        else   //If ID Pass match, then continue
Owner:  // Owner/Manager menu starts from here via interactive function

            select_owner = Menu(); //Users selection will return from function here
        if(select_owner==1)
        {
            system("cls");
            cout << endl << "Available Menu:" << endl;
            cout << "===============" << endl;
            for(int t=0; t<counter-1; t++)
            {
                arr[t].show();
            }
            cout << endl << "Press any key to Back: ";
            getch();
            system("cls");
Decide:
            //Reading From File//
//***************************//
            counter = readallitems();  //Counter will store total items counted from Food Menu.txt
//***************************//

            int decide;
            decide = DSide(); //call and store data from Interactive Function
            if(decide==1)
            {
                goto Main;
                system("cls");
            }
            else if(decide==2)
            {
                system("cls");
                goto Owner;
            }
            else if(decide==3)
            {
                // system(Color 0B);
                cout << "Exiting..................................." << endl;
                exit(0);
                // goto Save;
            }
        }

        else if(select_owner==2)
        {
            ofstream out;
            out.open("Food Menu.txt");
            cout << "How Many Menu: " << endl;
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cout << endl << "Enter Serial: ";
                cin>>sr;
                out<<sr<<endl;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin,nm);
                out<<nm<<endl;
                //cin>>nm;
                cout << "Enter Price: ";
                cin>>pc;
                out<<pc<<endl;
                cout << "Enter Available Quantity: ";
                cin>>amt;
                out<<amt<<endl;
                arr[i].put(sr, nm, pc,amt);
            }
            out.close();

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
            cout << endl << "\t\t\tMenu Added Successfully!" << endl;
            goto Decide;
        }

        /// Update and Add item

        else if (select_owner == 3)
        {
            ifstream in;
            in.open("Food Menu.txt");
            counter=0;
            while (in.eof() == 0)
            {
                in >> sr;
                in.ignore();
                getline(in, nm);
                //cin>>nm;
                in >> pc;
                in >> amt;
                arr[counter].put(sr, nm, pc, amt);
                counter++;
            }
            in.close();
            ////////////////////////////////////////////////
            cout << endl << "Available Menu:" << endl;
            cout << "===============" << endl;
            for(int t=0; t<counter-1; t++)
            {
                arr[t].show();
            }
            ////////////////////////////////////////////////
            cout << endl << "Which item you want to update?" << endl;
            int upser;
            cout << "Enter Serial: ";
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
            arr[upser - 1].put(sr, nm, pc, amt);
//Save data
//save_menu(counter);
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
            cout << endl << "\t\t\tUpdated Successfully." << endl;
            goto Decide;
        }
        //////////////////////////////////////////////////////////////////////
        else if (select_owner == 4)
        {
            ifstream in;
            in.open("Food Menu.txt");
            counter=0;
            while (in.eof() == 0)
            {
                in >> sr;
                in.ignore();
                getline(in, nm);
                //cin>>nm;
                in >> pc;
                in >> amt;
                arr[counter].put(sr, nm, pc, amt);
                counter++;
            }
            in.close();

            cout << "How many items you want to add?" << endl;
            int new_add, l;
            cout << "Enter the number: ";
            cin >> new_add;

            for (l = counter - 1; l < new_add + counter - 1; l++)
            {
                cout << endl << "Enter Serial: ";
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
            goto Decide;
        }
        ///////////////////////////////////////////End of update and add item

        if(select_owner==5)
        {
            system("cls");
            goto Decide;
        }
    }
    //////////////////////////////////////////////////////////
    if(user_select==2)  ///When user is a customer
    {
        ///Work Body:
UserLogin:
        system("cls");
        cout << "★ Welcome to Magpie ★" << endl;
        /*  cout << "=======================" << endl;
          cout << "1. Log in" << endl;
          cout << "2. Registration" << endl;
          cout << endl << "Select option: ";
          cin >> customer_show;  */

        customer_show = LogOrReg();  /// Customer will decide whether Sign in or Sign up
        if (customer_show == 1)
        {
            int clogin = customer_login();  /// Login Check
            if(clogin == 1)  /// If unseccessfull attempt try again
            {
                goto UserLogin;
            }
            else
                /// readall menu;
                cout << endl << "Available Menu:" << endl;
            cout << "===============" << endl;
            for(int t=0; t<counter-1; t++)
            {
                arr[t].show();
            }
            /////////////////////////////////////
Confirmation:
            cout << endl << "Want something....?\n";
            cout << "1.Yes" << endl;
            cout << "2.No" << endl;

            cin >> confirmation;
            if(confirmation==1)
            {
More:
                cout << endl
                     << "Please select a menu: ";
select_menu: //Level for jumping if wrong selection
                cin >> menu;
                if (menu <= counter)
                {
                    cout << "Quantity: ";
                    cin >> quantity;
                    check = arr[menu - 1].show_item(quantity);
                    // cout << "Checkpoint: " << check << endl;  //To take next step when command comes from function
                    if(check==1)
                    {
                        goto More;
                    }
                    else
                    {
Save:
                        ofstream save;
                        save.open("Food Menu.txt");

                        int run = 0;
                        int cnt = counter-1;
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

                else
                    cout << "<Please select an item from the list>" << endl;
                goto select_menu;
            }
            if(confirmation==2)
            {
                cout << "Thank you for your interest.\n";
                cout << "\t\tHope, you will find something needy next time......\n";
                exit(0);
            }
            else
                cout << "<Please select an option>" << endl;
            goto Confirmation;
        }
        else if(customer_show == 2)
        {
            customer_reg();
            /// cout << "<Please select 1 first>" << endl;
            goto Main;
        }
    }
////////////////////////////////////////////////////////

    return 0;

}
