#pragma once
class IntermediateCode
{
public:
	IntermediateCode();
	~IntermediateCode();
	IntermediateCode &Load(std::ifstream&);
	IntermediateCode *next();
private:
	bool ex1;
	bool ex2;
	bool ex0;
	int type;
	int code;
	unsigned short ifOffset;
	IntermediateCode *nextCode;
};

