#ifndef STACK_H
#define STACK_H
#include <bits/stdc++.h>
#include "SinglyLinkedList.h"
#include "currency.h"
#include "krone.h"
using namespace std;

class Stack : SinglyLinkedList
{
private:
    LinkNode *start;
    LinkNode *end;

public:
    Stack()
    {
        start = NULL;
        end = NULL;
    }

    ~Stack()
    {
    }
    /*
    This function pushes the inputted value into the stack
    Pre:
    Post:
    Return:
    */
    void push(Currency *data)
    {
        LinkNode *stack = new LinkNode();
        if (start == NULL)
        {
            stack->data = data;
            stack->next = NULL;
            start = stack;
        }
        else
        {
            stack->data = data;
            stack->next = start;
            start = stack;
        }
        // cout << "Value " << stack->data->getValue() << " pushed onto stack" << endl;
    }

    /*
    This function pops the last value out of the stack
    Pre:
    Post:
    Return:
    */
    void pop()
    {
        // cout << "Value " << start->data->getValue() << " popped from stack" << endl;
        start = start->next;
    }


    /*
    This function peeks the value of the first element of the stack
    Pre:
    Post:
    Return:
    */
    void peek()
    {
        cout << "Peek: " << start->data->getValue() << endl;
    }

    /*
    This function determines whether the stack is empty or not
    */
    bool isEmpty()
    {
        LinkNode* temp = start;
        if(temp == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    /* This function prints all the elements in a Stack in a string format
    Pre:
    Post:
    Return;
    
    */
    string PrintStack()
    {
        string stack = "";
        LinkNode *node = new LinkNode();
        node = start;
        if (start == nullptr)
        {
            return stack;
        }
        else
        {
            while (node != nullptr)
            {
                stack += node->data->get_currency() + "  ";
                stack += to_string(node->data->getValue()) + "  ";
                stack += '\t';
                node = node->next;
            }
        }
        return stack;
    }
};

#endif