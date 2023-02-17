/*
Lab        : #2
Name       : Brandon Hung & Hoang Khoi Do
*/

// Libraries
#include <bits/stdc++.h>

// Headers
#include "SinglyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkNode.h"
#include "currency.h"
#include "krone.h"
using namespace std;

int main()
{
    cout << "-" << setfill('-') << setw(20) << '-' << endl;
    cout << "ADT Program Initialized...." << endl;
    cout << "-" << setfill('-') << setw(30) << '-' << endl;

    // Declared twenty Krone objects of a Currency array
    Currency *krone[20];
    krone[0] = new Krone(57.12);
    krone[1] = new Krone(23.44);
    krone[2] = new Krone(87.43);
    krone[3] = new Krone(68.99);
    krone[4] = new Krone(111.22);
    krone[5] = new Krone(44.55);
    krone[6] = new Krone(77.77);
    krone[7] = new Krone(18.36);
    krone[8] = new Krone(543.21);
    krone[9] = new Krone(20.21);
    krone[10] = new Krone(345.67);
    krone[11] = new Krone(36.18);
    krone[12] = new Krone(48.48);
    krone[13] = new Krone(101.00);
    krone[14] = new Krone(11.00);
    krone[15] = new Krone(21.00);
    krone[16] = new Krone(51.00);
    krone[17] = new Krone(1.00);
    krone[18] = new Krone(251.00);
    krone[19] = new Krone(151.00);

    ////////////////////////////
    // Singly-Linked List ADT //
    ////////////////////////////
    cout << "Singly-Linked List Processing..." << endl;
    cout << "-" << setfill('-') << setw(20) << '-' << endl;

    SinglyLinkedList linkedlist;
    linkedlist.addCurrency(krone[6], 0);
    linkedlist.addCurrency(krone[5], 1);
    linkedlist.addCurrency(krone[4], 2);
    linkedlist.addCurrency(krone[3], 3);
    linkedlist.addCurrency(krone[2], 4);
    linkedlist.addCurrency(krone[1], 5);
    linkedlist.addCurrency(krone[0], 6);
    cout << linkedlist.printList() << endl;

    int indexFound1 = linkedlist.findCurrency(new Krone(87.43));
    int indexFound2 = linkedlist.findCurrency(new Krone(44.56));

    if (indexFound1 == -1)
    {
        cout << "Index not Found" << endl;
    }
    else
    {
        cout << "Index Found at:" << indexFound1 << endl;
    }

    if (indexFound2 == -1)
    {
        cout << "Index not Found" << endl;
    }
    else
    {
        cout << "Index Found at: " << indexFound2 << endl;
    }

    linkedlist.removeCurrency(krone[4]);
    linkedlist.removeCurrency(2);

    cout << linkedlist.printList() << endl;

    linkedlist.addCurrency(krone[8], linkedlist.countCurrency() % 5);
    linkedlist.addCurrency(krone[9], linkedlist.countCurrency() % 5);
    linkedlist.addCurrency(krone[10], linkedlist.countCurrency() % 5);
    linkedlist.addCurrency(krone[11], linkedlist.countCurrency() % 5);
    linkedlist.removeCurrency(linkedlist.countCurrency() % 6);
    linkedlist.removeCurrency(linkedlist.countCurrency() / 7);
    cout << linkedlist.printList() << endl;
    cout << "Singly-Linked List Completed!" << endl;
    cout << "-" << setfill('-') << setw(20) << '-' << endl;
    cout << "\n";

    //////////////////////
    // Stack (LIFO) ADT //
    /////////////////////
    cout << "Stack Processing..." << endl;
    cout << "-" << setfill('-') << setw(20) << '-' << endl;
    Stack stack;
    stack.push(krone[12]);
    stack.push(krone[13]);
    stack.push(krone[14]);
    stack.push(krone[15]);
    stack.push(krone[16]);
    stack.push(krone[17]);
    stack.push(krone[18]);

    cout << stack.PrintStack() << endl;

    stack.peek();
    stack.pop();
    stack.pop();
    stack.pop();

    cout << stack.PrintStack() << endl;

    stack.push(krone[0]);
    stack.push(krone[1]);
    stack.push(krone[2]);
    stack.push(krone[3]);
    stack.push(krone[4]);
    stack.pop();
    stack.pop();

    cout << stack.PrintStack() << endl;
    cout << "Stack Completed!" << endl;
    cout << '-' << setfill('-') << setw(20) << '-' << endl;
    cout << "\n";

    /////////////////////////
    // // Queue (FIFO) ADT //
    ////////////////////////
    cout << "Queue Processing..." << endl;
    cout << '-' << setfill('-') << setw(20) << '-' << endl;
    Queue queue;
    queue.Enqueue(krone[4]);
    queue.Enqueue(krone[6]);
    queue.Enqueue(krone[8]);
    queue.Enqueue(krone[10]);
    queue.Enqueue(krone[12]);
    queue.Enqueue(krone[14]);
    queue.Enqueue(krone[16]);

    cout << queue.PrintQueue() << endl;

    queue.PeekFront();
    queue.PeekRear();
    queue.Dequeue();
    queue.Dequeue();

    cout << queue.PrintQueue() << endl;

    queue.Enqueue(krone[9]);
    queue.Enqueue(krone[10]);
    queue.Enqueue(krone[11]);
    queue.Enqueue(krone[12]);
    queue.Enqueue(krone[13]);
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    cout << queue.PrintQueue() << endl;
    cout << "Queue Completed!" << endl;
    cout << "-" << setfill('-') << setw(20) << '-' << endl;
    cout << "\n";

    cout << "-" << setfill('-') << setw(20) << '-' << endl;
    cout << "ADT Program Finished!" << endl;
    cout << "-" << setfill('-') << setw(30) << '-' << endl;

    return 0;
}