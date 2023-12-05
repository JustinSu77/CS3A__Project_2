/**
    Name: Justin Su
    Date: 11/28/2023
    Assignment Title: Project #2
    Purpose: main.cpp for Project #2

**/
#include <fstream>
#include <string>
#include <iomanip>
#include "Node.h"
#include "Book.h"
#include "ChildrenBook.h"
#include "ComputerBook.h"
#include "Novel.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "InputException.h"
using namespace std;

// Define pointer of Node class with templated type of Book*
typedef Node<Book*>* BookNodePtr;
// Define pointer of Node class with templated type of Person*
typedef Node<Person*>* PersonNodePtr;


// Load up data into data structure
/**
    Purpose: Fill static array with linked lists of polymorphic Book objects reading from file book.txt.
    Input: - library as static array of heads of linked list of polymorphic Book objects
           - inputFile as ifstream object that has read book.txt
    Input Requirement: - Given library array should be of type BookNodePtr
                       - Given inputFile should have opened book.txt
    Result: Given library array is filled with heads of Linked Lists of polymorphic Book objects
**/
void fill_library_array(BookNodePtr library[3], ifstream& inputFile);

/**
    Purpose: Fill static array with linked lists of polymorphic Person objects reading from file person.txt
    Input: - person as a static array of heads of linked list of polymorphic person objects
           - inputFile as ifstream object that has read person.txt
    Input Requirement: - Given person array should be of type PersonNodePtr
                       - Given inputFile should have opened person.txt
    Result: Given person array is filled with heads of Linked Lists of polymorphic Person objects
**/
void fill_person_array(PersonNodePtr person[2], ifstream& inputFile);

/**
    Purpose: Create and insert node with data of given templated object 
             into Linked List of type T in ascending order of id.
    Input: - head as templated head of Linked List
           - object as templated instance of a class
    Input Requirement: - Given head should be the head of a Linked List with data type T
                       - Given object should be a instance of a class of data type S
                       - Given object should have an accessable id private member variable
    Result: Node with data of given object is inserted into Linked List with head of given head
    
**/
 template<class T, class S>
void insert_node_by_ascending_id(T& head, S object);

// Menu
/**
    Purpose: Show and prompt user a numbered selection of tasks to run for this program.
    Input: user_input as the variable to store the option the user chooses
    Input Requirement: Given user_input is of type char
    Result: - Display a list of tasks to be run for this program
            - Given user_input has char value of whatever user entered
**/
void show_menu(char& user_input);

// Task 1: Search a book 
/**
    Purpose: Function to be called when user select option to Search a Book
    Input: - library as an array of heads of Linked List of polymorphic Book objects
           - library_size as number of elements in given library
    Input Requirement: - Given library is of type BookNodePtr
                       - Given library_size is equal to number of elements in given library
                       - Given library_size is an integer
    Result: - Prompt user for book code
            - Prompt user for book title
            - If given book code is not valid throw const char* exception
            - If given title is empty or just spaces, throw const char* exception
            - If book to search for does not exist, throw "No Match"
            - Output title of book and book code to terminal
            - Output category, publisher, availability, and rented to terminal
**/
void search_book(BookNodePtr library[3], int library_size);

/**
    Purpose: - Find node with polymorphic Book object that has the given id and title.
             - Helper function for function search_book
    Input: - head as the head of a Linked List with polymorphic Book objects
           - code as the code of the book to look for
           - title as the title of the book to look for
    Input Requirement: - Given head should be the head of a Linked List 
                         of polymorphic Book objects
                       - Given code should be an integer
                       - Given title should be a string
    Result: - Return BookNodePtr node that has polymorphic Book object 
              as its data type with given code and title
            - Return NULL
**/
BookNodePtr find_book_with_given_code_and_title(BookNodePtr head, int code, string title);


// Task 2: Rent a book
/**
    Purpose: Function to call when user selects the option to Rent a Book
    Input: - library as an array of heads of Linked List of polymorphic Book objects
           - library_array_size as number of elements in given library array
           - person as an array of heads of Linked List of polymorphic Person objects
           - person_array_size as number of elements in given person array
    Input Requirement: - Given library array should be of type BookNodePtr
                       - Given library_array_size should be equal to number 
                         of elements in given library array
                       - Given person array should be of type PersonNodePtr
                       - Given person_array_size should be equal to number of elements 
                         in given person array
    Result: - Prompt user for id
            - Prompt user for book title
            - If id is invalid, throw const char* exception
            - If title is empty or just spaces throw const char* exception
            - If person to find does not exist, throw cons char* exception
            - If book to find does not exist, throw string
            - If book is not available, throw const char* message
            - Prompt user if they want to rent book with given title
            - If person already rented max number of books, throw integer
            - Output confirmation of successful renting of a book
**/
void rent_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size);

/**
    Purpose: Search if a node in Linked List of polymorphic Person object has the given id.
    Input: - head as the head of Linked List with polymorphic Person object
           - id as the id of polymorphic Person object to find
    Input Requirement: - Given head as head of Linked List of polymorphic Person objects
                       - Given id as the id of polymorphic Person object to look for
    Result: Return the PersonNodePtr with data that has given id
            Return NULL otherwise
**/
PersonNodePtr search_person_with_given_id(PersonNodePtr head, int id);

