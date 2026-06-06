#include "Customer.h"
using namespace std;

Customer::Customer(){ //default constructor
    id = 0;
    first = "";
    last = "";
}

Customer::~Customer() { //destructor to clean up transaction history
    for (Transaction* t : history) {
        delete t;
    }
    history.clear();
}

Customer::Customer(int id, string lastName, string firstName){ //parameterized constructor
    this->id = id;
    this-> first = firstName;
    this->last = lastName;
}

//getter functions
int Customer::getId() { 
    return id;
}

string Customer::getFirst() {
    return first;
}

string Customer::getLast() {
    return last;
}

void Customer::getHistory() const { //display transaction history
    cout << "Transaction History for " << first << " " << last << " (ID: " << id << "):" << endl;
    if (history.empty()) {
        cout << "No transactions found." << endl;
        return;
    }
    for (const Transaction* t : history) {
        t->display();
    }
}

void Customer::addTransaction(Transaction* t) { //add transaction to history

    if (t == nullptr) {
        cerr << "Error: transaction is null." << endl;
        return;
    }
    history.push_back(t);
}

bool Customer::hasBorrowedMovie(const Movie* m) const { //check if customer has borrowed a specific movie
    
    int counter = 0;
    for (const Transaction* t : history) {
        if(t->movie == m){
            if (dynamic_cast<const Borrow*>(t)) {
                counter++;                   // borrowed one
            } else if (dynamic_cast<const Return*>(t)) {
                counter--;                   // returned one
            }
        }

    }
    return counter > 0; // if counter > 0 the customer currently has the movie borrowed
}