/*
 * Teller.h
 *
 *  Created on: Oct 8, 2018
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
	int idleTime;
	void setIdleTime();
};

#endif /* TELLER_H_ */
