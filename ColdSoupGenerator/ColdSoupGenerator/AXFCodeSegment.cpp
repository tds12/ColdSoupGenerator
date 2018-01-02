#include <fstream>

#include "AXFCodeSegment.h"
#include "IntermediateCode.h"


AXFCodeSegment::AXFCodeSegment()
{
}


AXFCodeSegment::~AXFCodeSegment()
{
}

void AXFCodeSegment::Load(std::ifstream &axfile, size_t index, size_t size)
{
	axfile.seekg(index);
	{
		intermediateCode = new IntermediateCode();
		IntermediateCode *currentCode = intermediateCode;
		do {
			currentCode = currentCode->Load(axfile,static_cast<size_t>(axfile.tellg()),size);
		} while (currentCode);
	}
}

