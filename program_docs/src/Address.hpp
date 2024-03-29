// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include "State.h"

using std::ostream;
using std::string;

class Address
{
private:
    string street;
    string city;
    State state;
    int zip;

public:
    Address(string street, string city, State s, int zip)
    {
        this->street = street;
        this->city = city;
        this->state = s;
        this->zip = zip;
    }
    Address(char street[], char city[], State s, int zip)
    {
        this->street = street;
        this->city = city;
        this->state = s;
        this->zip = zip;
    }
    Address()
    {
        street = "";
        city = "";
        state = State();
        zip = 0;
    }

    // Getters
    string getStreet() const { return street; }
    string getCity() const { return city; }
    State getState() const { return state; }
    int getZip() const { return zip; }

    // Other functions
    friend ostream &operator<<(ostream &, Address &);
    bool operator==(Address &o) { return this->city == o.city && this->state == o.state && this->street == o.street && this->zip == o.zip; }
    bool operator!=(Address &o) { return this->city != o.city || this->state != o.state || this->street != o.street || this->zip != o.zip; }
};

ostream &operator<<(ostream &out, Address &a)
{
    string zipstr = std::to_string(a.zip);
    while (zipstr.length() < 5)
    {
        zipstr = "0" + zipstr;
    }
    // cout << zipstr;
    out << a.street << std::endl
        << a.city << " " << a.state << " " << zipstr;
    return out;
}
#endif

// AL: tracking_number, tracking_number.....
// AK: tracking_number, tracking_number.....
// AS: tracking_number, tracking_number.....
// AZ: tracking_number, tracking_number.....
// AR: tracking_number, tracking_number.....
// CA: tracking_number, tracking_number.....
// CO: tracking_number, tracking_number.....
// CT: tracking_number, tracking_number.....
// DE: tracking_number, tracking_number.....
// DC: tracking_number, tracking_number.....
// FL: tracking_number, tracking_number.....
// GA: tracking_number, tracking_number.....