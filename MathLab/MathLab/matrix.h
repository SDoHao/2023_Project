#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<vector>
#include <cctype>
#include"message.h"
#include"csvfile.h"

namespace mathlab
{
	class Matrix
	{
	private:
		//row 行
		//col 列
		bool isInit;
		//index 数量
		size_t index;
		size_t rows, cols;
		std::vector<double> mt_Data;
		void push_back(double a)
		{
			if (index == cols * rows)
			{
				info::Message(0);
				return;
			}
			index++;
			mt_Data.push_back(a);
		}
	public:

		Matrix() :rows(0), cols(0) { index = 0; isInit = false;}
		Matrix(size_t rows, size_t cols) :rows(rows), cols(cols)
		{
			index = 0;
			isInit = false;
			InitNumber(0, 0);
		}
		Matrix(size_t rows, size_t cols, double value) :rows(rows), cols(cols)
		{
			index = 0;
			isInit = false;
			InitNumber(0, value);
		}
		Matrix(char *_szpath)
		{
			file::CSVFile _scv(_szpath);
			rows = _scv.GetRowSize();
			cols = _scv.GetColSize();
			isInit = true;
			index = rows * cols;
			for (int i = 0; i < rows ; i++)
				for (int j = 0; j < cols; j++)
					mt_Data.push_back(atof(_scv.GetData(i, j).c_str()));
			
		}

		//拷贝函数
		Matrix(const Matrix & c) 
		{
			rows = c.rows;
			cols = c.cols;
			index = c.index;//rows * cols;
			isInit = true;

			//vector 1
			mt_Data.assign(c.mt_Data.begin(),c.mt_Data.end());

			//printf("Copy Constructor called !\n");
			//std::vector<double>::const_iterator  i;  //定义正向迭代器
			//for (i = c.mt_Data.begin(); i < c.mt_Data.end(); i++)
			//	;
			//vector 2
			//size_t i;
			//for (i = 0; i < index; i++)
			//	mt_Data.push_back(c.mt_Data.at(i));
		}

		void CopyFrom(const Matrix & c)
		{
			mt_Data = c.mt_Data;
		}

		void ReadText(char *_szpath)
		{

		}

		size_t GetRowSize()
		{
			return rows;
		}

		size_t GetColSize()
		{
			return  cols;
		}

		void InitNumber(size_t st, double a);
		bool isNotOutBounds(size_t row, size_t col);
		double GetElementValue(size_t row, size_t col);
		void Replace(size_t row, size_t col, double a);
		void DiagonalMatrix(double a);
		void ExpandRow(size_t add_rows);
		void ExpandCol(size_t add_cols);
		void InitZero(size_t row, size_t col);
		static friend std::ostream& operator<<(std::ostream& os, const Matrix & _matrix);
		friend Matrix operator*(Matrix & _matrix1, Matrix & _matrix2);

		//使用Input()和NextRow()依次插入元素
		void Input(double a)
		{
			index++;
			mt_Data.push_back(a);
		}

		void NextRow()
		{
			if (isInit)
			{
				if (cols != index - rows * cols)
				{
					info::Message(3);
					return;
				}
			}
			else
			{
				isInit = true;
				cols = index;
			}
			rows++;
		}
	};

	void Matrix::InitNumber(size_t st, double a)
	{
		for (index = st; index < rows * cols; index++)
			mt_Data.push_back(a);
		isInit = true;
	}

	bool Matrix::isNotOutBounds(size_t row, size_t col)
	{
		if (row >= rows)
		{
			info::Message(1, 1, rows - 1);
			return false;
		}
		if (col >= cols)
		{
			info::Message(1, 2, cols - 1);
			return false;
		}
		return true;
	}

	double Matrix::GetElementValue(size_t row, size_t col)
	{
		if (isNotOutBounds(row, col))
			return mt_Data[row * cols + col];
		return 0;
	}

	void Matrix::Replace(size_t row, size_t col, double a)
	{
		if (isNotOutBounds(row, col))
			mt_Data[row * cols + col] = a;
		else
			printf("     Attempt to index [row %d col %d]\n", row, col);
	}

	//单位矩阵/对角矩阵
	//void Matrix::IdentityMatrix(double a)
	void Matrix::DiagonalMatrix(double a)
	{
		size_t i, j;
		if (rows != cols)
			info::Message(4);
		else
			for (i = 0; i < rows; i++)
				for (j = 0; j < cols; j++)
					if (i == j)
						Replace(i, j, a);
					else
						Replace(i, j, 0);
	}

	void  Matrix::ExpandRow(size_t add_rows)
	{
		rows += add_rows;
		for (; index < rows * cols; index++)
		{
			mt_Data.push_back(0);
		}
	}

	void Matrix::ExpandCol(size_t add_cols)
	{

	}

	void Matrix::InitZero(size_t row, size_t col)
	{
		size_t i, j;
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				mt_Data.push_back(0);
		isInit = true;
		rows = row;
		cols = col;
		index = row * col;
	}

	Matrix operator*(Matrix & _matrix1, Matrix & _matrix2)
	{
		size_t i, j, k;
		double t_sum;
		if (_matrix1.cols == _matrix2.rows)
		{
			Matrix _MT_mt(_matrix1.rows, _matrix2.cols, 0);
			for (i = 0; i < _matrix1.rows; i++)
				for (j = 0; j < _matrix2.cols; j++)
				{
					t_sum = 0;
					for (k = 0; k < _matrix1.cols; k++)
					{
						t_sum = t_sum + _matrix1.GetElementValue(i,k) * _matrix2.GetElementValue(k,j);
					}
					_MT_mt.Replace(i,j,t_sum);
				}
			return _MT_mt;
		}
		else
		{
			info::Message(3);
			Matrix _MT_mt(1, 1, 0);
			return _MT_mt;
		}
	}

	static std::ostream& operator<<(std::ostream& os, const Matrix& _matrix)
	{
		if (_matrix.isInit)
		{
			size_t i, j;
			os << '[' << std::endl;
			for (i = 0; i < _matrix.rows; i++)
			{
				os << "    ";
				for (j = 0; j < _matrix.cols; j++)
					os << _matrix.mt_Data[i* _matrix.cols + j] << "   ";
				os << std::endl;
			}
			os << ']' << std::endl;
		}
		else
			info::Message(2);
		return os;
	}

}


#endif


