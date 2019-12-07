#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	string tmp = "0	44136 Minerva Green Nestor Alley	South Ceciliamouth	NE	45310";
	char delimiter = '\t';

	size_t v = tmp.find(delimiter);
	int id = stoi(tmp.substr(0, v));

	size_t v2 = tmp.find(delimiter, v + 1);

	string street = tmp.substr(v + 1, v2 - 1);

	v = v2;
	v2 = tmp.find(delimiter, v + 1);
	string city = tmp.substr(v + 1, tmp.substr(v + 1).find(delimiter));

	v = v2;
	v2 = tmp.find(delimiter, v + 1);
	string state = tmp.substr(v + 1, tmp.substr(v + 1).find(delimiter));
	v = v2;
	int zip = stoi(tmp.substr(v + 1));

	cout << street << endl
		 << city << endl
		 << state << endl
		 << zip << endl;
	// int zip = stoi(tmp.substr(v + 1));
	// cout << "hi";
	// cout << zip << endl;
	// a[id] = Address(street, city, State(state), zip);
	// cout << a[id];
}