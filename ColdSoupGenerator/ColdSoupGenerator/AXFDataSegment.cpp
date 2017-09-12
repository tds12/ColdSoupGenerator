
#include <vector>
#include <fstream>
#include "AXFDataSegment.h"



AXFDataSegment::AXFDataSegment()
{
}


AXFDataSegment::~AXFDataSegment()
{
}

void AXFDataSegment::Load(std::ifstream &axfile, int index, int size)
{
	axfile.seekg(index);
	{
		data = new std::vector<char>(size+1);
		axfile.read(data->data(), size);
	}
}

std::string *AXFDataSegment::GetStr(int index)
{
	std::string *result = nullptr;
	*result = std::string(data->data() + index);
	return result;
}

double AXFDataSegment::GetDouble(int index)
{
	return *(double*)(data->data() + index);
}