/**
    Purpose: Search if a node in Linked List of polymorphic Book object has the given title
    Input: - library as array of heads of Linked List of polymorphic Book objects
           - library_array_size as number of elements in given library array
           - title as the title of Book object to look for
    Input Requirement: - Given library should be of type BookNodePtr
                       - Given library should hold heads of Linked list of polymorphic Book objects
                       - Given library_array_size should be equal to number of elements in given library array
                       - Given library_array_size should be an integer
                       - Given title should be a string
    Result: Return the BookNodePtr with polymorphic Book object as its data that has given title as its title
            Otherwise return NULL
**/
BookNodePtr search_book_with_title(BookNodePtr library[3], int library_array_size, string title);

// Task 3: Return a book
/**
    Purpose: Function to be called when user selects the option to Return a Book
    Input: - library as array of heads of Linked list of polymorphic Book objects
           - library_array_size as the number of elements in given library array
           - person as array of heads of Linked List of polymorphic Person objects
           - person_array_size as the number of elements in given person array
    Input Requirement: - Given library array should be of type BookNodePtr
                       - Given library array should store heads of Linked List with data of polymorphic Book object
                       - Given library_array_size should be equal to the number of elements in given library array
                       - Given library_array_size should be an integer
                       - Given person array should be of type PersonNodePtr
                       - Given person array should store heads of Linked List with data of polymorphic Person object
                       - Given person_array_size should be equal to the number of elements in given person_array
                       - Given person_array_size should be an integer
    Result: - Prompt user for id
            - If given id is invalid throw const char* exception
            - Prompt user for book code
            - If book with given book code does not exist, throw string exception
            - If person with given id does not exist throw char const* exception
            - If person did not rent book with given code, throw integer exception
            - Prompt user if they want to rent book
            - If user enters Y or y remove book code from their rented book array
              and set book as returned
**/
void return_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size);

/**
    Purpose: Search given library array for node that has polymorphic 
             object with book code equal to given book_code.
    Input: - library as array of heads of Linked List with data of polymorphic Book objects
           - array_size as number of elements in given library array
           - book_code as the book code of polymorphic Book object to look for
    Input Requirement: - Given library array should be of type BookNodePtr
                       - Given library_array_size should store heads of Linked List with 
                         data of polymorphic Book objects
                       - Given book_code as the book code of polymorphic Book object to search for
    Result: Return BookNodePtr with data of polymorphic Book object that has given book_code
            Return NULL
**/
BookNodePtr search_book_with_code(BookNodePtr library[3], int library_array_size, int book_code);

/**
    Purpose: Function to call when user chooses the option of Show my information.
    Input: - person array of heads of Linked List with data of polymorphic Person objects
           - person_array_size as number of elements in given person array
           - library array of heads of Linked list with data of polymorphic Book objects
           - library_array_size as number of elements in given library array
    Input Requirement: - Given person array is of type PersonNodePtr
                       - Given person array stores the heads of Linked List of 
                         polymorphic Person object
                       - Given person_array_size is equal to the number of 
                         elements in given Person array
                       - Given person_array_size is an integer
                       - Given library is of type BookNodePtr
                       - Given library stores the heads of polymorphic Book object
                       - Given library_array_size is equal to number of elements
                       - Given library_array_size is an integer
    Result: - Prompt user for id
            - If id is not valid, throw  const char* exception
            - Prompt user for name
            - If given string is empty or only spaces, throw const char* exception
            - If person does not exist, throw integer exception
            - Output the number of books rented by person with given id to terminal
            - Output the title, code, and unique information to terminal
**/
// Task 4: Show Information
void show_person_info(PersonNodePtr person[2], int person_array_size, BookNodePtr library[3], int library_array_size);

/**
    Purpose: Function to call when user chooses the option of Show all Books.
    Input: - library as array of heads of Linked List with data of polymorphic Book objects
           - library_array_size as number of elements in given library array
           - book_types as an array of strings representing different genres of books
           - book_types_size as number of elements in given book-types array
    Input Requirement: - Given library is of type BookNodePtr
                       - Given library stores heads of Linked list of polymorphic Book objects
                       - Given library_array_size is equal to the number of elements in given library array
                       - Given book_types array is of type string
                       - Given book_types_size is equal to number of elements in given book_types
                       - Given book_types_size is an integer
    Result: Output the book code, title, unique book 
            information, available, and rented to terminal
**/
// Task 5: Show all books
void show_all_books(BookNodePtr library[3], int library_array_size, string book_types[], int book_types_size);

// Deallocate linked lists
/**
    Purpose: Deallocate the dynamic memory in data structures used in this project.
    Input: - array as a templated pointer to first element of an array
           - array_size as number of elements of given array
    Input Requirement: - Given array is points to first element of an array 
                         with templated data type T
                       - Given array_size is equal to number of elements 
                         in array pointed to by given array pointer
                       - Given array_size is an integer
**/
template <class T>
void deallocate_array(T* array, int array_size);


// Debugging
void display_library_array(BookNodePtr library[3], int library_array_size);
void display_person_array(PersonNodePtr person[2], int library_array_size);

