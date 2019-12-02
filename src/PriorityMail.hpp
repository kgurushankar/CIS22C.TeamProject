// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef PRIORITY_MAIL_H
#define PRIORITY_MAIL_H

#include <iostream>
#include "Mail.hpp"

using std::ostream;
using std::string;

class PriorityMail
{
private:
	Mail m;

public:
	PriorityMail(Mail mail){this->m = mail;};

	Mail getMail() { return m; }

	// Other functions
	friend ostream &operator<<(ostream &, Mail &);
	//Comparing priority
	bool operator<(const PriorityMail &o) { return (this->m.getTrackingNumber() < o.m.getTrackingNumber()); }
	bool operator>(const PriorityMail &o) { return (this->m.getTrackingNumber() > o.m.getTrackingNumber()); }
	bool operator==(const PriorityMail &o) { return (this->m.getTrackingNumber() == o.m.getTrackingNumber()); }
	bool operator!=(const PriorityMail &o) { return (this->m.getTrackingNumber() != o.m.getTrackingNumber()); }
};
ostream &operator<<(ostream &out, PriorityMail &m)
{
	out << m;
	return out;
}

#endif
