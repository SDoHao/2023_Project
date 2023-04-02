#include<iostream>
#include<Windows.h>
#include<algorithm>
#include"matrix.h"
#include"graph.h"
#include"model3d.h"

#define MID_X 80
#define MID_Y 80
#define MID_Z 30
#define HEIGHT 25
#define WIDTH 80

using namespace mathlab;


bool comp(Matrix &a,  Matrix &b) 
{
	return a.GetElementValue(2, 0) < b.GetElementValue(2, 0);
}


int main()
{
	system("title ����!");
	system("mode con cols=80 lines=25");
	HANDLE _std_optput = GetStdHandle(STD_OUTPUT_HANDLE);
	char* pc = ".:-+=*#%@";
	char buffer[500][500];

	short i = 0;
	size_t index;
	size_t max;
	Graph _graph;
	Matrix *MT_mt1;
	Model_3D _m3d("pointdata.ini", _graph);
	//_m3d.Mirror(0);
	//_m3d.Mirror(1);

	max = _m3d.GetSize();
	int dx, dy, dz;
	_m3d.RevolveXYZ(3, 100);
	_m3d.RevolveXYZ(2, 90);

	COORD coord;
	coord.X = 0;
	while (1)
	{
		_m3d.Transform();
		sort(_m3d.GetData().begin(), _m3d.GetData().end(), comp);

		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 80; j++)
				buffer[i][j] = ' ';
		for (index = 0; index < max; index++)
		{
			MT_mt1 = &(_m3d.GetMatrix(index));
			dx = (MT_mt1->GetElementValue(0, 0) + MID_X / 2) * HEIGHT / MID_X;
			dy = (MT_mt1->GetElementValue(1, 0) + MID_Y / 2) * WIDTH / MID_Y;
			dz = (MT_mt1->GetElementValue(2, 0) + MID_Z / 2) * 8 / MID_Z;
			buffer[dx][dy] = *(pc+dz);
		}

		buffer[23][50] = 'F';
		buffer[23][51] = 'o';
		buffer[23][52] = 'r';
		buffer[23][54] = 'H';
		buffer[23][55] = 'u';
		buffer[23][56] = 'Y';
		buffer[23][57] = 'u';
		buffer[23][58] = 'e';

		for (i = 0; i < 25; i++)
		{
			coord.Y = i;
			SetConsoleCursorPosition(_std_optput, coord);
			WriteConsole(_std_optput, buffer[i], 79, NULL, 0);
		}
		_m3d.RevolveXYZ(3, 10);
		Sleep(50);
	}

    return 0;
}

//system("color 07");
//�޸����н��汳�����������ɫ������������
//0 = ��ɫ    8 = ��ɫ
//1 = ��ɫ    9 = ����ɫ
//2 = ��ɫ    A = ����ɫ
//3 = ����    B = ǳ����ɫ
//4 = ��ɫ    C = ����ɫ
//5 = ��ɫ    D = ����ɫ
//6 = ��ɫ    E = ����ɫ
//7 = ��ɫ    F = ����ɫ