int main()
{  
    
    // Declare ifstream object inputFile
    ifstream inputFile;
    // Declare array of Book*
    BookNodePtr library[3];
    // Declare and initialize variable for number of elements in library array
    int library_array_size = sizeof(library) / sizeof(BookNodePtr);
    // Open book.txt
    inputFile.open("book.txt");
    // If failed to open book.txt
    if (inputFile.fail())
    {
        // Output newline to terminal for readability
        cout << endl;
        // Notify
        cout << "Failed to open book.txt" << endl;
        // Exit program with error code 1
        exit(1);
    }
    // Call function to fill library with data from book.txt
    fill_library_array(library, inputFile);
    // Close inputFile
    inputFile.close();
    // Declare static array of Person*
    PersonNodePtr person[2];
    // Declare and initialize variable for number of elements in person array
    int person_array_size = sizeof(person) / sizeof(PersonNodePtr);
    // Open person.txt
    inputFile.open("person.txt");
    // If failed to open file person.txt
    if (inputFile.fail())
    {
        // Output newline to terminal for readability
        cout << endl;
        // Notify
        cout << "Failed to open person.txt" << endl;
        // Exit program with error code 1
        exit(1);
    }
    // Call function to fill person array with data in person.txt
    fill_person_array(person, inputFile);
    // Close inputFile
    inputFile.close();
    // Declare and initialize string array to store genre of books
    string book_types[] = { "Children", "Computer", "Novel" };
    // Declare and initialize variable to store number of elements in book_types array
    int book_types_size = sizeof(book_types) / sizeof(string);
   
    //display_library_array(library, library_array_size);
    //cout << endl;
    //display_person_array(person, person_array_size);
    
   // Declare and initialize variable to store user input for their choice of task to run
   char user_input = ' ';
   // Declare and initialize variable to store the given user_input as int
   int user_input_as_int = 0;
   do
   {
       // Show menu to user and store their choice into user_input variable
        show_menu(user_input);
        // Change the user_input into an integer value
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
        // Run task based on vlaue of user_input_as_int
        switch (user_input_as_int)
        {
            // If user_input_as_int is 1
            case 1:
                // Call search_book function
                search_book(library, library_array_size);
                // Output newline to terminal for readability
                cout << endl;
                // Prevent fall through
                break;
            case 2:
                // Call rent_book function
                rent_book(library, library_array_size, person, person_array_size);
                // Output newline to terminal for readability
                cout << endl;
                // Prevent fall through
                break;
            case 3:
                // Call return_book function
                return_book(library, library_array_size, person, person_array_size);
                // Output newline to terminal for readability
                cout << endl;
                // Prevent fall through
                break;
            case 4:
                // Call show_info function
                show_person_info(person, person_array_size, library, library_array_size);
                // Outout newline to terminal for readability
                cout << endl;
                // Prevent fall through
                break;
            case 5:
                // Call show_all_books function
                show_all_books(library, library_array_size, book_types, book_types_size);
                // Output newline to terminal for readability
                cout << endl;
                // Prevent fall through
                break;
            default:
                // Output newline to terminal for readability
                cout << endl;
                // Notify program is about to exit
                cout << "Exiting...." << endl;
        }
    // Keep looping while user_input_as_int is not 6
   } while (user_input_as_int != 6);
    
   // Deallocate dynamic variables in library array
   deallocate_array(library, library_array_size);
   // Deallocate dynamic variables in person array
   deallocate_array(person, person_array_size);
   
   return 0;
}

void show_menu(char& user_input)
{
    // Show user menu with 6 options
    cout << "-----------------------" << endl;
    cout << "          Menu         " << endl;
    cout << "-----------------------" << endl;
    cout << "1. Search a book" << endl;
    cout << "2. Rent a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Show my information" << endl;
    cout << "5. Show all books" << endl;
    cout << "6. Exit" << endl;
    // Output newline to terminal for readability
    cout << endl;
    // Prompt to select one of six options
    cout << "Select (1-6) : ";
    // Store user input into given user_input variables
    cin >> user_input;
}

void fill_library_array(BookNodePtr library[3], ifstream& inputFile)
{
    // Declare and initialize BookNodePtr pointer as 
    // the head of Linked List of Children Book objects
    BookNodePtr children_books_head = NULL;
    // Declare and initialize BookNodePtr pointer as 
    // the head of Linked List of Computer Book objects
    BookNodePtr computer_books_head = NULL;
    // Declare and initialize BookNodePtr pointer as
    // the head of Linked List of Novel Book objects
    BookNodePtr novels_head = NULL;
    // Declare and initialize variable to store book code from opened file
    int book_code = 0;
    // Declare and initialize variable to store title from opened file
    string title = "";
    // Declare and initialize variable to store age from opened file
    int age = 0;
    // Declare and initialize variable to store available from opened file
    int available = 0;
    // Declare and initialize variable to store rented from opened file
    int rented = 0;
    // Declare and initialize variable to store publisher from opened file
    string publisher = "";
    // Declare and initialize variable to store published_date from opened file
    int published_date = 0;
    // Read entire file opened in inputFile object
    while (!inputFile.eof())
    {
        // Read in and store value in code
        inputFile >> book_code;
        // If code is greater than or equal to 1001 and less than or equal to 2000
        if (book_code >= 1001 && book_code <= 2000)
        {
            // Read in following data into variables title, age, available and rented
            inputFile >> title >> age >> available >> rented;
            // Declare and initialize Book pointer
            Book* children_book = nullptr;
            // Try to allocate a dynamic polymorphic ChildrenBook object
            try
            {
              // Allocate a dynamic polymorphic ChildenBook object with data read in from file
              children_book = new ChildrenBook(book_code, title, available, rented, age);
             
            }
            // If failed to allocate dynamic memory
            catch (bad_alloc)
            {
                // Notify
                cout << "Failed to allocate memory" << endl;
                // Exit program with error code 1
                exit(1);
            }
            // Insert the children_book object into Linked List of children books
            insert_node_by_ascending_id(children_books_head, children_book);
        }
        // If code read in is greater than or equal to 2001 and less than or equal to 3000
        else if (book_code >= 2001 && book_code <= 3000)
        {
            // Read in following data into title, publisher, available and rented
            inputFile >> title >> publisher >> available >> rented;
            // Declare and initialize Book pointer for computer_book
            Book* computer_book = nullptr;
            // Try to allocate a dynamic polymorphic ChildrenBook object
            try
            {
                // Allocate a dynamic polymorphic ComputerBook object with data read in from file
                computer_book = new ComputerBook(book_code, title, available, rented, publisher);
               
            }
            // If failed to allocate dynamic memory
            catch (bad_alloc)
            {
                // Notify 
                cout << "Failed to allocate memory" << endl;
                // Exit program with error code 1
                exit(1);
            }
            // Insert the computer_book object into Linked List of Computers
            insert_node_by_ascending_id(computer_books_head, computer_book);
        }
        // If code is greater than or equal to 3001 and less than or equal to 4000
        else if (book_code >= 3001 && book_code <= 4000)
        {
            // Read the following data in title, published_date, available, and rented
            inputFile >> title >> published_date >> available >> rented;
            // Declare and initialize Book pointer for computer_book
            Book* novel = nullptr;
            // Try to allocate a dynamic polymorphic Novel object
            try
            {
                // Allocate a dynamic polymorphic Novel object with data read in from file
                novel = new Novel(book_code, title, available, rented, published_date);
               
            }
            catch (bad_alloc)
            {
                // Notify 
                cout << "Failed to allocate memory" << endl;
                // Exit program with error code 1
                exit(1);
            }
            // Insert the Novel object into Linked List of Novel
            insert_node_by_ascending_id(novels_head, novel);
        }
        
    }
    // Set first element to head of Linked List of Children Books
    library[0] = children_books_head;
    // Set second element to head of Linked List of Computer Books
    library[1] = computer_books_head;
    // Set third element  to head of Linked List of Novel Books
    library[2] = novels_head;
     
}

