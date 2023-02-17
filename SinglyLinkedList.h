#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <bits/stdc++.h>
#include "LinkNode.h"
#include "krone.h"
#include "currency.h"

class SinglyLinkedList
{
private:
    int counts;
    LinkNode *start;
    LinkNode *end;

public:
    // Constructor
    SinglyLinkedList()
    {
        start = NULL;
        end = NULL;
    }
    // Destructor
    ~SinglyLinkedList()
    {
    }
    //// Mutators / Setters
    /*
    These functions are used to assign a value to the variable based on the input within the parameter
    Pre: int / pointer*
    Post: int / pointer*
    Return:
    */
    void set_count(int count)
    {
        this->counts = count;
    }
    void set_start(LinkNode *start)
    {
        this->start = start;
    }
    void set_end(LinkNode *end)
    {
        this->end = end;
    }

    // Accessors / Getters
    /*
    These functions are returns a value based on the set data type
    Pre: int / pointer*
    Post:
    Return: int / pointer*
    */
    int get_count()
    {
        return this->counts;
    }
    LinkNode *get_start()
    {
        return this->start;
    }
    LinkNode *get_end()
    {
        return this->end;
    }

    //// Functions
    /*
    This function adds the inputted object at the inputted index
    Pre: *data - a pointer datatype that is a reference of Currency object
          index - an integer datatype that desinates which position the object is added
    Post:
    Return:
    */
    void addCurrency(Currency *data, int index) // addCurrency method which takes a Currency object and a node index value as parameters to add the Currency to the list at that index.
    {
        LinkNode *node = new LinkNode();
        node->data = data;
        node->next = nullptr;
        if (index == 0)
        {
            node->next = start;
            start = node;
        }
        else
        {
            LinkNode *temp = start;
            while (--index > 0)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }
    /*
    This function removes the inputted object
    Pre: *data - a pointer datatype that is a reference of Currency object
    Post:
    Return:
    */
    void removeCurrency(Currency *data)
    {
        int n = 0;
        int n1 = 0;
        LinkNode *p = start;
        LinkNode *p1 = start;
        if (p == NULL)
        {
            cout << "\nLink List Empty";
        }
        else
        {
            LinkNode *prev;
            prev = NULL;
            while (p != NULL)
            {
                if (p->data == data)
                    break;
                prev = p;
                p = p->next;
            }
            prev->next = p->next;
            free(p);
            // cout << "\nRemove Data from Link list: " << data->getValue() << endl;
        }
    }
    /*
    This function removes an object at the inputed index
    Pre: index - an integer datatype that corresponds to a position in an ADT.
    Post:
    Return:
    */
    void removeCurrency(int index)
    {
        if (index == 0 && start != NULL)
        {
            LinkNode *nodetoDelete = start;
            start = start->next;
            free(nodetoDelete);
        }
        else
        {
            LinkNode *temp = start;
            for (int i = 0; i < index - 1; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
            }
            if (temp != NULL && temp->next != NULL)
            {
                LinkNode *nodetoDelete = temp->next;
                temp->next = temp->next->next;
                free(nodetoDelete);
            };
        }
    }
    /*
    A function that prints out all the elements in a Singly Linked List
    Pre:
    Post:
    Return:
    */
    string printList()
    {
        string list = "";
        LinkNode *node = start;
        if (start == nullptr)
        {
            return list;
        }
        else
        {
            while (node != nullptr)
            {
                list += node->data->get_currency() + " ";
                list += to_string(node->data->getValue());
                list += " ";
                node = node->next;
            }
        }

        return list;
    }
    /*
    A function that finds the inputted object in the ADT
    Pre:
    Post:
    Return:
    */
    int findCurrency(Currency *data)
    {
        LinkNode *p = start;
        int index = 0;
        if (start == NULL)
        {
            return -1;
        }
        else
        {
            while (p != NULL)
            {
                if (p->data->getValue() == data->getValue())
                {
                    return index;
                }
                p = p->next;
                index++;
            }
            return -1;
        }
    }

    /*
    A function that finds an object at the inputted index
    Pre: indexNode - an integer datatype that corresponds to the position of the ADT
    Post:
    Return:
    */
    void getCurrency(int indexNode)
    {
        if (indexNode > counts)
        {
            cout << "Index out of Array Range!" << endl;
        }
    }

    /*
    A function that determines whether the ADT is empty or not
    Pre:
    Post:
    Return: TRUE or FALSE
    */
    bool isListEmpty()
    {
        LinkNode *temp = start;
        if (temp == NULL)
        {
            return true;
        }
        else
            return false;
    }

    /*
    A function that counts the number of elements in an ADT
    Pre:
    Post:
    Return:
    */
    int countCurrency()
    {
        LinkNode *p = start;
        counts = 0;
        while (p != nullptr)
        {
            counts++;
            p = p->next;
        }
        return counts;
    }
};

#endif