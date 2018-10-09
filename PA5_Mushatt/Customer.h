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
	Customer(int time);
	void setEndTime(int time);
	int getTime();
	void setNextCustomer(Customer *cust);
	Customer *nextCustomer;
private:
	int startTime;
	int endTime;
};

#endif /* CUSTOMER_H_ */
