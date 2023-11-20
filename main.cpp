#include <iostream>
#include <fstream>
#include "Node.h"
#include "Book.h"
#include "ChildrenBook.h"
#include "ComputerBook.h"
#include "Novel.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

 
typedef Node<Book*>* BookNodePtr;
typedef Node<Person*>* PersonNodePtr;

void show_menu(char& user_input);



int main()
{
    
    
   
   
   
   
   
   char user_input = ' ';
   int user_input_as_int = 0;
    do
    {
       
        show_menu(user_input);
        user_input_as_int = static_cast<int>(user_input) - static_cast<int>('0');
       
        if (user_input_as_int < 1 || user_input_as_int > 6)
        {
            // Skip a line in terminal for readability
            cout << endl;
            // Notify
            cout << "Invalid option! Exiting program!" << endl;
            // Exit program with error code 1
            exit(1);
        }
        switch (user_input_as_int)
        {
            case 1:
                cout << "Calling fuction to search a book" << endl;
                cout << endl;
                cout << endl;
                break;
            case 2:
                cout << "Calling function to rent a book" << endl;
                cout << endl;
                cout << endl;
                break;
            case 3:
                cout << "Calling a function to return a book " << endl;
                cout << endl;
                cout << endl;
                break;
            case 4:
                cout << "Calling function to show information" << endl;
                cout << endl;
                cout << endl;
                break;
            case 5:
                cout << "Calling function to show all books" << endl;
                cout << endl;
                cout << endl;
                break;
            default:
                // Notify program is about to exit
                cout << endl;
                cout << "  Exiting....";
                cout << endl;
        }
         
    } while (user_input_as_int != 6);


    return 0;
}

void show_menu(char& user_input)
{
    cout << "-----------------------" << endl;
    cout << "          Menu         " << endl;
    cout << "-----------------------" << endl;
    cout << "1. Search a book" << endl;
    cout << "2. Rent a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Show my information" << endl;
    cout << "5. Show all books" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Select (1-6) : ";
    cin >> user_input;
}

 
