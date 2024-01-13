#pragma once
#include <string>
#include <vector>
#include "date.h"
using namespace std;
class trip;
class user {
protected:
	string name;
	date DoB;
	string email;
	string phoneNo;
	vector<trip*> trips;
	trip* currentTrip;
public:
	user(string name, date d,string e,  string pNo);
	void changeName(string obj);
	void changeDoB(date);
	void changePhoneNo(string pno);
	virtual float  getAvgRating() = 0;
	trip* getCurrentRide();;
	void setCurrentRide(trip* ride);
	void storeRide();
	vector<trip*> getTrips();
	friend ostream& operator<<(ostream& out, const user& temp);
};