#include "Hashtable.h"
#include <iostream>
using namespace std;

Hashtable::Hashtable(){ //default constructor
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr; //initialize all to null
    }
}

Hashtable::~Hashtable(){ //destructor
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete table[i]; 
    }
}

int Hashtable::hashFunction(int id) const{ //simple hash function using modulo
    return id % TABLE_SIZE;
}


bool Hashtable::insert( Customer* customer){ //insert customer into hashtable with linear probing
    int index = hashFunction(customer->getId()); //compute index
    
    if (table[index] == nullptr) { //empty spot, insert 
        table[index] = customer;
        //cout << "Customer " << customer->getId() << " inserted at index " << index << "." << endl;
        return true;

    } else {

        for (int i = 0; i < TABLE_SIZE; i++) { //linear probe
            int newIndex = (index + i) % TABLE_SIZE; //check next index

            if (table[newIndex] == nullptr) { //empty spot found
                table[newIndex] = customer; //insert 
              //  cout << "Customer " << customer->getId() << " inserted at index " << newIndex << "." << endl;
                return true;
            }

            if (table[newIndex]->getId() == customer->getId()) { //customer already exists
                cout << "Customer " << customer->getId() << " already exists. Insertion failed." << endl;
                return false;
            }

        }
        cout << "Hashtable is full. Insertion failed." << endl; //table is full
        return false;
    }
}

Customer* Hashtable::get(int id) const { //get customer
    int index = hashFunction(id); //compute index

    for (int i = 0; i < TABLE_SIZE; i++) { //linear probe
        int newIndex = (index + i) % TABLE_SIZE; //check next index

        if (table[newIndex] == nullptr) { //empty spot, customer not found
            return nullptr;
        }

        if (table[newIndex]->getId() == id) { //customer found
            return table[newIndex];
        }
    }
    return nullptr; //customer not found 
}
   

