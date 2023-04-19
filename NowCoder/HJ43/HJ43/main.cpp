//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<vector>
//
//int a[20][20];
//bool visit[20][20];
//int M, N;
//
//struct point
//{
//	int x;
//	int y;
//};
//
//std::vector<point> v;
//
//bool is_in_range(int x, int y)
//{
//	if (x >= 0 && x<M && y >= 0 && y<N)
//	{
//		return true;
//	}
//	return false;
//}
//
//bool can_move(int x, int y)
//{
//	return is_in_range(x, y) && !visit[x][y] && !a[x][y];
//}
//
//bool is_finish(int x, int y)
//{
//	return x == M - 1 && y == N - 1;
//}
//
//void move(int x, int y)
//{
//	if (is_finish(x, y))
//	{
//		for (auto i : v)
//		{
//			printf("(%d,%d)\n", i.x, i.y);
//		}
//		return;
//	}
//	if (can_move(x - 1, y))
//	{
//		visit[x - 1][y] = true;
//		v.push_back({ x - 1,y });
//		move(x - 1, y);
//		v.pop_back();
//	}
//	if (can_move(x + 1, y))
//	{
//		visit[x + 1][y] = true;
//		v.push_back({ x + 1,y });
//		move(x + 1, y);
//		v.pop_back();
//	}
//	if (can_move(x, y - 1))
//	{
//		visit[x][y - 1] = true;
//		v.push_back({ x,y - 1 });
//		move(x, y - 1);
//		v.pop_back();
//	}
//	if (can_move(x, y + 1))
//	{
//		visit[x][y + 1] = true;
//		v.push_back({ x,y + 1 });
//		move(x, y + 1);
//		v.pop_back();
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &M, &N);
//	for (int i = 0; i<M; i++)
//	{
//		for (int j = 0; j<N; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	v.push_back({ 0,0 });
//	move(0, 0);
//	return 0;
//}

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