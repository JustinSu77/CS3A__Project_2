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
void fill_library(BookNodePtr library[3], ifstream& inputFile);
void insert_node_into_linked_list_by_ascending_id(BookNodePtr& head, Book* object);

int main()
{
    BookNodePtr library[3];
    ifstream inputFile;
    inputFile.open("book.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open book.txt" << endl;
        exit(1);
    }
    fill_library(library, inputFile);
    inputFile.close();
   
   
   
   
   
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

void fill_library(BookNodePtr library[3], ifstream& inputFile)
{
    BookNodePtr children_books_head = NULL;
    BookNodePtr computer_books_head = NULL;
    BookNodePtr novels_head = NULL;
    int code = 0;
    string title = "";
    int age = 0;
    int available = 0;
    int rented = 0;
    string publisher = "";
    int published_date = 0;
    while (!inputFile.eof())
    {
        inputFile >> code;
        if (code >= 1001 && code <= 2000)
        {
            inputFile >> title >> age >> available >> rented;
            Book* children_book = new ChildrenBook(code, title, available, rented, age);
            insert_node_into_linked_list_by_ascending_id(children_books_head, children_book);
        }
        else if (code >= 2001 && code <= 3000)
        {
            inputFile >> title >> publisher >> available >> rented;
            Book* computer_book = new ComputerBook(code, title, available, rented, publisher);
            insert_node_into_linked_list_by_ascending_id(computer_books_head, computer_book);
        }
        else if (code >= 3001 && code <= 4000)
        {
            inputFile >> title >> published_date >> available >> rented;
            Book* novel = new Novel(code, title ,available, rented, published_date);
            insert_node_into_linked_list_by_ascending_id(novels_head, novel);
        }
    }
    library[0] = children_books_head;
    library[1] = computer_books_head;
    library[2] = novels_head;
}

void insert_node_into_linked_list_by_ascending_id(BookNodePtr& head, Book* object)
{
    BookNodePtr newNode = new Node<Book*>(object, NULL);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (object->getCode() <= head->getData()->getCode())
    {
        newNode->setLink(head);
        head = newNode;
        return;
    }
    BookNodePtr traverse = NULL;
    BookNodePtr prev = NULL;
    while (traverse != NULL && traverse->getData()->getCode() <= object->getCode())
    {
        prev = traverse;
        traverse = traverse->getLink();
    }
    prev->setLink(newNode);
    newNode->setLink(traverse);
}

 
