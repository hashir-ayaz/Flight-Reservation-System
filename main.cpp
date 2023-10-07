//hashir ayaz 22i2407
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>
using namespace std;
class Passport;//forward declaration
class User;
class Passenger;
class Admin;
class Airport;
class Plane;
class Flight;
class City;
class Booking;
class FlightSchedule;
class Finance;
bool validatePassword(string password){
    
    if(password.length() < 8){
        cout<<"Password must be atleast 8 characters long"<<endl;
        return false;
    }
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for(unsigned int i = 0; i < password.length(); i++){
        if(isupper(password[i])){
            hasUpper = true;
        }
        if(islower(password[i])){
            hasLower = true;
        }
        if(isdigit(password[i])){
            hasDigit = true;
        }
        if(password[i]=='!' ||  password[i]=='#'|| password[i]=='$'){
            hasSpecial = true;
        }

    }
    if(hasUpper == false){
        cout<<"Password must contain atleast one uppercase letter"<<endl;
        return false;
    }
    if(hasLower == false){
        cout<<"Password must contain atleast one lowercase letter"<<endl;
        return false;
    }
    if(hasDigit == false){
        cout<<"Password must contain atleast one digit"<<endl;
        return false;
    }
    if(hasSpecial == false){
        cout<<"Password must contain atleast one special character"<<endl;
        return false;
    }
    return true;
}

class Finance{
    private:


    public:
    Finance(){

    }


