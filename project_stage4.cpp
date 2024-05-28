#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <ctime>

using namespace std;

void date_printer()
{
    time_t now = time(0);

    char *nowt = ctime(&now);
    cout << "today's date and time :" << nowt << endl;

    struct tm local = *localtime(&now);
    // to give someone a date 90 days from present
    // cout<<"you can donate blood at or after : "<<local.tm_mday<<" "<<local.tm_mon+1<<" "<<local.tm_year+1900<<" "<<endl;
    if (local.tm_mon + 1 + 3 > 12)
    {
        cout << "you can donate blood at or after : " << local.tm_mday << " " << (local.tm_mon + 1 + 3) - 12 << " " << local.tm_year + 1900 + 1 << " " << endl;
    }
    else if (local.tm_mon + 1 + 3 <= 12)
    {
        cout << "\t\t\tyou can donate blood at or after : " << local.tm_mday << "-" << local.tm_mon + 1 + 3 << "-" << local.tm_year + 1900 << "" << endl;
    }
};
void bbprinter()
{
    cout << "\t\t\t\t\033[34m\033[1m@@@   @      @@@@@  @@@@@  @@@@        @@@@  @@@@@  @@    @  @  @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @@@   @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @ @@  @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@@@   @      @   @  @   @  @   @       @@@   @@@@@  @  @  @  @@\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @  @@ @  @ @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@  @  @      @   @  @   @  @   @       @  @  @   @  @   @@@  @  @\033[0m\033[0m\n";
    cout << "\t\t\t\t\033[34m\033[1m@@@   @@@@@  @@@@@  @@@@@  @@@@        @@@   @   @  @    @@  @   @\033[0m\033[0m\n";
};

class donor; // forward declaration for using the friend function

class donor
{
    string donor_name;
    string donor_id; // for ease in process of searching donor record
    string blood_group;
    string history; // includes any chronic disease and long term medication
    string age;     // date of previous blood donation
    string wgt;

public:
    ~donor(){};
    friend void option1(donor dummy);
    friend void table_printer();
    friend void modifier();
    friend void ddeleter();
};
class tblood
{
    int a_pos;
    int b_pos;
    int o_pos;
    int ab_pos;
    int a_neg;
    int b_neg;
    int o_neg;
    int ab_neg;

public:
    void getdata();

    void new_tester(string ninja, tblood qwe);
    friend void data_refresher(tblood xyx);
    void blood_amount();
    void printdata();
};
void tblood::printdata()
{
    cout << "a pos :" << a_pos << endl;
    cout << "a neg :" << a_neg << endl;
    cout << "b pos:" << b_pos << endl;
    cout << "b neg:" << b_neg << endl;
    cout << "ab pos:" << ab_pos << endl;
    cout << "ab neg:" << ab_neg << endl;
    cout << "o pos:" << o_pos << endl;
    cout << "o neg :" << o_neg << endl;
}
void tblood::getdata()
{
    a_pos = 0;
    b_pos = 0;
    o_pos = 0;
    ab_pos = 0;
    a_neg = 0;
    b_neg = 0;
    o_neg = 0;
    ab_neg = 0;
};
void tblood::new_tester(string ninja, tblood qwe)
{
    if (ninja == "a+")
    {
        qwe.a_pos++;
    }
    else if (ninja == "a-")
    {
        qwe.a_neg++;
    }
    else if (ninja == "b+")
    {
        qwe.b_pos++;
    }
    else if (ninja == "a-")
    {
        qwe.b_neg++;
    }
    else if (ninja == "a-")
    {
        qwe.ab_pos++;
    }
    else if (ninja == "a-")
    {
        qwe.ab_neg++;
    }
    else if (ninja == "a-")
    {
        qwe.o_pos++;
    }
    else if (ninja == "a-")
    {
        qwe.o_neg++;
    };
    cout << "\n\n\t\t\t\tyour data has been updatedn\n"
         << endl;
};

void data_refresher(tblood xyx)
{
    xyx.getdata();
    ifstream opner;
    opner.open("donorlist.txt", ios::in);

    string str280;
    while (!opner.eof())
    {
        getline(opner, str280);

        if (str280 == "a+")
        {
            (xyx.a_pos)++;
        }
        else if (str280 == "a-")
        {
            xyx.a_neg++;
        }
        else if (str280 == "b+")
        {
            xyx.b_pos++;
        }
        else if (str280 == "b-")
        {
            xyx.b_neg++;
        }
        else if (str280 == "ab+")
        {
            xyx.ab_pos++;
        }
        else if (str280 == "ab-")
        {
            xyx.ab_neg++;
        }
        else if (str280 == "o-")
        {
            xyx.o_neg++;
        }
        else if (str280 == "o+")
        {
            xyx.o_pos++;
        }
    };
};

