#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include<cmath>

#include"matrix.h"
#include"message.h"
#define M_PI  4 * atan(1)
//3.14159265358979323846

namespace mathlab
{
	class Graph
	{
	private:

		//×ó³Ë±ä»»¾ØÕó
		Matrix MT_RevX;
		Matrix MT_RevY;
		Matrix MT_RevZ;
		Matrix MT_Move;
		Matrix MT_Scale;

		double AngleToRadian(double theta);

	public:

		Graph()
		{
			
			MT_RevX.InitZero(4, 4);
			MT_RevY.InitZero(4, 4);
			MT_RevZ.InitZero(4, 4);
			MT_Move.InitZero(4, 4);
			MT_Scale.InitZero(4, 4);

			MT_RevX.DiagonalMatrix(1);
			MT_RevY.DiagonalMatrix(1);
			MT_RevZ.DiagonalMatrix(1);
			MT_Move.DiagonalMatrix(1);
			MT_Scale.DiagonalMatrix(1);

		}

		Matrix& RevolveX(double theta);
		Matrix& RevolveY(double theta);
		Matrix& RevolveZ(double theta);
		Matrix& Move(double mx,double my, double mz);
		Matrix& Scale(double sx, double sy, double sz);
	};

	Matrix& Graph::RevolveX(double theta)
	{
		theta = AngleToRadian(theta);
		MT_RevX.Replace(0, 0, cos(theta));
		MT_RevX.Replace(0, 1, -sin(theta));
		MT_RevX.Replace(1, 0, sin(theta));
		MT_RevX.Replace(1, 1, cos(theta));

		//std::cout << MT_RevX;
		return MT_RevX;
	}

	Matrix& Graph::RevolveY(double theta)
	{
		theta = AngleToRadian(theta);
		MT_RevY.Replace(0, 0, cos(theta));
		MT_RevY.Replace(0, 2, -sin(theta));
		MT_RevY.Replace(2, 0, sin(theta));
		MT_RevY.Replace(2, 2, cos(theta));

		//std::cout << MT_RevY;
		return MT_RevY;
	}

	Matrix& Graph::RevolveZ(double theta)
	{
		theta = AngleToRadian(theta);
		MT_RevZ.Replace(1, 1, cos(theta));
		MT_RevZ.Replace(1, 2, -sin(theta));
		MT_RevZ.Replace(2, 1, sin(theta));
		MT_RevZ.Replace(2, 2, cos(theta));

		//std::cout << MT_RevZ;
		return MT_RevZ;
	}

	Matrix& Graph::Move(double mx, double my, double mz)
	{
		MT_Move.Replace(0, 3, mx);
		MT_Move.Replace(1, 3, my);
		MT_Move.Replace(2, 3, mz);

		return MT_Move;
	}

	 Matrix& Graph::Scale(double sx, double sy, double sz)
	{
		MT_Move.Replace(0, 0, sx);
		MT_Move.Replace(1, 1, sy);
		MT_Move.Replace(2, 2, sz);

		return MT_Scale;
	}

	inline double Graph::AngleToRadian(double theta)
	{
		//½Ç¶È×ª»¡¶È
		return  theta * M_PI / 180;;
	}

}

#endif
#pragma once


/*MT_RevX.Replace(2, 2, 1);
MT_RevX.Replace(3, 3, 1);

MT_RevY.Replace(1, 1, 1);
MT_RevY.Replace(3, 3, 1);

MT_RevZ.Replace(0, 0, 1);
MT_RevZ.Replace(3, 3, 1);*/