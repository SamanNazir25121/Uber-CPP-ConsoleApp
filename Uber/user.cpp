#include "user.h"
user::user(string n, date d,string e, string pNo) {
	name = n;
	DoB = d;
	email = e;
	phoneNo = pNo;
	currentTrip = NULL;
}
void user::changeName(string obj) {
	name = obj;
}
void user::changeDoB(date obj) {
	DoB = obj;
}
void user::changePhoneNo(string pno) {
	phoneNo = pno;
}
trip* user::getCurrentRide() {
	if (currentTrip != NULL)
		return currentTrip;
	else
		return NULL;
}

void user::setCurrentRide(trip* ride) {
	currentTrip = ride;
}
void user::storeRide() {
	trips.push_back(currentTrip);
	currentTrip = NULL;
}
vector<trip*> user::getTrips() {
	return trips;
}
ostream& operator<<(ostream& out, const user& temp) {
	out << "Passenger Name: " << temp.name << endl;
	out << "Date of Birth: " << temp.DoB << endl;
	out << "Email: " << temp.email << endl;
	out << "Phone Number: " << temp.phoneNo << endl;
	return out;
}
