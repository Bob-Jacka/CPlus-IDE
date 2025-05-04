#pragma once

#include <iostream>
#include <string>

using namespace std;

//Print string (msg) without new line.
inline void print(const string &msg)
{
    cout << msg;
}

//Print string (msg) with new line.
inline void println(const string &msg)
{
    cout << msg << endl;
}

//Print error message in console.
inline void print_error(const string &msg)
{
    cout << msg << endl;
}
