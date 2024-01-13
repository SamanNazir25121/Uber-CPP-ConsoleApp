#include "trip.h"
trip::trip(passanger* p, driver* d, string source, string dest){
	status = 0;
	captain = d;
	customer = p;
	pickUpLocation = source;
	dropOffLocation = dest;
	dRating = 1;
	pRating = 1;
}
int trip::getDriverRating() {
	return dRating;
}
int trip::getPassengerRating() {
	return pRating;
}
int trip::getStatus() {
	return status;
}
void trip::changeStatus(int newStatus) {
	status = newStatus;
	if (newStatus == 2) {
		customer->storeRide();
		captain->storeRide();
	}
}

void trip::rateDriver(int rating) {
	if (rating <= 5 && rating >= 0) {
		dRating = rating;
	}
	else {
		cout << "Invalid Rating" << endl;
	}
}
void trip::ratePassenger(int rating) {
	if (rating <= 5 && rating >= 0) {
		pRating = rating;
	}
	else {
		cout << "Invalid Rating" << endl;
	}
}

void trip::setPickupLocation(string location) {
	if (location.size() > 0) {
		pickUpLocation = location;
	}
	else {
		cout << "Invalid Pickup Location" << endl;
	}
}

void trip::setDropoffLocation(string location) {
	if (location.size() > 0) {
		dropOffLocation = location;
	}
	else {
		cout << "Invalid Pickup Location" << endl;
	}
}
void trip::setDriver(driver* d) {
	captain = d;
}
void trip::setPassenger(passanger* p) {
	customer = p;
}
ostream& operator<<(ostream& out, const trip& temp) {
	if (temp.status == 0) {
		out << "Looking for Driver" << endl;
	}
	else if (temp.status == 1) {
		out << "In programs" << endl;
	}
	else if (temp.status == 2) {
		out << "Completed" << endl;
	}
	else if (temp.status == 3) {
		out << "Cancelled" << endl;
	}
	out << "Date: " << temp.d << endl;
	if (temp.captain != NULL)
		out << "Driver: " << *temp.captain << endl;
	else
		out << "No Driver Yet" << endl;
	if (temp.customer != NULL)
		out << "Passenger: " << *temp.customer << endl;
	else
		out << "No Passenger Yet" << endl;
	out << "Drop off Location: " << temp.dropOffLocation << endl;
	out << "Pickup Location: " << temp.pickUpLocation << endl;
	out << "Driver Rating: " << temp.dRating << endl;
	out << "Passenger Rating: " << temp.pRating << endl;
	return out;
}