void h_printer(){

};
void certificate()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t\tCERTIFICATE OF APPERICIATION\n\n\n";
    cout << "#1 We appreciate your donation! Your contribution will help us change lives \nliterally! Someone who would have lost their life was spared because you gave us your blood. \nSomeone's quality of life was improved because you gave us your blood.\n\n";
};

void option1(donor dummy)
{
    cout << "enter name of donor" << endl;
    cin >> dummy.donor_name;
    cout << "enter id of donor" << endl;
    cin >> dummy.donor_id;
    cout << "enter blood group of donor" << endl;
    cin >> dummy.blood_group;

    cout << "enter history of donor" << endl;
    cin >> dummy.history;
    cout << "enter age of donor" << endl;
    cin >> dummy.age;
    cout << "enter wieght of donor" << endl;
    cin >> dummy.wgt;

    ofstream indata;
    indata.open("donorlist.txt", ios::app);
    indata << dummy.donor_id << endl;
    indata << dummy.donor_name << endl;
    indata << dummy.blood_group << endl;
    indata << dummy.history << endl;
    indata << dummy.age << endl;
    indata << dummy.wgt << endl;
    indata.close();
};

void option2(string dummy)
{
    ifstream outdata;
    outdata.open("donorlist.txt", ios::out);
    string cmpr;
    do
    {
        getline(outdata, cmpr);
    } while (cmpr != dummy);
    cout << "details of donor with id  " << cmpr << " are ::\n";
    getline(outdata, cmpr);
    cout << "name:" << cmpr << endl;
    getline(outdata, cmpr);
    cout << "blood group:" << cmpr << endl;

    getline(outdata, cmpr);
    cout << "history:" << cmpr << endl;

    getline(outdata, cmpr);
    cout << "age:" << cmpr << endl;

    getline(outdata, cmpr);
    cout << "wieght:" << cmpr << endl;

    outdata.close();
};
void option3(){};
void loginpage()
{
    ifstream outdata;
    string name;
    cout << "enter username :" << endl;
    cin >> name;
    outdata.open("login_page2.txt", ios::out);
    string compare;
    do
    {
        getline(outdata, compare);
    } while (compare != name);
    cout << "username::" << name << endl;
    string passw;
    cout << "enter password :" << endl;
    cin >> passw;
    getline(outdata, compare);
    if (compare == passw)
    {
        cout << "access granted" << endl;
    }
    else
    {
        cout << "access denied" << endl;
        exit(0);
    }
};
void table_printer()
{
    string avail;
    string ttable[16][6];
    donor donors[16];
    ifstream details;
    details.open("donorlist.txt", ios::out);
    for (int i = 0; i < 16; i++)
    {
        getline(details, avail);
        donors[i].donor_id = avail;
        getline(details, avail);
        donors[i].donor_name = avail;
        getline(details, avail);
        donors[i].blood_group = avail;
        getline(details, avail);
        donors[i].history = avail;
        getline(details, avail);
        donors[i].wgt = avail;
        getline(details, avail);
        donors[i].age = avail;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][0] = donors[i].donor_id;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][1] = donors[i].donor_name;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][2] = donors[i].blood_group;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][3] = donors[i].history;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][4] = donors[i].wgt;
    };
    for (int i = 0; i < 16; i++)
    {
        ttable[i][5] = donors[i].age;
    };

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << ttable[i][j] << setw(15) << "\t";
        }
        cout << endl;
    }
    details.close();
};
void modifier()
{

    string enter;
    cout << "enter the id of donor to be modified:\n";
    cin >> enter;
    string avail;

    donor donors[16];
    ifstream details;
    details.open("donorlist.txt", ios::out);
    for (int i = 0; i < 16; i++)
    {
        getline(details, avail);
        donors[i].donor_id = avail;
        getline(details, avail);
        donors[i].donor_name = avail;
        getline(details, avail);
        donors[i].blood_group = avail;
        getline(details, avail);
        donors[i].history = avail;
        getline(details, avail);
        donors[i].wgt = avail;
        getline(details, avail);
        donors[i].age = avail;
    };

    details.close();
    int temp;
    for (int i = 0; i < 16; i++)
    {
        if (donors[i].donor_id == enter)
        {
            temp = i;
            break;
        };
    }
    donor happy;
    cout << "enter new name:" << endl;
    cin >> happy.donor_name;
    cout << "enter new blood group:\n";
    cin >> happy.blood_group;
    cout << "enter new weight:\n";
    cin >> happy.wgt;
    cout << "enter new age:\n";
    cin >> happy.age;
    cout << "enter new history:\n";
    cin >> happy.history;

    donors[temp].donor_name = happy.donor_name;
    donors[temp].blood_group = happy.blood_group;
    donors[temp].wgt = happy.wgt;
    donors[temp].age = happy.age;
    donors[temp].history = happy.history;

    ofstream ppp;
    ppp.open("donorlist.txt", ios::trunc);
    for (int i = 0; i < 16; i++)
    {
        ppp << donors[i].donor_id << endl;
        ;
        ppp << donors[i].donor_name << endl;
        ;
        ppp << donors[i].blood_group << endl;
        ;
        ppp << donors[i].history << endl;
        ;
        ppp << donors[i].wgt << endl;
        ;
        ppp << donors[i].age << endl;
        ;
    }
    ppp.close();
};
void ddeleter()
{

    string enter;
    cout << "enter the id of donor to be deleted:\n";
    cin >> enter;
    string avail;

    donor donors[16];
    ifstream details;
    details.open("donorlist.txt", ios::out);
    for (int i = 0; i < 16; i++)
    {
        getline(details, avail);
        donors[i].donor_id = avail;
        getline(details, avail);
        donors[i].donor_name = avail;
        getline(details, avail);
        donors[i].blood_group = avail;
        getline(details, avail);
        donors[i].history = avail;
        getline(details, avail);
        donors[i].wgt = avail;
        getline(details, avail);
        donors[i].age = avail;
    };

    details.close();
    int temp;
    for (int i = 0; i < 16; i++)
    {
        if (donors[i].donor_id == enter)
        {
            temp = i;
            break;
        };
    }

    for (int i = temp; i < 15; i++)
    {
        donors[i] = donors[i + 1];
    };

    ofstream ppp;
    ppp.open("donorlist.txt", ios::trunc);
    for (int i = 0; i < 15; i++)
    {
        if (i == temp)
        {
            continue;
        }
        ppp << donors[i].donor_id << endl;
        ;
        ppp << donors[i].donor_name << endl;
        ;
        ppp << donors[i].blood_group << endl;
        ;
        ppp << donors[i].history << endl;
        ;
        ppp << donors[i].wgt << endl;
        ;
        ppp << donors[i].age << endl;
        ;
    }
    ppp.close();
};

