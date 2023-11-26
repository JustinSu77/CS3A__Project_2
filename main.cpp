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
BookNodePtr find_book_with_given_id_and_title(BookNodePtr head, int id, string title);

// Task 2: Rent a book
void rent_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size);
PersonNodePtr person_exists(PersonNodePtr head, int id);
BookNodePtr find_book_with_title(BookNodePtr library[3], int array_size,  string title);

// Task 3: Return a book
void return_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size);
BookNodePtr find_book_with_code(BookNodePtr library[3], int array_size, int book_code);

// Task 4: Show Information
void show_info(PersonNodePtr person[2], int person_array_size, BookNodePtr library[3], int library_array_size);

// Task 5: Show all books
void show_all_books(BookNodePtr library[3], int library_array_size, string book_types[], int book_types_size);


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
    string book_types[] = { "Children", "Computer", "Novel" };
    int book_types_size = sizeof(book_types) / sizeof(string);
   
   
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
                return_book(library, library_array_size, person, person_array_size);
                cout << endl;
                break;
            case 4:
                show_info(person, person_array_size, library, library_array_size);
                cout << endl;
                break;
            case 5:
               
                show_all_books(library, library_array_size, book_types, book_types_size);
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
    int code = 0;
    string title = "";
    BookNodePtr head = NULL;
    BookNodePtr requested_book = NULL;
    try
    {
        cout << endl;
        cout << "Enter code : ";
        cin >> code;
        cin.ignore();
        cin.clear();
        cout << "Enter title : ";
        getline(cin, title);
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
            throw "Given id not valid!";
        }
        if (title.empty() || title.find_first_not_of(' ') == title.npos)
        {
            throw "Given title should not be empty!";
        }
        requested_book = find_book_with_given_id_and_title(head, code, title);
        if (requested_book == NULL)
        {
            throw "No Match";
        }

    }
    catch (const char* message)
    {
        cout << endl;
        cout << message << endl;
        return;
    }
    cout << endl;
    cout << title << "(" << code << ") exists." << endl;
    requested_book->getData()->displaySearchedInfo();
}

BookNodePtr find_book_with_given_id_and_title(BookNodePtr head, int id, string title)
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
    int id = 0;
    string title = "";
    PersonNodePtr personPtr = NULL;
    PersonNodePtr wanted_person = NULL;
    BookNodePtr book = NULL;
    int rented = 0;
    char userInput = ' ';
    try
    {
        cout << endl;
        cout << "Enter your id    : ";
        cin >> id;
        if (id < 1 || id > 300)
        {
            throw "Given id is invalid";
        }
        cin.ignore();
        cin.clear();
        cout << "Enter book title : ";
        getline(cin, title);
        if (title.empty() || title.find_first_not_of(' ') == title.npos)
        {
            throw "Given title should not be empty!";
        }
        if (id >= 1 && id <= 100)
        {
            personPtr = person[0];
        }
        else
        {
            personPtr = person[1];
        }
        wanted_person = person_exists(personPtr, id);
        if (wanted_person == NULL)
        {
            throw "Person with given id does not exist";
        }
        book = find_book_with_title(library, library_array_size, title);
        if (book == NULL)
        {
            throw "Book does is not available";
        }
        rented = wanted_person->getData()->getCount();
        if (rented == wanted_person->getData()->getMaxBooksToRent())
        {
            throw rented;
        }
        wanted_person->getData()->displayRentInfo();
        cout << "Do want to rent '" << title << "' (y/n)? ";
        cin >> userInput;
        if (userInput == 'Y' || userInput == 'y')
        {
            int available = 0;
            try
            {
                available = book->getData()->getAvailable();
                if (available == 0)
                {
                    throw book->getData()->getTitle();
                }
            }
            catch (const char* message)
            {
                cout << "All copies of " << message << " have been rented out." << endl;
                return;
            }
            int book_code = book->getData()->getCode();
            wanted_person->getData()->rentBook(book_code);
            book->getData()->markRented();
            cout << "**** Rent succeed. Check your info!" << endl;
        }
    }
    catch (const char* message)
    {
        cout << message << endl;
        return;
    }
    catch (int exception)
    {
        cout << "You have reached your maximum books to be rented of  " << exception << endl;
        return;
    }
}

PersonNodePtr person_exists(PersonNodePtr head, int id)
{
    PersonNodePtr traverse = head;
    while (traverse != NULL) 
    {
        if (traverse->getData()->getId() == id)
        {
            return traverse;
        }
        traverse = traverse->getLink();
    }
    return NULL;
}

BookNodePtr find_book_with_title(BookNodePtr library[3], int array_size, string title)
{
    for (int i = 0; i < array_size; i++)
    {
        BookNodePtr traverse = library[i];
        while (traverse != NULL)
        {
            if (traverse->getData()->getTitle() == title)
            {
                return traverse;
            }
            traverse = traverse->getLink();
        }
    }
    return NULL;
}

