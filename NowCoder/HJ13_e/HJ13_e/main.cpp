#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int i;
	string str;
	vector<string> vstr;
	while (cin >> str)
		vstr.push_back(str);
	for (auto it = vstr.rbegin(); it != vstr.rend(); it++)
		cout << *it << " ";
	//�������������д
	// for(i = vstr.size();i >=0 ;i--)
	//     cout<<vstr[i]<< ' ';
	return 0;
}