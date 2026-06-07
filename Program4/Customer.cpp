#include "Customer.h"
#include "Movie.h"
#include "Transaction.h"

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
int Customer::getId() const{ 
    return id;
}

string Customer::getFirst() const {
    return first;
}

string Customer::getLast() const {
    return last;
}

void Customer::showHistory() const { //display transaction history
    cout << "Transaction History for " << first << " " << last << " (ID: " << id << "):" << endl;
    if (history.empty()) {
        cout << "No transactions found." << endl;
        return;
    }
    for (int i = history.size() - 1; i >= 0; i--) {
        history[i]->display();
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
        if(t->getMovie() == m) {
            if (t->getAction() == 'B') {
                counter++;
            }
            else if (t->getAction() == 'R') {
                counter--;
            }
        }

    }
    return counter > 0; // if counter > 0 the customer currently has the movie borrowed
}