    void verifyFinancialDetails(){
    cout<<"Enter your credit card number: ";
    string creditCardNumber;
    cin>>creditCardNumber;
    cout<<"Enter your Pin: ";
    string pin;
    cin>>pin;
    cout<<"Enter your CVV: ";
    string cvv;
    cin>>cvv;
    cout<<"Enter your expiry date: ";
    string expiryDate;
    cin>>expiryDate;

    cout<<"Please wait , verifying payment details..."<<endl;
    sleep(3);
    cout<<"Payment Approved"<<endl;

    }
};
class Passport{
private:
    string passportNo;
    string name;
    int age;
    

public:
    Passport(){
        passportNo = "";
        name = "";
        age = 0;
    }
    Passport(string passportNo, string name, int age){
        this->passportNo = passportNo;
        this->name = name;
        this->age = age;
    }
    string getPassportNo(){
        return passportNo;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    void setPassportNo(string passportNo){
        this->passportNo = passportNo;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    Passport& operator=(const Passport& p){ //have a look at syntax again
        this->passportNo = p.passportNo;
        this->name = p.name;
        this->age = p.age;
        return *this;
    }
};//class passport ends here

class User{
private:
    string username;
    string password;
    // int row=1;
    // int col=2;
    // string **PassengerArray;// a 2d array of usernames and passwords
public:
    User(){
        username = "";
        password = "";
        // PassengerArray= new string*[row];
        // for (int i = 0; i < row; i++)
        // {
        //     PassengerArray[i] = new string[col];
        // };
    }
    User(string username, string password){
        this->username = username;
        this->password = password;
        // PassengerArray= new string*[row];
        // for (int i = 0; i < row; i++)
        // {
        //     PassengerArray[i] = new string[col];
        // };
        // PassengerArray[row-1][col-2]=username;//adding username to array
        // PassengerArray[row-1][col-1]=password;//adding password to array
        // cout<<"login details added to array "<<PassengerArray[row-1][col-2]<<endl;// to check if the array is being updated, remove later
        // row++;

    }
    string getUsername(){
        return username;
    }
    string getPassword(){
        return password;
    }
    void setUsername(string username){
        this->username = username;
    }
    void setPassword(string password){
        this->password = password;
    }
    // string getPassengerArray(int row, int col){
    //     return PassengerArray[row][col];
    // }
    // int getRow(){
    //     return row;
    // }
    // int getCol(){
    //     return col;
    // }
   
};//class user ends here

class Passenger: public User{
//private:
public:
    string name;
    int cnic;
    int age;
    Passport passport;
    string myBookings[10];
    int bookingCount = 0;
    Passenger(){
        cnic = 0;
        age = 0;
        passport = Passport();
        

    }
    Passenger(string username, string password, long cnic, int age, Passport passport):User(username, password){
        this->cnic = cnic;
        this->age = age;
        this->passport = passport;
        
    }
    
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    long getCnic(){
        return cnic;
    }
    int getAge(){
        return age;
    }
    Passport getPassport(){
        return passport;
    }
    void setCnic(long cnic){
        this->cnic = cnic;
    }
    void setAge(int age){
        this->age = age;
    }
    void setPassport(Passport passport){
        this->passport = passport;
    }
    bool login(){
        string username, password;
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;

        ifstream file;
        file.open("Passenger.txt");
        string line;
        while(getline(file, line)){
            if(line.find(username) != string::npos && line.find(password) != string::npos){
                string myString = line;
                cout<<"Login successful"<<endl;
                this->setUsername(username);
                this->setPassword(password);

                //implement functionality to assign the other data values from file to object
                //extracting each variable indivudally from the string
            stringstream ss(myString); // Use stringstream to read values from string
            string cnic, age, passportNo, name,user,pwd;
            ss >>user>>pwd>> cnic >> age >> passportNo;
            getline(ss, name);//working

            // Assigning the extracted values to the object
            this->setCnic(stoi(cnic));
            this->setAge(stoi(age));
            Passport p(passportNo, name, stoi(age));
            this->setPassport(p);


                file.close();
                return true;
            }
        }
        cout<<"Login failed try again"<<endl;
        sleep(10);
        exit(0);
        return false;
    }
    void Register(){//of passeneger class
        string username, password;
        long cnic;
        int age;
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;
        while(!validatePassword(password)){
            cin>>password;
        }
        cout<<"please re enter your password: ";
        string password2;
        cin>>password2;
        if(password != password2){
            cout<<"passwords do not match"<<endl;
            sleep(10);
            exit(0);
        }
        cout<<"how old are you? "<<endl;
        cin>>age;
        if (age<18)
        {
            cout<<"you are not eligible to register"<<endl;
            sleep(10);
            exit(0);
        }
        
        cout<<"Enter your CNIC: "<<endl;
        cin>>cnic;
        cout<<"Enter your passport number: "<<endl;
        string passportNo;
        cin>>passportNo;
        cout<<"Enter your name: "<<endl;
        string name;
        cin>>name;
        // Passport p(passportNo, name, age);
        // User(username, password);

        this->setUsername(username);
        this->setPassword(password);
        this->setCnic(cnic);
        this->setAge(age);
        this->passport.setPassportNo(passportNo);
        this->passport.setName(name);
        this->passport.setAge(age);
        this->setName(name);
        //this->setPassport(p);
        //this->setPassport(passport);

        ofstream file;
        file.open("Passenger.txt", ios::app);
        file<<username<<" "<<password<<" "<<cnic<<" "<<age<<" "<<passportNo<<" "<<name<<endl;
        file.close();


    }

    void makeBooking(){
        string myBookings[10];
        cout<<"enter flight number you want to book"<<endl;
        string flightNo;
        cin>>flightNo;
        myBookings[bookingCount] = flightNo;
        bookingCount++;

        //reading from file

        ifstream file;
        file.open("flightschedule.txt");
        string line;
        //reading from line and outputting
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Here are the details of the flight you selected"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        while(getline(file, line)){
            if(line.find(flightNo) != string::npos){
                istringstream ss(line);
                string keyword;
                while (getline(ss, keyword, '%')) {
                cout << keyword << endl;
                }
            }
        }
        file.close();
        Finance finance;
        finance.verifyFinancialDetails();
        cout<<"Booking successful"<<endl;
    }

    void viewMyBookings(){
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Here are the details of the flight you selected"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        for(int i = 0; i < bookingCount; i++){
            cout<<myBookings[i]<<endl;
        }
    }

    void cancelBooking(){
        cout<<"enter flight number you want to cancel"<<endl;
        string flightNo;
        cin>>flightNo;
        for(int i = 0; i < bookingCount; i++){
            if(myBookings[i] == flightNo){
                myBookings[i] = "";
                cout<<"Booking cancelled"<<endl;
                cout<<"75 percent of your money will be refunded";
                return;
            }
        }
        cout<<"Booking not found"<<endl;
        sleep(10);
        exit(0); 
    }
};//class passenger ends here

