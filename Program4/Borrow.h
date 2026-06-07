#pragma once

#include "MovieFac.h"
#include "Transaction.h"
#include "CustomerDatabase.h"
#include "InventoryManager.h"


class Borrow : public Transaction { //borrow child class
    public:
        Borrow();
        virtual ~Borrow();
        void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;    
        void setData(istream& input) override;
        void display() const override;
};