void fill_person_array(PersonNodePtr person[2], ifstream& inputFile) 
{
    // Declare and initialize variable to store id from file
    int id = 0;
    // Declare and initialize variable to store name from file
    string name = "";
    // Declare and initialize variable to store books_rented from file
    int books_rented = 0;
    // Declare and initialize variable to store first book code from file
    int first_book_code = 0;
    // Declare and initialize variable to store second book code from file
    int second_book_code = 0;
    // Declare and initialize variable to store third book code from file
    int third_book_code = 0;
    // Declare and initialize pointer variable for 
    // head of Linked list of dynamic polymorphic Person objects of Teachers
    PersonNodePtr teacher_head = NULL;
    // Declare and initialize pointer variable for 
    // head of Linked list of dynamic polymorphic Person objects of Students
    PersonNodePtr student_head = NULL;
    // Read entire file opened by given inputFile object
    while (!inputFile.eof()) 
    {
        // Read in id
        inputFile >> id;
        // if id is greater than and equal to 1 and less than equal to 100
        if (id >= 1 && id <= 100) 
        {
            // Read in the name and books_rented following id
            inputFile >> name >> books_rented;
            // If books_rented is equal to 1
            if (books_rented == 1) 
            {
                // Read in first book code
                inputFile >> first_book_code;
                // Declare and initialize Person pointer that will create a dynamic polymorphic Person object
                Person* teacher = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // teacher pointer allocates a dynamic Teacher object with data read in
                    teacher = new Teacher(id, name, books_rented, first_book_code, -1, -1);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Teachers 
                // sorted in ascending order by id
                insert_node_by_ascending_id(teacher_head, teacher);
            }
            // If books_rented is 2
            else if (books_rented == 2) 
            {
                // Read in first book code and second book code
                inputFile >> first_book_code >> second_book_code;
                // Declare and initialize Person pointer that will create a dynamic polymorphic Person object
                Person* teacher = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // teacher pointer allocates a dynamic Teacher object with data read in
                    teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, -1);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Teachers
                // sorted in ascending order by id
                insert_node_by_ascending_id(teacher_head, teacher);
            }
            // If books_rented is equal to 3
            else if (books_rented == 3) 
            {
                // Read in first book code, second book code, and third_book_code
                inputFile >> first_book_code >> second_book_code >> third_book_code;
                // Declare and initialize Person pointer that will create a dynamic polymorphic Person object
                Person* teacher = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // teacher pointer allocates a dynamic Teacher object with data read in
                    teacher = new Teacher(id, name, books_rented, first_book_code, second_book_code, third_book_code);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Teachers
                // sorted in ascending order by id
                insert_node_by_ascending_id(teacher_head, teacher);
            }
            // Otherwise if book_rented is 0
            else 
            {
                // Declare and initialize Person pointer that will create a dynamic polymorphic Person object
                Person* teacher = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // teacher pointer allocates a dynamic Teacher object data read in
                    teacher = new Teacher(id, name, books_rented, -1, -1, -1);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Teachers
                // sorted in ascending order by id
                insert_node_by_ascending_id(teacher_head, teacher);

            }
        }
        // If given id is greater than or equal to 101 and less than or equal to 300
        else if (id >= 101 && id <= 300) 
        {
            // Read in name and books_rented data following id
            inputFile >> name >> books_rented;
            // If books_rented is equal to 1
            if (books_rented == 1) 
            {
                // Read in first book code following books_rented
                inputFile >> first_book_code;
                // Declare and initialize Person pointer that will 
                // create a dynamic polymorphic person object
                Person* student = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // student pointer allocates a dynamic Student object with data read in
                    student = new Student(id, name, books_rented, first_book_code, -1);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Students
                // sorted in ascending order by id
                insert_node_by_ascending_id(student_head, student);
            }
            // If books_rented is equal to 2
            else if (books_rented == 2) 
            {
                // Read in first book code and second book_code following books_rented
                inputFile >> first_book_code >> second_book_code;
                // Declare and initialize Person pointer that will 
                // create a dynamic polymorphic person object
                Person* student = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // student pointer allocates a dynamic Student object with data read in
                    student = new Student(id, name, books_rented, first_book_code, second_book_code);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Students
                // sorted in ascending order by id
                insert_node_by_ascending_id(student_head, student);
            }
            // If books_rented equal 0
            else 
            {
                // Declare and initialize Person pointer that will 
               // create a dynamic polymorphic person object
                Person* student = NULL;
                // Try to allocate memory for dynamic polymorphic object
                try 
                {
                    // student pointer allocates a dynamic Student object with data read in
                    student = new Student(id, name, books_rented, -1, -1);
                }
                // If failed to allocate memory 
                catch (bad_alloc) 
                {
                    // Notify
                    cout << "Failed to allocate memory" << endl;
                    // Exit program with error code 1
                    exit(1);
                }
                // Insert created node into to Linked List of Students
               // sorted in ascending order by id
                insert_node_by_ascending_id(student_head, student);
            }
        }
    }
    // Store head of Linked List of teachers into given person array
    person[0] = teacher_head;
    // Store head of LinkeD List of students into given person array
    person[1] = student_head;
}

