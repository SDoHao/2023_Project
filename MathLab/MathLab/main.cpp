#include<iostream>
#include"matrix.h"
#include"model3d.h"
#include"draw.h"

using namespace mathlab;

int main()
{
	//Draw a 3D model heart
	Model_3D _m3d("pointdata.ini");
	Draw3D(_m3d, 7, 50, 0, 0, 30);

	//BFS

	std::cout << std::endl;
	Matrix maze("maze.csv");
	std::cout << maze;






    return 0;
}

