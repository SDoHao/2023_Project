#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<stdexcept>

namespace info
{
	static char *message[]
	{
		"Beyond the bounds of the array.",
		"Index at position %d exceeds array bounds (cannot exceed %d).",
		"Array not initialized.",
		"Inconsistent array dimensions to concatenate.",
		"Inconsistent matrix dimensions.",
		"Insufficient data so reading encountered an error.[Line %d,Index %d]",
		//6
		"Matrix is not square.",
		"Matrix is non-inversible",
	};

	void static Message(int i)
	{
		printf("\n<<    ");
		printf(message[i]);
		printf("\n");
	}

	void static Message(int i,int ag1,int ag2)
	{
		printf("\n<<    ");
		printf(message[i],ag1,ag2);
		printf("\n");
	}

	static const char* GetMessage(int i)
	{
		return message[i];
	}

	inline void Error(const char* message)
	{
		throw std::logic_error(message);
	}
}
#endif
#pragma once
