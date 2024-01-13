#pragma once
#include <string>
#include "user.h"
#include "driver.h"
#include "payment.h"
using namespace std;

class passanger: public virtual user {
private:
	payment *  paymentMethod[3];
public:
	passanger(string n, date d, string e, string pNo, payment p);
	void addPayment(payment obj);
	void deletePayment(payment obj);
	trip * bookRide(string source, string dest);
	void cancelRide();
	void rateDriver(trip* t, int rating);
	float getAvgRating();
	void printTrips();
	friend ostream& operator<<(ostream& out, const passanger& temp);
	~passanger();
};