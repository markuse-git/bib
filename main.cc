#include <iostream>
#include "library.h"
#include "book.h"
#include "user.h"


void print_menue(){
    std::cout << "1. Add User" << std::endl;
    std::cout << "2. Add Book" << std::endl;
    std::cout << "3. Borrow Book" << std::endl;
    std::cout << "4. Return Book" << std::endl;
    std::cout << "5. Remove User" << std::endl;
    std::cout << "6. Remove Book" << std::endl;
    std::cout << "7. Exit" << std::endl;
}


int main() {

    Library library("library.db");
    int choice;

    while(true){
        print_menue();
        std::cout << "Enter your choice" << std::endl;
        std::cin >> choice;

        if(choice == 7){
            break;
        }

        int id;
        std::string name, email, title, author, isbn;

        switch (choice)
        {
        case 1:
            std::cout << "Enter User Id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter user name: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter User email: " << std::endl;
            std::getline(std::cin, email);
            library.add_user(User(id, name, email));
            break;

        case 2:
            std::cout << "Enter Book Id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter book title: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter Book Author: " << std::endl;
            std::getline(std::cin, author);
            std::cout << "Enter Book ISBN" << std::endl;
            std::getline(std::cin, isbn);
            library.add_book(Book(id, title, author, isbn));
            break;

        case 3:
            std::cout << "Enter User Id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter Book ID: " << std::endl;
            int book_id;
            std::cin >> book_id;
            library.borrow_book(book_id, id);
            break;

        case 4:
            std::cout << "Enter User Id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter Book ID: " << std::endl;
            std::cin >> book_id;
            library.return_book(book_id, id);
            break;

        case 5:
            std::cout << "Enter User Id: " << std::endl;
            std::cin >> id;
            library.remove_user(id);
            break;

        case 6:
            std::cout << "Enter Book Id: " << std::endl;
            std::cin >> id;
            library.remove_book(id);
            break;
        
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    }

    return 0;
}
