// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include "Address.hpp"
#include "Date.hpp"

using std::ostream;
using std::string;

enum Type
{
    priority,
    normal,
    economy
};

class Mail
{
private:
    // Address from sender
    // Address from receiver
    // Type of Mail: Express, Business or etc..
    // Int: date sent/ date received
    // Int: estimate time to send the mail
    // Mailing Status: Sent/ In-process

    Address from;
    Address to;
    Date sent;
    Type type;
    int trackingNumber;

public:
    Mail(int, Address, Address, Date, Type);
    Mail()
    {
        from = Address();
        to = Address();
        sent = Date();
        trackingNumber = -1;
    }

    // Setters
    void setType(Type t) { this->type = t; };

    // Getters
    int getTrackingNumber() const { return trackingNumber; }
    Address getFrom() const { return from; }
    Address getTo() const { return to; }
    Date getSent() const { return sent; }
    Type getType() const { return this->type; }
    int comparePriority(const Mail &);

    // Other functions
    friend ostream &operator<<(ostream &, Mail &);
};

ostream &operator<<(ostream &out, Mail &m)
{
    out << "Tracking Number:" << std::endl
        << m.trackingNumber << std::endl
        << "From:" << std::endl
        << m.from << std::endl
        << "To:" << std::endl
        << m.to << std::endl
        << "Sent On:" << std::endl
        << m.sent << std::endl;
    return out;
}

#endif
