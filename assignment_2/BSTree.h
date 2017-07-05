#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

class BSTree {

  private:
    Node *root;

  private:
    void preOrder(Node *) const;
    void inOrder(Node *) const;
    void postOrder(Node *) const;
    void insert(Node *, Node *);
    Node *search(Node *, const string &) const;
    string smallest(const Node *) const;
    string largest(const Node *n) const;
    void destructor(Node *);
    Node *findMax(Node *) const;
    Node *findMin(Node *) const;
    void remove(Node *, const string &);
    Node *parent(Node *, const string &) const;
    int height(Node *) const;

  public:
    BSTree();
    ~BSTree();
    void insert(const string &);
    bool search(const string &) const;
    void inOrder( ) const;
    void postOrder( ) const;
    void preOrder( ) const;
    string largest( ) const;
    string smallest( ) const;
    int height(const string &) const;
    void remove(const string &);
};

#endif

