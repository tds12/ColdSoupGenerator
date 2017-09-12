
#include <vector>
#include <fstream>
#include "AXFDataSegment.h"



AXFDataSegment::AXFDataSegment()
{
}


AXFDataSegment::~AXFDataSegment()
{
}

void AXFDataSegment::Load(std::ifstream &axfile, size_t index, size_t size)
{
	axfile.seekg(index);
	{
		data = new std::vector<char>(size+1);
		axfile.read(data->data(), size);
	}
}

std::string *AXFDataSegment::GetStr(size_t index)
{
	std::string *result = nullptr;
	*result = std::string(data->data() + index);
	return result;
}

double AXFDataSegment::GetDouble(size_t index)
{
	return *(double*)(data->data() + index);
}
