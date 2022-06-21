#ifndef STACK_H
#define STACK_H

#include "UnderflowEx.h"
#include "OverflowEx.h"

/**
*
* class Stack
*
* Meine Implementation eines Stapelspeichers.
*
**/
class Stack
{
    private:

    int *storage;
    int capacity;
    int next;

    public:
    
    Stack(int capacity)
    {
        this->capacity = capacity;
        storage = nullptr;
        next = 0;
    }

    ~Stack()
    {
        delete[] storage;
    }

    Stack(const Stack &copy)
    {
        storage = new int[copy.capacity];
        capacity = copy.capacity;
        next = copy.next;
        for(int index = 0; index < next; index++)
        {
            storage[index] = copy.storage[index];
        }
    }

    void push(int data)
    {
        if(fullStack())
        {
            throw OverflowEx();
        }

        if(storage == nullptr)
        {
            storage = new int[capacity];
        }

        storage[next++] = data;
    }

    int pop()
    {
        if(emptyStack())
        {
            throw StackUnderflowEx();
        }
        return storage[--next];
    }

    int peek()
    {
        if(emptyStack())
        {
            throw UnderflowEx();
        }
        return storage[next-1];
    }

    int onStack()
    {
        return next;
    }

    int getCapacity()
    {
        return capacity;
    }

    bool emptyStack()
    {
        return next == 0;
    }

    bool fullStack()
    {
        return next == capacity;
    }
};

#endif // STACK_H
