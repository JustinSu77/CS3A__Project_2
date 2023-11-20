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

// Fill library
void fill_library_array(BookNodePtr library[3], ifstream& inputFile);
template<typename T, typename S>
void insert_node_by_ascending_id(T& head, S object);


// Fill person
void fill_person_array(PersonNodePtr person[2], ifstream& inputFile);


// Task: Search a book
 

// Debugging
void display_library_array(BookNodePtr library[3], int array_size);
void display_person_array(PersonNodePtr person[2], int array_size);


int main()
{
    ifstream inputFile;
   BookNodePtr library[3];
    int library_array_size = sizeof(library) / sizeof(BookNodePtr);
   
    inputFile.open("book.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open book.txt" << endl;
        exit(1);
    }
    fill_library_array(library, inputFile);
    display_library_array(library, library_array_size);
    inputFile.close();
   
    cout << endl;
    cout << endl;
    
    PersonNodePtr person[2];
    int person_array_size = sizeof(person) / sizeof(PersonNodePtr);
    inputFile.open("person.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open person.txt" << endl;
        exit(1);
    }
    fill_person_array(person, inputFile);
    display_person_array(person, person_array_size);
    inputFile.close();
   
   
   
   //char user_input = ' ';
   //int user_input_as_int = 0;
   // do
   // {
   //    
   //     show_menu(user_input);
   //     user_input_as_int = static_cast<int>(user_input) - static_cast<int>('0');
   //    
   //     if (user_input_as_int < 1 || user_input_as_int > 6)
   //     {
   //         // Skip a line in terminal for readability
   //         cout << endl;
   //         // Notify
   //         cout << "Invalid option! Exiting program!" << endl;
   //         // Exit program with error code 1
   //         exit(1);
   //     }
   //     switch (user_input_as_int)
   //     {
   //         case 1:
   //             cout << "Calling fuction to search a book" << endl;
   //             cout << endl;
   //             cout << endl;
   //             break;
   //         case 2:
   //             cout << "Calling function to rent a book" << endl;
   //             cout << endl;
   //             cout << endl;
   //             break;
   //         case 3:
   //             cout << "Calling a function to return a book " << endl;
   //             cout << endl;
   //             cout << endl;
   //             break;
   //         case 4:
   //             cout << "Calling function to show information" << endl;
   //             cout << endl;
   //             cout << endl;
   //             break;
   //         case 5:
   //             cout << "Calling function to show all books" << endl;
   //             cout << endl;
   //             cout << endl;
   //             break;
   //         default:
   //             // Notify program is about to exit
   //             cout << endl;
   //             cout << "  Exiting....";
   //             cout << endl;
   //     }
   //      
   // } while (user_input_as_int != 6);


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

void fill_library_array(BookNodePtr library[3], ifstream& inputFile)
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
            insert_node_by_ascending_id(children_books_head, children_book);
         }
        else if (code >= 2001 && code <= 3000)
        {
            inputFile >> title >> publisher >> available >> rented;
            Book* computer_book = new ComputerBook(code, title, available, rented, publisher);
            insert_node_by_ascending_id(computer_books_head, computer_book);
        }
        else if (code >= 3001 && code <= 4000)
        {
            inputFile >> title >> published_date >> available >> rented;
            Book* novel = new Novel(code, title, available, rented, published_date);
            insert_node_by_ascending_id(computer_books_head, novel);
        }
        
    }
    library[0] = children_books_head;
    library[1] = computer_books_head;
    library[2] = novels_head;
     
}
 

void display_library_array(BookNodePtr library[3], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        
        BookNodePtr traverse = library[i];
        while (traverse != NULL)
        {
            traverse->getData()->displayInfo();
            traverse = traverse->getLink();
        }
    }
}

void display_person_array(PersonNodePtr person[2], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        PersonNodePtr traverse = person[i];
        while (traverse != NULL)
        {
            traverse->getData()->displayInfo();
            traverse = traverse->getLink();
        }
    }
    cout << endl;
}

void fill_person_array(PersonNodePtr person[2], ifstream& inputFile)
{
    int id = 0;
    string name = "";
    int books_rented = 0;
    int first_book_code = 0;
    int second_book_code = 0;
    int third_book_code = 0;
    PersonNodePtr teacher_head = NULL;
    PersonNodePtr student_head = NULL;
    while (!inputFile.eof())
    {
        inputFile >> id;
        if (id >= 1 && id <= 100)
        {
            
            inputFile >> name >> books_rented;
            Person* teacher = NULL;
            if (books_rented == 1)
            {
                inputFile >> first_book_code;
                teacher = new Teacher(id, name, books_rented, first_book_code, -1, -1);
                insert_node_by_ascending_id(teacher_head, teacher);
            }
            else if (books_rented == 2)
            {
                inputFile >> first_book_code >> second_book_code;
                teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, -1);
                
            }
            else
            {
                inputFile >> first_book_code >> second_book_code >> third_book_code;
                teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, third_book_code);
                
            }
            insert_node_by_ascending_id(teacher_head, teacher);
        }
        else if (id >= 101 && id <= 300)
        {
            
            inputFile >> name >> books_rented;
            Person* student = NULL;
            if (books_rented == 1)
            {
                inputFile >> first_book_code;
                Person* student = new Student(id, name, books_rented, first_book_code, -1);
                insert_node_by_ascending_id(student_head, student);
            }
            else if (books_rented == 2)
            {
                inputFile >> first_book_code >> second_book_code;
              
                Person* student = new Student(id, name, books_rented, first_book_code, second_book_code);
                (student_head, student);
            }
           
             
        }
    }
    person[0] = teacher_head;
    person[1] = student_head;
}

template<typename T, typename S>
void insert_node_by_ascending_id(T& head, S object)
{
    T newNode = new Node<S>(object, NULL);
   if (head == NULL)
    {
        head = newNode;
        return;
    }
   
    if (object->get_identification() <= head->getData()->get_identification())
    {
        newNode->setLink(head);
        head = newNode;
        return;
    }
    
    T traverse = head;
    T prev = head;
    while (traverse != NULL && traverse->getData()->get_identification() <= object->get_identification())
    {
        prev = traverse;
        traverse = traverse->getLink();
    }
    newNode->setLink(traverse);
    prev->setLink(newNode);
}
