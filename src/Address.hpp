// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>

using std::ostream;
using std::string;

enum State
{
    AL,
    AK,
    AS,
    AZ,
    AR,
    CA,
    CO,
    CT,
    DE,
    DC,
    FL,
    GA,
    GU,
    HI,
    ID,
    IL,
    IN,
    IA,
    KS,
    KY,
    LA,
    ME,
    MD,
    MH,
    MA,
    MI,
    FM,
    MN,
    MS,
    MO,
    MT,
    NE,
    NV,
    NH,
    NJ,
    NM,
    NY,
    NC,
    ND,
    MP,
    OH,
    OK,
    OR,
    PW,
    PA,
    PR,
    RI,
    SC,
    SD,
    TN,
    TX,
    UT,
    VT,
    VA,
    VI,
    WA,
    WV,
    WI,
    WY
};

class Address
{
private:
    string street;
    string city;
    State state;
    int zip;

public:
    Address(string, string, State, int);

    // Getters
    string getStreet() const { return street; }
    string getCity() const { return city; }
    State getState() const { return state; }
    int getZip() const { return zip; }

    // Other functions
    friend ostream &operator<<(ostream &, Date &);
    bool operator==(const Date &);
    bool operator!=(const Date &);
};

#endif
