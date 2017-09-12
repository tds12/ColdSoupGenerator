#include <fstream>

#include "AXFCodeSegment.h"
#include "IntermediateCode.h"


AXFCodeSegment::AXFCodeSegment()
{
}


AXFCodeSegment::~AXFCodeSegment()
{
}

void AXFCodeSegment::Load(std::ifstream &axfile, int index, int size)
{
	axfile.seekg(index);
	{
		intermediateCode = new IntermediateCode();
		IntermediateCode *currentCode = intermediateCode;
		do {
			currentCode = currentCode->Load(axfile,static_cast<int>(axfile.tellg()),size);
		} while (currentCode);
	}
}

