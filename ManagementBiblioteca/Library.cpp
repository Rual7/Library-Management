#include "Library.h"

// Constructor
Library::Library(const std::string& name, const std::string& address)
    : name(name), address(address)
{
}

// Book management
void Library::addBook(const std::string& isbn,
    const std::string& title,
    const std::string& author,
    const std::string& publisher,
    const std::string& category,
    int publicationYear,
    int pageCount)
{
    bookInventory.emplace_back(isbn, title, author, publisher, category, publicationYear, pageCount);
}

void Library::removeBook(const std::string& isbn)
{
    Book* book = findBookByIsbn(isbn);

    if (book == nullptr)
    {
        std::cout << "The book does not exist.\n";
        return;
    }

    bookInventory.erase(
        std::remove_if(bookInventory.begin(), bookInventory.end(),
            [&isbn](const Book& element)
            {
                return element.getIsbn() == isbn;
            }),
        bookInventory.end());
}

Book* Library::findBookByIsbn(const std::string& isbn)
{
    for (auto& element : bookInventory)
    {
        if (element.getIsbn() == isbn)
        {
            return &element;
        }
    }

    return nullptr;
}

Book* Library::findBookByTitle(const std::string& title)
{
    for (auto& element : bookInventory)
    {
        if (element.getTitle() == title)
        {
            return &element;
        }
    }

    return nullptr;
}

Book* Library::findBookByAuthor(const std::string& author)
{
    for (auto& element : bookInventory)
    {
        if (element.getAuthor() == author)
        {
            return &element;
        }
    }

    return nullptr;
}

Book* Library::findBookByCategory(const std::string& category)
{
    for (auto& element : bookInventory)
    {
        if (element.getCategory() == category)
        {
            return &element;
        }
    }

    return nullptr;
}

// Member management
void Library::addMember(const std::string& name,
    const std::string& address,
    const std::string& phone,
    const std::string& email)
{
    memberIdCounter++;
    memberList.emplace_back(memberIdCounter, name, address, phone, email);
}

void Library::removeMember(int memberId)
{
    Member* member = findMemberById(memberId);

    if (member == nullptr)
    {
        std::cout << "The member does not exist.\n";
        return;
    }

    memberList.erase(
        std::remove_if(memberList.begin(), memberList.end(),
            [memberId](const Member& element)
            {
                return element.getId() == memberId;
            }),
        memberList.end());

    memberIdCounter--;
    int index = 1;
    for (auto& element : memberList)
    {
        element.setId(index++);
    }
}

Member* Library::findMemberById(int id)
{
    for (auto& element : memberList)
    {
        if (element.getId() == id)
        {
            return &element;
        }
    }

    return nullptr;
}

Member* Library::findMemberByName(const std::string& name)
{
    for (auto& element : memberList)
    {
        if (element.getName() == name)
        {
            return &element;
        }
    }

    return nullptr;
}

// Borrowing management
void Library::borrowBook(int memberId, const std::string& isbn, const std::string& borrowDate)
{
    Member* member = findMemberById(memberId);
    if (member == nullptr)
    {
        std::cout << "The member does not exist.\n";
        return;
    }

    Book* book = findBookByIsbn(isbn);
    if (book == nullptr)
    {
        std::cout << "The book does not exist.\n";
        return;
    }

    member->borrowBook(book, borrowDate);
}

void Library::returnBook(int memberId, const std::string& isbn)
{
    Member* member = findMemberById(memberId);
    if (member == nullptr)
    {
        std::cout << "The member does not exist.\n";
        return;
    }

    Book* book = findBookByIsbn(isbn);
    if (book == nullptr)
    {
        std::cout << "The book does not exist.\n";
        return;
    }

    member->returnBook(book);
}

// Reservation management
void Library::addReservation(int memberId, const std::string& isbn, const std::string& reservationDate)
{
    Member* member = findMemberById(memberId);
    if (member == nullptr)
    {
        std::cout << "The member does not exist.\n";
        return;
    }

    Book* book = findBookByIsbn(isbn);
    if (book == nullptr)
    {
        std::cout << "The book does not exist.\n";
        return;
    }

    if (book->getIsBorrowed())
    {
        std::cout << "The book is already borrowed and cannot be reserved.\n";
        return;
    }

    reservationIdCounter++;
    reservationList.emplace_back(reservationIdCounter, member, book, reservationDate);
    std::cout << "Reservation added successfully.\n";
}

void Library::processReservation(int reservationId, const std::string& borrowDate)
{
    for (auto& element : reservationList)
    {
        if (element.getId() == reservationId && element.isReservationActive())
        {
            element.processReservation(borrowDate);
            return;
        }
    }

    std::cout << "The reservation does not exist.\n";
}

// Fine management
void Library::addFine(int memberId, const std::string& isbn, const std::string& reason, double amount)
{
    Member* member = findMemberById(memberId);
    if (member == nullptr)
    {
        std::cout << "The member does not exist.\n";
        return;
    }

    Book* book = findBookByIsbn(isbn);
    if (book == nullptr)
    {
        std::cout << "The book does not exist.\n";
        return;
    }

    fineIdCounter++;
    fineList.emplace_back(fineIdCounter, member, book, reason, amount);
    std::cout << "Fine added successfully.\n";
}

void Library::payFine(int fineId)
{
    for (auto& element : fineList)
    {
        if (element.getId() == fineId)
        {
            element.payFine();
            return;
        }
    }

    std::cout << "The fine does not exist.\n";
}

// Reports
void Library::displayBookInventory() const
{
    std::cout << "The library has " << bookInventory.size() << " books.\n";
    for (const auto& element : bookInventory)
    {
        std::cout << element;
    }
}

void Library::displayMembers() const
{
    std::cout << "The library has " << memberList.size() << " members.\n";
    for (const auto& element : memberList)
    {
        std::cout << element;
    }
}

void Library::displayActiveReservations() const
{
    bool found = false;

    for (const auto& element : reservationList)
    {
        if (element.isReservationActive())
        {
            std::cout << element;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "There are no active reservations.\n";
    }
}

void Library::displayUnpaidFines() const
{
    bool found = false;

    for (const auto& element : fineList)
    {
        if (!element.isPaidStatus())
        {
            std::cout << element;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "There are no unpaid fines.\n";
    }
}

void Library::displayLibraryStatistics() const
{
    std::cout << "_- Library Statistics -_\n";
    std::cout << "Name: " << name << '\n';
    std::cout << "Address: " << address << '\n';
    std::cout << "Total books: " << bookInventory.size() << '\n';
    std::cout << "Total members: " << memberList.size() << '\n';

    int activeLoans = 0;
    for (const auto& element : memberList)
    {
        if (element.getBorrowedBooksCount() != 0)
        {
            activeLoans += static_cast<int>(element.getBorrowedBooksCount());
        }
    }
    std::cout << "Total active loans: " << activeLoans << '\n';

    int activeReservations = 0;
    for (const auto& element : reservationList)
    {
        if (element.isReservationActive())
        {
            activeReservations++;
        }
    }
    std::cout << "Total active reservations: " << activeReservations << '\n';

    int unpaidFines = 0;
    int paidFines = 0;

    for (const auto& element : fineList)
    {
        if (element.isPaidStatus())
        {
            paidFines++;
        }
        else
        {
            unpaidFines++;
        }
    }

    std::cout << "Total fines: " << fineList.size() << '\n';
    std::cout << "-> Paid: " << paidFines << '\n';
    std::cout << "-> Unpaid: " << unpaidFines << '\n';
}