#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
	unordered_map<char, bool> _hasp(10);
	bool flag = true;
	string s1, s2;
	int n1, n2, i;
	cin >> s1 >> s2;
	n1 = s1.size();
	n2 = s2.size();
	for (i = 0; i < n1; i++)
		_hasp[s1[i]] =  false;
	for (i = 0; i < n2; i++)
	{
		if(_hasp.count(s2[i]))
			_hasp[s2[i]] = true;
	}
	for (pair<char, int> i : _hasp)
		if(!i.second)
		{
			flag =  false;
			break;
		}
	if(flag)
		cout<<"true"<<endl;	
	else
		cout<<"false"<<endl;
	return 0;
}