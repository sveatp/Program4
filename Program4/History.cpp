#include "History.h"

void History::setData(istream& input) {
    input >> customerId; //read customer ID for history display

}

void History::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) {
    Customer* customer = customerDB.getCustomer(customerId); //get customer from database
    if (customer == nullptr) {
        cout << "Customer ID " << customerId << " not found." << endl;
        return;
    }
    customer->getHistory(); //display customer's transaction history
}

void History::display() const {
    // No additional display needed for history transaction, as the customer's getHistory() method handles it
}