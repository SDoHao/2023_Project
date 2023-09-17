#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
void BFS(unordered_map<int, vector<int>> &map, vector<int> &index)
{
	std::queue<int> q;
	int a = index.size();
	int val = map.begin()->first;
	bool is = true;
	q.push(val);
	while (!q.empty())
	{
		int front = q.front();
		if (index[front])
		{
			is = false;
			break;
		}
		index[front] = 1;
		q.pop();
		if (map[front].size())
		{
			for (int i = 0; i < map[front].size(); i++)
				q.push(map[front][i]);
			for (auto & v: map)
			{
				for (int i = 0; i < v.second.size();i++)
					if(v.second[i] == front)
						q.push(v.first);
			}
				
		}
	}
	for (int i = 1; i < a;i++)
		if (index[i] == 0)
		{
			is = false;
			break;
		}
	if (is)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main()
{
	int n;
	int a, b,t1,t2;
	cin >> n;
	while (n-- > 0)
	{
		unordered_map<int,vector<int>> map;
		vector<int> index;
		cin >> a >> b;
		for (int i = 1; i <= a; i++)
		{
			vector<int> tt;
			map[i] = tt;
		}
		for (int i = 0; i <= a; i++)
		{
			index.push_back(0);
		}			
		for (int i = 0; i < b; i++)
		{
			cin >> t1 >> t2;
			map[t1].push_back(t2);
			//map[t2].push_back(t1);
		}
		
		BFS(map, index);

	}

	return 0;
}