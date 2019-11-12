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
enum Status
{
    sent,
    waiting,
    on_time,
    late
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
    Status status;

public:
    enum Type
    {
        priority,
        normal,
        economy
    };
    enum Status
    {
        sent,
        waiting,
        on_time,
        late
    };
    Mail(Address, Address, Date, Type);

    // Setters
    bool setType(Type);
    bool setStatus(Status);

    // Getters
    Address getFrom() const { return from; }
    Address getTo() const { return to; }
    Date getSent() const { return sent; }
    Type getType() const { return type; }
    Status getStatus() const { return status; }

    // Other functions
    friend ostream &operator<<(ostream &, Mail &);
    //Comparing priority
    bool operator<(const Mail &);
    bool operator>(const Mail &);
    bool operator==(const Mail &);
    bool operator!=(const Mail &);
};

#endif
