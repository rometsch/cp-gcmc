/*
 * Box.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include "Box.h"

Box::Box(int M, int L, double z) {
	// @param:	M -> legnth of the squre box.
	this->M = M;
	// Construct grid.
	for (int i=0; i<this->M; i++) {
		this->grid.push_back(std::vector<bool>());
		this->grid[i].assign(M,0);
	}
	// Start with 0 rods.
	this->Nrod = 0;
	this->Nrodh = 0;
	this->Nrodv = 0;
	// Use default rod length of 3.
	this->Lrod = L;

	// Initialize rng.
	rng.set_seed(20);

	// Initialize z.
	this->z = z;
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

void Box::iterate() {
	// Make one iteration. Choose insertion or deletion with probability 1/2 each.
//	this->print_grid();
	if (this->rng.draw_bool()) this->insert_rod();
	else this->delete_rod();
}

void Box::insert_rod() {
	// Insert rod into the grid.
	// Decide whether to insert.
	if ( this->rng.draw() > 2.*z*this->M*this->M/(this->Nrod+1) ) {
		return;
	}
	// Create new rod with random indices and random orientation.
	int x = this->rng.draw_between_int(0,this->M-1);
	int y = this->rng.draw_between_int(0,this->M-1);
	bool otn = this->rng.draw_bool();
	// Candidate rod.
	Rod cand(x,y,otn);
	if (check_collision(cand)) {
		return;
	}
	// Update grid.
	for (int i=0; i<this->Lrod; i++) {
		this->set_grid(x+otn*i ,y +(!otn)*i , true);
	}
	// Update rod counter.
	this->Nrod++;
	if (otn==true) this->Nrodv++;
	else this->Nrodh++;
	// Place rod at end of rod list.
	this->rods.push_back(cand);
	// Print success message.
	std::cout << "Inserted rod at x=" << x << " , y=" << y << " with orientation " << otn << std::endl;
}

void Box::delete_rod() {
	// Remove rod from the grid.
	if (this->Nrod==0) return;
	// Decide whether to delete.
	if ( this->rng.draw() > .5*this->Nrod/this->M/this->M/this->z ) {
		return;
	}
	// Get random index for rod to be deleted.
	int n = this->rng.draw_between_int(0,this->Nrod);
	// Get position and orientation of theselected rod.
	Rod rod = this->rods[n];
	// Update grid.
	for (int i=0; i<this->Lrod; i++) {
		this->set_grid(rod.x+rod.otn*i ,rod.y +(!rod.otn)*i , false);
	}
	// Update rod counter.
	this->Nrod--;
	if (rod.otn==true) this->Nrodv--;
	else this->Nrodh--;
	// Remove rod from rod list.
	this->rods.erase(this->rods.begin()+n);
}

bool Box::check_collision(Rod cand) {
	// Check if candidate rod c is colliding with existing rods.
	// Return true if there is a collision.
	bool iscol = false;
	for (int i=0; i<this->Lrod; i++) {
		iscol = iscol or this->get_grid(cand.x+cand.otn*i ,cand.y +(!cand.otn)*i);
	}
//	if (iscol) {
//		std::cout << "Rejected at x=" << cand.x << " , y=" << cand.y << " with orientation " << cand.otn << std::endl;
//	}
	return iscol;
}


bool Box::get_grid(int x, int y) {
	// Get value of grid at position i,j.
	// Account for periodic boundary conditions.
	return this->grid[(x+this->M)%this->M][(y+this->M)%this->M];
}

void Box::set_grid(int x, int y, bool val) {
	// Set value of grid at position i,j.
	// Account for periodic boundary conditions.
	this->grid[(x+this->M)%this->M][(y+this->M)%this->M] = val;
}

void Box::print_grid() {
	// Print out the content of the box to std::cout.
	std::cout << "Simulation box: " << this->M << "x" << this->M << " box:" << std::endl;
	for (int i=0; i<this->M; i++) {
		for (int j=0; j<this->M; j++) {
			std::cout << this->grid[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
