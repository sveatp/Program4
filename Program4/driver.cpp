#include "Hashtable.h"
#include "CustomerDatabase.h"
#include "Customer.h"
#include <iostream>

int main(){
    CustomerDatabase db; //create customer database
    db.addCustomer(1000, "Smith", "John"); //add customers
    db.addCustomer(2000, "Doe", "Jane");
    db.addCustomer(5555, "Brown", "Charlie");

    Customer* c1 = db.getCustomer(1000); //get customers by id
    if(c1 != nullptr){
        std::cout << "Customer 1: " << c1->getFirst() << " " << c1->getLast() << std::endl;
    } else {
        std::cout << "Customer 1 not found" << std::endl;
    }

    Customer* c2 = db.getCustomer(2000);
    if(c2 != nullptr){
        std::cout << "Customer 2: " << c2->getFirst() << " " << c2->getLast() << std::endl;
    } else {
        std::cout << "Customer 2 not found" << std::endl;
    }

    Customer* c3 = db.getCustomer(5555);
    if(c3 != nullptr){
        std::cout << "Customer 3: " << c3->getFirst() << " " << c3->getLast() << std::endl;
    } else {
        std::cout << "Customer 3 not found" << std::endl;
    }

    return 0;
}