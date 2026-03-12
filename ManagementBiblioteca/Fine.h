#pragma once

#include <string>
#include <iostream>

#include "Member.h"
#include "Book.h"

class Fine
{
private:
    int id;
    Member* member = nullptr;
    Book* book = nullptr;
    std::string reason;
    double amount;
    bool isPaid;

public:
    // Constructor
    Fine(int id, Member* member, Book* book, const std::string& reason, double amount);

    // Getters
    int getId() const;
    Member* getMember() const;
    Book* getBook() const;
    std::string getReason() const;
    double getAmount() const;
    bool isPaidStatus() const;

    // Methods
    void payFine();

    // Operators
    friend std::ostream& operator<<(std::ostream& os, const Fine& fine);
};