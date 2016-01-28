/*
 * Sim.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include "Sim.h"

Sim::Sim() {
	this->M = 32;
	this->L = 8;
	this->Niter = std::pow(10,5);
	this->step = 100;
	this->z = 1.1;
	this->box = new Box(this->M,this->L,this->z);
}

Sim::~Sim() {
	delete this->box;
}


void Sim::run() {
	// Run simulation.
	std::cout << "here" << std::endl;
	for (int i=0; i<this->Niter; i++) {
		if(i%this->step==0) {
			// Take a snapshot.
			this->snapshot();
		}
		std::cout << "iteration " << i << std::endl;
		box->iterate();
	}

	// Print out data.
//	this->print_data();
}

void Sim::snapshot() {
	// Store the set of observables from the box.
	this->N.push_back(this->box->Nrod);
	this->Nh.push_back(this->box->Nrodh);
	this->Nv.push_back(this->box->Nrodv);
}

void Sim::print_data() {
	// Print the data stored in log vectors.
	for (int i=0; i<this->N.size(); i++) {
		std::cout << this->N[i] << "\t" << this->Nh[i] << "\t" << this->Nv[i] << std::endl;
	}
}
