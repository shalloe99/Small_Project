//============================================================================
// Name        : linked_list.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList ll("Test List");
    Node* n2 = new Node(88);
    ll.insert_back(n2);
    Node* new_node = new Node(10);
    ll.insert_front(new_node);
    ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

    Node* new_node2 = new Node(11);
    ll.insert_front(new_node2);
    ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

    Node* new_node3 = new Node(12);
    ll.insert_front(new_node3);
    ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

    ll.makeTestList();
    ll.print_head();
    ll.print_tail();
    ll.print();
    //system("pause");
}
