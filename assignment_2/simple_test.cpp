#include "Node.h"
#include <iostream>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << endl;
  cout << "Inorder = ";
  tree->inOrder( ) ;
  cout << endl;
  cout << "Postorder = ";
  tree->postOrder( );
  cout << endl;
}

int main( ) {

  BSTree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert("hoppy");
  tree.insert("gadget");
  tree.insert("dad");
  tree.insert("happy");
  tree.insert("hoppy");
  tree.insert("mother");
  tree.insert("zebra");
  tree.insert("make");
  tree.insert("mother");
  printOrders(&tree);
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search testing" << endl;
  if (tree.search("mother")) {
    cout << "Passed" << endl;
  } else {
    cout << "Failed" << endl;
  }
  cout << "----------------------------------------------------------------" 
      << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
      << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
      << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"hoppy\" = " 
      << tree.height("mother") << endl;
  cout << "----------------------------------------------------------------" 
      << endl;
  // cout << "Test 6: Remove testing" << endl;
  // cout << "Removing \"hoppy\"" << endl;
  // tree.remove("hoppy");
  // printOrders(&tree);
  // cout << "----------------------------------------------------------------" 
  //     << endl;

  return 0;
}