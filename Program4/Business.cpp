#include "Business.h"

Business::Business() {

}

Business::~Business() {

}

// buildMovie
// Delegates directly to InventoryManager
void Business::buildMovie(ifstream& infile) {
	inventory.buildInventory(infile);
}

// buildCustomer
// Reads customer files line by line
// Format: Cusomter ID LastName FirstName
void Business::buildCustomer(ifstream& infile) {
	int id;
	string firstName;
	string lastName;

	while (infile >> id >> lastName >> firstName) {
		customers.addCustomer(id, lastName, firstName);
	}
}

// processTransaction
// Reads commands file line by line
// 'I' is handled directly (does not go to TransFac)
void Business::processTransaction(ifstream& infile) {
	TransFac factory;
	char action;

	while (infile >> action) {
		if (action == 'I') {
			inventory.displayInventory(cout);
			continue;
		}

		Transaction* t = factory.createTransaction(action);
		if (t == nullptr) {
			infile.ignore(256, '\n');
			continue;
		}

		infile.clear();
		t->setData(infile);
		t->doTrans(customers, inventory);
		delete t;
	}



}