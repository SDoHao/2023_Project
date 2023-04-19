#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include"matrix.h"
#include"model3d.h"
#include"draw.h"

using namespace mathlab;

using pos = struct pos;
struct pos
{
	int x;
	int y;
	pos *pre;
	//pos(int xx, int yy, pos* p) :x(xx), y(yy), pre(p) {}
};

void BFS(Matrix maze, int stx, int sty, int edx, int edy)
{
	std::queue<pos*> q;
	std::queue<pos*> path;
	pos *_pp = new pos{ edx, edy, nullptr };
	int n = maze.GetColSize() - 1;
	int m = maze.GetRowSize() - 1;
	q.push(_pp);
	while (!q.empty())
	{
		_pp = q.front();
		q.pop();
		path.push(_pp);
		maze.Replace(_pp->x, _pp->y, 2);
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
		if (_pp->x > 0 && maze.GetElementValue(_pp->x - 1, _pp->y) == 0)
		{
			maze.Replace(_pp->x - 1, _pp->y, 1);
			pos *_tup = new pos{ _pp->x - 1, _pp->y, _pp };
			q.push(_tup);
		}
		if (_pp->x < n && maze.GetElementValue(_pp->x + 1, _pp->y) == 0)
		{
			maze.Replace(_pp->x + 1, _pp->y, 1);
			pos* _tdown = new pos{ _pp->x + 1, _pp->y, _pp };
			q.push(_tdown);
		}
		if (_pp->y > 0 && maze.GetElementValue(_pp->x , _pp->y- 1) == 0)
		{
			maze.Replace(_pp->x , _pp->y - 1, 1);
			pos* _tleft = new pos{ _pp->x, _pp->y - 1, _pp };
			q.push(_tleft);
		}
		if (_pp->y < m && maze.GetElementValue(_pp->x, _pp->y + 1) == 0)
		{
			maze.Replace(_pp->x, _pp->y + 1, 1); 
			pos* _tright = new pos{ _pp->x, _pp->y + 1, _pp };
			q.push(_tright);
		}
	}
	//相反向输出路径（测试）
	while (_pp)
	{
		std::cout << '(' << _pp->x << ',' << _pp->y << ')' << std::endl;
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
	//Draw a 3D model heart
	//Model_3D _m3d("pointdata.ini");
	//Draw3D(_m3d, 7, 50, 0, 0, 30);

	/*Matrix maze1("1.csv");
	Matrix maze2("2.csv");
	std::cout << maze1 << std::endl;
	maze1.ExpandCol(2);
	std::cout << maze1 << std::endl;*/

	//std::cout << maze2 << std::endl;
	//std::cout << maze2.Inverse() << std::endl;
	//std::cout << maze1 *  maze2 << std::endl;
	//std::cout << maze1 *  maze2.Inverse() << std::endl;
	//std::cout << maze1 /  maze2 << std::endl;
	//std::cout << maze1.Adjoint() << std::endl;

	//BFS
	std::cout << std::endl;
	Matrix maze("maze.csv");
	std::cout << maze;

	BFS(maze, 0, 0,9,9);
    return 0;
}



