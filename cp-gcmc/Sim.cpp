/*
 * Sim.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include "Sim.h"

Sim::Sim(std::stringstream &out) {
	this->M = 32;
	this->L = 8;
	this->Niter = 2L<<20;
	this->Ntherm = 2<<11;
	this->step = this->Niter/2000;
	this->z = 1.1;
	this->box = new Box(this->M,this->L,this->z);
	this->out=out;
}

Sim::~Sim() {
	delete this->box;
}

void Sim::update_parameters(double z, long int Niter, int Ntherm, int M, int L, int steps) {
	// Update simulation parameteres.
	this->M = M;
	this->z = z;
	this->L = L;
	this->Niter = Niter;
	this->Ntherm = Ntherm;
	this->step = this->Niter/step;
	// Built a new box.
	delete this->box;
	this->box = new Box(this->M,this->L,this->z);
}



void Sim::run(double z, long int Niter, int Ntherm, int M, int L, int steps) {
	this->update_parameters(z, Niter, Ntherm, M , L, steps);
	this->print_header("%");
	// Thermalize.
	for (int i=0; i<this->Ntherm; i++) this->box->iterate();
	// Run simulation.
	for (long int i=0; i<this->Niter; i++) {
		if(i%this->step==0) {
			// Take a snapshot.
			this->snapshot(i);
//			std::cout << i << "\t" << this->box->Nrod << "\t" << this->box->Nrodh << "\t" << this->box->Nrodv << "\t" << std::endl;
		}
//		std::cout << "iteration " << i << std::endl;
		this->box->iterate();

	}

	// Print out data.
	this->print_data();
}

void Sim::snapshot(long int i) {
	// Store the set of observables from the box.
	this->T.push_back(i);
	this->Nrod.push_back(this->box->Nrod);
	this->Nh.push_back(this->box->Nrodh);
	this->Nv.push_back(this->box->Nrodv);
}

void Sim::print_data() {
	// Print the data stored in log vectors.
	for (int i=0; i<this->Nrod.size(); i++) {
		std::cout << this->T[i] << "\t" << this->Nrod[i] << "\t" << this->Nh[i] << "\t" << this->Nv[i] << std::endl;
	}
}

void Sim::print_header(std::string sep) {
	// Print simulation parameters.
	std::cout << sep <<  " z = " << this->z << std::endl;
	std::cout << sep << " Niter = " << this->Niter << std::endl;
	std::cout << sep << " Ntherm = " << this->Ntherm << std::endl;
	std::cout << sep << " M = " << this->M << std::endl;
	std::cout << sep << " L = " << this->L << std::endl;
	std::cout << sep << " t \t N \t N+ \t N-" << std::endl;
}

void Sim::print_position_horizontal() {
	// Print position of horizontal rods.
	for (int i=0; i<this->box->Nrod; i++) {
		if (!this->box->rods.at(i).otn) { // Check orientation flag of rod. Flag is false for horizontal.
			std::cout << this->box->rods.at(i).x << "\t" << this->box->rods.at(i).y << std::endl;
		}
	}
}
void Sim::print_position_vertical() {
	// Print position of vertical rods.
	for (int i=0; i<this->box->Nrod; i++) {
		if (this->box->rods.at(i).otn) { // Check orientation flag of rod. Flag is true for vertical.
			std::cout << this->box->rods.at(i).x << "\t" << this->box->rods.at(i).y << std::endl;
		}
	}
}
