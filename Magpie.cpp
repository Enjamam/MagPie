// C211108
// Magpie Restaurant App
// V5

#include <bits/stdc++.h>
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
    void put(string nam_put, string pass_put)
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
        cout << "#" << serial << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Amount: " << amount << endl;
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

Magpie arr[150];  //Global Magpie array object
Manager mangr[150]; //Global Magpie Manager array object

//Manager Portion
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
        mangr[i].put(nam_man, pass_man);
        i++;
    }
    file.close();
    return i;
}

void owner_id_pass()   //Checking purpose, to check data available or not
{
    int f = 0;
    int x = read_manager_info() + 1;  // Available numbers of manager

    while (x--)  // reading numbers untill the end of file
    {
        mangr[f].show_all_manager(f+1);
        f++;
    }
}

int manager_login()
{
    int x, run, cnt;
    string name_inp, pass_inp, getnam, getpass, real_name, real_pass;

    run = 0;  //To continue looping proccess
    cnt = 0;  //Flag to check
    x = read_manager_info() + 1;  // Available numbers of manager
    cout << "Please input your user name: ";
    cin >> name_inp;
    cout << endl;
    cout << "Input your password: ";
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
             << "Login succesfull!" << endl << endl
             << "What do you want....?" << endl
             << "---------------------" << endl;
        return 2;
    }
    else if (cnt == 0)
    {
        cout << endl << "Login Unsuccessfull!" << endl
             << "Check your command again." << endl << endl;
        // owner_id_pass();  //Check list empty or not also to manage listed user later
        return 1;
        // exit(0);
    }
    return 0;
}


void manager_reg()
{
    int total_man, run;
    string inp_name, inp_pass, nam, pass;

    cout << "\t" << "User name: ";
    cin >> inp_name;
    cout << endl;
    cout << "\t" << "Password: ";
    cin >> inp_pass;
    cout << endl;

    total_man = read_manager_info();
    ofstream on;
    on.open("Manager.txt");

    run = 0;  //To continue looping proccess
    while (total_man--) // reading numbers untill the end of file
    {
        on << arr[run].get_nam(nam) << endl;
        on << arr[run].get_pass(pass) << endl;
        run++;
    }
    on << inp_name << endl;
    on << inp_pass << endl;
    on.close();

    cout << "Registration successfull.......!" << endl;
    cout << "Going to main menu........................................." << endl;
    return;
}
//............................


//Read all items using this command........
int readallitems()
{
    // Magpie arr[150];
    int items, sr, pc, amt;
    string nm;
    ifstream in;
    in.open("DB.txt");
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
//End of Reading..........

//Save data..................
/*
void save_menu(int counter)
{
    int items, sr, pc, amt, nm;
            ofstream save;
            save.open("DB.txt");
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

            return;
}
*/
//End of saving.......

int main()
{
    // Magpie arr[150];
    int n, i, counter, menu, check;
    int pc, amt, sr;
    int customer_show, user_select, select_owner, quantity, confirmation;
    string nm;

//Reading From File//
//***************************//
    counter = readallitems();  //Counter will store total items counted from DB.txt
//***************************//

    // Dialogue Part:
Main:
    cout << endl << "Main Menu:" << endl;
    cout << "===============" << endl;
    cout << "1.Owner" << endl;
    cout << "2.Customer" << endl;
    cout << "I am: ";
    cin >> user_select;  //Select either owner or customer

    if(user_select==1)
    {
        int log_reg;
        cout << "\t" << "1.Login" << endl;
        cout << "\t" << "2.Registration" << endl;
        cout << "Your choice: ";
        cin >> log_reg;
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
Owner:
            cout << "\t" << "1.Existing Menu" << endl;
        cout << "\t" << "2.New Menu" << endl;
        cout << "\t" << "3.Update Menu" << endl;
        cout << "\t" << "4.Add Menu" << endl;
        cout << "\t" << "5.Skip" << endl;

        cout << "Select: ";
        cin >> select_owner;
        if(select_owner==1)
        {
            cout << endl << "Available Menu:" << endl;
            cout << "===============" << endl;
            for(int t=0; t<counter-1; t++)
            {
                arr[t].show();
            }
Decide:
            //Reading From File//
//***************************//
            counter = readallitems();  //Counter will store total items counted from DB.txt
//***************************//
            cout << endl << "===================" << endl;
            cout << "\t" << "1.Main Menu" << endl;
            cout << "\t" << "2.Back" << endl;
            cout << "\t" << "3.Exit" << endl;

            cout << "Select: ";
            int decide;
            cin >> decide;
            if(decide==1)
            {
                goto Main;
            }
            else if(decide==2)
            {
                goto Owner;
            }
            else if(decide==3)
            {
                cout << "Exiting..................................." << endl;
                exit(0);
                // goto Save;
            }
        }

        else if(select_owner==2)
        {
            ofstream out;
            out.open("DB.txt");
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
            save.open("DB.txt");
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
        //////////////////////////////////////Update and Add item

        else if (select_owner == 3)
        {
            ifstream in;
            in.open("DB.txt");
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
            save.open("DB.txt");
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
            in.open("DB.txt");
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
            save.open("DB.txt");
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
            goto Decide;
        }
    }
    //////////////////////////////////////////////////////////
    if(user_select==2)  //When user is a customer
    {
        //Work Body:
        cout << endl
             << "=======================" << endl;
        cout << "★ Welcome to Magpie ★" << endl
             << endl;
        cout << "1. Show all" << endl;
        cout << "2. Select" << endl;
        cout << endl << "Select 1: ";
select_1: //Level for jumping if wrong input
        cin >> customer_show;

        if (customer_show == 1)
        {
            // readall;
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
                        save.open("DB.txt");

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
        else
            cout << "<Please select 1 first>" << endl;
        goto select_1;
    }
////////////////////////////////////////////////////////

    return 0;

}
