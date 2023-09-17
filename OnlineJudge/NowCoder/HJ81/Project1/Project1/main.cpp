#include<iostream>
#include<string>
int main()
{
	std::string s;
	int i = 0;
	while (std::cin >> s)
	{
		for (i = 0; i < s.size(); i++)
		{
			std::cout << s[i] << std::endl;
		}
	}
	return 0;
}