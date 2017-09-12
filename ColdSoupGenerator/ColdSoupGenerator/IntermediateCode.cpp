#include <fstream>

#include "IntermediateCode.h"

const short EXFLG_0 = 0x1000;
const short EXFLG_1 = 0x2000;
const short EXFLG_2 = 0x4000;
const short CSTYPE = 0xfff;
const short TYPE_CMPCMD = 11;

IntermediateCode::IntermediateCode()
{
}

IntermediateCode::~IntermediateCode()
{
}

IntermediateCode & IntermediateCode::Load(std::ifstream &ifs)
{
	short ex;
	short code16;
	ifs.read((char*)&ex, sizeof(ex));
	if (ex & 0x8000) {
		ifs.read(reinterpret_cast<char *>(&code), sizeof(code));
	}
	else {
		ifs.read((char *)&code16, sizeof(code16));
		code = static_cast<int>(code16);
	}
	ex0 = ex & EXFLG_0;
	ex1 = ex & EXFLG_1;
	ex2 = ex & EXFLG_2;
	type = ex & CSTYPE;
	if (type == TYPE_CMPCMD) {
		ifs.read(reinterpret_cast<char*>(&ifOffset), sizeof(ifOffset));
	}
	nextCode = new IntermediateCode();
	return *nextCode;
}

IntermediateCode * IntermediateCode::next()
{
	return nextCode;
}
