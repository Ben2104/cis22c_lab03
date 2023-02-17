#ifndef QUEUE_H
#define QUEUE_H
#include <bits/stdc++.h>
#include "SinglyLinkedList.h"
#include "currency.h"
#include "krone.h"

class Queue : public SinglyLinkedList
{
private:
    LinkNode *start;
    LinkNode *end;
public:
    Queue(){
        start = NULL;
        end = NULL;
    };

    ~Queue(){
    }

    /*
    This function adds the inputted object into the queue.
    Pre:
    Post:
    Return:
    */
    void Enqueue(Currency *data){
       LinkNode* queue = new LinkNode();
       queue->data = data;
       queue->next = NULL;
       if (start == NULL)
           start = queue;
       else
       {
           LinkNode* temp = start;
           while (temp->next!=NULL)
           {
               temp = temp->next;
           }
           temp->next = queue;
       }
    //    cout << "Enqueue Data into Queue: " << queue->data->getValue() << endl;;
   }

   /*
   This function removes the element currently located in the head.
   Pre:
   Post:
   Return;
   */
    void Dequeue()
    {
        // return the copy of object
        if (start == NULL){
            cout << "EMPTY" << endl;
        }
        else{
            start = start->next;

            // cout << " Dequeued... First Element is now " << start->data->getValue() << endl;
        }
        
    }
    /*
    This sfunction peeks and returns the element currently in the head.
    Pre:
    Post:
    Return:
    */
    void PeekFront()
    {
        if (start == NULL){
            cout <<  "EMPTY" << endl;
        }
        else
        {
            if(start != NULL && end == NULL) {
                cout << "Front: " << start->data->getValue() << endl;

            }
            else {
            cout << "Front: " << end->data->getValue() << endl;
            }
        }
    }
    /*
    This sfunction peeks and returns the element currently in the tail.
    Pre:
    Post:
    Return:
    */
    void PeekRear()
    {
        // return the copy of object
        if (start == NULL){
            cout << "EMPTY" << endl;
        }
        else{
            LinkNode *temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            cout << "Rear: " << temp->data->getValue() << endl;;
        }
    }
    /*
    This function prints the all the elements in the queue in a string format.
    Pre:
    Post:
    Return:
    */
    string PrintQueue()
    {
        string queue = "";
        LinkNode *node = new LinkNode();
        node = start;
        if (start == nullptr)
        {
            return queue;
        }
        else
        {
            while (node != nullptr)
            {
                queue += node->data->get_currency() + " ";
                queue += to_string(node->data->getValue()) + " ";
                queue += '\t';
                node = node->next;
            }
        }
        return queue; 
    }

};
#endif