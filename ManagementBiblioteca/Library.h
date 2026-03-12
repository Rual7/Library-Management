#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Book.h"
#include "Member.h"
#include "Reservation.h"
#include "Fine.h"

class Library
{
private:
    std::string name;
    std::string address;

    std::vector<Book> bookInventory;
    std::vector<Member> memberList;
    std::vector<Reservation> reservationList;
    std::vector<Fine> fineList;

    int memberIdCounter = 0;
    int reservationIdCounter = 0;
    int fineIdCounter = 0;

public:
    // Constructor
    Library(const std::string& name, const std::string& address);

    // Book management
    void addBook(const std::string& isbn,
        const std::string& title,
        const std::string& author,
        const std::string& publisher,
        const std::string& category,
        int publicationYear,
        int pageCount);

    void removeBook(const std::string& isbn);
    Book* findBookByIsbn(const std::string& isbn);
    Book* findBookByTitle(const std::string& title);
    Book* findBookByAuthor(const std::string& author);
    Book* findBookByCategory(const std::string& category);

    // Member management
    void addMember(const std::string& name,
        const std::string& address,
        const std::string& phone,
        const std::string& email);

    void removeMember(int memberId);
    Member* findMemberById(int id);
    Member* findMemberByName(const std::string& name);

    // Borrowing management
    void borrowBook(int memberId, const std::string& isbn, const std::string& borrowDate);
    void returnBook(int memberId, const std::string& isbn);

    // Reservation management
    void addReservation(int memberId, const std::string& isbn, const std::string& reservationDate);
    void processReservation(int reservationId, const std::string& borrowDate);

    // Fine management
    void addFine(int memberId, const std::string& isbn, const std::string& reason, double amount);
    void payFine(int fineId);

    // Reports
    void displayBookInventory() const;
    void displayMembers() const;
    void displayActiveReservations() const;
    void displayUnpaidFines() const;
    void displayLibraryStatistics() const;
};