#include "InventoryManager.h"

InventoryManager::InventoryManager() : comedyTree(nullptr), dramaTree(nullptr), classicTree(nullptr) {}

InventoryManager::~InventoryManager() {
	clearTree(comedyTree);
	clearTree(dramaTree);
	clearTree(classicTree);
}

void InventoryManager::buildInventory(ifstream& filename) {
	MovieFac factory;
	char category;

	while (filename >> category) {
		Movie* movie = factory.createMovie(category);

		if (movie != nullptr) {
			movie->setData(filename);
			addMovie(movie);
		} else {
			// Movie factory already logs an error for unknown category, so we can just skip to the next line
			filename.ignore(256, '\n'); // Skip the rest of the line for this invalid entry
			continue;
		}
	}
}

bool InventoryManager::addMovie(Movie* movie) {
	if (movie == nullptr) {
		cerr << "Error: Cannot add null movie to inventory." << endl;
		return false;
	}

	char genre = movie->getCategory();
	BSTNode* root = getRoot(genre);

	if (!root) {
		root = new BSTNode(movie);
		getRoot(genre) = root;
	} else {
		insert(root, movie);
	}

	return true;
}

bool InventoryManager::getMovie(Movie* target, Movie*& result) {
	char genre = target->getCategory();
	const BSTNode* root = getRoot(genre);

	return search(root, target, result);
}

void InventoryManager::displayInventory(ostream& os) const {
	os << "Comedy Movies: " << endl;
	inOrderDisplay(comedyTree, os);
	os << "Drama Movies: " << endl;
	inOrderDisplay(dramaTree, os);
	os << "Classic Movies: " << endl;
	inOrderDisplay(classicTree, os);
}

const InventoryManager::BSTNode* InventoryManager::getRoot(char genre) const {
	switch (genre) {
		case 'F': return comedyTree;
		case 'D': return dramaTree;
		case 'C': return classicTree;
		default:
			cerr << "Error: Unknown genre '" << genre << "'. Cannot get root." << endl;
			return comedyTree; // Return something to avoid compiler error, but this should never be used
	}
}

void InventoryManager::clearTree(BSTNode* root) {
	if (root == nullptr) {
		return;
	}

	clearTree(root->leftChild);
	clearTree(root->rightChild);
	delete root->data;
	delete root;
}

void InventoryManager::insert(BSTNode*& root, Movie* m) {
	if (root == nullptr) {
		root = new BSTNode(m);
		return;
	}

	if (*m == *root->data) {
		// Movie already exists in inventory, so we just update the stock
		root->data->addStock(m->getStock());
		delete m;
		return;
	}

	if (*m < *root->data) {
		insert(root->leftChild, m);
	}
	else {
		insert(root->rightChild, m);
	}
}

bool InventoryManager::search(const BSTNode* root, Movie* target, Movie*& result) const {
	if (root == nullptr) {
		return false;
	}
	if (*target == *root->data) {
		result = root->data;
		return true;
	}
	else if (*target < *root->data) {
		return search(root->leftChild, target, result);
	}
	else {
		return search(root->rightChild, target, result);
	}
}

void InventoryManager::inOrderDisplay(const BSTNode* root, ostream& os) const {
	if (root == nullptr) {
		return;
	}
	inOrderDisplay(root->leftChild, os);
	os << *root->data << endl;
	inOrderDisplay(root->rightChild, os);
}

InventoryManager::BSTNode*& InventoryManager::getRoot(char genre) {
	switch (genre) {
	case 'F': return comedyTree;
	case 'D': return dramaTree;
	case 'C': return classicTree;
	default:
		cerr << "Error: Unknown genre '" << genre << "'. Cannot get root." << endl;
		return comedyTree; // Return something to avoid compiler error, but this should never be used
	}
}

