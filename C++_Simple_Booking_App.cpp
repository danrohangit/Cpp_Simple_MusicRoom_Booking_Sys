#include <iostream>;
#include <list>;
#include <string>;
#include <chrono>;
#include <time.h>;
#include <string>;
#include <stdio.h>;

//https://www.javatpoint.com/how-to-split-strings-in-cpp

// # TODO

// Use vector to store objects
// Use booking date in seconds as "key"(not exactly key) so that vector can be sorted according to date
// Divide the seconds by 100k or 1mil or something to make the number smaller or no need if it makes no difference

using namespace std;

 class Records{
    public:
        double theKey;
        int dD;
        int mM;
        int yY;
        string name;
        bool checkedIn;
}; 

string checkDate(string theDateElems[]){

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

}

/* void addBooking(string userOption){

    cout << "Book Musicians\n";
    cout << "-------------------\n";

    list<theList> objElem;

    string theDateElems[5];

    int tempDate;
    int tempMonth;
    int tempYear;
    string tempName;
    bool tempCheckedIn;

    auto curDateResult = checkDate(theDateElems);

    int curMonth = stoi(theDateElems[1]);
    int curDay = stoi(theDateElems[2]);
    int curYear = stoi(theDateElems[4]); 

    cout << "\nInsert MONTH in MM format!: ";
    cin >> tempMonth;

    cout << "\nInsert DATE in DD format!: ";
    cin >> tempDate;    

    cout << "\nInsert YEAR in YYYY format!: ";
    cin >> tempYear;          

} */

double retrieveCurSec(){
    time_t timer;
    struct tm y2k = {0};
    double seconds;

    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 120;
    y2k.tm_mon = 0;
    y2k.tm_mday = 1;

    time(&timer);

    seconds = difftime(timer,mktime(&y2k));   

    return seconds;
}

double retrieveBookSec(int tempYear,int tempMonth, int tempDate){

    struct tm y2k = {0};
    double seconds;

    struct tm y2k1 = {0};

    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = tempYear - 1900;
    y2k.tm_mon = tempMonth;
    y2k.tm_mday = tempDate;

    y2k1.tm_hour = 0;
    y2k1.tm_min = 0;
    y2k1.tm_sec = 0;
    y2k1.tm_year = 120;
    y2k1.tm_mon = 0;
    y2k1.tm_mday = 1;    

    seconds = difftime(mktime(&y2k),mktime(&y2k1));   

    return seconds;   

}

void addBooking(string userOption){

    cout << "Book Musicians\n";
    cout << "-------------------\n";

    Records objElem;  

    int tempDate;
    int tempMonth;
    int tempYear;
    string tempName;
    bool tempCheckedIn;

    //cout << "\nInsert MONTH in MM format!: ";
    //cin >> tempMonth;

    //cout << "\nInsert DATE in DD format!: ";
    //cin >> tempDate;    

    //cout << "\nInsert YEAR in YYYY format!: ";
    //cin >> tempYear; 

    tempYear = 2022;
    tempMonth = 11;
    tempDate = 07;

    string theDateElems[5];

    auto curDateResult = checkDate(theDateElems);

    int curYear = stoi(theDateElems[4]);

    if (tempYear < curYear || tempYear > curYear + 1){
        cout << "\nInvalid Year/Cannot book more than 2 years ahead!!\n\n";
    }
    else{

        double curSeconds = retrieveCurSec();

        int newCurSecs = int(curSeconds);

        double bookingSecs = retrieveBookSec(tempYear,tempMonth,tempDate);

        int newBookingSecs = int(bookingSecs);

        cout << "Current secs" << newCurSecs;
        cout << "\nbooking secs\n" << newBookingSecs;

        if (newBookingSecs < newCurSecs){
            cout << "\nInvalid Booking Date. Can only book same day or future day\n\n";             
        }
        else{
            cout << "\nInsert Name of Musician: ";
            cin >> tempName;

            tempCheckedIn = false;

/*          objElem.dD = tempDate;
            objElem.mM = tempMonth;
            objElem.yY = tempYear;
            objElem.name = tempName;
            objElem.checkedIn = tempCheckedIn;

            cout << "\nTempDate: " << objElem.dD;
            cout << "\nTempMonth: " << objElem.mM;
            cout << "\nTempYear: " << objElem.yY;
            cout << "\nTempName: " << objElem.name;
            cout << "\nTempCheckedIn: " << objElem.checkedIn; */

            //
        };

    };     

}

void startMenu(string userOption){
    cout << "Music Room Booking System: \n";
    cout << "-------------------------------------------\n";
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
