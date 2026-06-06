#include "Transaction.h"
using namespace std;

Transaction::Transaction(){ //default constructor
    customerId = 0;
    movie = nullptr;
}

Transaction::~Transaction(){ //destructor, virtual class
    delete movie;
}

