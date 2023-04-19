#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class pos
{
public:
	int x;
	int y;
	pos *pre;
	pos(int xx, int yy, pos* p) :x(xx), y(yy), pre(p) {}
};

void BFS(vector<vector<int>> maze, int stx, int sty, int edx, int edy)
{
	queue<pos*> q;
	queue<pos*> path;
	pos *_pp = new pos(edx, edy,nullptr);
	int n = maze.size() - 1;
	int m = maze[0].size() - 1;
	q.push(_pp);
	while (!q.empty())
	{
		_pp = q.front();
		q.pop();
		path.push(_pp);
		maze[_pp->x][_pp->y] = 2;
		if (_pp->x == stx && _pp->y == sty)
		{
			while (!q.empty())
			{
				path.push(q.front());
				q.pop();
			}
			break;
		}
		// 找相领点并放入队列
		if (_pp->x > 0 && maze[_pp->x - 1][_pp->y] == 0)
		{
			maze[_pp->x - 1][_pp->y] = 1;
			pos *_tup = new pos( _pp->x - 1,_pp->y,_pp);
			q.push(_tup);
		}
		if (_pp->x < n && maze[_pp->x + 1][_pp->y] == 0)
		{
			maze[_pp->x + 1][_pp->y] = 1;
			pos* _tdown = new pos( _pp->x + 1,_pp->y,_pp);
			q.push(_tdown);
		}
		if (_pp->y > 0 && maze[_pp->x][_pp->y - 1] == 0)
		{
			maze[_pp->x][_pp->y - 1] = 1;
			pos* _tleft = new pos( _pp->x,_pp->y - 1,_pp );
			q.push(_tleft);
		}
		if (_pp->y < m && maze[_pp->x][_pp->y + 1] == 0)
		{
			maze[_pp->x][_pp->y + 1] = 1;
			pos* _tright = new pos( _pp->x,_pp->y + 1,_pp);
			q.push(_tright);
		}
	}
	//相反向输出路径（测试）
	while (_pp)
	{
		cout << '(' << _pp->x << ',' << _pp->y << ')' << endl;
		_pp = _pp->pre;
	}

	while (!path.empty())
	{
		_pp = path.front();
		path.pop();
		delete _pp;
	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];
	BFS(maze, 0, 0, n - 1, m - 1);
	return 0;
}