/*
 * Rod.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#include "Rod.h"

Rod::Rod(int x, int y, bool otn) {
	// Set position and orientation.
	this->x = x;
	this->y = y;
	this->otn = otn;
	// Use standard length of 3 and width of 1.
	this->L = 3;
	this->W = 1;
}

Rod::~Rod() {
	// TODO Auto-generated destructor stub
}