class Admin: protected User{
private:
    string name;
    string emailID;
public:
    Admin(){
        name = "";
        emailID = "";
    }
    Admin(string username, string password, string name, string emailID):User(username, password){
        this->name = name;
        this->emailID = emailID;
    }
    string getName(){
        return name;
    }
    string getEmailID(){
        return emailID;
    }
    void setName(string name){
        this->name = name;
    }
    void setEmailID(string emailID){
        this->emailID = emailID;
    }
    void Register(){//of admin class
        string username, password, name, emailID;
        cout<<"Enter username: ";
        cin>>username;

        cout<<"Enter password: ";
        cin>>password;
        while(!validatePassword(password)){
            cin>>password;
        }
        cout<<"please re enter your password: ";
        string password2;
        cin>>password2;
        if(password != password2){
            cout<<"passwords do not match"<<endl;
            sleep(10);
            exit(0);
        }
        cout<<"Enter your name: "<<endl;
        cin>>name;
        cout<<"Enter your email ID: "<<endl;
        cin>>emailID;
        this->setUsername(username);
        this->setPassword(password);
        this->setName(name);
        this->setEmailID(emailID);

        ofstream file;
        file.open("Admin.txt", ios::app);
        file<<username<<" "<<password<<" "<<name<<" "<<emailID<<endl;
        file.close();

    }
    bool login(){
        string username, password;
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;

        ifstream file;
        file.open("Admin.txt");
        string line;
        while(getline(file, line)){
            if(line.find(username) != string::npos && line.find(password) != string::npos){
                string myString = line;
                cout<<"Login successful"<<endl;
                this->setUsername(username);
                this->setPassword(password);

                //implement functionality to assign the other data values from file to object
                //extracting each variable indivudally from the string
            stringstream ss(myString); // Use stringstream to read values from string
            string name,emailID,user,pwd;
            ss >>user>>pwd>> name >> emailID;
            getline(ss, name);//working

            // Assigning the extracted values to the object
            this->setName(name);
            this->setEmailID(emailID);

                file.close();
                return true;
            }
        }
        cout<<"Login failed try again"<<endl;
        sleep(10);
        return false;
    }

    void addFlight(){
        cout<<"Enter flight number: ";
        string flightNo;
        cin>>flightNo;
        cout<<"enter source: "<<endl;
        string source;
        cin>>source;
        cout<<"enter destination: "<<endl;
        string destination;
        cin>>destination;
        cout<<"enter time of departure: "<<endl;
        int timeOfDeparture;
        cin>>timeOfDeparture;   
        cout<<"enter time of arrival: "<<endl;
        int timeOfArrival;
        cin>>timeOfArrival;
        cout<<"enter duration of flight"<<endl;
        int duration;
        cin>>duration;
        cout<<"enter distance between destination and source: "<<endl;
        int distance;
        cin>>distance;

        ofstream fout;
        fout.open("flightschedule.txt", ios::app);
        fout<<flightNo<<"%"<<source<<"%"<<destination<<"%"<<timeOfDeparture<<"%"<<timeOfArrival<<"%"<<duration<<"%"<<distance<<endl;
        fout.close();

        
    }
};//class admin ends here

class Airport{
private:
    string name;
    string location;
    int currentPlanes;
    int maxPlanes;
public:
    Airport(){
        name = "";
        location = "";
        currentPlanes = 0;
        maxPlanes=5;
    }
    Airport(string name, string location, int currentPlanes){
        this->name = name;
        this->location = location;
        this->currentPlanes = currentPlanes;
        maxPlanes=5;
    }
    string getName(){
        return name;
    }
    string getLocation(){
        return location;
    }
    int getCurrentPlanes(){
        return currentPlanes;
    }
    int getMaxPlanes(){
        return maxPlanes;
    }
    void setName(string name){
        this->name = name;
    }
    void setLocation(string location){
        this->location = location;
    }
    void setCurrentPlanes(int currentPlanes){
        this->currentPlanes = currentPlanes;
    }
    void setMaxPlanes(int maxPlanes){
        this->maxPlanes = maxPlanes;
    }
    Airport& operator=(const Airport& a){
        name = a.name;
        location = a.location;
        currentPlanes = a.currentPlanes;
        maxPlanes = a.maxPlanes;
        return *this;
    }

};//class airport ends here

