#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{
    srand(time(0));

    BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();

    tree1->add("10");
    tree1->add("20");
    tree1->add("30");
    tree1->add("40");
    tree1->add("50");
    tree1->add("60");
    tree1->add("70");
    tree1->add("80");
    tree1->add("90");
    tree1->add("100");
    tree1->add("110");

    BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();

    tree2->add("10");
    tree2->add("20");
    tree2->add("30");
    tree2->add("40");
    tree2->add("50");
    tree2->add("60");
    tree2->add("70");
    tree2->add("80");
    tree2->add("90");
    tree2->add("100");
    tree2->add("110");

    cout<<"Tree 1 Inorder:\n";
    tree1->inorderTraverse(display);
    cout<<"Tree 2 Inorder:\n";
    tree2->inorderTraverse(display);

    cout << "Tree 1 height: " << tree1->getHeight() << endl;
    cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;

    cout << "Tree 2 height: " << tree2->getHeight() << endl;
    cout << "Tree 2 number of nodes: " << tree2->getNumberOfNodes() << endl;

   return 0;
}  // end main

/* SAMPLE OUTPUT
 Script started on Fri Apr 15 20:33:03 2016
 [?1034hbash-3.2$ ./a.out
 Tree 1 Inorder:
 Displaying item - 110
 Displaying item - 40
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Displaying item - 100
 Displaying item - 70
 Displaying item - 20
 Displaying item - 90
 Displaying item - 80
 Displaying item - 50
 Tree 2 Inorder:
 Displaying item - 90
 Displaying item - 20
 Displaying item - 100
 Displaying item - 40
 Displaying item - 50
 Displaying item - 70
 Displaying item - 110
 Displaying item - 10
 Displaying item - 60
 Displaying item - 30
 Displaying item - 80
 Tree 1 height: 5
 Tree 1 number of nodes: 11
 Tree 2 height: 6
 Tree 2 number of nodes: 11
 bash-3.2$ exit
 exit

 Script done on Fri Apr 15 20:33:12 2016

 */
