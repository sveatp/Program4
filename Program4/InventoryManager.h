#pragma once

#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "MovieFac.h"
#include <iostream>
#include <fstream>

using namespace std;

class InventoryManager {
	public:
		// Constructor and Destructor
		InventoryManager();
		~InventoryManager();

		// Reads movie data from input file and populates the three BSTs
		void buildInventory(ifstream& filename);

		// Adds a movie to the correct BST based on category.
		bool addMovie(Movie* movie);

		// Retrieves a movie from the inventory based on the movie's attributes (title, director, release year, etc.)
		// Returns true and sets the output parameter to the found movie if it exists, or returns false if the movie is not found
		bool getMovie(Movie* target, Movie*& result);

		// Displays the entire inventory of movies, grouped by category
		void displayInventory(ostream& os) const;

	private:
		struct BSTNode {
			Movie* data;
			BSTNode* leftChild;
			BSTNode* rightChild;
			
			BSTNode(Movie* m) : data(m), leftChild(nullptr), rightChild(nullptr) {}
		};

		BSTNode* comedyTree;
		BSTNode* dramaTree;
		BSTNode* classicTree;

		// Returns the root pointer for the specified genre's BST
		BSTNode*& getRoot(char genre);
		const BSTNode* getRoot(char genre) const;

		// Recursive BST insert, uses the Movie's comparison operators to determine placement
		void insert(BSTNode*& root, Movie* m);

		// Recursive BST search, uses the Movie's comparison operators to determine placement
		// Returns true and sets the output parameter to the found movie if it exists, or returns false if the movie is not found
		bool search(const BSTNode* root, Movie* target, Movie*& result) const;

		// Recursive in-order traversal to display movies in sorted order
		void inOrderDisplay(const BSTNode* root, ostream& os) const;

		// Recursive function to clear all nodes in a BST
		void clearTree(BSTNode* root);
};

#endif // INVENTORY_MANAGER_H