class City{
protected:
    string name;
    Airport* northAirport; //composition used here
    Airport* southAirport;  //composition used here
public:
    City(){ //made default constructor to remove error
        name = "";
        northAirport = new Airport();
        southAirport = new Airport();
    }
    City(string name, Airport northAirport, Airport southAirport){
        this->name = name;
        this->northAirport = new Airport(northAirport.getName(), northAirport.getLocation(), northAirport.getCurrentPlanes());
        this->southAirport = new Airport(southAirport.getName(), southAirport.getLocation(), southAirport.getCurrentPlanes());
    }
    void displayAirports(){
        cout<<"North Airport: "<<northAirport->getName()<<endl;
        cout<<"North Airport: "<<northAirport->getLocation()<<endl;
        cout<<"North Airport: "<<northAirport->getCurrentPlanes()<<endl;

        cout<<"South Airport: "<<southAirport->getName()<<endl;
        cout<<"South Airport: "<<southAirport->getLocation()<<endl;
        cout<<"South Airport: "<<southAirport->getCurrentPlanes()<<endl;

    }
};//class city ends here

class Country{
protected:
    string countryName;
    int distance;
public:
    Country(){
        countryName = "";
        distance = 0;
    }
    Country(string countryName, int distance){
        this->countryName = countryName;
        this->distance = distance;
    }
    string getCountryName(){
        return countryName;
    }
    void setCountryName(string countryName){
        this->countryName = countryName;
    }
    int getDistance(){
        return distance;
    }
    void setDistance(int distance){
        this->distance = distance;
    }
};//class country ends here


class Flight: protected City, protected Country{
private:
string flightNumber;
string source;
string destination;
int departureTime;
int arrivalTime;
int duration;
float price;
int distanceTravel;

public:
Flight(){
    flightNumber = "";
    source = "";
    destination = "";
    departureTime = 0;
    arrivalTime = 0;
    duration = 0;
    price = 0;
    distanceTravel = 0;
}
Flight(string flightNumber, string source, string destination, int departureTime, int arrivalTime, int duration, int distanceTravel){
    this->flightNumber = flightNumber;
    this->source = source;
    this->destination = destination;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->duration = duration;
    this->price = 1.05*(duration*10000); //formual for price of local flights
    this->distanceTravel = distanceTravel;
}   
string getFlightNumber(){
    return flightNumber;
    }
string getSource(){
    return source;
}
string getDestination(){
    return destination;
    }
int getDepartureTime(){
    return departureTime;
    }
int getArrivalTime(){
    return arrivalTime;
    }
int getDuration(){
    return duration;
    }
float getPrice(){
    return price;
    }

int getDistance(){
    return distanceTravel;
    }
void setFlightNumber(string flightNumber){
    this->flightNumber = flightNumber;
    }
void setSource(string source){
    this->source = source;
    }
void setDestination(string destination){
    this->destination = destination;
    }
void setDepartureTime(int departureTime){
    this->departureTime = departureTime;
    }
void setArrivalTime(int arrivalTime){
    this->arrivalTime = arrivalTime;
    }
void setDuration(int duration){
    this->duration = duration;
    }
void setPrice(float price){
    this->price = price;
    }
void setDistance(int distanceTravel){
    this->distanceTravel = distanceTravel;
    }


Flight& operator=(const Flight& f){ 
    flightNumber = f.flightNumber;
    source = f.source;
    destination = f.destination;
    departureTime = f.departureTime;
    arrivalTime = f.arrivalTime;
    duration = f.duration;
    price = f.price;
    distanceTravel = f.distanceTravel;
    return *this;
}
};//class flight ends here


class Booking: protected Flight{
    string PassengerName;
    Flight flight;
    int seatNumber;
    int bookingID;
public:
    Booking(){
        PassengerName = "";
        seatNumber = 0;
        bookingID = 0;
    }
    Booking(string PassengerName, Flight flight, int seatNumber, int bookingID){
        this->PassengerName = PassengerName;
        this->flight = flight;
        this->seatNumber = seatNumber;
        this->bookingID = bookingID;
    }
    string getPassengerName(){
        return PassengerName;
    }
    Flight getFlight(){
        return flight;
    }
    int getSeatNumber(){
        return seatNumber;
    }
    int getBookingID(){
        return bookingID;
    }
    void setPassengerName(string PassengerName){
        this->PassengerName = PassengerName;
    }
    void setFlight(Flight flight){
        this->flight = flight;
    }
    void setSeatNumber(int seatNumber){
        this->seatNumber = seatNumber;
    }
    void setBookingID(int bookingID){
        this->bookingID = bookingID;
    }
    Booking& operator=(const Booking& b){
        PassengerName = b.PassengerName;
        flight = b.flight;
        seatNumber = b.seatNumber;
        bookingID = b.bookingID;
        return *this;
    }


};//class booking ends here

