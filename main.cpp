#include <iostream>
#include <fstream>
#include <string>
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


// Task 1: Search a book
void search_book(BookNodePtr library[3], int array_size);
BookNodePtr book_exists(BookNodePtr head, int id, string title);

// Task 2: Rent a book
void rent_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size);


// Deallocate linked lists
void deallocate_libray_array(BookNodePtr library[3], int array_size);
void deallocate_person_array(PersonNodePtr person[2], int array_size);

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
    //display_library_array(library, library_array_size);
    inputFile.close();
    
    //cout << endl;
    //cout << endl;
    
    PersonNodePtr person[2];
    int person_array_size = sizeof(person) / sizeof(PersonNodePtr);
    inputFile.open("person.txt");
    if (inputFile.fail())
    {
        cout << "Failed to open person.txt" << endl;
        exit(1);
    }
    fill_person_array(person, inputFile);
    //display_person_array(person, person_array_size);
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
                search_book(library, library_array_size);
                cout << endl;
                break;
            case 2:
                rent_book(library, library_array_size, person, person_array_size);
                cout << endl;
                break;
            case 3:
                cout << "Calling a function to return a book " << endl;
                cout << endl;
                break;
            case 4:
                cout << "Calling function to show information" << endl;
                cout << endl;
                break;
            case 5:
                cout << "Calling function to show all books" << endl;
                cout << endl;
                break;
            default:
                // Notify program is about to exit
                cout << endl;
                cout << "Exiting....";
                cout << endl;
        }
         
    } while (user_input_as_int != 6);

    deallocate_libray_array(library, library_array_size);
    deallocate_person_array(person, person_array_size);
    
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
            Book* children_book = nullptr;
            try
            {
              children_book = new ChildrenBook(code, title, available, rented, age);
             
            }
            catch (bad_alloc)
            {
                cout << "Failed to allocate memory" << endl;
                exit(1);
            }
            insert_node_by_ascending_id(children_books_head, children_book);
        }
        else if (code >= 2001 && code <= 3000)
        {
            inputFile >> title >> publisher >> available >> rented;
            Book* computer_book = nullptr;
            try
            {
                computer_book = new ComputerBook(code, title, available, rented, publisher);
               
            }
            catch (bad_alloc)
            {
                cout << "Failed to allocate memory" << endl;
                exit(1);
            }
            insert_node_by_ascending_id(computer_books_head, computer_book);
        }
        else if (code >= 3001 && code <= 4000)
        {
            inputFile >> title >> published_date >> available >> rented;
            Book* novel = nullptr;
            try
            {
                novel = new Novel(code, title, available, rented, published_date);
               
            }
            catch (bad_alloc)
            {
                cout << "Failed to allocate memory" << endl;
                exit(1);
            }
            insert_node_by_ascending_id(novels_head, novel);
        }
        
    }
    library[0] = children_books_head;
    library[1] = computer_books_head;
    library[2] = novels_head;
     
}
 

void search_book(BookNodePtr library[3], int array_size)
{
    cout << endl;
    int code = 0;
    cout << "Enter code : ";
    cin >> code;
    string title = "";
    cin.ignore();
    cin.clear();
    cout << "Enter title : ";
    getline(cin, title);
    BookNodePtr head = NULL;
    
    if (code >= 1001 && code <= 2000)
    {
        
        head = library[0];
       
    }
    else if (code >= 2001 && code <= 3000)
    {
       
        head = library[1];
    }
    else if (code >= 3001 && code <= 4000)
    {
         
        head = library[2];
    }
    else
    {
        cout << endl;
        cout << "Given id is invalid!" << endl;
        return;
    }

    try
    {
        BookNodePtr target = book_exists(head, code, title);
        if (target == NULL)
        {
            throw "No Match";
        }
        cout << endl;
        cout << title << "(" << code << ") exists." << endl;
        target->getData()->displayInfo();
    }
    catch (const char* message)
    {
        cout << endl;
        cout << message << endl;
    }
    
}

BookNodePtr book_exists(BookNodePtr head, int id, string title)
{
    BookNodePtr traverse = head;
    while (traverse != NULL)
    {
        if (traverse->getData()->getCode() == id && 
            traverse->getData()->getTitle() == title)
        {
            return traverse;
        }
        traverse = traverse->getLink();
    }
    return NULL;
}

void rent_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size)
{
    cout << endl;
    int id = 0;
    cout << "Enter your id    : ";
    cin >> id;
    string title = "";
    cin.ignore();
    cin.clear();
    cout << "Enter book title : ";
    getline(cin, title);
    cout << "Id: " << id << endl;
    cout << "Title: " << title << endl;

}

void deallocate_libray_array(BookNodePtr library[3], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        BookNodePtr traverse = library[i];
        BookNodePtr discard = NULL;
        while (traverse != NULL)
        {
            discard = traverse;
            traverse = traverse->getLink();
            delete discard;
        }
        library[i] =  nullptr;
    }
}

void deallocate_person_array(PersonNodePtr person[2], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        PersonNodePtr traverse = person[i];
        PersonNodePtr discard = NULL;
        while (traverse != NULL)
        {
            discard = traverse;
            traverse = traverse->getLink();
            delete discard;
        }
        person[i] = nullptr;
    }
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
            // Person* teacher = nullptr;
            if (books_rented == 1)
            {
                inputFile >> first_book_code;
                Person* teacher = nullptr;
                try
                {
                    teacher = new Teacher(id, name, books_rented, first_book_code, -1, -1);
                }
                catch (bad_alloc)
                {
                    cout << "Failed to allocate memory" << endl;
                    exit(1);
                }
               
                insert_node_by_ascending_id(teacher_head, teacher);
            }
            else if (books_rented == 2)
            {
                inputFile >> first_book_code >> second_book_code;
                Person* teacher = nullptr;
                try
                {
                    teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, -1);
                }
                catch (bad_alloc)
                {
                    cout << "Failed to allocate memory" << endl;
                    exit(1);
                }
             insert_node_by_ascending_id(teacher_head, teacher);
            }
            else
            {
                inputFile >> first_book_code >> second_book_code >> third_book_code;
                Person* teacher = nullptr;
                try
                {
                    teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, third_book_code);
                }
                catch (bad_alloc)
                {
                    cout << "Failed to allocate memory" << endl;
                    exit(1);
                }
                insert_node_by_ascending_id(teacher_head, teacher);
            }
        }
        else if (id >= 101 && id <= 300)
        {
           
            inputFile >> name >> books_rented;
           
            if (books_rented == 1)
            {
                inputFile >> first_book_code;
                Person* student = nullptr;
                try
                {
                    student = new Student(id, name, books_rented, first_book_code, -1);
                }
                catch (bad_alloc)
                {
                    cout << "Failed to allocate memory" << endl;
                    exit(1);
                }
                insert_node_by_ascending_id(student_head, student);
            }
            else if (books_rented == 2)
            {
                inputFile >> first_book_code >> second_book_code;
                Person* student = nullptr;
                try
                {
                    student = new Student(id, name, books_rented, first_book_code, second_book_code);
                }
                catch (bad_alloc)
                {
                    cout << "Failed to allocate memory" << endl;
                    exit(1);
                }
                insert_node_by_ascending_id(student_head, student);
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
    while (traverse != NULL && 
        traverse->getData()->get_identification() <= object->get_identification())
    {
        prev = traverse;
        traverse = traverse->getLink();
    }
    newNode->setLink(traverse);
    prev->setLink(newNode);
}

 

 

 
