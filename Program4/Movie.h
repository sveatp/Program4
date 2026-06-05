#pragma once

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

using namespace std;


class Movie {
	public:
		Movie();

		virtual ~Movie();

		virtual bool operator==(const Movie& other) const = 0;
		virtual bool operator<(const Movie& other) const = 0;

		// Returns the amount of stock
		int getStock() const;

		// Adds the specified amount to the stock of this movie
		void addStock(int amount);

		// Decrease stock by 1 if available, and returns true
		bool borrowMovie();	

		// Increments the stock
		void returnMovie();			

		string getTitle() const;
		string getDirector() const;
		int getReleaseYear() const;
		char getCategory() const;

		virtual void setData(istream& infile) = 0;	// Pure virtual function to set movie data from input stream
		virtual void display(std::ostream& os) const = 0;

		// Redirect streams to the display function
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	protected:
		char category;				// 'C' for Classic, 'D' for Drama, 'F' for Comedy
		int stock;
		string director;
		string title;
		int releaseYear;
};

#endif // MOVIE_H