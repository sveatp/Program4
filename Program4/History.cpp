#include "History.h"


History::History() {
    action = 'H';
}

void History::setData(istream& input) {
	if (!(input >> customerId)) { // Attempt to read customer ID
		cerr << "Error: Invalid input for customer ID." << endl;
		customerId = -1; // Set to an invalid ID to indicate failure
		return;
	}

    //input >> customerId; //read customer ID for history display
}

void History::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) {
    Customer* customer = customerDB.getCustomer(customerId); //get customer from database
    if (customer == nullptr) {
        cerr << "Customer ID " << customerId << " not found." << endl;
        return;
    }

    customer->showHistory(); //display customer's transaction history
}

void History::display() const {
    // No additional display needed for history transaction, as the customer's showHistory() method handles it
}