#include "Transaction.h"
using namespace std;

class Borrow : public Transaction{ //borrow child class
    public:
        void doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) override;    
        void setData(istream& input) override;
        void display() const override;
};