// Header file for the Type class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef TYPE_H
#define TYPE_H
#include <iostream>
using std::ostream;
using std::string;
enum TypeOption
{
	priority,
	normal,
	economy
};

class Type
{
private:
	TypeOption t;

public:
	Type(string str);
	Type() { t; };
	string toString();
	int toInt();
	bool operator==(Type &o) { return this->toInt() == o.toInt(); }
	bool operator!=(Type &o) { return this->toInt() != o.toInt(); }
	bool operator>(Type &o) { return this->toInt() > o.toInt(); }
	bool operator>=(Type &o) { return this->toInt() >= o.toInt(); }
	bool operator<(Type &o) { return this->toInt() < o.toInt(); }
	bool operator<=(Type &o) { return this->toInt() <= o.toInt(); }
	friend ostream &operator<<(ostream &, Type &);
};
Type::Type(string str)
{
	if (str == "economy")
		this->t = TypeOption::economy;
	else if (str == "normal")
		this->t = TypeOption::normal;
	else if (str == "priority")
		this->t = TypeOption::priority;
	else
		throw std::invalid_argument(str + " is not a valid type");
}
int Type::toInt()
{
	if (this->t == TypeOption::economy)
		return 0;
	else if (this->t == TypeOption::normal)
		return 1;
	else if (this->t == TypeOption::priority)
		return 2;
	else
		return -1;
}
string Type::toString()
{
	if (this->t == TypeOption::economy)
		return "economy";
	else if (this->t == TypeOption::normal)
		return "normal";
	else if (this->t == TypeOption::priority)
		return "priority";
	else
		return "";
}

#endif