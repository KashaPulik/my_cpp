#include <iostream>

using namespace std;

int check_time(int hours, int minutes)
{
    if(hours > 23 || hours < 0)
        return 1;
    if(minutes > 59 || minutes < 0)
        return 1;
    return 0;
}

int check_input(char twodot)
{
    if (twodot == ':') 
        return 0;
    return 1;
}

int main()
{
    int minutes1, hours1;
    int minutes2, hours2;
    char twodot;
    cin >> hours1 >> twodot >> minutes1;
    if (check_input(twodot)) {
        cout << "Error1" << endl;
        return 1;
    }
    if(check_time(hours1, minutes1)) {
        cout << "Error2" << endl;
        return 1;
    }
    minutes1 += hours1 * 60;
    cin >> hours2 >> twodot >> minutes2;
    if (check_input(twodot)) {
        cout << "Error3" << endl;
        return 1;
    }
    if(check_time(hours2, minutes2)) {
        cout << "Error4" << endl;
        return 1;
    }
    minutes2 += hours2 * 60;
    if(minutes2 >= minutes1) {
        minutes2 -= minutes1;
        hours2 = minutes2 / 60;
        minutes2 = minutes2 % 60;
        cout << hours2 << ":";
        if(minutes2 < 10)
            cout << 0;
        cout << minutes2 << endl;
    } else {
        cout << "Error" << endl;
        return 1;
    }
    return 0;
}