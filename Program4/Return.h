#pragma once

#include "MovieFac.h"
#include "Transaction.h"
#include "CustomerDatabase.h"
#include "InventoryManager.h"

class Return : public Transaction{ //return child class
    public:
        Return();
        virtual ~Return();
        void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;    
        void setData(istream& input) override;
        void display() const override;
};
