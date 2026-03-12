#include <iostream>
#include <fstream>
#include <vector>

// Implemented classes
#include "Book.h"
#include "Member.h"
#include "Fine.h"
#include "Reservation.h"
#include "Library.h"

/*
    The purpose of this source file is to test the functionality
    of the previously implemented classes.
*/

void readLibraryData(std::string& libraryName, std::string& libraryAddress, const std::string& fileName)
{
    std::ifstream file(fileName);
    file >> libraryName >> libraryAddress;
    file.close();
}

void readBookInventory(Library& library, const std::string& fileName)
{
    std::ifstream bookFile(fileName);

    std::string isbn;
    std::string title, author, publisher, category;
    int publicationYear, pageCount;

    while (bookFile >> isbn >> title >> author >> publisher >> category >> publicationYear >> pageCount)
    {
        library.addBook(isbn, title, author, publisher, category, publicationYear, pageCount);
    }

    bookFile.close();
}

void readMemberList(Library& library, const std::string& fileName)
{
    std::ifstream memberFile(fileName);

    std::string name, address, phone, email;
    while (memberFile >> name >> address >> phone >> email)
    {
        library.addMember(name, address, phone, email);
    }

    memberFile.close();
}

int main()
{
    // LIBRARY DECLARATION AND DATA LOADING
    std::string libraryName, libraryAddress;
    readLibraryData(libraryName, libraryAddress, "libraryData.txt");
    Library library(libraryName, libraryAddress);

    std::cout << "=========================================================================\n";

    // LOAD BOOKS AND MEMBERS FROM EXTERNAL FILES
    readBookInventory(library, "bookInventory.txt");
    library.displayBookInventory();
    std::cout << '\n';

    readMemberList(library, "memberList.txt");
    library.displayMembers();
    std::cout << '\n';

    std::cout << "=========================================================================\n";

    // REMOVE A BOOK AND A MEMBER FROM THE LIBRARY
    library.removeBook("978-LUN-0002");
    library.displayBookInventory();
    std::cout << '\n';

    library.removeMember(1);
    library.displayMembers();
    std::cout << '\n';

    std::cout << "=========================================================================\n";

    // ADD AND PROCESS A RESERVATION + RETURN A BOOK
    library.addReservation(1, "978-LUN-0001", "05.04.2024");
    std::cout << '\n';

    library.displayActiveReservations();
    std::cout << '\n';

    library.processReservation(1, "06.04.2024");
    std::cout << '\n';

    library.returnBook(1, "978-LUN-0001");
    std::cout << '\n';

    std::cout << "=========================================================================\n";

    // ADD AND PAY A FINE
    library.addFine(1, "978-LUN-0001", "Damaged book", 100);
    std::cout << '\n';

    library.displayUnpaidFines();
    std::cout << '\n';

    library.payFine(1);
    std::cout << '\n';

    std::cout << "=========================================================================\n";

    // DISPLAY LIBRARY STATISTICS
    library.displayLibraryStatistics();
    std::cout << '\n';

    std::cout << "=========================================================================\n";

    return 0;
}