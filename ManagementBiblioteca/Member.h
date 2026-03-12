#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Book.h"

class Member
{
private:
    int id;
    std::string name;
    std::string address;
    std::string phone;
    std::string email;
    std::vector<Book*> borrowedBooks;

public:
    // Constructor
    Member(int id,
        const std::string& name,
        const std::string& address,
        const std::string& phone,
        const std::string& email);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;
    std::string getEmail() const;
    size_t getBorrowedBooksCount() const;

    // Setters
    void setId(int newId);
    void setAddress(const std::string& newAddress);
    void setPhone(const std::string& newPhone);
    void setEmail(const std::string& newEmail);

    // Methods
    void displayBorrowedBooks() const;
    void borrowBook(Book* book, const std::string& borrowDate);
    void returnBook(Book* book);

    // Operators
    friend std::ostream& operator<<(std::ostream& os, const Member& member);
};