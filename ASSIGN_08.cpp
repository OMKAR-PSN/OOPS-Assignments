/*A program to deal with the day-to-day administration of bookings for a Cinema for a single day. Each 
day there are three separate performances. An early afternoon performance at 1pm, an early 
evening performance at 5pm, and the main performance at 8.30pm. The program should be able to handle 
the booking of cinema seats for any of these three performances and supply details about the remaining 
seats for a particular performance.*/ 
____________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
const int TOTAL_SEATS = 50;  // Total seats per performance 
class Show { 
private: 
string time; 
int bookedSeats[TOTAL_SEATS]; 
int seatCount; 
 
public: 
    Show(string t) { 
        time = t; 
        seatCount = 0; 
        for (int i = 0; i < TOTAL_SEATS; i++) 
            bookedSeats[i] = 0; // 0 means available 
    } 
 
    void bookSeat() { 
        if (seatCount >= TOTAL_SEATS) { 
            cout << "Sorry, all seats are booked for " << time << " show.\n"; 
            return; 
        } 
 
        int seatNo; 
        cout << "Enter seat number to book (1 to " << TOTAL_SEATS << "): "; 
        cin >> seatNo; 
 
        if (seatNo < 1 || seatNo > TOTAL_SEATS) { 
            cout << "Invalid seat number.\n"; 
            return; 
        } 
 
        if (bookedSeats[seatNo - 1] == 1) { 
            cout << "Seat already booked.\n"; 
        } else { 
            bookedSeats[seatNo - 1] = 1; 
            seatCount++; 
            cout << "Seat " << seatNo << " successfully booked for " << time << " show.\n"; 
        } 
    } 
 
    void showAvailableSeats() const { 
        cout << "\nPerformance at " << time << ":\n"; 
        cout << "Total Seats: " << TOTAL_SEATS << "\n"; 
        cout << "Booked Seats: " << seatCount << "\n"; 
        cout << "Available Seats: " << TOTAL_SEATS - seatCount << "\n"; 
    } 
}; 
int main() { 
    Show matinee("1:00 PM"), evening("5:00 PM"), night("8:30 PM"); 
    int choice, showChoice; 
 
    do { 
        cout << "\n--- Cinema Booking Menu ---\n"; 
        cout << "1. Book a Seat\n"; 
        cout << "2. Show Available Seats\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        if (choice == 1 || choice == 2) { 
            cout << "Select Show:\n"; 
            cout << "1. 1:00 PM\n2. 5:00 PM\n3. 8:30 PM\n"; 
            cout << "Enter show number: "; 
            cin >> showChoice; 
 
            Show* selectedShow = nullptr; 
 
            if (showChoice == 1) selectedShow = &matinee; 
            else if (showChoice == 2) selectedShow = &evening; 
            else if (showChoice == 3) selectedShow = &night; 
            else { 
                cout << "Invalid show selection.\n"; 
                continue; 
            } 
 
            if (choice == 1) 
                selectedShow->bookSeat(); 
            else 
                selectedShow->showAvailableSeats(); 
        } 
        else if (choice == 3) { 
            cout << "Exiting booking system.\n"; 
        } 
        else { 
            cout << "Invalid choice.\n"; 
        } 
 
    } while (choice != 3); 
 
    return 0; 
}
