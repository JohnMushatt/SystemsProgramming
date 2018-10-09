/*
 * Customer.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jemushatt
 */

#include "Customer.h"

Customer::Customer() {
	// TODO Auto-generated constructor stub
	startTime=0;
	endTime=0;
	nextCustomer=nullptr;
}
Customer::Customer(int time) {
	startTime= time;
	endTime = 0;
	nextCustomer=nullptr;

}
void Customer::setNextCustomer(Customer *cust) {
	nextCustomer = cust;
}
void Customer::setEndTime(int time) {
	endTime = time;
}
int Customer::getTime() {
	return startTime;
}
Customer::~Customer() {
	// TODO Auto-generated destructor stub
}
