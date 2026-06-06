#include "Movie.h"
#include "MovieFac.h"
#include "Return.h"


void Return::setData(istream& input) { //set data for return transaction
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





void Return::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory){
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

    if (!customer->hasBorrowedMovie(inventoryMovie)) { //check if customer has borrowed the movie
        cout << "Customer " << customer->getFirst() << " " << customer->getLast() << " has not borrowed: " << *inventoryMovie << endl;
        return;
    }


    inventoryMovie->returnMovie(); //return movie to inventory
    cout << "Customer " << customer->getFirst() << " " << customer->getLast() << " returned: " << *inventoryMovie << endl;
}

void Return::display() const { //display return transaction
    cout << "Return Transaction - Movie: " << (movie ? movie->getTitle() : "None") << endl;
}