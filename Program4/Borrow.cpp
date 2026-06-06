#include "Borrow.h"
#include "Movie.h"
#include "MovieFac.h"


void Borrow::setData(istream& input) { //set data for borrow transaction
    char mediaType;
    char movieType;
    input >> customerId >> mediaType >> movieType;
    movie = MovieFac::createMovie(movieType); //create movie using factory
    if (movie == nullptr) { 
        input.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        return;
    }
    movie->setData(input); //set data for the movie
}



void Borrow::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) { //perform borrow transaction
    Customer* customer = customerDB.getCustomer(customerId); //get customer from database
    if (customer == nullptr) {
        cout << "Customer ID " << customerId << " not found." << endl;
        return;
    }
    if (movie == nullptr) {
        cout << "Movie not found." << endl;
        return;
    }

    Movie* inventoryMovie = nullptr; //result movie from inventory search
    
    if (!inventory.getMovie(movie, inventoryMovie)) {
        cout << "Movie not found in inventory." << endl;
        return;
    }
    if (inventoryMovie->borrowMovie()) { //borrow movie if available
        movie = inventoryMovie; //update movie pointer to the one in inventory for accurate transaction history
        customer->addTransaction(*this); //add transaction to customer's history
        cout << "Customer " << customer->getFirst() << " " << customer->getLast() << " borrowed: " << *inventoryMovie << endl;
    } 
    else {
        cout << "Movie out of stock." << endl;
    }
    
}



void Borrow::display() const { //display borrow transaction
    cout << "Borrow Transaction - Movie: " << (movie ? movie->getTitle() : "None") << endl;
}