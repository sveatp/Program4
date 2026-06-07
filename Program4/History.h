#pragma once


#include "Transaction.h"
#include "CustomerDatabase.h"

class History : public Transaction { //history display child class
public:
    History();
    void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;
    void setData(istream& input) override;
    void display() const override;
};