class Plane{
private:
    int seatingCapacityEconomy;
    int seatingCapacityBusiness;
public:
    Plane(){
        seatingCapacityEconomy = 50;
        seatingCapacityBusiness = 10;
    }
    Plane(int seatingCapacityEconomy, int seatingCapacityBusiness){
        this->seatingCapacityEconomy = seatingCapacityEconomy;
        this->seatingCapacityBusiness = seatingCapacityBusiness;
    }
    int getSeatingCapacityEconomy(){
        return seatingCapacityEconomy;
    }
    int getSeatingCapacityBusiness(){
        return seatingCapacityBusiness;
    }
    void setSeatingCapacityEconomy(int seatingCapacityEconomy){
        this->seatingCapacityEconomy = seatingCapacityEconomy;
    }
    void setSeatingCapacityBusiness(int seatingCapacityBusiness){
        this->seatingCapacityBusiness = seatingCapacityBusiness;
    }
    Plane& operator=(const Plane& p){
        seatingCapacityEconomy = p.seatingCapacityEconomy;
        seatingCapacityBusiness = p.seatingCapacityBusiness;
        return *this;
    }

};//class plane ends here


class FlightSchedule{
protected:
int totalFlights;
Flight* allFlights;
public:
friend class Admin;

    FlightSchedule(){
        allFlights = NULL;
        totalFlights = 0;
    }
    FlightSchedule(Flight* allFlights, int totalFlights){
        this->allFlights = new Flight[totalFlights];
        for(int i = 0; i < totalFlights; i++){
            this->allFlights[i] = allFlights[i];
        }
        this->totalFlights = totalFlights;
    }
    void showAllFlights(){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"----------------------All Flights--------------------------"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;

        // for(int i = 0; i < totalFlights; i++){
        //     cout << "Flight Number: " << allFlights[i].getFlightNumber() << endl;
        //     cout << "Source: " << allFlights[i].getSource() << endl;
        //     cout << "Destination: " << allFlights[i].getDestination() << endl;
        //     cout << "Departure Time: " << allFlights[i].getDepartureTime() << endl;
        //     cout << "Arrival Time: " << allFlights[i].getArrivalTime() << endl;
        //     cout << "Duration: " << allFlights[i].getDuration() <<" hours"<< endl;
        //     cout << "Price: " << allFlights[i].getPrice() <<" pkr"<< endl;
        //     cout << "Distance: " << allFlights[i].getDistance() <<" kilometres"<< endl;
        //     cout << endl;
        // }

        ifstream fin;
        fin.open("flightschedule.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string token;
            while (getline(ss, token, '%')) {
                cout << token << endl;
            }
            cout << endl;
            
        }
        
    }
    void addFlight(Flight flight) {
        Flight* newFlights = new Flight[totalFlights+1];
        for(int i=0; i<totalFlights; i++) {
            newFlights[i] = allFlights[i];
        }
        newFlights[totalFlights] = flight;
        delete[] allFlights;
        allFlights = newFlights;
        totalFlights++;
        ofstream fout;
        fout.open("flightschedule.txt", ios::app);
        fout << flight.getFlightNumber() <<"%"<< flight.getSource() <<"%"<< flight.getDestination() <<"%"<< flight.getDepartureTime() <<"%"<< flight.getArrivalTime() <<"%"<< flight.getDuration() <<"%"<< flight.getPrice() <<"%"<< flight.getDistance() << endl;
        fout.close();
    }

    ~FlightSchedule(){
        delete[] allFlights;
    }

};//class flight schedule ends here


