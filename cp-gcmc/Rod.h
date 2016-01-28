/*
 * Rod.h
 *
 *  Created on: Jan 28, 2016
 *      Author: thomas
 */

#ifndef ROD_H_
#define ROD_H_

class Rod {
public:
	int x;			// x postition of rod in box.
	int y;			// y postition of rod in box.
	bool otn;		// Orientation of rod. False for horizontal, true for vertical.

	int L;			// Length of rod.
	int W;			// Width of rod.

	Rod(int x, int y, bool otn);
	virtual ~Rod();
};

#endif /* ROD_H_ */