void search_book(BookNodePtr library[3], int library_size)
{
    // Declare and initialize variable to store book code
    int book_code = 0;
    // Declare and initialize variable to store title of book
    string title = "";
    // Declare and initialize  variable to store head of 
    // Linked List in given library to traverse
    BookNodePtr book_head = NULL;
    // Declare and initialize variable to store BookNodePtr node 
    // with data of a polymorphic Book object that 
    // has the given book_code and title
    BookNodePtr requested_book = NULL;
    // Put main function logic in try so any exception can be handled
    try
    {
        // Output newline to terminal for readability
        cout << endl;
        // Prompt user for book code
        cout << "Enter code : ";
        // Save user input into book_code variable
        cin >> book_code;
        // Ignore last input in cin to allow getline to work
        cin.ignore();
        // Clear the cin stream to allow geline to work
        cin.clear();
        // Prompt user for title
        cout << "Enter title : ";
        // Save user input into title
        getline(cin, title);
        // If given code is greater than 1001 and less than or equal to 2000
        if (book_code >= 1001 && book_code <= 2000)
        {
            // Set book_head to first node of Children Book Linked List
            book_head = library[0];
        }
        // If given code is greater than 2001 and less than or equal to 3000
        else if (book_code >= 2001 && book_code <= 3000)
        {
            // Set book_head to first node of Computer Book Linked List
            book_head = library[1];
        }
        else if (book_code >= 3001 && book_code <= 4000)
        {
            // Set book_head to first node of Novel Linked List
            book_head = library[2];
        }
        // If code is invalid
        else
        {
            // Throw custom exception InputException
            throw InputException("Given book code is not valid!");
        }
        // If given title is empty or only has spaces then throw const char* message
        if (title.empty() || title.find_first_not_of(' ') == title.npos)
        {
            // throw custom exception InputException
            throw InputException("Given title should not be empty!");
        }
       
        // Set requested_book pointer to result of function to find book with given code and title
        requested_book = find_book_with_given_code_and_title(book_head, book_code, title);
        // If requested_book is NULL
        if (requested_book == NULL)
        {
            // Throw const char* exception
            throw InputException("No Match");
        }

    }
    // Catch exception if one is thrown
    catch (const InputException& exception)
    {
        // Output newline for readability
        cout << endl;
        // Output const char* message to terminal
        cout << exception.get_message() << endl;
        // Get out of function
        return;
    }
    // Output newline for readability
    cout << endl;
    // Output that the book with given title and book code exists 
    cout << title << "(" << book_code << ") exists." << endl;
    // Call function that display information about book searched
    requested_book->getData()->displaySearchedInfo();
}

BookNodePtr find_book_with_given_code_and_title(BookNodePtr head, int code, string title)
{
    // Declare and initialize BookNodePtr pointer to 
    // traverse Linked List to start at given head
    BookNodePtr traverse = head;
    // Keep traversing Linked List while traverse is not NULL
    while (traverse != NULL)
    {
        // If the code and title of current the data of current node is equal to given code and title
        if (traverse->getData()->getCode() == code && 
            traverse->getData()->getTitle() == title)
        {
            // Return the node
            return traverse;
        }
        // Go to next node
        traverse = traverse->getLink();
    }
    // If no node with data that has given code and title is found return NULL
    return NULL;
}

