/*
 * Sim.h
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#ifndef SIM_H_
#define SIM_H_

#include <vector>
#include "Box.h"

class Sim {
public:
	Box* box;		// Simulation box.
	int M;			// Box size.
	int L;			// Rod length.
	int Niter;		// Number of steps.
	int step;		// number of steps to take a snapshot.
	double z;		// Activity. exp(beta mu)

	// Log vectors.
	std::vector<int> N;
	std::vector<int> Nh;
	std::vector<int> Nv;

	Sim();
	virtual ~Sim();

	void run();
	void snapshot();

	void print_data();
};

#endif /* SIM_H_ */
