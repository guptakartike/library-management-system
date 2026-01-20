#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book{
    public:
    int book_id;
    string book_name;
    bool available;

    Book(int i, string n){
        book_id=i;
        book_name=n;
        available=true;
    }
};
class Member{
    public:
    int member_id;
    string member_name;
    Member(int i, string n){
        member_id=i;
        member_name=n;
    }
};
vector<Book>books;
vector<Member>members;

void addBook(int id, string title){
    
    books.push_back(Book(id,title));
    cout<<"Book added: "<<id<<" "<<title<<endl;
}

void showBook(){
    
    for(Book &b:books){
        cout<<"ID: "<<b.book_id<<endl<<"Title: "<<b.book_name<<endl<< "Available: "<<(b.available?"Yes":"No")<<endl;
    }
}

void issueBook(int bookId){
    for(Book &b:books){
        if(b.book_id==bookId&&b.available){
            b.available=false;
            cout<<"Book issued successfully\n";
            return;
        }
    }
    cout<<"Book not available";
}

void returnBook(int bookId){
    for(Book &b:books){
        if(b.book_id==bookId && b.available ==false){
            b.available = true;
            cout<<"Book returned Successfully\n";
            return;
        }
    }
    cout<<"Invalid return\n";
}

int main(){
    cout<<"\n----- Books in Library -----\n";
    int choice;
    while(true){
        cout << "\n1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:{
                int id;
                cin>>id;
                cin.ignore(); // To ignore the newline character after integer input
                string title;
                getline(cin, title);
                addBook(id, title);
                break;
            }
            case 2:{
                showBook();
                break;
            }
            case 3:{
                int bookId;
                cin>>bookId;
                issueBook(bookId);
                break;
            }
            case 4:{
                int returnId;
                cin>>returnId;
                returnBook(returnId);
                break;
            }
            case 5:{
                return 0;
            }
            default:
            cout<<"Invalid Choice";
        }
        
    }
    return 0;
}