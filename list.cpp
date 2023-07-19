#ifndef LIST_H
#define LIST_H

#include "EmptyListEx.h"

struct Node
{
    int data;
    Node *next;
    Node *before;
};

class List
{
    
private:
    
    Node *head;
    Node *tail;

public:
    
    List()
    {
        head = tail = nullptr;
    }

    ~List()
    {
        remove_all();
    }
    
    bool contains(int value)
    {
        bool check = false;
        Node *temp = head;

        while(temp != nullptr)
        {
            if(value == temp->data)
            {
                check = true;
            }
            temp = temp->next;
        }

        return check;
    }
    
    void add_last(int append)
    {
        if(head == nullptr)
        {
        Node* any = new Node();

        any->data = append;
        any->next = nullptr;
        any->before = nullptr;
        head = any;
        tail = any;
        }
        else
        {
        Node *any = new Node();

        any->data = append;
        tail->next = any;
        any->before = tail;
        any->next = nullptr;

        tail = any;
        }
    }
    
    void add_first(int append) {

        if(head == nullptr)
        {
            Node* any = new Node();

            any->data = append;
            any->next = nullptr;
            any->before = nullptr;
            head = any;
            tail = any;
        }
        else
        {
            Node *any = new Node();

            any->data = append;
            head->before = any;
            any->next = head;
            any->before = nullptr;

            head = any;
        }
    }
    
    void remove_last()
    {
        if(head == nullptr)
        {
            throw EmptyListEx();
        }

        Node *temp = tail;

        temp = temp->before;
        temp->next = nullptr;

        delete tail;

        tail = temp;
    }
    
    void remove_first()
    {
        if(head == nullptr)
        {
            throw EmptyListEx();
        }

        Node *temp = head;

        temp = temp->next;

        temp->before = nullptr;

        delete head;

        head = temp;
    }
    
    void remove_all()
    {
        Node *temp = head;

        while(head != nullptr)
        {
            temp = temp->next;

            delete head;

            head = temp;
        }
        tail = nullptr;
    }
}
#endif // LIST_H
