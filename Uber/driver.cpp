#include "trip.h"

driver::driver(string n, date d, string e, string pNo, string dLic, string vID):user(n,d,e,pNo) {
	drivingLicenceNumber = dLic;
	vehicleIDNumber = vID;
}
void driver::pickARide(trip* paramTrip) {
	if (paramTrip->getStatus() == 0) {
		if (this->getCurrentRide() == NULL) {
			paramTrip->changeStatus(1);
			paramTrip->setDriver(this);
			this->setCurrentRide(paramTrip);
		}
		else {
			cout << "You're already in a ride" << endl;
		}
	}
	else {
		cout << "Cannot pick this ride!" << endl;
	}
}

void driver::endARide() {
	trip* ride = this->getCurrentRide();
	if (ride != NULL) {
		ride->changeStatus(2);
		this->setCurrentRide(NULL);
	}
}
void driver::ratePassanger(trip* paramTrip, int rating) {
	vector<trip*> obj = this->getTrips();
	bool ownTrip = false;
	for (int i = 0; i < obj.size(); i++) {
		if (obj[i] == paramTrip) {
			ownTrip = true;
		}
	}
	if (ownTrip && paramTrip->getStatus() == 2) {
		paramTrip->ratePassenger(rating);
	}
	else {
		cout << "Error the trip wasn't complete." << endl;
	}

}
float driver::getAvgRating() {
	vector<trip*> obj = this->getTrips();
	int sum = 0, count = 0;
	for (int i = 0; i < obj.size(); i++) {
		sum += obj[i]->getDriverRating();
		count++;
	}
	return (float)sum / (float)count;
}
void driver::printTrips() {
	vector<trip*> obj = this->getTrips();
	for (int i = 0; i < obj.size(); i++) {
		cout << "TRIP " << i << ": " << *obj[i];
	}
}
ostream& operator<<(ostream& out, const driver& temp) {
	out << "Name: " << temp.name << endl;
	out << "Date of Birth: " << temp.DoB << endl;
	out << "Email: " << temp.email << endl;
	out << "Phone Number: " << temp.phoneNo << endl;
	out << "Driving Licence Number: " << temp.drivingLicenceNumber << endl;
	out << "Vehicle ID Number: " << temp.vehicleIDNumber << endl;
	return out;
}
driver::~driver() {

}