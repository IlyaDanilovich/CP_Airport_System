#pragma once
#include<exception>
using namespace std;

class OpenFileExpception : public exception
{
public:
	OpenFileExpception(const char*);
	~OpenFileExpception();
};

