#ifndef ModelD_H
#define ModelD_H
#include<fstream>
#include<string>
#include"matrix.h"
#include"graph.h"
#include"message.h"

namespace mathlab
{
	class Model_3D
	{
	private:
		size_t size;
		Matrix MT_Trans;
		Graph _graph;
		std::vector<Matrix> m3dPointData;
	public:
		Model_3D() {}
		Model_3D(char *_szpath, Graph _graph):_graph(_graph)
		{
			double a;
			int i;
			std::ifstream fp(_szpath);
			MT_Trans.InitZero(4, 4);
			MT_Trans.DiagonalMatrix(1);

			while (!fp.eof())
			{
				Matrix _temp(4, 1, 1);
				for (i = 0; i < 3; i++)
				{
					if(fp >> a)
						_temp.Replace(i, 0, a * 15);
					else
					{
						info::Message(5, size, i + 1);
						break;
					}
				}
				m3dPointData.push_back(_temp);
				if(i==3)
					size++;
			}
		}

		void Clear()
		{
			MT_Trans.DiagonalMatrix(1);
		}

		void RevolveXYZ(int type,double theat)
		{
			switch (type)
			{
				//1 xÖáÐý×ª
				//2 yÖáÐý×ª
				//3 zÖáÐý×ª
			case(1) :
				MT_Trans = MT_Trans * _graph.RevolveX(theat);
				break;
			case(2) :
				MT_Trans = MT_Trans * _graph.RevolveY(theat);
				break;
			case(3) :
				MT_Trans = MT_Trans * _graph.RevolveZ(theat);
				break;
			default :
				break;
			}
		}

		void MoveNScale(bool type, double x, double y, double z)
		{
			if (type)
			{
				MT_Trans = _graph.Move(x, y, z) * MT_Trans;
			}
			else
				MT_Trans = _graph.Scale(x, y, z) * MT_Trans ;
		}

		void Mirror(int type)
		{
			if (type < 3)
			{
				int s = size;
				for (int i = 0; i < s; i++) 
				{
					Matrix _temp(4, 1, 1);
					_temp.CopyFrom(m3dPointData[i]);
					_temp.Replace(type,0,-m3dPointData[i].GetElementValue(type, 0));
					m3dPointData.push_back(_temp);
					size++;
				}
			}
		}

		void Transform()
		{
			size_t i;
			for (i = 0; i < size; i++)
				m3dPointData[i].CopyFrom(MT_Trans * m3dPointData[i]);
			Clear();
		}

		size_t GetSize()
		{
			return size;
		}

		Matrix& GetMatrix(size_t index)
		{
			if (index < size)
				return m3dPointData[index];
			else
				info::Error("error index.");
				return MT_Trans;
		}

		std::vector<Matrix>& GetData()
		{
			return m3dPointData;
		}
	};
}

#endif