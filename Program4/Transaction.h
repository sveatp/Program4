#pragma once

#include <iostream>

using namespace std;

#include "Movie.h"
#include "InventoryManager.h"
#include "CustomerDatabase.h"


class Transaction { //abstract class for transactions
    protected:
        int customerId;
        Movie* movie;
        char action;        // 'B', 'R', or 'H'
        bool ownsMovie = true;
    public:
        Transaction();
        virtual ~Transaction();
        //pure virtual functions for transactions
        virtual void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) = 0;   
        virtual void setData(istream& input) = 0;
        virtual void display() const = 0;
        char getAction() const;
        Movie* getMovie() const;
};

