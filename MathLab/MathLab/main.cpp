#include<iostream>
#include"matrix.h"
#include"graph.h"
#include"model3d.h"
#include"draw.h"


using namespace mathlab;


int main()
{
	Graph _graph;
	Model_3D _m3d("pointdata.ini", _graph);
	Draw3D(_m3d,1000,50, 0, 0, 30);
    return 0;
}

