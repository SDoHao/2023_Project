#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> _split(string str, string pattern)
{
	vector<string> result;
	string::size_type pos;
	str += pattern;
	int size = str.size(), i = 0;
	while (i < size)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
		i++;
	}
	return result;
}

int main()
{
	string str;
	string d = " ";
	char c;
	while (getline(cin, str))
	{
		vector<string> vstr = _split(str, d);
		for (int i = vstr.size() - 1; i >=0 ; i--)
			cout << vstr[i] << ' ';
	}

	return 0;
}