 /*A bookshop maintains the inventory of books that are being sold at the shop. The list includes details 
such as author, title, price, publisher and stock position. Whenever a customer wants a book, the 
salesperson inputs the title and author and the system searches the list and displays whether it is 
available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the 
book details and requests for the number of copies required. If the requested copies are available, 
the total cost of the requested copies is displayed; otherwise “Required copies not in stock” is displayed. 
Design a system using a class called books with suitable member functions and constructors. Use 
new operators in constructors to allocate the memory space required.*/
____________________________________________________________________________________________________________________________
#include <iostream> 
using namespace std; 
class Book { 
private: 
char* title; 
char* author; 
    char* publisher; 
    float price; 
    int stock; 
 
    int isEqual(const char* s1, const char* s2) const { 
        int i = 0; 
        while (s1[i] != '\0' && s2[i] != '\0') { 
            if (s1[i] != s2[i]) 
                return 0; 
            i++; 
        } 
        if (s1[i] == '\0' && s2[i] == '\0') 
            return 1; 
        else 
            return 0; 
    } 
 
public: 
     
    Book() { 
        title = new char[50]; 
        author = new char[50]; 
        publisher = new char[50]; 
        price = 0.0; 
        stock = 0; 
    } 
 
     
    ~Book() { 
        delete[] title; 
        delete[] author; 
        delete[] publisher; 
    } 
    void input() { 
        cin.ignore(); 
        cout << "Enter title: "; 
        cin.getline(title, 50); 
        cout << "Enter author: "; 
        cin.getline(author, 50); 
        cout << "Enter publisher: "; 
        cin.getline(publisher, 50); 
        cout << "Enter price: "; 
        cin >> price; 
        cout << "Enter stock: "; 
        cin >> stock; 
    } 
    void display() const { 
        cout << "\nTitle: " << title 
             << "\nAuthor: " << author 
             << "\nPublisher: " << publisher 
             << "\nPrice: " << price 
             << "\nStock: " << stock << endl; 
    } 
    int search(const char* t, const char* a) const { 
        if (isEqual(title, t) && isEqual(author, a)) 
            return 1; 
        else 
            return 0; 
    } 
    void sell() { 
        int copies; 
        cout << "Enter number of copies required: "; 
        cin >> copies; 
        if (copies <= stock) { 
            cout << "Total cost: " << copies * price << endl; 
            stock -= copies; 
        } else { 
            cout << "Required copies not in stock.\n"; 
        } 
    } 
}; 
 
int main() { 
    const int size = 3; 
    Book books[size]; 
    int choice; 
    char title[50], author[50]; 
    cout << "--- Enter Book Details ---\n"; 
    for (int i = 0; i < size; ++i) { 
        cout << "\nBook " << i + 1 << ":\n"; 
        books[i].input(); 
    } 
    do { 
        cout << "\n--- Menu ---\n"; 
        cout << "1. Search and Buy a Book\n"; 
        cout << "2. Display All Books\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: { 
                cin.ignore(); 
                cout << "Enter book title: "; 
                cin.getline(title, 50); 
                cout << "Enter author name: "; 
                cin.getline(author, 50); 
 
                int found = 0; 
                for (int i = 0; i < size; ++i) { 
                    if (books[i].search(title, author) == 1) { 
                        cout << "\nBook Found!\n"; 
                        books[i].display(); 
                        books[i].sell(); 
                        found = 1; 
                        break; 
                    } 
                } 
                if (found == 0) 
                    cout << "Book not found.\n"; 
                break; 
            } 
 
            case 2: 
                for (int i = 0; i < size; ++i) { 
                    cout << "\nBook " << i + 1 << " Details:"; 
                    books[i].display(); 
                } 
                break; 
 
            case 3: 
                cout << "Exiting program.\n"; 
                break; 
 
            default: 
                cout << "Invalid choice.\n"; 
        } 
 
    } while (choice != 3); 
 
    return 0; 
} 
