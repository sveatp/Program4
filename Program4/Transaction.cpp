#include "Transaction.h"

Transaction::Transaction() { //default constructor
    customerId = 0;
    movie = nullptr;
    action = '\0';
}

Transaction::~Transaction(){ //destructor, virtual class
    if (ownsMovie) {
        delete movie;
    }
}

char Transaction::getAction() const {
    return action;
}

Movie* Transaction::getMovie() const {
    return movie;
}