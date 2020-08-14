//============================================================================
// Name        : copy_assignment.cpp
// Author      : Shawn Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList ll("Test List");
    ll.insert_front(10);
    ll.insert_back(12);
    cout << "Outputting Test List..." << endl;
    cout << ll << endl;
    cout << "Printing Test List head..." << endl; ll.print_head();
    cout << "Printing Test List tail:" << endl; ll.print_tail();
    cout << endl;

    LinkedList ll2("Test List2");
    ll2.insert_front(34);
    ll2.insert_back(11);
    cout << "Outputting Test List2..." << endl;
    cout << ll2 << endl;
    cout << "Printing Test List head..." << endl; ll2.print_head();
    cout << "Printing Test List tail:" << endl; ll2.print_tail();
    cout << endl;

    ll2 = ll;
    cout << "Outputting Test List2 (after assignment, ll2=ll)..." << endl;
    cout << ll2 << endl;
    cout << "Printing Test List2 head..." << endl; ll2.print_head();
    cout << "Printing Test List2 tail:" << endl; ll2.print_tail();
    cout << endl;

    ll2.insert_after(10,11);
     cout << "Outputting Test List (after ll2.insert_after(10,11);)..." << endl;
    cout << ll << endl;
    cout << "Printing Test List head..." << endl; ll.print_head();
    cout << "Printing Test List tail:" << endl; ll.print_tail();
    cout << "Outputting Test List2 (after ll2.insert_after(10,11);)..." << endl;
    cout << ll2 << endl;
    cout << "Printing Test List2 head..." << endl; ll2.print_head();
    cout << "Printing Test List2 tail:" << endl; ll2.print_tail();
    cout << endl;

    return 0;
}
