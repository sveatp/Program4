#pragma once

#include "Customer.h"


class Hashtable{ //hashtable class
    public:
        Hashtable();
        ~Hashtable();
        bool insert(Customer* customer);
        Customer* get(int id) const;

    private:
        static const int TABLE_SIZE = 997; //size of hashtable, prime number to reduce collisions
        Customer* table[TABLE_SIZE]; //array of pointers to customers

        int hashFunction(int id) const; //hash function to compute index
};