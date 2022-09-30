#include <iostream>;
#include <list>;
#include <string>;
#include <chrono>;
#include <time.h>;
#include <string>;

//https://www.javatpoint.com/how-to-split-strings-in-cpp

// # TODO

//1) Put get date into function
//2) Create compare cur date to booking date
//3) If 350 days more than cur date, deny booking

using namespace std;

class theList{
    public:
        int dD;
        int mM;
        int yY;
        string name;
        bool checkedIn;
};

void addBooking(string userOption){

    cout << "Book Musicians\n";
    cout << "-------------------\n";

    list<theList> objElem;

    string theDateElems[5];

    int tempDate;
    int tempMonth;
    int tempYear;
    string tempName;

    //cout << "\nInsert MONTH in MM format!: ";
    //cin >> tempMonth;

    //cout << "\nInsert DATE in DD format!: ";
    //cin >> tempDate;    

    //cout << "\nInsert YEAR in YYYY format!: ";
    //cin >> tempYear;

    // Retrieve current date START ------------------------------------------------------------------------
    time_t now = time(0);

    string dt = ctime(&now);

    string delim = " ";

    size_t pos = 0;
    string token1;

    int count = 0; 

    while (( pos = dt.find(delim)) != std::string::npos){

        token1 = dt.substr(0,pos);

        string theMonths[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dev"};

        for (int i = 0;i<13;i++){
            if (token1 == theMonths[i]){
                if (i<10){
                    string temp0 = "0";
                    string temp1 = to_string(i);

                    token1 = temp0 + temp1;
                }
                else{
                    token1 = to_string(i);
                }
            }
        }

        theDateElems[count] = token1;

        count = count + 1;

        dt.erase(0,pos+delim.length());
    }

    theDateElems[4] = dt;

    // index 1,2,4 = mm/dd/yyyy
    //for (int i = 0;i<5;i++){
    //    cout << theDateElems[i] << "\n";
    //}

    // Retrieve current date END ------------------------------------------------------------------------       

}

void startMenu(string userOption){
    cout << "Music Room Booking System: \n";
    cout << "1) Book room for musicians\n";
    cout << "2) Check-In Musicians\n";
    cout << "3) Display details of bookings with date prompt\n";

    cout << "\n0) To exit Booking System\n";
    cout << "-------------------------------------------\n";
    cout << "Option: ";

}

int main(){

    string userOption = "";

    while (userOption != "0"){

        startMenu(userOption);

        cin >> userOption;
        cout << "\n";

        if (userOption == "1"){
            addBooking(userOption);
        }
    }

    exit(0);

}
