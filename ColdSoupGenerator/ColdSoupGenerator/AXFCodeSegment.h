#pragma once
#include "IntermediateCode.h"

class AXFCodeSegment
{
public:
	AXFCodeSegment();
	~AXFCodeSegment();
	void Load(std::ifstream &, int, int);
private:
	IntermediateCode *intermediateCode;
};

