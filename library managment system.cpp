#include <iostream>
#include <string>
using namespace std;

class Library {
    string books[100];
    bool issued[100];
    string student[100];
    int days[100];
    int count = 0;

public:
    void addBook(string name){
        books[count] = name;
        issued[count] = false;
        student[count] = "";
        days[count] = 0;
        count++;
    }

    void showBooks(){
        cout << "\n--- Library Books ---\n";
        for(int i=0;i<count;i++){
            cout << i+1 << ". " << books[i];
            if(issued[i])
                cout << " (Issued to " << student[i] << ")";
            cout << endl;
        }
    }

    void issueBook(int id){
        if(id<1 || id>count){
            cout << "Invalid Book ID!\n";
            return;
        }

        if(issued[id-1]){
            cout << "Book already issued!\n";
            return;
        }

        cout << "Enter Student Name: ";
        cin >> student[id-1];
        cout << "Enter number of days borrowed: ";
        cin >> days[id-1];

        issued[id-1] = true;
        cout << "Book issued successfully!\n";
    }

    void returnBook(int id){
        if(id<1 || id>count){
            cout << "Invalid Book ID!\n";
            return;
        }

        if(!issued[id-1]){
            cout << "Book was not issued!\n";
            return;
        }

        int extraDays;
        cout << "Enter extra days (0 if returned on time): ";
        cin >> extraDays;

        int fine = extraDays * 5;
        if(fine > 0)
            cout << "Late fine: ?" << fine << endl;
        else
            cout << "No fine. Thank you!\n";

        issued[id-1] = false;
        student[id-1] = "";
        days[id-1] = 0;

        cout << "Book returned successfully!\n";
    }
};

int main(){
    Library lib;
    lib.addBook("C++ Programming");
    lib.addBook("Java Programming");
    lib.addBook("Data Structures");

    int ch,id;

    while(true){
        cout << "\n1. Show Books\n2. Issue Book\n3. Return Book\n4. Exit\nEnter choice: ";
        cin >> ch;

        if(ch==1) lib.showBooks();
        else if(ch==2){
            cout << "Enter Book ID: ";
            cin >> id;
            lib.issueBook(id);
        }
        else if(ch==3){
            cout << "Enter Book ID: ";
            cin >> id;
            lib.returnBook(id);
        }
        else break;
    }
}

