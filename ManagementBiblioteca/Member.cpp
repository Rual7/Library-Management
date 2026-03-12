#include "Member.h"

// Constructor
Member::Member(int id,
    const std::string& name,
    const std::string& address,
    const std::string& phone,
    const std::string& email)
    : id(id),
    name(name),
    address(address),
    phone(phone),
    email(email)
{
}

// Getters
int Member::getId() const
{
    return id;
}

std::string Member::getName() const
{
    return name;
}

std::string Member::getAddress() const
{
    return address;
}

std::string Member::getPhone() const
{
    return phone;
}

std::string Member::getEmail() const
{
    return email;
}

size_t Member::getBorrowedBooksCount() const
{
    return borrowedBooks.size();
}

// Setters
void Member::setId(int newId)
{
    id = newId;
}

void Member::setAddress(const std::string& newAddress)
{
    address = newAddress;
}

void Member::setPhone(const std::string& newPhone)
{
    phone = newPhone;
}

void Member::setEmail(const std::string& newEmail)
{
    email = newEmail;
}

// Methods
void Member::displayBorrowedBooks() const
{
    std::cout << "Borrowed books:\n";

    if (borrowedBooks.empty())
    {
        std::cout << "No books are currently borrowed.\n";
        return;
    }

    for (const auto& book : borrowedBooks)
    {
        std::cout << *book;
    }
}

void Member::borrowBook(Book* book, const std::string& borrowDate)
{
    if (book->getIsBorrowed())
    {
        std::cout << "The book is already borrowed.\n";
        return;
    }

    book->borrowBook(name, borrowDate);
    borrowedBooks.push_back(book);
    std::cout << "The book was borrowed successfully.\n";
}

void Member::returnBook(Book* book)
{
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);

    if (it == borrowedBooks.end())
    {
        std::cout << "The book you want to return was not borrowed.\n";
        return;
    }

    book->returnBook();
    borrowedBooks.erase(it);
    std::cout << "The book was returned successfully.\n";
}

// Operators
std::ostream& operator<<(std::ostream& os, const Member& member)
{
    os << "| "
        << member.id << ", "
        << member.name << ", "
        << member.phone << ", "
        << member.email
        << " |\n";

    return os;
}