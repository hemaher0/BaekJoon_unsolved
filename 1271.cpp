#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	string b;
	string quotient="";
	string tmp="";
	int rest = 0;
	cin >> a;
	cin >> b;
	if (stoi(a) >= 1 && stoi(b) >= 1)
	{
		int length_a = a.length();
		int length_b = b.length();
		tmp = a;
		if (length_a < length_b)
		{	
			a = b;
			b = tmp;
			length_a = a.length();
			length_b = b.length();
		}
		string tmp1 = to_string(stoi(tmp.substr(0)) / stoi(b.substr(0)));
		string tmp2 = to_string(stoi(tmp.substr(0)) % stoi(b.substr(0)));
		quotient = tmp1;
		rest = stoi(tmp2);
	}
	cout << quotient << "\n" << rest;
	
	return 0;
	
}