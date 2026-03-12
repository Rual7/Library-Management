#pragma once

#include <string>
#include <iostream>

class Book
{
private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string publisher;
    std::string category;
    int publicationYear;
    int pageCount;

    bool isBorrowed;
    std::string borrowDetails;

public:
    // Constructor
    Book(const std::string& isbn,
        const std::string& title,
        const std::string& author,
        const std::string& publisher,
        const std::string& category,
        int publicationYear,
        int pageCount);

    // Getters
    std::string getIsbn() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPublisher() const;
    std::string getCategory() const;
    int getPublicationYear() const;
    int getPageCount() const;
    bool getIsBorrowed() const;
    std::string getBorrowDetails() const;

    // Methods
    void borrowBook(const std::string& personName, const std::string& borrowDate);
    void returnBook();
    void displayDetails() const;

    // Operators
    bool operator==(const Book& book) const;
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};