void return_book(BookNodePtr library[3], int library_array_size, PersonNodePtr person[2], int person_array_size)
{
    cout << endl;
    int id = 0;
    cout << "Enter your id    : ";
    try
    {
        cin >> id;
        if (id < 1 || id > 300)
        {
            throw "Given id is invalid";
        }

    }
    catch (const char* message)
    {
        cout << message << endl;
        return;
    }
    int book_code = 0;
    cout << "Enter the book code to return : ";
    cin >> book_code;

    BookNodePtr book = nullptr;
    try
    {
        book = find_book_with_code(library, library_array_size, book_code);

    }
    catch (int exception)
    {
        cout << "Book with id " << exception << " does not exist" << endl;
        return;
    }

    PersonNodePtr personPtr = nullptr;
    if (id >= 1 && id <= 100)
    {
        personPtr = person[0];
    }
    else
    {
        personPtr = person[1];
    }
    PersonNodePtr wanted_person = nullptr;
    try
    {
        wanted_person = person_exists(personPtr, id);
        if (wanted_person == NULL)
        {
            throw "Person with given id does not exist";
        }

    }
    catch (const char* message)
    {
        cout << message << endl;
        return;
    }
    try
    {
        bool book_rented = wanted_person->getData()->hasRentedBookWithGivenCode(book_code);
        if (!book_rented)
        {
            throw book_code;
        }
    }
    catch (int exception)
    {
        cout << "User " << id << "did not rent book with id " << exception  << endl;
        return;
    }
    cout << endl;
    cout << endl;
    char userInput = ' ';
    cout << "Do you want to return `" << book->getData()->getTitle() << "` (y/n) ?";
    cin >> userInput;
    if (userInput == 'Y' || userInput == 'y')
    {
        wanted_person->getData()->returnBook(book_code);
        book->getData()->markReturned();
        cout << "**** Return Succeed. Check your info!" << endl;
    }

}

BookNodePtr find_book_with_code(BookNodePtr library[3], int array_size, int book_code)
{
    BookNodePtr traverse = nullptr;
    if (book_code >= 1001 && book_code <= 2000)
    {
        traverse = library[0];
    }
    else if (book_code >= 2001 && book_code <= 3000)
    {
        traverse = library[1];
    }
    else if(book_code >= 3001 && book_code <= 4000)
    {
        traverse = library[2];
    }
    else
    {
        throw book_code;
    }
    while (traverse != NULL)
    {
        if (traverse->getData()->getCode() == book_code)
        {
            return traverse;
        }
        traverse = traverse->getLink();
    }
    return NULL;
}

void show_info(PersonNodePtr person[2], int person_array_size, BookNodePtr library[3], int library_array_size)
{
    int id = 0;
    cout << "Enter your id   : ";
    cin >> id;
  
    cin.ignore();
    cin.clear();
    string name = "";
    cout << "Enter your name : ";
    try
    {
        getline(cin, name);
        if (name.empty() || name.find_first_not_of(' ') == name.npos)
        {
            throw "Given title should not be empty!";
        }
    }
    catch (const char* message)
    {
        cout << message << endl;
        return;
    }
    PersonNodePtr head = nullptr;
    if (id >= 1 || id <= 100)
    {
        head = person[0];
    }
    else
    {
        head = person[1];
    }
    PersonNodePtr wanted_person = nullptr;
    try
    {
        wanted_person = person_exists(head, id);
        if (wanted_person == NULL)
        {
            throw id;
        }
    }
    catch (int exception)
    {
        cout << endl;
        cout << "Person with id of " << exception  << " does not exist" << endl;
        return;
    }
    int maxBooksToRent = wanted_person->getData()->getMaxBooksToRent();
    for (int i = 0; i < maxBooksToRent; i++)
    {
        int book_code = wanted_person->getData()->getCodeAtIndex(i);
        BookNodePtr book = nullptr;
        if (book_code != -1)
        {
            try
            {
                 book = find_book_with_code(library, library_array_size, book_code);
                 if (book == NULL)
                 {
                     throw book_code;
                 }
            }
            catch (int exception)
            {
                cout << "Book with id of " << exception << " does not exist" << endl;
                return;
            }
            cout << endl;
            cout << "You rented " << wanted_person->getData()->getCount() << " books." << endl;
            book->getData()->displayInfo();
        }
    }
    
}

void show_all_books(BookNodePtr library[3], int array_size, string book_types[], int book_type_size)
{
    for (int i = 0; i < array_size; i++)
    {
        string activity = book_types[i];
        if (activity == "Children")
        {
            cout << "===========================================================" << endl;
            cout << "                Children Books                             " << endl;
            cout << "===========================================================" << endl;
            cout << " code              title             age  available rented" <<  endl;
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (activity == "Computer")
        {
            cout << "========================================================================" << endl;
            cout << "                       Computer Books                             " << endl;
            cout << "========================================================================" << endl;
            cout << " code                title                 publisher    available rented" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }
        else if (activity == "Novel")
        {

            cout << "=================================================================" << endl;
            cout << "                       Novel Books                             " << endl;
            cout << "=================================================================" << endl;
            cout << " code                 title       publish date    available rented" << endl;
            cout << "-----------------------------------------------------------------" << endl;
        }
        BookNodePtr book_list_traverse = library[i];
        while (book_list_traverse != NULL)
        {
            book_list_traverse->getData()->displayAllInfo();
            book_list_traverse = book_list_traverse->getLink();
        }
        cout << endl;
    }
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
            traverse->getData()->displaySearchedInfo();
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
    if (object->getIdentification() <= head->getData()->getIdentification())
    {
        newNode->setLink(head);
        head = newNode;
        return;
    }
    
    T traverse = head;
    T prev = head;
    while (traverse != NULL && 
        traverse->getData()->getIdentification() <= object->getIdentification())
    {
        prev = traverse;
        traverse = traverse->getLink();
    }
    newNode->setLink(traverse);
    prev->setLink(newNode);
}

 

 

 
