#include <iostream>
#include "Movie.h"
#include "InventoryManager.h"
#include "CustomerDatabase.h"
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction{ //abstract class for transactions
    protected:
        int customerId;
        Movie* movie;
    public:
        Transaction();
        virtual ~Transaction();
        //pure virtual functions for transactions
        virtual void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) = 0;   
        virtual void setData(istream& input) = 0;
        virtual void display() const = 0;
};