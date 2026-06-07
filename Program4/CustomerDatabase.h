#pragma once

#include "Customer.h"
#include "Hashtable.h"

class CustomerDatabase{
    public:
        CustomerDatabase();
        ~CustomerDatabase();
        void addCustomer(int id, std::string lastName, std::string firstName);
        Customer* getCustomer(int id) const;

    private:
        Hashtable customerTable; //hashtable to store customers
        

};   