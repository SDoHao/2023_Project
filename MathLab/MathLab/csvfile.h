#ifndef CSVFILE_H
#define CSVFILE_H
#include<vector>
#include<string>
#include<fstream>
#include <sstream>
#define MaxLineWords 1024

namespace file
{
	using TdStringVector = std::vector<std::vector<std::string>>;
	class CSVFile
	{
	public:
		CSVFile();
		CSVFile(char * path);

		~CSVFile();

		void ReadCSV(char * path);
		void ShowCSV();
		size_t GetRowSize();
		size_t GetColSize();
		std::string GetData(int i, int j);
	private:
		TdStringVector datas;
	};

	CSVFile::CSVFile(){}
	CSVFile::CSVFile(char * path)
	{
		ReadCSV(path);
	}

	CSVFile::~CSVFile() {}

	void CSVFile::ReadCSV(char * path)
	{
		using namespace std;
		ifstream fp(path); //��������һ��ifstream����ָ���ļ�·��
		string line;
		//getline(fp, line); //������������һ�в�������
		while (getline(fp, line)) //ѭ����ȡÿ������
		{ 
			vector<string> data_line;
			string line_word;
			istringstream readstr(line); //string��������
			while (getline(readstr, line_word, ','))//��һ�����ݰ�'��'�ָ�
				data_line.push_back(line_word);
			CSVFile::datas.push_back(data_line); //���뵽vector��
		}
	}

	void CSVFile::ShowCSV()
	{
		file::TdStringVector::iterator it_o;
		std::vector<std::string>::iterator it_i;
		for (it_o = CSVFile::datas.begin(); it_o != CSVFile::datas.end(); it_o++)
		{
			for (it_i = it_o->begin(); it_i != it_o->end(); it_i++)
			{
				std::cout << *it_i << ' ';
			}
			std::cout << std::endl;
		}
	}

	size_t CSVFile::GetRowSize()
	{
		return CSVFile::datas.size();
	}

	size_t CSVFile::GetColSize()
	{
		return  CSVFile::datas[0].size();
	}

	std::string CSVFile::GetData(int i, int j)
	{ 
		//int max_i, max_j;
		//max_i = CSVFile::datas.size();
		//max_j = CSVFile::datas[i].size();
		return CSVFile::datas[i][j];
	}
}


#endif