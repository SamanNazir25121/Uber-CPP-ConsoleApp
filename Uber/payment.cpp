#include "payment.h"
#include <iostream>
payment::payment(string card, string t) {
	Type = t;
	cardNumber = card;
}
payment::payment(string t) {
	Type = t;
}
string payment::getCard() {
	return cardNumber;
}
void payment::setCard(string card) {
	cardNumber = card;
}
ostream& operator<<(ostream& out, const payment& temp) {
	
	out <<"Payment Type: " <<  temp.Type << endl;
	if (temp.cardNumber.size() > 0)
		out <<"Card Number: " <<  temp.cardNumber << endl;

	return out;
}
bool operator==(payment& temp1,payment& temp){
	bool ans = false;
	if (temp1.Type == temp.Type && temp1.cardNumber == temp.cardNumber) {
		ans = true;
		return ans;
	}
	return ans;
}