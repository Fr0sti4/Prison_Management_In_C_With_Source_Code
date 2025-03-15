//Prison management system

// username = admin
// password = pass
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>    // For std::chrono::milliseconds
#include <thread>    // For std::this_thread::sleep_for
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

void FrontPage(); // Front Page Or Main Page
void Date();      // Getting Date
void Time();      // Display time

class Prison
{
private:
    // Detaiils of Prisoner
    std::array<std::string, 20> First_Name = { "" };
    std::array<std::string, 20> Second_Name;
    std::array<std::string, 20> Gender;
    std::array<int, 20> CellNo = { 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010,
                              1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020 };
    std::array<int, 20> Age;
    std::array<double, 20> Height;
    std::array<std::string, 20> Eyecolor;
    std::array<std::string, 20> Crime;
    std::array<std::string, 20> Punishmentmonths;
    int o = 0;

public:
    void SetData();      // Set data of the prisoners
    void Details();      // Getting details of the prisoners
    void Afterlogin();   // After login page OR Menu function
    void Attendance();   // Storing attendace of the prisoners
    void Release();      // Release the prisoners
    void SearchPrison(); // Search Prison
    void PrisonFile();   // Priosn File
    void Logout();       // Logout
    void Exit();         // Exit function
    void Login();        //login
};

void Prison::Logout()
{
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\t";
    cout << "logging out ";

    for (int x = 0; x < 15; x++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << ".";
    }   
    Prison::Login();
}

void Prison::Login()
{

    std::array<std::string, 15> Username;
    std::array<std::string, 15> Password;
    char Epwd;
    int true1 = 1;
    int try1 = 0;

    do
    {
        system("cls");
        Time();
        cout << "\n\n\n\n\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    ----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    |   PRISON STATION MANAGEMENT SYSTEM   |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    ----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin >> Username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        for (i = 0;;)
        {
            Epwd = getch();
            if ((Epwd >= 'a' && Epwd <= 'z') || (Epwd >= 'A' && Epwd <= 'Z') || (Epwd >= '0' && Epwd <= '9'))
            {
                Password[i] = Epwd;
                ++i;
                cout << "*";
            }
            if (Epwd == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (Epwd == '\r')
            {
                Password[i] = '\0';
                break;
            }
        }

        if (strcmp(Username, "admin") == 0 && strcmp(Password, "pass") == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t";
            system("pause");
            system("cls");
            true1 = 0;
            try1 = 4;
            Prison::Afterlogin();
        }
        else
        {
            system("cls");
            try1 = try1 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3 - try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("pause");

            if (try1 >= 3)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");
                exit;
            }
        }
    } while (try1 < 3);
}

