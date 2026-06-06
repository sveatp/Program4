#include "Transaction.h"

class Inventory : public Transaction{ //inventory display child class
    public:
        void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;    
        void setData(istream& input) override;
        void display() const override;
};