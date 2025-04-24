/*A program which maintains the state of books in a small school library. Each book in the library has a 
class mark which is a number in the range 1 - 999. Two or more identical books will have a different 
class mark. A person may:   Check a book out of the library. 
                            Reserve a book which is out on loan. 
                            Inquire as to the current status of a book. 
The program should be able to handle the above day-to-day transactions. In addition, a facility 
should be included which will provide a summary about the current status of the books in the library.*/
___________________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
const int MAX_BOOKS = 100; 
class Book { 
private: 
int classMark;      
int status;         
public: 
Book() { 
classMark = 0; 
        status = 0; 
    } 
 
    void setClassMark(int cm) { 
        classMark = cm; 
        status = 0; 
    } 
 
    int getClassMark() const { 
        return classMark; 
    } 
 
    void checkOut() { 
        if (status == 0) { 
            status = 1; 
            cout << "Book " << classMark << " has been checked out.\n"; 
        } else { 
            cout << "Book " << classMark << " is not available for checkout.\n"; 
        } 
    } 
 
    void reserve() { 
        if (status == 1) { 
            status = 2; 
            cout << "Book " << classMark << " has been reserved.\n"; 
        } else if (status == 0) { 
            cout << "Book is available, no need to reserve.\n"; 
        } else { 
            cout << "Book already reserved.\n"; 
        } 
    } 
 
    void returnBook() { 
        if (status != 0) { 
            status = 0; 
            cout << "Book " << classMark << " returned to shelf.\n"; 
        } else { 
            cout << "Book is already on the shelf.\n"; 
        } 
    } 
 
    void showStatus() const { 
        cout << "Book " << classMark << " is "; 
        if (status == 0) 
            cout << "on the shelf.\n"; 
        else if (status == 1) 
            cout << "on loan.\n"; 
        else 
            cout << "reserved.\n"; 
    } 
 
    int getStatus() const { 
        return status; 
    } 
}; 
 
int findBook(Book books[], int total, int classMark) { 
    for (int i = 0; i < total; ++i) { 
        if (books[i].getClassMark() == classMark) 
            return i; 
    } 
    return -1; 
} 
 
int main() { 
    Book books[MAX_BOOKS]; 
    int totalBooks = 0; 
    int choice, classMark; 
    cout << "Enter number of books to add (max 100): "; 
    cin >> totalBooks; 
 
    for (int i = 0; i < totalBooks; ++i) { 
        cout << "Enter class mark for book " << i + 1 << " (1-999): "; 
        cin >> classMark; 
        books[i].setClassMark(classMark); 
    } 
 
    do { 
        cout << "\n--- Library Menu ---\n"; 
        cout << "1. Check Out Book\n"; 
        cout << "2. Reserve Book\n"; 
        cout << "3. Return Book\n"; 
        cout << "4. Inquire Status\n"; 
        cout << "5. Library Summary\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        if (choice >= 1 && choice <= 4) { 
            cout << "Enter class mark of book: "; 
            cin >> classMark; 
            int index = findBook(books, totalBooks, classMark); 
 
            if (index == -1) { 
                cout << "Book not found.\n"; 
                continue; 
            } 
 
            if (choice == 1) 
                books[index].checkOut(); 
            else if (choice == 2) 
                books[index].reserve(); 
            else if (choice == 3) 
                books[index].returnBook(); 
            else if (choice == 4) 
                books[index].showStatus(); 
        } 
 
        else if (choice == 5) { 
            int onLoan = 0, reserved = 0, available = 0; 
            for (int i = 0; i < totalBooks; ++i) { 
                int stat = books[i].getStatus(); 
                if (stat == 0) 
                    available++; 
                else if (stat == 1) 
                    onLoan++; 
                else if (stat == 2) 
                    reserved++; 
            } 
 
            cout << "\n--- Library Summary ---\n"; 
            cout << "Total books: " << totalBooks << endl; 
            cout << "Books on loan: " << onLoan << endl; 
            cout << "Books reserved: " << reserved << endl; 
            cout << "Books on shelves: " << available << endl; 
        } 
 
        else if (choice == 6) { 
            cout << "Exiting library system.\n"; 
        } 
 
        else { 
            cout << "Invalid choice.\n"; 
        } 
 
    } while (choice != 6); 
 
    return 0; 
}