void Prison ::SetData()
{
    system("cls");
    Time();
    int s;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    |         Enter basic information of prisoner       |\n";
    cout << "\t\t\t\t    |                                                   |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    cout << "Enter first name : ";
    cin >> First_Name[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter second name : ";
    cin >> Second_Name[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter gender : ";
    cin >> Gender[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter age : ";
    cin >> Age[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter height : ";
    cin >> Height[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter eyecolor : ";
    cin >> Eyecolor[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter crime : ";
    cin >> Crime[o];
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Enter punishment span in months : ";
    cin >> Punishmentmonths[o];
    cout << "\t\t\t\t\t";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout << "Your Cell No is " << CellNo[o];
    cout << "\n\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    o = o + 1;
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison ::Afterlogin();
    }
}

void Prison ::Details()
{
    system("cls");
    Time();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    |                                                   |\n";
    cout << "\t\t\t\t    |                Prisoner list                      |\n";
    cout << "\t\t\t\t    |                                                   |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    -----------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    int s = 0;
    int c = 0; 
    int p = 0;

    cout << "\n\t\t\t\t\t";

    cout << "\n===========================================================================================================\n";
    cout << "SR.\tNAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
    cout << "===========================================================================================================\n";

    for (int x = 0; x <= 19; x++)
    {
        if (First_Name[x] != " ")
        {
            p++;
            cout << p << "\t" << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
            cout << "\n"
                 << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "\n\t\t\t\t\t";
        cout << "No prisoner Present";
        cout << "\n";
        cout << "\t\t\t\t\t";
    }
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Afterlogin();
    }
}

void Prison ::Attendance()
{
    int s = 0;
    int l = 0;
    int c = 0;
    char ch;
    do
    {
        system("cls");
        Time();
        system("cls");
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |           Prisoner attendance maintainer          |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        cout << "\n\t\t\t\t\t";
        cout << "\n===========================================================================================================\n";
        cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
        cout << "===========================================================================================================\n";
        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                cout << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
                cout << "\n"
                     << endl;
                c++;
            }
        }
        if (c != 0)
        {
            cout << "\n\t\t\t\t\t";
            cout << "Enter the cell  block of the prisoner :";
            scanf("%d", &l);
            l = l - 1001;
            cout << "\n\t\t\t\t\t";
            cout << "Name : ";
            cout << First_Name[l] << " " << Second_Name[l];
            Punishmentmonths[l]--;
            cout << "\n\t\t\t\t\t";
            cout << "Punishment for :" << Punishmentmonths[l] << " months";
            if (Punishmentmonths[l] <= 0)
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is ready for release";
            }
            cout << "\n\n";
            cout << "\n\t\t\t\t\t";
            cout << "Press y to choose another prisoner and press n to exit :";
            cin >> ch;
        }
        else
        {
            cout << "\t\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t\t";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t                                                    \n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t    |             No prisoners present             |\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t    ------------------------------------------------\n";
        }

    } while (ch == 'y');
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Afterlogin();
    }
}

void Prison ::Release()
{
    int s = 0;
    int l = 0;
    int c = 0;
    int r = 0;
    char ch;
    do
    {
        system("cls");
        Time();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |                Release prisoner                   |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        cout << "\n\t\t\t\t\t";
        cout << "\n===========================================================================================================\n";
        cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
        cout << "===========================================================================================================\n";

        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                cout << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t\t" << Age[x] << "\t" << Gender[x] << "\t" << Height[x] << "\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
                cout << "\n"
                     << endl;
                c++;
            }
        }
        if (c != 0)
        {
            cout << "\n\t\t\t\t\t";
            cout << "Enter the cell block of the prisoner :";
            scanf("%d", &l);
            l = l - 1001;
            cout << "\n\t\t\t\t\t";
            cout << "Name : ";
            cout << First_Name[l] << " " << Second_Name[l];
            cout << "\n\t\t\t\t\t";
            if (Punishmentmonths[l] <= 0)
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is ready for release";
                cout << "\n\t\t\t\t\t";
                cout << "Press 1 to release the prisoner :";
                cin >> r;
                if (r == 1)
                {
                    First_Name[l] = " ";
                    Second_Name[l] = " ";
                    Gender[l] = " ";
                    Age[l] = 0;
                    Height[l] = 0;
                    Eyecolor[l] = " ";
                    Punishmentmonths[l] = 0;
                    cout << "\n\t\t\t\t\tProcessing";

                    for (int process = 0; process < 7; process++)
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(200));
                        cout << ".";
                    }
                    cout << "\n\t\t\t\t\t";
                    cout << "Prisoner released successfully";
                }
            }
            else
            {
                cout << "\n\t\t\t\t\t";
                cout << "Prisoner is not ready for release";
            }

            cout << "\n\n";
            cout << "\n\t\t\t\t\t";
            cout << "Press y to choose another prisoner and press n to exit :";
            cin >> ch;
        }
        else
        {
            cout << "\t\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t\t";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t                                                    \n";
            cout << "\t\t\t\t    ------------------------------------------------\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t    |             No prisoners present             |\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            cout << "\t\t\t\t    ------------------------------------------------\n";
            break;
        }
    } while (ch == 'y');
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Afterlogin();
    }
}

void Prison ::SearchPrison()
{
    int info;
    int CN;
    int i;
    int s;
    int l;
    int c = 0;
    int p = 0;

    system("cls");
    cout << "\t\t\t\t    ----------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    |             Search Menu              |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    ----------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Enter the prisoner cell id to be searched : ";
    cin >> CN;
    cout << "\n\t\t\t\t";
    cout << "\n===========================================================================================================\n";
    cout << "NAME\t\t\tCell Block\tAge\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
    cout << "===========================================================================================================\n";
    l = CN - 1001;
    info = CellNo[l];
    if (CN == info)
    {
        if (First_Name[l] != " ")
        {
            cout << First_Name[l] << "" << Second_Name[l] << "\t\t" << CellNo[l] << "\t\t" << Age[l] << "\t" << Gender[l] << "\t" << Height[l] << "\t" << Eyecolor[l] << "\t\t" << Crime[l] << "\t\t" << Punishmentmonths[l] << endl;
            cout << "\n"
                 << endl;
        }
        else
        {
            cout << "\n";
            cout << "\t\t\t\t";
            cout << "\n";
            cout << "\t\t\t\t";
            cout << "cell block empty" << endl;
        }
    }
    else
    {
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t";
        cout << "invalid cell id" << endl;
    }
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Afterlogin();
    }
}

