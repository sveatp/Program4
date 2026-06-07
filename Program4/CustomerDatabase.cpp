#include "CustomerDatabase.h"
#include <iostream>

CustomerDatabase::CustomerDatabase(){ //default constructor
    //hashtable is already initialized
}

CustomerDatabase::~CustomerDatabase(){ //destructor
    //hashtable destructor takes care of customers
}

Customer* CustomerDatabase::getCustomer(int id) const{ //get customer by id
    return customerTable.get(id); //use hashtable function
}

void CustomerDatabase::addCustomer(int id, std::string lastName, std::string firstName){ //add customer to database
    Customer* newCustomer = new Customer(id, lastName, firstName); //create new customer object
    if (!customerTable.insert(newCustomer)) {
		cerr << "Error: Customer with ID " << id << " already exists." << endl;
        delete newCustomer;
    }
}