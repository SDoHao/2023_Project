#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<char, int> _hasp(10);
	string s1, s2;
	int n1, n2, i;
	cin >> s1 >> s2;
	n1 = s1.size();
	n2 = s2.size();
	
	for (i = 0; i<n1; i++)
		_hasp[s1[i]] = 1;
	for (pair<char,int> i : _hasp)
		cout << i.first << ' ' << i.second << endl;

	return 0;
}