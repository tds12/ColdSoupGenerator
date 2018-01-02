#include <fstream>

#include "IntermediateCode.h"

const unsigned short EXFLG_0 = 0x1000;
const unsigned short EXFLG_1 = 0x2000;
const unsigned short EXFLG_2 = 0x4000;
const unsigned short EXFLG_BIT15 = 0x8000;
const short CSTYPE = 0xfff;
const short TYPE_CMPCMD = 11;

IntermediateCode::IntermediateCode()
{
}

IntermediateCode::~IntermediateCode()
{
}

IntermediateCode *IntermediateCode::Load(std::ifstream &axfile, size_t index, size_t size)
{
	unsigned short ex;
	unsigned short code16;
	if (static_cast<size_t>(axfile.tellg()) + sizeof(ex) + sizeof(code16) <= size) {
		nextCode = nullptr;
		return nullptr;
	}
	axfile.read((char*)&ex, sizeof(ex));
		if (ex & EXFLG_BIT15) {
			if (static_cast<size_t>(axfile.tellg()) + sizeof(code) <= size) {
			nextCode = nullptr;
			return nullptr;
		}
		axfile.read(reinterpret_cast<char *>(&code), sizeof(code));
	}
	else {
		axfile.read((char *)&code16, sizeof(code16));
		code = static_cast<size_t>(code16);
	}
	ex0 = ex & EXFLG_0;
	ex1 = ex & EXFLG_1;
	ex2 = ex & EXFLG_2;
	type = ex & CSTYPE;
	if (type == TYPE_CMPCMD) {
		if (static_cast<size_t>(axfile.tellg()) + sizeof(ifOffset) <= size) {
			nextCode = nullptr;
			return nullptr;
		}
		axfile.read(reinterpret_cast<char*>(&ifOffset), sizeof(ifOffset));
	}
	nextCode = new IntermediateCode();
	return nextCode;
}

IntermediateCode * IntermediateCode::next()
{
	return nextCode;
}