void Prison ::PrisonFile()
{
    Time();
    system("cls");

    int format;
    int s, c = 0, p = 0;
    cout << "\n\n\n";
    cout << "\t\t\t\t-----------------------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t|                                                               |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t|                     1)   Txt File                             |\n";
    cout << "\t\t\t\t|                                                               |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t|                     2)   Html File                            |\n";
    cout << "\t\t\t\t|                                                               |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t|                     3)   Word File                            |\n";
    cout << "\t\t\t\t|                                                               |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t-----------------------------------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t";
    cout << "In which format you want to open your file? ";
    cin >> format;
    std::ofstream MyFile_;
    switch (format)
    {
    case 1:
        Time();
        system("cls");
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |        Txt File created successfully              |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";

        MyFile_.open("Prison_Data.txt");

        MyFile_ << "\t\t\t\t    -----------------------------------------------------\n";
        MyFile_ << "\t\t\t\t    |                                                                            |\n";
        MyFile_ << "\t\t\t\t    |                Prisoner list                                     |\n";
        MyFile_ << "\t\t\t\t    |                                                                            |\n";
        MyFile_ << "\t\t\t\t    -----------------------------------------------------\n";

        MyFile_ << "\n\t\t\t\t\t";

        MyFile_ << "\n=====================================================================================================================\n";
        MyFile_ << "SR.\tNAME\t\t\tCell Block\tAge\t\tGender\tHeight\tEye Colour\tCrime\tPunishment\n";
        MyFile_ << "=======================================================================================================================\n";

        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                p++;
                MyFile_ << p << "\t" << First_Name[x] << "" << Second_Name[x] << "\t\t" << CellNo[x] << "\t" << Age[x] << "\t\t" << Gender[x] << "\t" << Height[x] << "\t\t" << Eyecolor[x] << "\t\t" << Crime[x] << "\t\t" << Punishmentmonths[x] << endl;
                MyFile_ << "\n"
                        << endl;
                c++;
            }
        }
        if (c == 0)
        {
            MyFile_ << "\n\t\t\t\t\t";
            MyFile_ << "No prisoner Present";
            MyFile_ << "\n";
            MyFile_ << "\t\t\t\t\t";
        }
        MyFile_.close();
        break;

    case 2:
        Time();
        system("cls");
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |          Html File created successfully           |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";

        MyFile_.open("Prison_Data.html");

        MyFile_ << "\t\t\t\t    -----------------------------------------------------";
        MyFile_ << "\t\t\t\t    |                                                   |";
        MyFile_ << "\t\t\t\t    |                Prisoner list                      |";
        MyFile_ << "\t\t\t\t    |                                                   |";
        MyFile_ << "\t\t\t\t    -----------------------------------------------------";
        MyFile_ << "<br>";

        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                MyFile_ << "First name: " << First_Name[x];
                MyFile_ << "<br>";
                MyFile_ << "Second name: " << Second_Name[x];
                MyFile_ << "<br>";
                MyFile_ << "Cell number: " << CellNo[x];
                MyFile_ << "<br>";
                MyFile_ << "Age: " << Age[x];
                MyFile_ << "<br>";
                MyFile_ << "Gender: " << Gender[x];
                MyFile_ << "<br>";
                MyFile_ << "Height: " << Height[x];
                MyFile_ << "<br>";
                MyFile_ << "Eye colour: " << Eyecolor[x];
                MyFile_ << "<br>";
                MyFile_ << "Crime: " << Crime[x];
                MyFile_ << "<br>";
                MyFile_ << "Punishment Months: " << Punishmentmonths[x];
                MyFile_ << "<br>";
                MyFile_ << "<br>";
                c++;
            }
        }
        if (c == 0)
        {

            MyFile_ << "<br>\t\t\t\t\t";
            MyFile_ << "No prisoner Present";
            MyFile_ << "<br>";
            MyFile_ << "\t\t\t\t\t";
        }
        MyFile_.close();
        break;

    case 3:
        Time();
        system("cls");
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    |          Word File created successfully           |\n";
        cout << "\t\t\t\t    |                                                   |\n";
        cout << "\t\t\t\t    -----------------------------------------------------\n";

        MyFile_.open("Prison_Data.doc");

        MyFile_ << "\t\t\t *** Prisoner list *** ";
        MyFile_ << "\n";

        for (int x = 0; x <= 19; x++)
        {
            if (First_Name[x] != " ")
            {
                MyFile_ << "First name: " << First_Name[x];
                MyFile_ << "\n";
                MyFile_ << "Second name: " << Second_Name[x];
                MyFile_ << "\n";
                MyFile_ << "Cell number: " << CellNo[x];
                MyFile_ << "\n";
                MyFile_ << "Age: " << Age[x];
                MyFile_ << "\n";
                MyFile_ << "Gender: " << Gender[x];
                MyFile_ << "\n";
                MyFile_ << "Height: " << Height[x];
                MyFile_ << "\n";
                MyFile_ << "Eye colour: " << Eyecolor[x];
                MyFile_ << "\n";
                MyFile_ << "Crime: " << Crime[x];
                MyFile_ << "\n";
                MyFile_ << "Punishment Months: " << Punishmentmonths[x];
                MyFile_ << "\n";
                MyFile_ << "\n";
                c++;
            }
        }
        if (c == 0)
        {

            MyFile_ << "\n\t\t\t\t";
            MyFile_ << "No prisoner Present";
            MyFile_ << "\n";
            MyFile_ << "\t\t\t\t\t";
        }
        MyFile_.close();
        break;
    default:
        cout << "Invalid choice";
        break;
    }

    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "Press 1 to return : ";
    scanf("%d", &s);
    if (s == 1)
    {
        Prison::Afterlogin();
    }
}

