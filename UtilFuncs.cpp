#include <iostream>

using namespace std;

//Print string (msg) without new line.
void print(const string &msg)
{
    cout << msg;
}

//Print string (msg) with new line.
void println(const string &msg)
{
    cout << msg << endl;
}

//Print error message in console.
void print_error(const string &msg)
{
    cout << msg << endl;
}
