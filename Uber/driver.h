#pragma once
#include "user.h"
class trip;
class driver : public virtual user {
	string drivingLicenceNumber;
	string vehicleIDNumber;
public:
	driver(string n, date d, string e, string pNo, string dLic, string vID);
	void pickARide(trip* paramTrip);
	void endARide();
	void ratePassanger(trip* paramTrip, int rating);
	float getAvgRating();
	void printTrips();
	friend ostream& operator<<(ostream& out, const driver& temp);
	~driver();
};