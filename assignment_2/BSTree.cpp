#include "Node.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

BSTree::BSTree() //DONE
{
    root = 0;
}

BSTree::~BSTree()
{
    if (root)
    {
        destructor(root);
    }
}

void BSTree::destructor(Node *n)
{
    if (n)
    {
        Node *temp = n;
        destructor(n->left);
        destructor(n->right);
        delete temp;
    }
}

void BSTree::insert(const string &str) //DONE
{
    Node *temp = new Node(str);
    if (!root)
    {
        root = temp;
        return;
    }
    insert(root, temp);
    return;
}

bool BSTree::search(const string &str) const //DONE
{
    if (!root)
    {
        return false;
    }
    if (search(root, str))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BSTree::inOrder() const //DONE
{
    inOrder(root);
    cout << endl;
}

void BSTree::postOrder() const //DONE
{
    postOrder(root);
    cout << endl;
}

void BSTree::preOrder() const //DONE
{
    preOrder(root);
    cout << endl;
}

void BSTree::inOrder(Node *NodePtr) const //DONE
{
    if (NodePtr)
    {
        inOrder(NodePtr->left);
        cout << NodePtr->data << "(" << NodePtr->count << "), ";
        inOrder(NodePtr->right);
    }
}

void BSTree::postOrder(Node *NodePtr) const //DONE
{
    if (NodePtr)
    {
        postOrder(NodePtr->left);
        postOrder(NodePtr->right);
        cout << NodePtr->data <<  "(" << NodePtr->count << "), ";
    }
}

void BSTree::preOrder(Node *NodePtr) const //DONE
{
    if (NodePtr)
    {
        cout << NodePtr->data <<  "(" << NodePtr->count << "), ";
        preOrder(NodePtr->left);
        preOrder(NodePtr->right);
    }
}

string BSTree::largest() const //DONE
{
    if (!root)
    {
        return "";
    }
    return largest(root);
}

string BSTree::largest(const Node *n) const //DONE
{
    string word = "";
    if (!n->right)
    {
        return n->data;
    }
    else
    {
        word = largest(n->right);
    }
    return word;
}

Node *BSTree::findMax(Node *n) const //DONE
{
    Node *temp = 0;
    if (!n->right)
    {
        return n;
    }
    else
    {
        temp = findMax(n->right);
    }
    return temp;
}

Node *BSTree::findMin(Node *n) const //DONE
{
    Node *temp = 0;
    if (!n->left)
    {
        return n;
    }
    else
    {
        temp = findMin(n->left);
    }
    return temp;
}

string BSTree::smallest() const //DONE
{
    if (!root)
    {
        return "";
    }
   return smallest(root);
}

string BSTree::smallest(const Node *n) const //DONE
{
    string word = "";
    if (!n->left)
    {
        // word = n->data;
        return n->data;
    }
    else
    {
        word = smallest(n->left);
    }
    return word;
}

int BSTree::height(const string &str) const //DONE
{
    if (!root)
    {
        return -1;
    }
    if (!search(str))
    {
        return -1;
    }
    Node *temp = search(root, str);
    return height(temp);
}

int BSTree::height(Node *n) const
{
    if (!n)
    {
        return -1;
    }
    int count = height(n->left);
    int count2 = height(n->right);
    if (count > count2)
    {
        return count + 1;
    }
    else
    {
        return count2 + 1;
    }
}

Node *BSTree::parent(Node *n, const string &str) const
{
    if (str == n->data)
    {
        return n;
    }
    else if (((n->left) && (str == n->left->data)) || ((n->right) && (str == n->right->data)))
    {
        return n;
    }
    else if (n->data > str)
    {
        return parent(n->left, str);
    }
    else
    {
        return parent(n->right, str);
    }
}

void BSTree::remove(const string &str)
{
    if (!search(str)) //return if not found
    {
        return;
    }
    else if (search(root, str)->count > 1)  //if duplicate, decrement
    {
        --search(root, str)->count;
        return;
    }
    remove(search(root, str), str);
    return;
}

void BSTree::remove(Node *n, const string &str)
{
    if ((n->left == 0) && (n->right == 0)) //if a leaf
    {
        if (n == root)
        {
            Node *temp = root;
            root = 0;
            delete temp;
            return;
        }
        Node *temp = parent(root, n->data);
        if (temp->left == n)
        {
            temp->left = 0;
        }
        else if (temp->right == n)
        {
            temp->right = 0;
        }
        delete n;
    } 
    else if ((n->left == 0) && (n->right)) //if right child only
    {
        string temp_string = smallest(n->right);
        int temp_count = search(n->right, temp_string)->count;
        --search(n->right, temp_string)->count;
        remove(search(n, smallest(n->right)), smallest(n->right));
        n->data = temp_string;
        n->count = temp_count;
    } 
    else //if left or both
    {
        string temp_string = largest(n->left);
        int temp_count = search(n->left, temp_string)->count;
        --search(n->left, temp_string)->count;
        remove(search(n, largest(n->left)), largest(n->left));
        n->data = temp_string;
        n->count = temp_count;
    }
    return;
}

Node *BSTree::search(Node *n, const string &str) const //DONE
{
    if (!n)
    {
        return 0;
    }
    if (n->data == str)
    {
        return n;
    }
    else if (n->data > str)
    {
        return search(n->left, str);
    }
    else if (n->data < str)
    {
        return search(n->right, str);
    }
    else
    {
        return search(n->right, str);
    }
}

void BSTree::insert(Node *n, Node *temp) //DONE
{
    if ((n->left == 0) && (n->right == 0))  //if node is a leaf
    {
        if (temp->data == n->data)    //if string matches current leaf data
        {
            ++n->count;
            return;
        }
        else
        {
            if (n->data > temp->data)
            {
                n->left = temp;
                return;
            }
            else
            {
                n->right = temp;
                return;
            }
        }
    }
    else if ((n->left == 0) || (n->right == 0)) //if half leaf
    {
        if (n->data == temp->data)
        {
            ++n->count;
            return;
        }
        if (n->data > temp->data)
        {
            if (!n->left)
            {
                n->left = temp;
                return;
            }
            else
            {
                insert(n->left, temp);
            }
        }
        if (n->data < temp->data)
        {
            if (!n->right)
            {
                n->right = temp;
                return;
            }
            else
            {
                insert(n->right, temp);
            }
        }
    }
    else if (n->data > temp->data)
    {
        insert(n->left, temp);
    }
    else if (n->data < temp->data)
    {
        insert(n->right, temp);
    }
    else 
    {
        ++n->count;
    }
    return;
}