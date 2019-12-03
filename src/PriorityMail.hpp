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

	int _compare(const PriorityMail &o);

public:
	PriorityMail(Mail mail){this->m = mail;};
	PriorityMail(){this->m=Mail();}

	Mail getMail() { return m; }

	// Other functions
	friend ostream &operator<<(ostream &, Mail &);
	//Comparing priority
	bool operator<( const PriorityMail &o) { return  this->_compare(o)<0; }
	bool operator>( const PriorityMail &o) { return  this->_compare(o)>0; }
	bool operator==(const PriorityMail &o) { return this->_compare(o)==0; }
	bool operator!=(const PriorityMail &o) { return this->_compare(o)!=0; }
};
ostream &operator<<(ostream &out, PriorityMail &m)
{
	out << m;
	return out;
}

int PriorityMail::_compare(const PriorityMail &o){
	if (this->m.getType()!=o.m.getType())
	{
		if (this->m.getType()>o.m.getType()) // if i have a higher priority
			return 1;
		else 
			return -1;
	}
	else if (this->m.getSent()!=o.m.getSent())
	{
		if (this->m.getSent()<o.m.getSent()) //if i was sent sooner
			return 1;
		else 
			return -1;
	}
	else if (this->m.getTrackingNumber()!=o.m.getTrackingNumber()) // then use tracking number, because hopefully first tracking number went into system fist
	{
		if (this->m.getTrackingNumber()<o.m.getTrackingNumber()) //if i have lower number
			return 1;
		else 
			return -1;
	}
	else 
		return 0;
}

#endif
