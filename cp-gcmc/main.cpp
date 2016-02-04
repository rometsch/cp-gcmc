/*
 * main.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include "Sim.h"

int main(int argc, char *argv[]) {
	// Call in command line with following optional arguments.
	// z Niter Ntherm M L steps

	// Initialize simulation parameters with default values.
	double z = 1.1;
	long int Niter = 2L<<32;
	int Ntherm = 2<<27;
	int M = 64;
	int L = 8;
	int steps = 1000;

	// Parse parameters from command line.
	if (argc > 1) z = std::stod(argv[1]);
	if (argc > 2) Niter = std::stol(argv[2]);
	if (argc > 3) Ntherm = std::stoi(argv[3]);
	if (argc > 4) M = std::stoi(argv[4]);
	if (argc > 5) L = std::stoi(argv[5]);
	if (argc > 6) steps = std::stoi(argv[6]);


	Sim sim;
	sim.run(z, Niter, Ntherm, M, L, steps);

}

