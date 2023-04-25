// Justmirr

#include <iostream>
#include <fstream>
#include <conio.h>
#include <limits>
#include <string>

using namespace std;

class address{
    private:
        string first_name, last_name, house, address, landmark, city, contact_no;

    public:
        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted();
};

void address::menu() {  //Main menu
    int choice;
    char x;
    while (true) {
        system("cls");
        cout << "* USER ADDRESS BOOK *\n" << endl;
        cout << "1. Add a new contact" << endl;
        cout << "2. Display all contacts" << endl;
        cout << "3. Edit a contact" << endl;
        cout << "4. Search address book" << endl;
        cout << "5. Delete a contact" << endl;
        cout << "6. Exit" << endl;

        cout << "\nChoose an option: 1/2/3/4/5/6: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    insert();
                    cout << "Add another contact (Y/N): ";
                    cin >> x;
                } while (x == 'y' || x == 'Y');
                cout << "Press any key to continue!";
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleted();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice, please try again!\n";
                break;
        }
        getch();
    }
}

void address::insert() { // Adding contact details
    system("cls");
    fstream file;

    cout << "\n* Add Contact *" << endl;
    cout << "Enter first name: ";
    cin >> first_name;
    // Validate first name
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid first name: ";
        cin >> first_name;
    }

    cout << "Enter last name: ";
    cin >> last_name;
    // Validate last name
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid last name: ";
        cin >> last_name;
    }

    cout << "Enter house no.: ";
    cin >> house;
    // Validate house number
    while (cin.fail() || house.length() > 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid house number: ";
        cin >> house;
    }

    cout << "Enter address line: ";
    cin >> address;
    // Validate address
    while (cin.fail() || address.length() > 50) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid address: ";
        cin >> address;
    }

    cout << "Enter landmark: ";
    cin >> landmark;
    // Validate landmark
    while (cin.fail() || landmark.length() > 20) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid landmark: ";
        cin >> landmark;
    }

    cout << "Enter city: ";
    cin >> city;
    // Validate city
    while (cin.fail() || city.length() > 20) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid city: ";
        cin >> city;
    }

    cout << "Enter contact no.: ";
    cin >> contact_no;
    // Validate contact number
    while (cin.fail() || contact_no.length() != 10) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid 10-digit contact number: ";
        cin >> contact_no;
    }

    file.open("addressBook.txt", ios::app | ios::out);
    file << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
    file.close();
}


void address::display(){ //Displaying all contacts
    system("cls");
    fstream file;
    int total = 0;
    cout << "* Address Book *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file) {
        cout << "Book is empty!\n";
    } else {
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()) {
            cout << "\nContact entry no.: " << ++total << endl;
            cout << "\nFirst name: " << first_name << endl;
            cout << "Last name: " << last_name << endl;
            cout << "House no.: " << house << endl;
            cout << "Address line: " << address << endl;
            cout << "Landmark: " << landmark << endl;
            cout << "City: " << city << endl;
            cout << "Contact no.: " << contact_no << endl;
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (total == 0) {
            cout << "Address Book Empty\nPress any key to continue!";
        }
    }
    file.close();
}

void address::search() { //Searching contacts using name or number
    system("cls");
    fstream file;
    int choice, total = 0;
    string search_name, search_contact;
    cout << "* Search Contact *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file) {
        cout << "Book is empty!\n";
    }
    else {
        cout << "1. Search by Name\n2. Search by Contact Number\nEnter your choice: ";
        cin >> choice;  
        if (choice == 1) {
            cout << "Enter the name of the person you want to search: ";
            cin >> search_name;
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
            while (!file.eof()) {
                if (search_name == first_name || search_name == last_name) {
                    cout << "\nContact entry no.: " << ++total << endl;
                    cout << "\nFirst name: " << first_name << endl;
                    cout << "Last name: " << last_name << endl;
                    cout << "House no.: " << house << endl;
                    cout << "Address line: " << address << endl;
                    cout << "Landmark: " << landmark << endl;
                    cout << "City: " << city << endl;
                    cout << "Contact no.: " << contact_no << endl;
                }
                file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
            }
            if (total == 0)
                cout << "No contact found.\n";
        }
        else if (choice == 2) {
            int found = 0;
            cout << "\nEnter a contact number: ";
            cin >> search_contact;
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
            while (!file.eof()) {
                if (search_contact == contact_no) {
                    cout << "First name: " << first_name << endl;
                    cout << "Last name: " << last_name << endl;
                    cout << "House no.: " << house << endl;
                    cout << "Address line: " << address << endl;
                    cout << "Landmark: " << landmark << endl;
                    cout << "City: " << city << endl;
                    cout << "Contact no.: " << contact_no << endl;
                    found++;
                }
                file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
            }
            if (found == 0)
                cout << "\nContact not found!\n";
        }
        else {
            cout << "\nInvalid choice!";
        }
        file.close();
    }
}

void address::modify(){  //Modifying contact details
    system("cls");
    fstream file, file1;
    string contact;
    int found = 0;
    cout << "* Edit Contact *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file) {
        cout << "Book is empty!";
        return; // Exit the function if the file is empty
    } else {
        cout << "\nEnter a contact number: ";
        cin >> contact;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
            cout << "Invalid input! Please enter a valid contact number." << endl;
            return; // exit the function if input is invalid
        }
        file1.open("temp.txt", ios::out); // Open the temporary file for writing
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()) { // Use eof() instead of >> to avoid skipping the last line
            if (contact != contact_no) {
                file1 << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
            } else {
                cout << "Enter new first name: ";
                cin >> first_name;
                cout << "Enter new last name: ";
                cin >> last_name;
                cout << "Enter house no.: ";
                cin >> house;
                cout << "Enter new address line: ";
                cin >> address;
                cout << "Enter new landmark: ";
                cin >> landmark;
                cout << "Enter new city: ";
                cin >> city;
                cout << "Enter new contact: ";
                cin >> contact_no;
                if (cin.fail()) {
                    cin.clear(); // clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
                    cout << "Invalid input! Please enter a valid contact number." << endl;
                    return; // exit the function if input is invalid
                }
                file1 << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
                found++;
            }
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        file.close();
        file1.close();
        remove("addressBook.txt");
        rename("temp.txt", "addressBook.txt");
        if (found == 0)
            cout << "Contact not found!" << endl;
        else
            cout << "Contact updated!" << endl;
    }
}

void address::deleted()  //Deleting contact
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "* Delete Contact *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file)
    {
        cout << "Book is empty!";
        file.close();
    }
    else
    {
        cout << "Enter a contact number: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()){
            if (roll != contact_no)
                file1 << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
            else{
                found++;
                cout << "\nContact deleted successfully!\n";
            }
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (found == 0)
            cout << "\nContact not found!";
        file1.close();
        file.close();
        remove("addressBook.txt");
        rename("record.txt", "addressBook.txt");
    }
}

int main(){
    address project;
    project.menu();
    return 0;
}