#include "Business.h"

int main(){
    auto stripBOM = [](ifstream& f) {
        char bom[3];
        f.read(bom, 3);
        if (!((unsigned char)bom[0] == 0xEF &&
            (unsigned char)bom[1] == 0xBB &&
            (unsigned char)bom[2] == 0xBF)) {
            f.seekg(0);
        }
        };

    Business store;

    ifstream movieFile("data4movies.txt");
    ifstream customerFile("data4customers.txt");
    ifstream commandFile("data4commands.txt");

    stripBOM(movieFile);
    stripBOM(customerFile);
    stripBOM(commandFile);

    if (!movieFile) {
        cerr << "Error: Could not open data4movies.txt" << endl;
        return 1;
    }

    if (!customerFile) {
        cerr << "Error: Could not open data4customers.txt" << endl;
        return 1;
    }

    if (!commandFile) {
        cerr << "Error: Could not open data4commands.txt" << endl;
        return 1;
    }


    store.buildMovie(movieFile);
    store.buildCustomer(customerFile);
    store.processTransaction(commandFile);

    return 0;
}