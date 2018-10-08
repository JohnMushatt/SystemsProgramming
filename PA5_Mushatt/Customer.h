/*
 * Customer.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
public:
	Customer();
	virtual ~Customer();
	Customer(float time);
	void setEndTime(float time);
	Customer *nextCustomer;
private:
	float startTime;
	float endTime;
};

#endif /* CUSTOMER_H_ */
