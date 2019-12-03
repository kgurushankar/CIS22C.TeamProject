#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	string s = "test tes te";
	cout << s.substr(s.find(" ")) << endl;
	cout << s.substr(0, s.find(" ")) << endl;
	return 0;
}