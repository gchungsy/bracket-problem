/*
 Author:      Gary Chung
 Date:        March 15, 2016
 Description: My solution to balance brackets problem, and more
              For fun: if the number of brackets is even (balance) -> )))(((
              turn each pair of bracket into an egg like this -> ()()()
              after sorting them -> ((()))
*/
#include <iostream>
#include <fstream>

using namespace std;

// forward function declarations
bool balance_brackets(string str);
string sort_brackets(string str);
void egg_generator(string str);

// program entry point
int main()
{
    ifstream inputFile("testcases.txt");
    string inputstr;
    string tmpstr;

    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            inputFile >> inputstr;
            cout << "Current inputstr: " << inputstr << endl;
            if(balance_brackets(inputstr))
            {
                tmpstr = sort_brackets(inputstr);
                egg_generator(tmpstr);
            }
            else
            {
                sort_brackets(inputstr);
                cout << "Fail! We have an broken egg" << endl;
                cout << endl;
            }
        }
    }
    return 0;
}

bool balance_brackets(string str)
{
    char tmp; // current character in current index
    int last; // index of the last element
    int counter = 0;

    for ( size_t i = 0; i <= str.length() - 1; i++)
    {
        if(str[i] == '(') counter += 1;
        else if(str[i] == ')') counter -= 1;
    }
    // Compare results
    if(counter != 0) return false;
    return true;
}

string sort_brackets(string str)
{
    char tmp;
    int last;
    int exit_condition;
    last = str.length() - 1;
    exit_condition = last;

    for ( size_t i = 0; i <= exit_condition; i++)
    {
        tmp = str[i];
        if(i != last)
        {
            if(tmp == ')')
            {
                // 'delete' element by shifting all elements to current position
                for (size_t j = i; j < last; j++)
                    str[j] = str[j+1];
                str[last] = tmp;
                exit_condition -= 1;
                i--;
            }
        }
        // Compare with last element
        if(i == last && tmp == '(')
        {
            for (size_t j = i; j > 0; j--)
                str[j] = str[j-1];
            str[0] = tmp;
        }
    }
    // Compare results
    cout << "After sorting: " << str << endl;
    return str;
}

void egg_generator(string str)
{
    int last = str.length() - 1;

    for ( size_t i = 1; str[i] == '('; i += 2)
    {
        char tmp = str[i];
        str[i] = str[last - i];
        str[last - i] = tmp;
    }
    cout << "Success! " << str << endl << endl;
}
