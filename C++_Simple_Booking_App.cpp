#include <iostream>;

using namespace std;

void addBooking(string userOption){
    cout << "Book Musicians\n";
    cout << "-------------------\n\n";
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
