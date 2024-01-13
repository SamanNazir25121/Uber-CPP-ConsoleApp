#pragma once
#include <string>
using namespace std;

class payment {
	string Type;
	string cardNumber;
public:
	payment(string t, string card);
	payment(string t);
	string getCard();
	void setCard(string card);
	friend ostream& operator<<(ostream& out, const payment& temp);
	friend bool operator==(payment& temp1, payment& temp);
};