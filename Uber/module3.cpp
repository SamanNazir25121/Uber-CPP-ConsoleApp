#include "date.h"
#include "driver.h"
#include "passanger.h"
#include "payment.h"
#include "trip.h"
#include <fstream>
#include <string>
const int SIZE = 20;
user* UsersArray[10] = { NULL };
int index = 0;
trip** uberTrips = new trip * [SIZE];
int n = 0;
using namespace std;
void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}
void loadUsers(string filename) {
	ifstream fin;
	fin.open(filename);
	if (fin.is_open()) {
		string buffer;
		char type;
		while (!fin.eof()) {
			fin >> type;
			fin.ignore();
			string name;
			getline(fin, name, ',');
			int day, month, year;
			fin >> day;
			fin.ignore();
			fin >> month;
			fin.ignore();
			fin >> year;
			fin.ignore();
			string email;
			getline(fin, email, ',');
			string pNo;
			getline(fin, pNo);
			if (type == 'p') {
				UsersArray[index++] = new passanger(name, date(day, month, year), email, pNo, payment("cash"));

			}
			else if (type == 'd') {
				UsersArray[index++] = new driver(name, date(day, month, year), email, pNo,"", "");
			}
		}
	}
	fin.close();
}
void printAllUsers() {
	for (int i = 0; i < 10; i++) {
		if (UsersArray[i] != NULL) {
			cout << *UsersArray[i] << endl;
		}
	}
}
user* highlyRatedUser()
{
	float rating = 0, max = 0;
	user* temp = nullptr;

	for (int i = 0; i < 10; i++)
	{
		if (UsersArray[i] != NULL) {
			rating = UsersArray[i]->getAvgRating();
			if (rating > max)
			{
				max = rating;
				temp = UsersArray[i];
			}
		}
	}
	return temp;
}
passanger* highlyRatedPassenger()
{
	passanger* temp = nullptr;
	float max = 0, rating = 0;
	for (int i = 0; i < 10; i++)
	{
		if (UsersArray[i] != NULL) {
			if (strcmp(typeid(*UsersArray[i]).name(), "class passanger") == 0)
			{
				rating = UsersArray[i]->getAvgRating();
				if (rating > max)
				{
					max = rating;
					temp = dynamic_cast<passanger*>(UsersArray[i]);
				}
			}
		}
	}
	return temp;
}
driver* highlyRatedDriver()
{
	driver* temp = nullptr;
	float max = -1, rating = 0;
	for (int i = 0; i < 10; i++)
	{
		if (UsersArray[i] != NULL) {
			if (strcmp(typeid(*UsersArray[i]).name(), "class driver") == 0)
			{
				rating = UsersArray[i]->getAvgRating();
				if (rating > max)
				{
					max = rating;
					temp = dynamic_cast<driver*>(UsersArray[i]);
				}
			}
		}
	}

	return temp;
}
int main()
{

	loadUsers("data.txt");

	trip* ptr1 = nullptr, * ptr2 = nullptr;
	ptr1 = dynamic_cast<passanger*>(UsersArray[0])->bookRide("A", "B");

	dynamic_cast<driver*>(UsersArray[1])->pickARide(ptr1);


	dynamic_cast<driver*>(UsersArray[1])->endARide();

	dynamic_cast<passanger*>(UsersArray[0])->rateDriver(ptr1, 5);
	dynamic_cast<driver*>(UsersArray[1])->ratePassanger(ptr1, 4);


	ptr2 = dynamic_cast<passanger*>(UsersArray[2])->bookRide("C", "D");
	dynamic_cast<driver*>(UsersArray[4])->pickARide(ptr2);

	dynamic_cast<driver*>(UsersArray[4])->endARide();

	dynamic_cast<driver*>(UsersArray[4])->ratePassanger(ptr2, 3);

	dynamic_cast<passanger*>(UsersArray[2])->rateDriver(ptr2, 4);

	cout << *highlyRatedUser() << endl << highlyRatedUser()->getAvgRating() << endl << endl;
	cout << *highlyRatedPassenger() << endl << highlyRatedPassenger()->getAvgRating() << endl << endl;
	cout << *highlyRatedDriver() << endl << highlyRatedDriver()->getAvgRating() << endl << endl;



	return 0;
}
