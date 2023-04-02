#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<vector>
#include"message.h"
namespace mathlab
{
	template<class T>
	class Matrix
	{
	private:
		bool isInit;
		size_t index;
		std::vector<T> m_Data;
		size_t size_w, size_h;

		//template<typename ...Args>
		//void assign(T a, Args ...args)
		//{
		//	m_Data.push_back(a);
		//	assign(args...);
		//	index++;
		//}
		//void assign() {}

	public:
		Matrix() :size_h(0), size_w(0) { index = 0; }

		Matrix(size_t rows,size_t cols) :size_h(rows), size_w(cols)
		{ 
			index = 0; 
			isInit = false;
			InitNumber(0, 0);
		}

		Matrix(size_t rows, size_t cols, T a) :size_h(rows), size_w(cols)
		{
			index = 0;
			isInit = false;
			InitNumber(0, a);
		}

		void InitNumber(size_t st,T a)
		{
			for (index = st; index < size_w * size_h; index++)
				m_Data.push_back(a);
			isInit = true;
		}

		//template<typename ...Args>
		//void emplace(Args ...args)
		//{
		//	assign(args...);
		//	size_w = index;
		//	size_h = 1;
		//	isInit = true;
		//}

		void push_back(T a)
		{
			index++;
			m_Data.push_back(a);
		}

		void expand_row()
		{
			if (isInit)
			{
				if (size_w != index)
				{
					info::Message(3);
					return;
				}
			}
			else
			{
				isInit = true;
				size_w = index;
			}
			index = 0;
			size_h++;
		}

		//µ•Œªæÿ’Û
		void IdentityMatrix(T a)
		{
			size_t i,j;
			for (i = 0; i < size_h; i++)
				for (j = 0; j < size_h; j++)
					if (i == j)
						Replace(i, j, a);
					else
						Replace(i, j, 0);
		}
		//∂‘Ω«æÿ’Û
		//void DiagonalMatrix(T a)£ª

		void Replace(size_t row, size_t col,T a)
		{
			if (isNotOutBounds(row, col))
				m_Data[row * size_w + col] = a;
		}

		bool isNotOutBounds(size_t row, size_t col)
		{
			bool isNotOut = true;
			if (row >= size_h)
			{
				info::Message(1, 1, size_h - 1);
				isNotOut = false;
			}
			if (col >= size_w)
			{
				info::Message(1, 2, size_w - 1);
				isNotOut = false;
			}
			return isNotOut;
		}
	
		T& operator()(size_t row, size_t col)
		{
			if (isNotOutBounds(row, col))
				return m_Data[row * size_w + col];
			else
				return  m_Data[0];
		}

		template<class U>
		static friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& _matrix);

		template<class U>
		Matrix<U>& operator=(const Matrix<U>& _matrix)
		{
			return *this;
		}

	};

	template<class U>
	static std::ostream& operator<<(std::ostream& os, const Matrix<U>& _matrix)
	{
		if (_matrix.isInit)
		{
			size_t i, j;
			os << '[' << std::endl;
			for (i = 0; i < _matrix.size_h; i++)
			{
				os << ' ';
				for (j = 0; j < _matrix.size_w; j++)
					os << _matrix.m_Data[i* _matrix.size_w + j] << ' ';
				os << std::endl;
			}
			os << ']';
		}
		else
			info::Message(2);
		return os;
	}
}
#endif


//#include<iostream>
//#include"matrix.h"
//#include<array>
//int main()
//{
//	using namespace mathlab;
//	int x = 6, y = 6;
//
//	//Matrix<int> _t_M(x, y, 2);
//	//std::cout << _t_M(6, 6) << std::endl;
//
//	//_t_M.IdentityMatrix(1);
//
//	//std::cout << _t_M << std::endl;
//	//
//
//	Matrix<double> _t_M_;
//	std::cout << _t_M_ << std::endl;
//
//	_t_M_.push_back(1);
//	_t_M_.push_back(1);
//	_t_M_.push_back(1);
//	_t_M_.expand_row();
//	_t_M_.push_back(1);
//	_t_M_.push_back(1);
//	_t_M_.push_back(1);
//	_t_M_.expand_row();
//	_t_M_.push_back(2);
//	_t_M_.push_back(2);
//	_t_M_.push_back(3);
//	_t_M_.expand_row();
//
//	std::cout << _t_M_ << std::endl;
//	return 0;
//}
