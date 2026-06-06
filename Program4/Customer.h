#include <iostream>
#include <string>
#include "Transaction.h"

using namespace std;
#pragma once

class Customer{ //customer class
    public:
        Customer();
        Customer(int id, string first, string last);
        ~Customer();
        int getId();
        string getFirst() ;
        string getLast() ;
        void getHistory() const;
        void addTransaction(Transaction* t);
        bool hasBorrowedMovie(const Movie* m) const; //check if customer has borrowed a specific movie
       


    private:
        int id;
        string first;
        string last;
        vector<Transaction*> history; //vector to store transaction history
};