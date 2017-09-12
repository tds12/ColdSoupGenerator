#pragma once
#include <string>
#include <vector>
#include <fstream>

class AXFDataSegment
{
public:
	AXFDataSegment();
	~AXFDataSegment();
	void Load(std::ifstream &,size_t,size_t);
	std::string *GetStr(int index);
	double GetDouble(int index);
private:
	std::vector<char> *data;
};

