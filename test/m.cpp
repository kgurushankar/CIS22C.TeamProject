#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	string s = "test tes\tte";
	cout << s.substr(s.find("\t")) << endl;
	cout << s.substr(0, s.find("\t")) << endl;
	return 0;
}