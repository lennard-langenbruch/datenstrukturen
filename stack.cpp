#ifndef STACK_H
#define STACK_H

#include "UnderflowEx.h"
#include "OverflowEx.h"

/**
*
* class Stack
*
* Meine Implementation eines Stack.
*
* @author LL
*
**/
class Stack
{
    private:

    int *storage;
    int capacity;
    int next;

    public:

    /**
    *
    * Konstruktor mit Parameter
    *
    * @param capacity: Kapazität des zu erstellenden Stacks.
    *
    * Beschreibung:
    * Übergibt die größe des Stack an "capacity".
    * Setzt den Zeiger "storage" auf das Schlüsselwort "nullptr".
    * Setzt "next" gleich 0.
    *
    **/
    Stack(int capacity)
    {
        this->capacity = capacity;
        storage = nullptr;
        next = 0;
    }

    /**
    *
    * Destruktor.
    *
    * Beschreibung:
    * Gibt den vom Stack allokierten Speicher frei.
    *
    **/
    ~Stack()
    {
        delete[] storage;
    }

    /**
    *
    * Kopierkonstruktor.
    *
    * Beschreibung:
    * Erlaubt das korrekte Kopieren eines Stack.
    *
    **/
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

    /**
    *
    * Methode.
    *
    * Beschreibung:
    * Wenn der Stapel voll ist wird eine Exception geworfen.
    * Wenn das Feld zum speichern der Daten noch nicht existiert wird es erstellt.
    *
    * Legt ein Objekt vom Typ Integer auf den Stapel.
    *
    **/
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