void rent_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size)
{
    // Declare and initialize variable to store id from user
    int id = 0;
    // Declare and initialize variable to store title from user
    string title = "";
    // Declare and initialize variable to traverse Linked List of polymorphic Person object
    PersonNodePtr person_ptr = NULL;
    // Declare and initialize variable to store PersonNodePtr node to look for
    PersonNodePtr wanted_person = NULL;
    // Declare and initialize variable to store BookNodePtr node to look for
    BookNodePtr book = NULL;
    // Declare and initialize variable to store number of books rented by person to look for
    int rented = 0;
    // Declare and initialize variable to store user
    char user_input = ' ';
    // Put main function logic in try so any exception can be handled
    try
    {
        // Output newline to terminal for readability
        cout << endl;
        // Promp user for id
        cout << "Enter your id    : ";
        // Store given id from user to variable id
        cin >> id;
        // If given id is invalid
        if (id < 1 && id > 300)
        {
            // throw const char* exception
            throw "Given id is invalid";
        }
        
        // Ignore last input in cin to allow getline to work
        cin.ignore();
        // Clear the cin stream to allow geline to work
        cin.clear();
        // Prompt user for book title
        cout << "Enter book title : ";
        // Store user input in title
        getline(cin, title);
        // If title is empty or only has spaces
        if (title.empty() || title.find_first_not_of(' ') == title.npos)
        {
            // throw const char* exception
            throw "Given title should not be empty!";
        }
        // If given id is greater than or equal to 1 and less than or equal to 100
        if (id >= 1 && id <= 100)
        {
            // Make person_ptr point to first element of 
            // given person array, a Linked List of teachers
            person_ptr = person[0];
        }
        // Otherwise if given id is 
        else if (id >= 101 && id <= 300)
        {
            person_ptr = person[1];
        }
        // otherwise
        else
        {
            // Throw const char* exception
            throw "Given id is invalid";
        }
        // Set wanted_person to result of function 
        // to find person with given id
        wanted_person = search_person_with_given_id(person_ptr, id);
        // If wanted_person is still NULL
        if (wanted_person == NULL)
        {
            // throw const char* exception
            throw "Person with given id does not exist";
        }
        // Set book to result of function to search book by given title
        book = search_book_with_title(library, library_array_size, title);
        // If book is still NULL
        if (book == NULL)
        {
            // throw  title as string exception
            throw title;
        }
        // Set rented to the number of books rented in searched person object
        rented = wanted_person->getData()->getCount();
        // If rented equal to the max number of books allowed to be rented
        if (rented == wanted_person->getData()->getMaxBooksToRent())
        {
            // throw rented as integer exception
            throw rented;
        }
        // Call function of the data of wanted_person 
        // node to display information of books they rented
        wanted_person->getData()->displayRentInfo();
        // Prompt user if they want to rent book with given title
        cout << "Do want to rent '" << title << "' (y/n)? ";
        // Store user input into variable user_input
        cin >> user_input;
        // if user_input is Y or y
        if (user_input == 'Y' || user_input == 'y')
        {
            // Declare and initialize variable to store 
            // available books to be rented
            int available = 0;
            try
            {
                // Set variable to the value of the available private member 
                // varible of the searched book node
                available = book->getData()->getAvailable();
                // if available is 0
                if (available == 0)
                {
                    // throw string exception
                    throw book->getData()->getTitle();
                }
            }
            // Catch the string exception thrown
            catch (string message)
            {
                // Notify 
                cout << "All copies of " << message << " have been rented out." << endl;
                // Get out of function
                return;
            }
            // Declare and initialize book_code as the 
            // book code of data of searched book node
            int book_code = book->getData()->getCode();
            // Call rentBook function of the data of wanted_person node
            wanted_person->getData()->rentBook(book_code);
            // Call markRented function of the data of book node
            book->getData()->markRented();
            // Notify user that rent succeeded
            cout << "**** Rent succeed. Check your info!" << endl;
        }
    }
    // Catch string exception thrown
    catch (string exception)
    {
        // Notify
        cout << exception << " does not exist" << endl;
        // Get out of function
        return;
    }
    // Catch const char* exception thrown
    catch (const char* message)
    {
        // Notify
        cout << message << endl;
        // Get out of function
        return;
    }
    // Catch integer exception thrown
    catch (int exception)
    {
        // Notify
        cout << "You have reached your maximum books to be rented of  " << exception << endl;
        // Get out of function
        return;
    }
}

PersonNodePtr search_person_with_given_id(PersonNodePtr head, int id)
{
    // Declare and initialize PersonNodePtr pointer to 
    // traverse Linked List to given head
    PersonNodePtr traverse = head;
    // Keep traversing Linked List while traverse is not NULL
    while (traverse != NULL) 
    {
        // If a node with data that has id equal to given id
        if (traverse->getData()->getId() == id)
        {
            // Return that node 
            return traverse;
        }
        // Otherwise keep traversing Linked List
        traverse = traverse->getLink();
    }
    // If no node is found, return NULL
    return NULL;
}

BookNodePtr search_book_with_title(BookNodePtr library[3], int library_array_size, string title)
{
    // Loop through given library array
    for (int i = 0; i < library_array_size; i++)
    {
        // Declare and initialize variable to traverse Linked List to point 
        // to current element of library array that is the head of a Linked List
        BookNodePtr traverse = library[i];
        // Keep traversing Linked List while traverse is not NULL
        while (traverse != NULL)
        {
            // if a node with data that has a title equal to given title
            if (traverse->getData()->getTitle() == title)
            {
                // Return that node
                return traverse;
            }
            // Otherwise keep traversing Linked List
            traverse = traverse->getLink();
        }
    }
    // If node is found, return NULL
    return NULL;
}

