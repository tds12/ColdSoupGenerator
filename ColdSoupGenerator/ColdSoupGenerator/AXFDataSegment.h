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
	std::string *GetStr(size_t index);
	double GetDouble(size_t index);
private:
	std::vector<char> *data;
};

