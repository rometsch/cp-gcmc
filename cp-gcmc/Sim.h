/*
 * Sim.h
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#ifndef SIM_H_
#define SIM_H_

#include <vector>
#include <sstream>
#include "Box.h"

class Sim {
public:
	Box* box;		// Simulation box.
	int M;			// Box size.
	int L;			// Rod length.
	long int Niter;		// Number of steps.
	int Ntherm;		// Number thermalization steps.
	int step;		// number of steps to take a snapshot.
	double z;		// Activity. exp(beta mu)

	// Log vectors.
	std::vector<long int> T;
	std::vector<int> Nrod;
	std::vector<int> Nh;
	std::vector<int> Nv;

	Sim();
	virtual ~Sim();

	void update_parameters(double z, long int Niter, int Ntherm, int M, int L, int step);

	void run(double z, long int Niter, int Ntherm, int M, int L, int step);
	void snapshot(long int i);

	void print_data(std::ostream &out);
	void print_header(std::ostream &out, std::string sep);
	void print_position_horizontal(std::ostream &out);
	void print_position_vertical(std::ostream &out);
};

#endif /* SIM_H_ */