void return_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size)
{
    // Output newline to terminal for readability
    cout << endl;
    // Declare and initialize variable to store id from user
    int id = 0;
    // Declare and initialize variable to store book_code from user
    int book_code = 0;
    // Declare and initialize pointer to store node with book object as data
    BookNodePtr book = nullptr;
    // Declare and initialize pointer to store node to traverse Linked List of polymorphic objects
    PersonNodePtr person_ptr = nullptr;
    // Declare and initialize pointer to store node with 
    PersonNodePtr wanted_person = nullptr;
    // Put main function logic in try so any exception can be handled
    try 
    {
        // Prompt user for id
        cout << "Enter your id    : ";
        // Store user input in id
        cin >> id;
        // If given id is not valid 
        if (id < 1 || id > 300)
        {
            // throw const char* exception
            throw "Given id is invalid";
        }
        // Prompt user for book code
        cout << "Enter the book code to return : ";
        // Store user input into book_code
        cin >> book_code;
        // Set book pointer to result of calling function to find 
        // node with data that has book object with given book_code
        book = search_book_with_code(library, library_array_size, book_code);
        // If book pointer is still NULL
        if (book == NULL)
        {
           // throw string exception
         throw string("Book with code " + to_string(book_code) + " does not exist");
        }
        // If given id is greater than 1 and less than equal to 100
        if (id >= 1 && id <= 100)
        {
            // Set person_ptr to first element of person array
            person_ptr = person[0];
        }
        else
        {
            // Set person_ptr to second element of person array
            person_ptr = person[1];
        }
        // Set wanted _person to the result of function that 
        // returns a node that has polymorphic person object with id equal to given id
        wanted_person = search_person_with_given_id(person_ptr, id);
        // If wanted_person is still NULL
        if (wanted_person == NULL)
        {
            // throw const char* exception
            throw "Person with given id does not exist";
        }
        // Declare and initialize variable to store 
        // if a person has rented a book with given book_code
        bool book_rented = wanted_person->getData()->hasRentedBookWithGivenCode(book_code);
        // If book_rented is false
        if (!book_rented)
        {
            // throw integer exception
            throw book_code;
        }
        // Output newline to terminal for readability
        cout << endl;
        // Output newline to terminal for readability
        cout << endl;
        // Declare and initialize variable to store char input
        char user_input = ' ';
        // Prompt user if they want to return book
        cout << "Do you want to return `" << book->getData()->getTitle() << "` (y/n) ?";
        // Save user input into user_input variablke
        cin >> user_input;
        // if user_input is Y or y
        if (user_input == 'Y' || user_input == 'y')
        {
            // Call function of object in wanted_person node to return book
            wanted_person->getData()->returnBook(book_code);
            // Set Book object in book node as returned
            book->getData()->markReturned();
            // Notify user book return is succeeded
            cout << "**** Return Succeed. Check your info!" << endl;
        }
    }
    // Catch integer exception
    catch (int exception)
    {
        // Notify
        cout << "User " << id << "did not rent book with code " << exception << endl;
        // Get out of this function
        return;
    }
    catch (string message)
    {
        // Notify
        cout << message << endl;
        // Get out of this function
        return;
    }
    catch (const char* message)
    {
        // Notify
        cout << message << endl;
        // Get out of this function
        return;
    }
}

BookNodePtr search_book_with_code(BookNodePtr library[3], int library_array_size, int book_code)
{
    // Declare and initialize BookNodePtr pointer 
    // to traverse Linked List of povlymorphic Book objects
    BookNodePtr traverse = nullptr;
    // If given book-code is greater than or equal 
    // to 1001 and less than or equal to 2000
    if (book_code >= 1001 && book_code <= 2000)
    {
        // Set traverse to first element of given 
        // library array to traverse Linked List of Children Books
        traverse = library[0];
    }
    // If given book-code is greater than or equal 
    // to 2001 and less than or equal to 3000
    else if (book_code >= 2001 && book_code <= 3000)
    {
        // Set traverse to second element of given 
        // library array to traverse Linked List of Computer Books
        traverse = library[1];
    }
    // If given book-code is greater than or equal 
   // to 3001 and less than or equal to 4000
    else if(book_code >= 3001 && book_code <= 4000)
    {
        // Set traverse to second element of given 
       // library array to traverse Linked List of Novel
        traverse = library[2];
    }
    // Traverse Linked List until NULL
    while (traverse != NULL)
    {
        // If current node has polymorphic Book 
        // object with book code equal to given book_code
        if (traverse->getData()->getCode() == book_code)
        {
            // Return traverse node
            return traverse;
        }
        // Keep traversing Linked List
        traverse = traverse->getLink();
    }
    // If no node is found, return NULL
    return NULL;
}

void show_person_info(PersonNodePtr person[2], int person_array_size, BookNodePtr library[3], int library_array_size)
{
    // Declare and initialize variable to store id from user
    int id = 0;
    // Declare and initialize variable to store name from user
    string name = "";
    // Declare and initialize pointer variable to traverse linked list of person objects
    PersonNodePtr person_ptr = NULL;
    // Declare and initialize pointer to store node of person to look for
    PersonNodePtr wanted_person = NULL;
    // Put main function logic in try so any exception can be handled
    try
    {
        // Prompt user for id
        cout << "Enter your id   : ";
        // Store user input into id
        cin >> id;
        // If id is invalid
        if (id < 1 || id > 300)
        {
            // throw const char* exception
            throw "Given id is invalid";
        }
        // Ignore last input in cin to allow getline to work
        cin.ignore();
        // Clear the cin stream to allow geline to work
        cin.clear();
        // Prompt user for name 
        cout << "Enter your name : ";
        // Store user input into name
        getline(cin, name);
        // if name is empty or only has spaces
        if (name.empty() || name.find_first_not_of(' ') == name.npos)
        {
            // throw const char* message
            throw "Given name should not be empty!";
        }
        // If id is greater than or equal to 1 and less than equal to 100
        if (id >= 1 && id <= 100)
        {
            // Set person_ptr to linked list in first element of array
            person_ptr = person[0];
        }
        // Otherwise
        else
        {
            // Set person_ptr to linked list in second element of array
            person_ptr = person[1];
        }
        // Set wanted_person to the result of function that searches a 
        // Linked list of person objects for one that has id equal to given id
        wanted_person = search_person_with_given_id(person_ptr, id);
        // If wanted_person is still NULL
        if (wanted_person == NULL)
        {
            // throw integer exception
            throw id;
        }
        // Declare and initialize  variable to store the 
        // max number of books the searched person can have
        int books_rented = wanted_person->getData()->getCount();
        // Output newline to terminal
        cout << endl;
        // Output how many books searched person has rented 
        cout << "You rented " << books_rented << " books." << endl;
        // Loop through all the books rented
        for (int i = 0; i < books_rented; i++)
        {
            // Declare and initialize variable to store the book code of rented books
            int book_code = wanted_person->getData()->getCodeAtIndex(i);
            // Declare and initialize BookNodePtr to store the 
            // node with polymorphic Book object that has book code equal to book_code
            BookNodePtr book = search_book_with_code(library, library_array_size, book_code);
            // Call member function to display unique information of polymorphic Book objects
            book->getData()->displayInfoForPerson();
         }
    }
    // if integer exception is caught
    catch (int exception)
    {
        // Output newline to terminal
        cout << endl;
        // Notify
        cout << "Person with id of " << exception << " does not exist" << endl;
       
        

    }
    // if const char* exception is caught
    catch (const char* message)
    {
        // Output newline to terminal
        cout << endl;
        // Notify
        cout << message << endl;
    }
}

