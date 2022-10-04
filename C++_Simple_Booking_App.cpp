#include <iostream>;
#include <list>;
#include <string>;
#include <chrono>;
#include <time.h>;
#include <string>;
#include <stdio.h>;
#include <vector>;
#include <algorithm>;
#include <stdlib.h>;
#include <cmath>;
#include <cctype>;
#include <clocale>;
#include <bits/stdc++.h>;

//https://www.javatpoint.com/how-to-split-strings-in-cpp
//https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects

using namespace std;

struct Records
{
    int theKey;
    int dD;
    int mM;
    int yY;
    string name;
    bool checkedIn;

    Records(double k, int d, int m, int y, string  n, bool cI) : theKey(k), dD(d), mM(m), yY(y), name(n), checkedIn(cI) {}
};


// -- Start of extra functions -------------------------------------------------------------------------
struct compareKeys
{
    inline bool operator() (const Records& struct1, const Records& struct2)
    {
        return (struct1.theKey < struct2.theKey);
    }
};

string checkDate(string theDateElems[]){

    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    string dt = asctime(timeinfo);

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
                    string temp1 = to_string(i+1);

                    token1 = temp0 + temp1;
                }
                else{
                    token1 = to_string(i+1);
                }
            }
        }

        theDateElems[count] = token1;

        count = count + 1;

        dt.erase(0,pos+delim.length());
    }

    theDateElems[4] = dt;   

}

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

// -- END of extra functions -------------------------------------------------------------------------

vector<Records> displayBooking(string userOption,vector<Records>vec){
    system("cls");

    int tempDate,tempMonth,tempYear;

    cout << "Check Bookings\n";
    cout << "-------------------\n";    

    cout << "\nEnter Date in DD format: ";
    cin >> tempDate;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempDate = 9999;   
        cout << "\nInvalid Date! Try again! Insert Date in DD format!: ";              
        cin >> tempDate;
    }     

    cout << "\nEnter Month in MM format: ";
    cin >> tempMonth;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempMonth = 9999;   
        cout << "\nInvalid Month! Try again! Insert Month in MM format!: ";              
        cin >> tempMonth;
    }     

    cout << "\nEnter Year in YYYY format: ";
    cin >> tempYear;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempYear = 9999;   
        cout << "\nInvalid YEAR! Try again! Insert YEAR in YYYY format!: ";              
        cin >> tempYear;
    }     

    double curSeconds = retrieveBookSec(tempYear,tempMonth,tempDate);

    int newCurSecs = int(curSeconds);

    int vectorSize = vec.size();

    int first = 0;

    if (first > vectorSize){
        system("cls");
        cout << "\nBooking not found\n\n";        

        return vec;
    }
    else if (vectorSize == 1){
        if (vec[0].theKey == newCurSecs){
            system("cls");

            string tempBool;

            if (vec[0].checkedIn == 0){
                tempBool = "No";
            }

            else{
                tempBool = "Yes";
            };

            cout << "\nDate: " << vec[0].dD << " Month: " << vec[0].mM << " Year: " << vec[0].yY << " Name: " << vec[0].name << " Checked-In: " << vec[0].checkedIn << "\n\n";

            return vec;            

        }

        else{
            system("cls");
            cout << "\nBooking not found\n\n";   

            return vec;          
        };
    }

    else{
        int mid = vectorSize/2;
        mid = ceil(mid);

        bool elementFound = false;

        int minusOrPlus = 0;

        int tempMid = mid;

        int count = 0;

        while (vec[tempMid+1].theKey == vec[tempMid].theKey){
            tempMid = tempMid + 1;
            mid = mid + 1;
        }

        system("cls");                

        while (mid != -1 && mid != vectorSize + 1){
            
            if (minusOrPlus == 0){
                if (vec[mid].theKey >= newCurSecs){
                    minusOrPlus = 1;
                }

                else{
                    minusOrPlus = 2;
                };
            }

            else{                     

                if (minusOrPlus == 1){

                    if (vec[mid].dD == tempDate && vec[mid].mM == tempMonth && vec[mid].yY == tempYear){

                        elementFound = true;

                        cout << "\nDate: " << vec[mid].dD << " Month: " << vec[mid].mM << " Year: " << vec[mid].yY << " Name: " << vec[mid].name << " Checked-In: " << vec[mid].checkedIn << "\n";   
                
                    }

                    mid = mid - 1;
                }

                else{

                    if (vec[mid].dD == tempDate && vec[mid].mM == tempMonth && vec[mid].yY == tempYear){

                        elementFound = true;

                        cout << "\nDate: " << vec[mid].dD << " Month: " << vec[mid].mM << " Year: " << vec[mid].yY << " Name: " << vec[mid].name << " Checked-In: " << vec[mid].checkedIn << "\n";   
                
                    }

                    mid = mid + 1;
                };
            };
            
        }

        if (elementFound == true){
            cout << "\n";
            return vec;
        }
        else{
            cout << "\nBooking not found\n\n";    

            return vec;
        }    
    };

}