int main(){
   //just making objects of the 5 possible cities
    {
City c("Karachi", Airport("N Jinnah International Airport", "Karachi", 5), Airport("S Jinnah International Airport", "Karachi", 5));
City c2("Lahore", Airport("N Allama Iqbal International Airport", "Lahore", 5), Airport("S Allama Iqbal International Airport", "Lahore", 5));
City c3("Islamabad", Airport("N Islamabad International Airport", "Islamabad", 5), Airport("S Islamabad International Airport", "Islamabad", 5));
City c4("Peshawar", Airport("N Bacha Khan International Airport", "Peshawar", 5), Airport("S Bacha Khan International Airport", "Peshawar", 5));
City c5("Quetta", Airport("N Quetta International Airport", "Quetta", 5), Airport("S Quetta International Airport", "Quetta", 5));}

//some sample flight schedules

FlightSchedule mySchedule;

Flight f("PK-123", "Karachi", "Lahore", 1200, 1400, 2, 1000);
Flight f2("PK-124", "Lahore", "Karachi", 1500, 1700, 2, 1000);
Flight f3("PK-125", "Karachi", "Islamabad", 1200, 1400, 2, 1000);
Flight f4("PK-126", "Islamabad", "Karachi", 1500, 1700, 2, 1000);

Admin myAdmin;

Passenger myUser;





//mySchedule.showAllFlights();


cout<<"---------------------------------------------------------"<<endl;
cout<<"Welcome to the Yummiest ever NAFS Airlines Booking System"<<endl;
cout<<"---------------------------------------------------------"<<endl;

cout<<"Would you like to login/register or view Schedule"<<endl;
cout<<"1. Login/Register"<<endl;
cout<<"2. View Schedule"<<endl;
int choice1;
cin>>choice1;
if(choice1==2){
    mySchedule.showAllFlights();
    sleep(10);
    exit(0);
}else if(choice1==1){
    cout<<"Continuing to Login/Sign Up Page"<<endl;
}else{
    cout<<"Invalid input"<<endl;
    sleep(10);
    exit(0);
}


cout<<"Are you a passenger[1] or an admin[2]? "<<endl;
int choice;
cin>>choice;
if(choice==1){
    cout<<"Do you have an account? y/n "<<endl;
    string choice2;
    cin>>choice2;
    if(choice2=="y"){
        myUser.login();
    }else if(choice2=="n"){
        myUser.Register();
    }else{
        cout<<"Invalid input"<<endl;
    }
    

    cout<<"What do you want to do? "<<endl;
    cout<<"1. Book a flight"<<endl;
    cout<<"2. Cancel a flight"<<endl;
    cout<<"3. View your bookings"<<endl;
    cout<<"4. View all flights"<<endl;
    cout<<"5. Exit"<<endl;
    int choice3;//for the above menu
    cin>>choice3;

    switch(choice3){
        case 1:{
            cout<<"here are the available flights: "<<endl;
            mySchedule.showAllFlights();
            
            myUser.makeBooking();
            break;
            }
        case 2:{
            myUser.cancelBooking();
            break;}
        case 3:{

            myUser.viewMyBookings();
            break;
        }
        case 4:{
            mySchedule.showAllFlights();
            break;}
        case 5:{
            break;}
        default:{
            cout<<"Invalid input"<<endl;}
    }

}else if(choice==2){
    cout<<"Do you have an account? y/n "<<endl;
    string choice2;
    cin>>choice2;
    if(choice2=="y"){
        myAdmin.login();
    }else if(choice2=="n"){
        myAdmin.Register();
    }else{
        cout<<"Invalid input"<<endl;
    }
    cout<<"What do you want to do? "<<endl;
    cout<<"1. Add a flight"<<endl;
    cout<<"2. Cancel a flight"<<endl;
    cout<<"3. View all flights"<<endl;
    cout<<"4. Exit"<<endl;

    int choice3;//for the above menu
    cin>>choice3;
    switch(choice3){
        case 1:
            myAdmin.addFlight();
            break;
        case 2:
            //myAdmin.cancelFlight();
            break;
        case 3:
            mySchedule.showAllFlights();
            break;
        case 4:{
            cout<<"logging out..."<<endl;
            sleep(10);
            cout<<"goodbye"<<endl;
            exit(0);
            break;
        }
        default:
            cout<<"Invalid input"<<endl;
    }
}

cout<<"working"<<endl;

    return 0;
}