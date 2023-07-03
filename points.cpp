#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;

int main()
{
    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << "Hello " << name << "!" << endl;

    cout << "Please, enter your middle and final assessments: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all assessments for your homework and EOF at the end: ";

    int count = 0;
    double sum = 0;

    double x;

    while (cin >> x) {
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Your final assessment is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;

    return 0;
}