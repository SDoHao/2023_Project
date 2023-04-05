#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include"matrix.h"
#include"model3d.h"
#include"draw.h"

using namespace mathlab;

struct POS
{
	size_t x;
	size_t y;
};
typedef struct POS POS;

void FindNeighbor(Matrix& visited,size_t r, size_t c, std::vector<POS>& _pos)
{
	if (r != 0 && visited.GetElementValue(r - 1, c) == 0)
	{
		POS a;
		a.x = r - 1;
		a.y = c;
		_pos.push_back(a);
	} 
	if (r != visited.GetRowSize() - 1 && visited.GetElementValue(r + 1, c) == 0)
	{
		POS a;
		a.x = r + 1;
		a.y = c;
		_pos.push_back(a);
	}
	if (c != 0 && visited.GetElementValue(r,c - 1) == 0)
	{
		POS a;
		a.x = r;
		a.y = c - 1;
		_pos.push_back(a);
	}
	if (c != visited.GetColSize() - 1 && visited.GetElementValue(r, c + 1) == 0)
	{
		POS a;
		a.x = r;
		a.y = c + 1;
		_pos.push_back(a);
	}
}

void BFS(std::queue<POS> &_q,Matrix& _mat,size_t x,size_t y)
{
	POS _pos;
	POS _t;
	_pos.x = x;
	_pos.y = y;
	_q.push(_pos);
	_mat.Replace(x, y, 2);
	int r, c;
	while (!_q.empty())
	{
		_t = _q.front();
		_q.pop();
		std::vector<POS> _vpos;
		FindNeighbor(_mat, _t.x, _t.y, _vpos);
		/*std::vector<POS> _vpos;
		r = _t.x;
		c = _t.y;
		if (r != 0 && _mat.GetElementValue(r - 1, c) == 0)
		{
			POS a;
			a.x = r - 1;
			a.y = c;
			_vpos.push_back(a);
		}
		if (r != _mat.GetRowSize() - 1 && _mat.GetElementValue(r + 1, c) == 0)
		{
			POS a;
			a.x = r + 1;
			a.y = c;
			_vpos.push_back(a);
		}
		if (c != 0 && _mat.GetElementValue(r, c - 1) == 0)
		{
			POS a;
			a.x = r;
			a.y = c - 1;
			_vpos.push_back(a);
		}
		if (c != _mat.GetColSize() - 1 && _mat.GetElementValue(r, c + 1) == 0)
		{
			POS a;
			a.x = r;
			a.y = c + 1;
			_vpos.push_back(a);
		}*/

		std::vector<POS>::iterator _ivp;
		for (_ivp = _vpos.begin(); _ivp < _vpos.end(); _ivp++)
		{
			_mat.Replace(_ivp->x, _ivp->y, 2);
			std::cout << _mat;
			if (_ivp->x == 4 && _ivp->y == 4)
			{
				while (!_q.empty())
					_q.pop();
				break;
			}
			_q.push(*_ivp);
		}
	}
}


int main()
{
	////Draw a 3D model heart
	//Model_3D _m3d("pointdata.ini");
	//Draw3D(_m3d, 7, 50, 0, 0, 30);

	//BFS
	std::cout << std::endl;
	Matrix maze("maze.csv");
	std::cout << maze;

	std::queue<POS> Q;
	BFS(Q, maze, 0, 0);

	
    return 0;
}

