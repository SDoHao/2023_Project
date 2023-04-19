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
			for (size_t i = 0; i < rows ; i++)
				for (size_t j = 0; j < cols; j++)
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
		Matrix Transpose(); // 矩阵转置
		double Determinant();//求矩阵对应的行列式的值
		Matrix Inverse();//求逆矩阵
		 // 计算伴随矩阵
		Matrix Adjoint();

		static friend std::ostream& operator<<(std::ostream& os, const Matrix & _matrix);
		friend Matrix operator*(Matrix & _matrix1, Matrix & _matrix2);
		friend Matrix operator/(Matrix & _matrix1, Matrix & _matrix2);

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
		int n = mt_Data.size();
		int add_num = add_cols * rows;
		index += add_num;
		for (size_t i = n ; i >= cols; i -= cols)
			for (size_t j = 0; j < add_cols; j++)
				mt_Data.insert(mt_Data.begin() + i, 0);
		cols += add_cols;
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

	Matrix  Matrix::Transpose()
	{
		Matrix res(rows, cols);
		for (size_t i = 0; i < rows; i++)
			for (size_t j = 0; j < cols; j++)
				res.mt_Data[j * cols + i] = mt_Data[i * cols+j];
		return res;
	}

	// 求行列式的值
	double  Matrix::Determinant()
	{
		if (rows != cols)
		{
			info::Message(6);
			return 0;
		}
		double det = 1;
		Matrix temp(*this);

		for (size_t i = 0; i < rows - 1; i++)
		{
			if (temp.mt_Data[i * cols + i] == 0)
			{
				det = 0;
				break;
			}
			for (size_t j = i + 1; j < rows; j++)
			{
				double ratio = temp.mt_Data[j * cols + i] / temp.mt_Data[i * cols + i];
				for (size_t k = i; k < cols; k++)
					temp.mt_Data[j * cols + k] -= ratio * temp.mt_Data[i * cols + k];
			}
		}
		for (size_t i = 0; i < rows; i++)
			det *= temp.mt_Data[i * cols + i];
		return det;
	}

	// 求逆矩阵
	Matrix Matrix::Inverse() 
	{
		if (rows != cols)
		{
			info::Error(info::GetMessage(6));
		}
		if (Matrix::Determinant() == 0)
		{
			info::Error(info::GetMessage(7));
		}
		int n = rows;
		int nn = 2 * n;
		double t, a;
		Matrix mat(n, nn,0);
		
		// 初始化n x n部分为原矩阵，0 x n到n x 2n部分为单位矩阵
		for (int i = 0; i < n; i++) 
		{
			mat.mt_Data[i * nn + i + n] = 1;
			for (int j = 0; j < n; j++) 
			{
				mat.mt_Data[i * nn + j] = mt_Data[i * n + j];
			}
		}
		// 高斯-约旦消元，转换为上三角矩阵
		for (int i = 0; i < n; i++) {
			t = mat.mt_Data[i * nn + i];
			for (int k = i; k < nn; k++) 
			{
				mat.mt_Data[i * nn + k] /= t;
			}
			for (int j = 0; j < n; j++) 
			{
				if (j == i) 
					continue;
				a = mat.mt_Data[j * nn + i];
				for (int k = i; k < nn; k++) 
				{
					mat.mt_Data[j * nn + k] = mat.mt_Data[j * nn + k] - a * mat.mt_Data[i * nn + k];
				}
			}
		}
		
		// 获取结果逆矩阵（n x n右边的部分）
		Matrix res(n, n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res.mt_Data[i * n + j] = mat.mt_Data[i * nn + j + n];
		return res;
	}

	Matrix Matrix::Adjoint()
	{
		if (rows != cols)
		{
			info::Error(info::GetMessage(6));
		}
		int size = rows;
		int sign;
		Matrix adj(size, size);
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++) 
			{
				Matrix tmp(size - 1, size - 1);
				for (int k = 0; k < size - 1; k++) 
				{
					for (int l = 0; l < size - 1; l++) 
					{
						int row = k + (k >= i);
						int col = l + (l >= j);
						tmp.mt_Data[k * size + l - k] = mt_Data[row * size + col];
					}
				}
				sign = ((i + j) % 2 == 0) ? 1 : -1;
				adj.mt_Data[j * size + i] = sign * tmp.Determinant();
			}
		}
		return adj;
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

	Matrix operator/(Matrix & _matrix1, Matrix & _matrix2)
	{

		return _matrix1 * _matrix2.Inverse();
	}

	static std::ostream& operator<<(std::ostream& os, const Matrix& _matrix)
	{
		if (_matrix.isInit)
		{
			size_t i, j;
			os <<"ans = "<< '[' << std::endl;
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


