#include "trip.h"

passanger::passanger(string n, date d, string e, string pNo, payment p):user(n,d,e,pNo) {
	this->addPayment(p);

}
void passanger::addPayment(payment obj) {
	bool flag = true;
	for (int i = 0; i < 3; i++) {
		if (paymentMethod[i] == NULL && flag) {
			paymentMethod[i] = new payment(obj);
			flag = false;
		}
	}
}
void passanger::deletePayment(payment obj) {
	bool flag = true;
	for (int i = 0; i < 3; i++) {
		if (paymentMethod[i] != NULL) {
			if (*paymentMethod[i] == obj) {
				delete paymentMethod[i];
				paymentMethod[i] = NULL;
			}
		}
	}
}

trip* passanger::bookRide(string source, string dest) {
	trip* temp = NULL;
	if (this->getCurrentRide() == NULL) {
		temp = new trip(this, NULL, source, dest);
		this->setCurrentRide(temp);
	}
	else {
		cout << "You're already on a trip" << endl;
	}
	return temp;
}
void passanger::cancelRide() {
	trip* temp = this->getCurrentRide();
	if (temp != NULL) {
		temp->changeStatus(3);
		this->setCurrentRide(NULL);
	}
	else {
		cout << "You are not in a ride." << endl;
	}
}
void passanger::rateDriver(trip* t, int rating) {
	vector<trip*> obj = this->getTrips();
	bool ownTrip = false;
	for (int i = 0; i < obj.size(); i++) {
		if (obj[i] == t) {
			ownTrip = true;
		}
	}
	if (ownTrip && t->getStatus() == 2) {
		t->rateDriver(rating);
	}
	else {
		cout << "Error the trip wasn't complete." << endl;
	}

}
float passanger::getAvgRating() {
	vector<trip*> obj = this->getTrips();
	int sum = 0, count = 0;
	for (int i = 0; i < obj.size(); i++) {
		sum += obj[i]->getPassengerRating();
		count++;
	}
	return (float)sum / (float)count;
}
void passanger::printTrips() {
	vector<trip*> obj = this->getTrips();
	for (int i = 0; i < obj.size(); i++) {
		cout << "TRIP " << i << ": " << *obj[i];
	}
}
ostream& operator<<(ostream& out, const passanger& temp) {
	out << "Passenger Name: " <<  temp.name << endl;
	out << "Date of Birth: " << temp.DoB << endl;
	out << "Email: " << temp.email << endl;
	out << "Phone Number: " << temp.phoneNo << endl;
	for (int i = 0; i < 3; i++) {
		if (temp.paymentMethod[i] != NULL) {
			out << "Payment Method: " << *temp.paymentMethod[i] << endl;
		}
	}

	return out;
}
passanger::~passanger() {

}