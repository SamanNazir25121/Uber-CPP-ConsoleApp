//#include <iostream>
//#include "payment.h"
//#include "driver.h"
//#include "date.h"
//#include "passanger.h"
//#include "trip.h"
//using namespace std;
//
//const int SIZE=20;
////an array of trips to keep pointers of all the trips of uber application
////This array will keep data of all the trips ever created. 
//trip **uberTrips = new trip*[SIZE]; 
//int n=0;
//
//void addToUberTrips(trip* t)// function to add new trips to uberTrips
//{
//	if(n<SIZE-1 && t!=nullptr)
//	{
//		uberTrips[n++]= t;
//	}
//} 
//void printUberTrips() //function to print uberTrips
//{
//	for(int i=0; i<n; i++)
//	{
//		cout<<i<<" "<<*uberTrips[i]<<endl;
//	}
//} 
//void main()
//{
//
//	passanger * p1= new passanger("P1", date(10,10,1990), "ali@yahoo.com", "0334564334" ,payment("111-222-333-333", "card") );
//	driver *d1= new driver("D1", date(16,1,1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");
//	
//	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
//	cout<<*p1<<endl;
//	cout<<*d1<<endl; 
//
//	addToUberTrips( p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
//	cout<<*uberTrips[n-1];// will print this trip
//	addToUberTrips( p1->bookRide("C", "D"));//prints error as p1 has already booked a ride
//	d1->pickARide(uberTrips[n-1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
//	d1->ratePassanger(uberTrips[n-1], 5); //error as the trip is not complete
//	p1->rateDriver(uberTrips[n-1],4); //error as the trip is not complete
//
//	cout<<*p1<<endl;
//	cout<<*d1<<endl; 
//	
//	d1->endARide(); //will change the status of uberTrip[0] to Complete
//
//	d1->ratePassanger(uberTrips[n-1], 5); //error as the trip is not complete
//	p1->rateDriver(uberTrips[n-1],4); //error as the trip is not complete
//	cout<<*uberTrips[n-1]<<endl;
//	cout<<*p1<<endl;
//	cout<<*d1<<endl; 
//	d1->pickARide(uberTrips[n-1]);//prints error as the ride is completed
//	cout<<"-------------------------------------"<<endl;
//
//	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
//	addToUberTrips(p1->bookRide("C", "D"));
//	d1->pickARide(uberTrips[n-1]); 
//	cout<<*p1<<endl;
//	cout<<*d1<<endl;
//	p1->cancelRide();
//	p1->cancelRide();//error as there is no current ride
//	cout<<*p1<<endl;
//	cout<<*d1<<endl;
//	d1->ratePassanger(uberTrips[n-1], 5); //error as the ride was not complete
//	p1->rateDriver(uberTrips[n-1], 5); //error as the ride was not complete
//	cout<<"-------------------------------------"<<endl;
//
//	////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
//	addToUberTrips(p1->bookRide("D", "E"));
//	p1->cancelRide();
//	d1->pickARide(uberTrips[n-1]); //error as this ride is not looking for driver
//	d1->ratePassanger(uberTrips[n-1], 5); //error as the ride was not complete
//	p1->rateDriver(uberTrips[n-1], 5); //error as the ride was not complete
//	cout<<"-------------------------------------"<<endl;
//
//	////Test Case 4: getting avg ratings adn print trip funnction
//	//Adding some more test data
//	addToUberTrips( p1->bookRide("X", "Y"));
//	d1->pickARide(uberTrips[n-1]); 
//	d1->endARide(); 
//	d1->ratePassanger(uberTrips[n-1], 3); 
//	p1->rateDriver(uberTrips[n-1],5); 
//
//	addToUberTrips( p1->bookRide("X", "Y"));
//	d1->pickARide(uberTrips[n-1]); 
//	d1->endARide(); 
//	d1->ratePassanger(uberTrips[n-1], 6);//error as the rating is not between 1 and 5 
//	d1->ratePassanger(uberTrips[n-1], 4);
//	d1->ratePassanger(uberTrips[n-1], 3);// will upate the passanging rating from 4 to 3
//	p1->rateDriver(uberTrips[n-1],1);
//
//	p1->printTrips();
//	d1->printTrips();
//	cout<<p1->getAvgRating();
//	cout<<d1->getAvgRating();
//	
//
//
//	
//
//
//	system("PAUSE");
//	
//}