int main()
{
    tblood blood_database;
    blood_database.getdata();
    int option;
    bbprinter();

    cout << "\n\n\n\t\t\t\t" << endl;
    cout << "\t\t\t\t\033[4mLOGIN\033[0m\n";
    loginpage();
    h_printer();
    cout << "\n\n\n\n\n\t\t\t\t\t\t \033[4m enter 0 to next \033[0m\n";
    int next;
    cin >> next;
    if (next == 0)
    {
        system("cls");
    };
    while (1)
    {
        cout << "\t\t\tSELECT AN OPERATION TO PERFORM::" << endl;
        cout << "\n\n\n\n\t\t\t\t\toptions\n\t\t1.new donnor\n\t\t2.search old donor\n\t\t3.modify data\n\t\t4.delete record\n\t\t5.buy blood\n\t\t6.exit\n\t\t7.refresh database\n\t\t8.print table\n\t\t9.modify data\n\t\t10. delete donor" << endl;
        cin >> option;
        system("cls");
        switch (option)
        {
        case 1:
        {
            donor add_donor;
            option1(add_donor);
            certificate();
            cout << "\n\n\n\t\t\t\t";
            date_printer();
        };
        break;
        case 2:
        {
            cout << "enter the id of donor to be searched\n ";
            string donor_id;
            cin >> donor_id;
            option2(donor_id);
        }
        break;
        case3:
        {
            cout << "enter the id of donor whose data is to be modified  ::\n";
            string id2;
            cin >> id2;
        }
        break;
        case 6:
            exit(0);
        case 7:
        {
            data_refresher(blood_database);
            blood_database.printdata();
        }
        break;
        case 8:
        {
            table_printer();
        }
        break;
        case 9:
        {
            modifier();
        }
        break;
        case 10:
        {
            ddeleter();
        }
        break;
        }

        sleep(10);
        system("cls");
    }
    return 0;
}