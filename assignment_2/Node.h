#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
   public:
    string data;
    int count;
    Node *left;
    Node *right;
    Node(string data) : data(data), count(1), left(0), right(0) {}
};

#endif