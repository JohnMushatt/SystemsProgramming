/*
 * Customer.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: jemushatt
 */

#include "Customer.h"

Customer::Customer() {
	// TODO Auto-generated constructor stub
	startTime=0;
	endTime=0;

}
Customer::Customer(float time) {
	startTime= time;
	endTime = 0;
}

void Customer::setEndTime(float time) {
	endTime = time;
}
Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

