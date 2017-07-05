#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &str)
{
    string temp_string = "";
    
    ifstream fin;
    fin.open(str.c_str());
    if (!fin.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }
    
    
    while (!fin.eof())
    {
        fin >> temp_string;
        dict.push_back(temp_string);
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{
    int check_first = 0;
    for (list<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        if (*it == start)
        {
            check_first = 1;
        }
    }
    if (check_first == 0)
    {
        cout << "Error: First word not found." << endl;
        return;
    }
    
    
    int check_end = 0;
    for (list<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        if (*it == end)
        {
            check_end = 1;
            
        }
    }
    if (check_end == 0)
    {
        cout << "Error: Last word not found." << endl;
        return;
    }
    
//-------------------------------------------------------
//main algorithm
//-------------------------------------------------------
    stack<string> my_stack;    
    my_stack.push(start);       //stack of strings with first word pushed
    
    queue<stack<string> > q;
    q.push(my_stack);          //push stack onto queue
    unsigned letter_counter = 0;
    
    ofstream fout;
    fout.open(outputFile.c_str());
    if (!fout.is_open())
    {
        cout << "Could not open " << outputFile << endl;
        return;
    }
    if (start == end)
    {
        fout << start << ' ';
        fout.close();
        return;
    }

    while (!q.empty())                       //new queue
    {
        string temp_string = q.front().top();
        for (list<string>::iterator it = dict.begin(); it != dict.end(); ) //new word
        {
            for (unsigned i = 0; i < 5; ++i)               //new letter
            {
                if (temp_string.at(i) == it->at(i))
                {
                    ++letter_counter;
                }
            }
            
            if (letter_counter == 4)   //one-off word
            {
                stack<string> temp_stack = q.front();
                temp_stack.push(*it);
                if (*it == end)    //end word
                {
                    list<string> out;           //fill list
                    while (!q.front().empty())
                    {
                        out.push_front(q.front().top());
                        q.front().pop();
                    }
                    for (list<string>::iterator it = out.begin(); it != out.end(); ++it)
                    {
                        fout << *it << ' ';
                    }
                    fout << end << ' ';
                    fout.close();
                    return;
                }
                q.push(temp_stack);
                it = dict.erase(it);
            }
            else
            {
                ++it;
            }
            letter_counter = 0;
        }
        q.pop();
    }
    fout << "No Word Ladder Found!!" << endl;
    fout.close();
    return;
}