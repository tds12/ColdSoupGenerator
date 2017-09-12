#pragma once
#include "IntermediateCode.h"

class AXFCodeSegment
{
public:
	AXFCodeSegment();
	~AXFCodeSegment();
	void Load(std::ifstream &, size_t, size_t);
private:
	IntermediateCode *intermediateCode;
};

