#include "Reservation.h"

// Constructor
Reservation::Reservation(int id, Member* member, Book* book, const std::string& reservationDate)
    : id(id),
    member(member),
    book(book),
    reservationDate(reservationDate),
    isActive(true)
{
}

// Getters
int Reservation::getId() const
{
    return id;
}

Member* Reservation::getMember() const
{
    return member;
}

Book* Reservation::getBook() const
{
    return book;
}

std::string Reservation::getReservationDate() const
{
    return reservationDate;
}

bool Reservation::isReservationActive() const
{
    return isActive;
}

// Methods
void Reservation::cancel()
{
    if (!isActive)
    {
        std::cout << "The reservation is not active.\n";
        return;
    }

    isActive = false;
    std::cout << "The reservation has been canceled.\n";
}

void Reservation::processReservation(const std::string& borrowDate)
{
    if (!isActive)
    {
        std::cout << "The reservation is not active.\n";
        return;
    }

    member->borrowBook(book, borrowDate);
    std::cout << "The reservation was processed successfully.\n";
    isActive = false;
}

// Operators
std::ostream& operator<<(std::ostream& os, const Reservation& reservation)
{
    os << "| Reservation " << reservation.id << " ->\n"
        << *reservation.member
        << *reservation.book;

    os << "| Status: "
        << (reservation.isActive ? "active" : "inactive")
        << ", " << reservation.reservationDate << " |\n";

    return os;
}   