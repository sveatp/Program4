#ifndef BORROW_H
#define BORROW_H

#include "Transaction.h"
#include "CustomerDatabase.h"
#include "InventoryManager.h"


class Borrow : public Transaction{ //borrow child class
    public:
        void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;    
        void setData(istream& input) override;
        void display() const override;
};
#endif