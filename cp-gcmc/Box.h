/*
 * Box.h
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#ifndef BOX_H_
#define BOX_H_

#include <vector>
#include <deque>
#include <iostream>
#include "Rod.h"
#include "Rng.h"

class Box {
public:
	int M;										// Side length of box.
	std::vector<std::vector<bool> > grid;		// Simulation box to put rods in.
	int Lrod;									// Length of rods.
	std::deque<Rod> rods;						// List of rods. Use list because of deletion at random positions.

	// Control parameters.
	double z;

	// Observables
	int Nrod;									// Number of rods.
	int Nrodh;									// Number of rods with horizontal orientation.
	int Nrodv;									// Number of rods with vertical orientation.


	Rng rng;		// Wrapper object to std library rngs.


	Box(int M, int L, double z);
	virtual ~Box();

	void iterate();					// Make one iteration.
	void insert_rod();				// Insert rod into the grid.
	void delete_rod();				// Remove rod from the grid.
	bool check_collision(Rod cand);	// Check if candidate rod cand is colliding with existing rods.

	bool get_grid(int x, int y);			// Get value of grid at position i,j.
	void set_grid(int x, int y, bool val);	// Set value of grid at position i,j.
	void print_grid();						// Print out the content of the box to std::cout.

	int rand();						// Uniform number from [0,1]. Wrapper to std lib rng.

};

#endif /* BOX_H_ */