vector<Records> checkInBooking(string userOption,vector<Records>vec){

    system("cls");

    cout << "Check-In Musicians\n";
    cout << "-------------------\n";     

    string theDateElems[5];

    auto curDateResult = checkDate(theDateElems);

    int curYear = stoi(theDateElems[4]);
    int curMonth = stoi(theDateElems[1]);
    int curDay = stoi(theDateElems[2]);

    string tempName;

    cout << "\nEnter Name: ";
    cin >> tempName;

    for(auto& c : tempName)
    {
    c = tolower(c);
    }

    int vectorSize = vec.size();

    int first = 0;

    double curSeconds = retrieveBookSec(curYear,curMonth,curDay);

    int newCurSecs = int(curSeconds);    

    if (first > vectorSize){

        system("cls");
        cout << "\nBooking not found\n\n";

        return vec;
    }

    else if(vectorSize == 1){
        if (vec[0].theKey == newCurSecs){

            vec[0].checkedIn = true;

            system("cls");

            cout << "\nBooking found and guest checked in\n\n";

            return vec;
        }

        else{
            system("cls");

            cout << "\n Booking not found!\n\n";

            return vec;
        };
    }
    else{

        int mid = vectorSize/2;
        mid = ceil(mid);

        mid = int(mid);

        bool elementFound = false;

        int minusOrPlus = 0;

        int tempMid = mid;

        while (vec[tempMid+1].theKey == vec[tempMid].theKey){
            tempMid = tempMid + 1;
            mid = mid + 1;
        }        

        while (mid != -1 && mid != vectorSize + 1){

            if (vec[mid].dD == curDay && vec[mid].mM == curMonth && vec[mid].yY == curYear && vec[mid].name == tempName){

                vec[mid].checkedIn = true;

                system("cls");

                cout << "\nBooking found and guest checked in\n\n";

                return vec;   
             
            }

            else{

                if (minusOrPlus == 0){
                    if (vec[mid].theKey >= newCurSecs){
                        minusOrPlus = 1;
                    }

                    else{
                        minusOrPlus = 2;
                    }
                }

                else{

                    if (minusOrPlus == 1){
                        mid = mid - 1;
                    }

                    else{
                        mid = mid + 1;
                    }
                }

            };

        };

/*         while (first <= vectorSize){
            int mid = (first+vectorSize)/2;

            cout << "\nnewcursecs: " << newCurSecs << "\n";
            cout << "arraySECS: " << vec[mid].theKey << "\n"; 

            if (vec[mid].dD == curDay && vec[mid].mM == curMonth && vec[mid].yY == curYear && vec[mid].name ==
            tempName){
                vec[mid].checkedIn = true;


                system("cls");

                cout << "\nBooking found and guest checked in";

                return vec;
            }

            else if (vec[mid].theKey < newCurSecs){
                vectorSize = mid - 1;

                cout << "\n" << "-1\n";
            }

            else{
                first = mid + 1;

                cout << "\n" << "+1\n";
            };

        } */

        system("cls");
        cout << "Booking not found\n\n";

        return vec;
    };
}

