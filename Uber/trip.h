#pragma once
#include <iostream>
#include <string>
#include "passanger.h"
#include "driver.h"
#include "date.h"
using namespace std;
class  trip {
private:
	int status; //0 = Looking for Driver, 1 = In progress, 2 = Complete, 3 = Cancelled
	driver* captain;
	passanger* customer;
	date d;
	string pickUpLocation;
	string dropOffLocation;
	int dRating;
	int pRating;
public:
	trip(passanger * p, driver * d, string source, string dest);
	void changeStatus(int newStatus);
	void rateDriver(int rating);
	void ratePassenger(int rating);
	void setPickupLocation(string location);
	void setDropoffLocation(string location);
	void setDriver(driver* d);
	void setPassenger(passanger* p);
	int getDriverRating();
	int getPassengerRating();
	int getStatus();
	friend ostream& operator << (ostream&, const trip&);
	~trip();
};