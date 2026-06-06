#include "Inventory.h"

void Inventory::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) {
    // display the inventory
    inventory.displayInventory(cout);
}

void Inventory::setData(istream& input) {
    // No data to set for inventory display transaction
}

void Inventory::display() const {
}