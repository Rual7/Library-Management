#include "Fine.h"

// Constructor
Fine::Fine(int id, Member* member, Book* book, const std::string& reason, double amount)
    : id(id),
    member(member),
    book(book),
    reason(reason),
    amount(amount),
    isPaid(false)
{
}

// Getters
int Fine::getId() const
{
    return id;
}

Member* Fine::getMember() const
{
    return member;
}

Book* Fine::getBook() const
{
    return book;
}

std::string Fine::getReason() const
{
    return reason;
}

double Fine::getAmount() const
{
    return amount;
}

bool Fine::isPaidStatus() const
{
    return isPaid;
}

// Methods
void Fine::payFine()
{
    if (isPaid)
    {
        std::cout << "The fine has already been paid.\n";
        return;
    }

    isPaid = true;
    std::cout << "The fine was paid successfully.\n";
}

// Operators
std::ostream& operator<<(std::ostream& os, const Fine& fine)
{
    os << "| Fine " << fine.id << " ->\n"
        << *fine.member
        << *fine.book;

    os << "| Reason: " << fine.reason << " |\n";
    os << "| Total amount: " << fine.amount
        << " | Status: " << (fine.isPaid ? "Paid" : "Unpaid") << " |\n";

    return os;
}