vector<Records> addBooking(string userOption,vector<Records>vec){

    system("cls");

    cout << "Book Musicians\n";
    cout << "-------------------\n";  

    int tempDate;
    int tempMonth;
    int tempYear;
    string tempName;
    bool tempCheckedIn;

    cout << "\nInsert MONTH in MM format!: ";
    cin >> tempMonth;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempMonth = 13;   
        cout << "\nInvalid MONTH! Try again! Insert MONTH in MM format!: ";              
        cin >> tempMonth;
    }     

    cout << "\nInsert DATE in DD format!: ";
    cin >> tempDate;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempDate = 34;   
        cout << "\nInvalid DATE! Try again! Insert DATE in DD format!: ";              
        cin >> tempDate;
    }         

    cout << "\nInsert YEAR in YYYY format!: ";
    cin >> tempYear;

    while (cin.fail()) 
    {
        cin.clear(); cin.ignore(INT_MAX,'\n');
        tempYear = 9999;   
        cout << "\nInvalid YEAR! Try again! Insert YEAR in YYYY format!: ";              
        cin >> tempYear;
    }          

    string theDateElems[5];

    auto curDateResult = checkDate(theDateElems);

    int curYear = stoi(theDateElems[4]);
    int curMonth = stoi(theDateElems[1]);
    int curDay = stoi(theDateElems[2]);

    if (tempYear < curYear || tempYear > curYear + 1){

        system("cls");

        cout << "\nInvalid Year/Cannot book more than 2 years ahead!!\n\n";

        return vec;
    }
    else{

        double curSeconds = retrieveBookSec(curYear,curMonth,curDay);

        int newCurSecs = int(curSeconds);

        double bookingSecs = retrieveBookSec(tempYear,tempMonth,tempDate);

        int newBookingSecs = int(bookingSecs);

        if (newBookingSecs < newCurSecs){

            system("cls");

            cout << "\nInvalid Booking Date. Can only book same day or future day\n\n";

            return vec;             
        }
        else{

            int vectorSize = vec.size();

            bool canBeBooked = false;

            if (vectorSize <= 1){
                canBeBooked = true;
            }

            else {

                int mid = vectorSize/2;
                mid = ceil(mid);

                mid = int(mid);

                int elementFound = 0;

                int count = 0;

                int minusOrPlus = 0;

                int tempMid = mid;

                while (vec[tempMid+1].theKey == vec[tempMid].theKey){
                    tempMid = tempMid + 1;
                    mid = mid + 1;
                }                

                while (mid != -1 && mid != vectorSize + 1){

                    if (vec[mid].dD == tempDate && vec[mid].mM == tempMonth && vec[mid].yY == tempYear){

                        elementFound = elementFound + 1;   
                    
                    }                   

                    if (elementFound == 0){
                        if (minusOrPlus == 0){
                            if (vec[mid].theKey >= newBookingSecs){
                                minusOrPlus = 1;
                            }

                            else{
                                minusOrPlus = 2;
                            }
                        }

                        else{

                            if (minusOrPlus == 1){

                                mid = mid - 1;
                           
                            }

                            else{

                                mid = mid + 1;

                            }
                        }
                    }

                    else{
                            if (minusOrPlus == 0){
                            if (vec[mid].theKey >= newBookingSecs){

                                minusOrPlus = 1;
                            }

                            else{

                                minusOrPlus = 2;
                            };
                        }

                        else{

                            if (minusOrPlus == 1){

                                mid = mid - 1;

                                count = count + 1;

                                if (elementFound == 2 || count == 2){
                                mid = -1;
                                }                                
                            }

                            else{

                                mid = mid + 1;

                                count = count + 1;

                                if (elementFound == 2 || count == 2){
                                mid = -1;
                                }

                            };
                        };                           
                    };

                };

                if (elementFound > 1){
                    canBeBooked = false;
                }
                else{
                    canBeBooked = true;
                }                
            }

            if (canBeBooked == true){
                cout << "\nInsert Name of Musician: ";
                cin >> tempName;

                for(auto& c : tempName)
                {
                c = tolower(c);
                }

                tempCheckedIn = false;

                vec.push_back(Records(newBookingSecs, tempDate, tempMonth, tempYear, tempName, tempCheckedIn));

                sort(vec.begin(), vec.end(), compareKeys());

                system("cls");

                cout << "Added booking to database: " << tempDate << "-" << tempMonth << "-" << tempYear <<
                "-" << tempName << "\n\n"; 

                return vec;
            }

            else{
                system("cls");

                cout << "No bookable rooms!\n\n";

                return vec;
            }

        }

    };     

}

void startMenu(string userOption){
    cout << "Music Room Booking System \n";
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

    vector<Records>vec;   

    while (userOption != "0"){

        startMenu(userOption);

        cin >> userOption;
        cout << "\n";

        if (userOption == "1"){

            system("cls");

            vec = addBooking(userOption,vec);
           
        }

        else if (userOption == "2"){

            system("cls");

            vec = checkInBooking(userOption,vec);

        }

        else if (userOption == "3"){

            system("cls");

            vec = displayBooking(userOption,vec);

        }
    }

    exit(0);

}
