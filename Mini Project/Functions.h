#include <iostream>
#include <chrono>
#include <ctime>
#include "Nodes.h"
#include <cctype>
#include <Windows.h>
#include <string>

using namespace std;
using namespace chrono;

enum Month
{
    January, February, March, April, May, June, July, August, September, October, November, December
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Month getMonth(int mnth) {
    Month m;
    switch (mnth) {
    case 1:
        return January;
    case 2:
        return February;
    case 3:
        return March;
    case 4:
        return April;
    case 5:
        return May;
    case 6:
        return June;
    case 7:
        return July;
    case 8:
        return August;
    case 9:
        return September;
    case 10:
        return October;
    case 11:
        return November;
    case 12:
        return December;
    }
}

string getMonth(Month month) {
    switch (month) {
    case January:
        return "January";
        break;
    case February:
        return "February";
        break;
    case March:
        return "March";
        break;
    case April:
        return "April";
        break;
    case May:
        return "May";
        break;
    case June:
        return "June";
        break;
    case July:
        return "July";
        break;
    case August:
        return "August";
        break;
    case September:
        return "September";
        break;
    case October:
        return "October";
        break;
    case November:
        return "November";
        break;
    case December:
        return "December";
        break;
    }
}

class Date {
public:
    int year;
    Month month;
    int date;

    Date() {
        auto start = chrono::system_clock::now();
        auto legacyStart = chrono::system_clock::to_time_t(start);
        tm tmBuff;
        localtime_s(&tmBuff, &legacyStart);
        date = tmBuff.tm_mday;
        month = getMonth(tmBuff.tm_mon + 1);
        year = tmBuff.tm_year + 1900;
    }

    Date(int y, Month m, int d) {
        year = y;
        month = m;
        date = d;
    }

    Date(short* rowPos, short colPos) {
        short col = colPos;
        short row = *rowPos;
        int yr;
        string input;
        short temp = col + 22;
        short temp2 = temp + 7;
        while (true) {  
            while (true) {
                SetConsoleCursorPosition(hConsole, { temp,row++ });
                cout << "Year : ";
                cin >> input;
                try {
                    yr = stoi(input);
                    break;
                }
                catch (invalid_argument&) {
                    SetConsoleCursorPosition(hConsole, { temp,row++ });
                    cout << "Enter a valid number" << endl;
                }
            }
            if (yr >= 2023)
                break;
            else {

                SetConsoleCursorPosition(hConsole, { temp2,row++ });
                cout << "Invalid year" << endl;
            }
                
        }
        year = yr;
        int mnth;
        while (true) {
            temp = colPos - 13;
            temp2 = temp + 7;
            while (true) {
                SetConsoleCursorPosition(hConsole, { temp,row++ });
                cout << "Month(Eg: January - 1, February - 2,..) : ";
                cin >> input;
                try {
                    mnth = stoi(input);
                    break;
                }
                catch (invalid_argument&) {
                    SetConsoleCursorPosition(hConsole, { temp,row++ });
                    cout << "Enter a valid number" << endl;
                }
            }
            if (mnth >= 1 && mnth <= 12)
                break;
            else {
                SetConsoleCursorPosition(hConsole, { temp2,row++ });
                cout << "Invalid Month" << endl;
            }
                
        }
        month = getMonth(mnth);
        int dt;
        while (true) {
            temp = colPos + 22;
            temp2 = temp + 7;
            while (true) {
                SetConsoleCursorPosition(hConsole, { temp,row++ });
                cout << "Date : ";
                cin >> input;
                try {
                    dt = stoi(input);
                    break;
                }
                catch (invalid_argument&) {
                    SetConsoleCursorPosition(hConsole, { temp,row++ });
                    cout << "Enter a valid number" << endl;
                }
            }
            if ((mnth == 1 || mnth== 3 || mnth == 5|| mnth== 7 || mnth== 8 || mnth== 10 || mnth == 12) && dt >= 0 && dt <= 31)
                break;
            else if (yr % 4 == 0 && mnth == 2 && dt >= 0 && dt <= 29)
                break;
            else if (yr % 4 != 0 && mnth == 2 && dt >= 0 && dt <= 28)
                break;
            else if ((mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11) && dt >= 0 && dt <= 30)
                break;
            else {
                SetConsoleCursorPosition(hConsole, { temp2,row++ });
                cout << "Invalid date" << endl;
            }
        }
        date = dt;
        *rowPos = row;
    }

    void printDate() {
        cout << year << " " << getMonth(month) << " " << date;
    }
};













