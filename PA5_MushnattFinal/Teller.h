/*
 * Teller.h
 *
 *  Created on: Oct 6, 2018
 *      Author: jemushatt
 */

#ifndef TELLER_H_
#define TELLER_H_

class Teller {
public:
	Teller();
	virtual ~Teller();
private:
	const int idleTimeConst= 600;
	float idleTime;
};

#endif /* TELLER_H_ */
