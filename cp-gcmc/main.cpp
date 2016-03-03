/*
 * main.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include <fstream>
#include "Sim.h"

int main(int argc, char *argv[]) {
	// Call in command line with following optional arguments.
	// z Niter Ntherm M L steps

	// Initialize simulation parameters with default values.
	double z = 1.1;
	long int Niter = 2L<<32;
	int Ntherm = 0;//2<<27;
	int M = 64;
	int L = 8;
	int step = 10000;

	// Parse parameters from command line.
	if (argc > 1) z = std::stod(argv[1]);
	if (argc > 2) Niter = std::stol(argv[2]);
	if (argc > 3) Ntherm = std::stoi(argv[3]);
	if (argc > 4) M = std::stoi(argv[4]);
	if (argc > 5) L = std::stoi(argv[5]);
	if (argc > 6) step = std::stoi(argv[6]);


	Sim sim;
	sim.run(z, Niter, Ntherm, M, L, step);
	// Data ofstream.
	std::ofstream data_file("data_z"+std::to_string(z)+".txt", std::ofstream::out);
	sim.print_data(data_file);
	data_file.close();
	std::ofstream data_file_hor("horiontal_z"+std::to_string(z)+".txt", std::ofstream::out);
	sim.print_position_horizontal(data_file_hor);
	data_file_hor.close();
	std::ofstream data_file_vert("vertical_z"+std::to_string(z)+".txt", std::ofstream::out);
	sim.print_position_vertical(data_file_vert);
	data_file_vert.close();
}

