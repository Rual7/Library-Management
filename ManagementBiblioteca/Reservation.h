#pragma once

#include <string>
#include <iostream>

#include "Member.h"
#include "Book.h"

class Reservation
{
private:
    int id;
    Member* member = nullptr;
    Book* book = nullptr;
    std::string reservationDate;
    bool isActive;

public:
    // Constructor
    Reservation(int id, Member* member, Book* book, const std::string& reservationDate);

    // Getters
    int getId() const;
    Member* getMember() const;
    Book* getBook() const;
    std::string getReservationDate() const;
    bool isReservationActive() const;

    // Methods
    void cancel();
    void processReservation(const std::string& borrowDate);

    // Operators
    friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
};