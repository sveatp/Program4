#pragma once

#include <iostream>
#include <string>
#include <vector>


class Transaction; //forward declaration of Transaction class
class Movie; //forward declaration of Movie class

using namespace std;


class Customer { //customer class
    public:
        Customer();
        Customer(int id, string first, string last);
        ~Customer();

        int getId() const;
        string getFirst() const;
        string getLast() const;
        void showHistory() const;

        void addTransaction(Transaction* t);

        bool hasBorrowedMovie(const Movie* m) const; //check if customer has borrowed a specific movie
       


    private:
        int id;
        string first;
        string last;
        vector<Transaction*> history; //vector to store transaction history
};