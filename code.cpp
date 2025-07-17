#include <iostream>
#include <string>
using namespace std;

const int books = 10; // max nums of books as the mentor said

int ids[books]; // array for saving tbhe books
string titles[books]; // array for saving the titles
string authors[books]; // array for saving the authors
bool Available[books]; // array tells if the books are avilable or not

int bookCount = 0;

bool Authentication() {                                             // Done.. No more changes // 
    cout << "== Authentication ==" << endl;                         // Designing area :)
    int id;
    cout << "Please enter your 5 nums ID: " << endl;
    cout << "---> ";  cin >> id;
    
    if (id >= 10000 && id <= 99999 && id % 1000 == 1) {
        cout << "\033[32mWelcome to the system :).\033[0m" << endl;
        return true;
    }
    else {
        cout << "\033[31mPls try again. Your ID must be 5 nums and ends with 001 :(\033[0m" << endl;
        return false;
    }
}

void displayMenu() {                                                 // Done.. No more changes // 
    cout << "=== Library Menu ===" << endl;
    cout << ".1. Add Book" << endl;
    cout << ".2. Search for a book" << endl;
    cout << ".3. Display All Books" << endl;
    cout << ".4. Borrow Book" << endl;
    cout << ".5. Remove Book" << endl;
    cout << ".6. Update Book's ID" << endl;
    cout << ".7. Return Book" << endl;
    cout << "\033[31m.8. Exit\033[0m" << endl;
    cout << "Enter your choice: ";
}

void addBook() {
    cout << "Enter book ID: ";                                       // Done.. No more changes // 
    cin >> ids[bookCount]; // 3la tool f el id array

    cout << "Enter title: ";
    cin >> titles[bookCount]; //3la tol f el title array

    cout << "Enter author: ";
    cin >> authors[bookCount]; //3la tol f el aurhors array

    Available[bookCount] = 1;
    bookCount++;
    cout << endl;
    cout << "The book is added successfully :)" << endl;
}

void displayBooks() {                              
    cout << endl;                                                                                         // Done.. No more changes // 
    cout << "\033[32mThe Avilable books are: \033[0m" << endl;
    cout << endl;
    cout << "==========================" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << ids[i] << endl << "Title: " << titles[i] << endl << "Author: " << authors[i] << endl;
        cout << "==========================" << endl;
    }
}

int findBookId(int id) {                                             // Done.. No more changes // 
    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == id) {
            cout << "Book has been found :)" << endl;
            return i; // FOUND F EL ARRAY
        }
    }
    cout << "This book cant be found :(" << endl;
    return -1; // NOT FOUND F EL ARRAY 
}

void borrowBook() {                                                    // Done.. No more changes //
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;

    int num = findBookId(id);

    if (num == -1) { // NOT FOUND F EL ARRAY
        cout << endl;
        cout << "This book ID was not found :(" << endl;
        return;
    }

    if (Available[num] == false) {
        cout << endl;
        cout << "This book is already borrowed :(" << endl;
        return;
    }

    Available[num] = false;
    cout << endl;
    cout << "You have borrowed the book successfully! :)" << endl;
}

void removeBook() {                                                                              // Done.. No more changes //
    int id;
    cout << "Enter the ID of the book to remove it from the system: " << endl;
    cin >> id;

    int num = findBookId(id);

    if (num == -1) {
        cout << endl;
        cout << "Book not found :(" << endl;
        return;
    }

    for (int i = num; i < bookCount - 1; i++) {
        ids[i] = ids[i + 1];
        titles[i] = titles[i + 1];
        authors[i] = authors[i + 1];
        Available[i] = Available[i + 1];
    }

    bookCount--;
    cout << "The book has been removed :)" << endl;
}

void returnBook() {                                                              // Done.. No more changes //
    int id;
    cout << "Enter the book ID to return it: ";
    cin >> id;

    int num = findBookId(id);

    if (num == -1) {
        cout << endl;
        cout << "Book ID cant be found :o " << endl;
        return;
    }

    if (Available[num] = true){
        cout << endl;
        cout << "Book returned successfully :)" << endl;
    }
}
void updateBookId() {                                              // Done.. No more changes // 
    int Currentid;
    cout << "Enter the current ID of the book you wanna update: " << endl;
    cin >> Currentid;

    int num = findBookId(Currentid);

    if (num == -1) {
        cout << "Book not found :(" << endl;
        return;
    }

    int newId;
    cout << "Enter the new ID for the book you choosed :) " << endl;
    cin >> newId;

    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == newId) {
            cout << "This ID is already used in use by another book :>" << endl;
            return;
        }
    }

    ids[num] = newId;
    cout << "Book ID updated successfully!" << endl;

}


int main() {
    int choice;
    int ID;

    if (Authentication()) {
        displayMenu();

        do {
            cin >> choice;

            switch (choice) {
            case 1:
                addBook(); // Done.. No more changes // 
                break;
            case 2:
                cout << "Pls enter the ID for the book you wanna find" << endl; // Done.. No more changes // 
                cin >> ID;
                findBookId(ID);
                break;
            case 3:
                displayBooks(); // Done.. No more changes // 
                break;
            case 4:
                borrowBook(); // Done.. No more changes // 
                break;
            case 5:
                removeBook(); // Done.. No more changes // 
                break;
            case 6:
                updateBookId(); // Done.. No more changes // 
                break;
            case 7:
                returnBook(); // Done.. No more changes // 
                break;
            case 8:
                cout << endl;
                cout << "\033[31mExiting..\033[0m" << endl;
                break;
            default:
                cout << "\033[31mWrong choice\033[0m" << endl; 
            }

            if (choice != 6) {
                cout << endl << "\033[34mReturning to main menu...\033[0m" << endl;
                displayMenu();
            }

        } while (choice != 8);
    }

    return 0;
}

// I added an authentication Function to read the student's ID which must be 5 nums and ends with 001
// I used colors used ansi codes to make the project look better
// Coudnt do the updateBookID all right so i used the help of google and some yt videos ( hope thats alr ) 
