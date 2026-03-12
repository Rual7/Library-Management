#include "Book.h"

// Constructor
Book::Book(const std::string& isbn,
    const std::string& title,
    const std::string& author,
    const std::string& publisher,
    const std::string& category,
    int publicationYear,
    int pageCount)
    : isbn(isbn),
    title(title),
    author(author),
    publisher(publisher),
    category(category),
    publicationYear(publicationYear),
    pageCount(pageCount),
    isBorrowed(false),
    borrowDetails("")
{
}

// Getters
std::string Book::getIsbn() const
{
    return isbn;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getPublisher() const
{
    return publisher;
}

std::string Book::getCategory() const
{
    return category;
}

int Book::getPublicationYear() const
{
    return publicationYear;
}

int Book::getPageCount() const
{
    return pageCount;
}

bool Book::getIsBorrowed() const
{
    return isBorrowed;
}

std::string Book::getBorrowDetails() const
{
    return borrowDetails;
}

// Methods
void Book::borrowBook(const std::string& personName, const std::string& borrowDate)
{
    if (isBorrowed)
    {
        std::cout << "The book is already borrowed.\n";
        return;
    }

    isBorrowed = true;
    borrowDetails = personName + " " + borrowDate;
}

void Book::returnBook()
{
    if (!isBorrowed)
    {
        std::cout << "The book was not borrowed.\n";
        return;
    }

    isBorrowed = false;
    borrowDetails = "";
}

void Book::displayDetails() const
{
    std::cout << "BOOK " << isbn << ":\n";
    std::cout << "Title: " << title
        << " | Author: " << author
        << " | Publisher: " << publisher << '\n';

    std::cout << "Category: " << category
        << " | Publication Year: " << publicationYear
        << " | Pages: " << pageCount << '\n';

    std::cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << '\n';

    if (isBorrowed)
    {
        std::cout << "Borrow Details: " << borrowDetails << '\n';
    }
}

// Operators
bool Book::operator==(const Book& book) const
{
    return isbn == book.isbn;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "| Author: " << book.author
        << ". Title: " << book.title
        << ". Publisher: " << book.publisher
        << ", " << book.publicationYear << " |\n";

    return os;
}