void show_all_books(BookNodePtr library[3], int library_array_size, string book_types[], int book_type_size)
{
    // Loop through given arrays library and book_types
    for (int i = 0; i < library_array_size; i++)
    {
        // Store current element of book_types
        string activity = book_types[i];
        // If activity equal to Children
        if (activity == "Children")
        {
            // Output the header for information of Children books
            cout << "===========================================================" << endl;
            cout << "                Children Books                             " << endl;
            cout << "===========================================================" << endl;
            cout << " code              title             age  available rented" <<  endl;
            cout << "-----------------------------------------------------------" << endl;
        }
        // If activity equal to Computer
        else if (activity == "Computer")
        {
            // Output the header for information of Computer books
            cout << "========================================================================" << endl;
            cout << "                       Computer Books                             " << endl;
            cout << "========================================================================" << endl;
            cout << " code                title                 publisher    available rented" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }
        // If activity equal to Novel
        else if (activity == "Novel")
        {
            // Output the header for information of Novel books
            cout << "=================================================================" << endl;
            cout << "                       Novel Books                             " << endl;
            cout << "=================================================================" << endl;
            cout << " code                 title       publish date    available rented" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        // Declare and initialize BookNodePtr to point to head of 
        // Linked List of polymorphic Book objects in current element of library array
        BookNodePtr book_list_traverse = library[i];
        // Traverse the nodes of Linked List to end
        while (book_list_traverse != NULL)
        {
            // Call function in each polymorphic Book 
            // object in current node to display unique information
            book_list_traverse->getData()->displayAllInfo();
            // Go to next node
            book_list_traverse = book_list_traverse->getLink();
        }
        // Output newline for readability
        cout << endl;
    }
}

void display_library_array(BookNodePtr library[3], int library_array_size)
{
    
    for (int i = 0; i < library_array_size; i++)
    {
        
        BookNodePtr traverse = library[i];
        
        while (traverse != NULL)
        {
            traverse->getData()->displayAllInfo();
            traverse = traverse->getLink();
        }
        cout << endl;
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



template<typename T, typename S>
void insert_node_by_ascending_id(T& head, S object)
{
    // Create templated node with templatd object as its data
    T newNode = new Node<S>(object, NULL);
    // If the Linked List is empty
   if (head == NULL)
    {
       // Make new node the head
        head = newNode;
        // Get out of function
        return;
    }
   // If the id of given object is less than or equal to the id of the object stored in head node
    if (object->getIdentification() <= head->getData()->getIdentification())
    {
        // Insert new node into start of Linked List
        // Set next node of new node to be the head
        newNode->setLink(head);
        // Make the new node the head
        head = newNode;
        // Get out of function
        return;
    }
    // Declare and initialize templated pointer 
    // that will traverse existing Linked List
    T traverse = head;
    // Declare and initialize templated pointer that 
    // will point to node before current traversed node
    T prev = head;
    // Keep traversing Linked list until end and as long as the id 
    // of the object in current node is less than or equal to id of given object
    while (traverse != NULL && 
        traverse->getData()->getIdentification() <= object->getIdentification())
    {
        // Set prev pointer to last traversed node
        prev = traverse;
        // Set traverse to next node
        traverse = traverse->getLink();
    }
    // Insert new node in between prev and current node
    // Set next node of new node to current node
    newNode->setLink(traverse);
    // Set next node of prev node to new node
    prev->setLink(newNode);
}

template<class T>
void deallocate_array(T* array, int array_size)
{
    // Loop through given array
    for (int i = 0; i < array_size; i++)
    {
        // Declare and initialize templated pointer to 
        // traverse Linked List at current index
        T traverse = array[i];
        // Declare and initialize templated 
        // pointer to store node to be deleted
        T discard = NULL;
        // Traverse Linked List to end
        while (traverse != NULL)
        {
            // Store node to be deleted
            discard = traverse;
            // Go to next node
            traverse = traverse->getLink();
            // Delete dynamic polymorphic object in node
            delete discard->getData();
            // Delete node
            delete discard;
        }
        // Set current element to NULL
        array[i] = NULL;
    }
}