void Prison ::Afterlogin()
{
    int c;
    int v;
    do
    {
        v = 0;
        system("cls");
        Time();
        cout << "\n\n\n";
        cout << "\t\t\t\t---------------------------------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     1)   New prisoner entry                             |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     2)   Prisoner details                               |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     3)   Attendace prisoner                             |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     4)   Release prisoner                               |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     5)   Search prisoner                                |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     6)   Prison File                                    |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     7)   Logout                                         |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                     8)   Exit                                           |\n";
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t|                                                                         |\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\t\t\t\t---------------------------------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << "\n";
        cout << "\t\t\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t";
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            Prison ::SetData();
            break;
        case 2:
            Prison ::Details();
            break;
        case 3:
            Prison ::Attendance();
            break;
        case 4:
            Prison ::Release();
            break;
        case 5:
            Prison ::SearchPrison();
            break;
        case 6:
            Prison::PrisonFile();
            break;
        case 7:
            Prison::Logout();
            break;
        case 8:
            Prison::Exit();
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice\n";
            cout << "\t\t\t\tPress 1 to return : ";
            cin >> v;
        }
    } while (v == 1);
}

void Prison ::Exit()
{
    system("cls");
    Time();
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t";
    cout << "Thank you!!";
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t";
    getch();
}

void Date()
{
    time_t T = time(nullptr);
    struct tm tm = *localtime(&T);
    cout << "\n\n\n";
    cout << "\t\t\t\t\t   Date: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << "\n";
}

void Time()
{
    time_t curr_time;
    curr_time = time(nullptr);

    tm *tm_local = localtime(&curr_time);
    cout << "Time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
}

void FrontPage()
{
    int process = 0;
    system("cls");
    Time();
    Date();
    cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    ----------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    |   PRISON STATION MANAGEMENT SYSTEM   |\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\t\t\t\t    ----------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "\n\n";
    cout << "\t\t\t\t";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
   
    cout << "Mini Project   ";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << ":";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    cout << "   Prison Management System";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "\n\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
    system("pause");
    cout << "\n\t\t\t\tLoading";

    for (process = 0; process < 15; process++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        cout << ".";
    }
}

int main()
{
    Prison a;

    FrontPage();
    a.Login();
    return 0;
}
