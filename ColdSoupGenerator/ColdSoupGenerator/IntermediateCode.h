#pragma once
class IntermediateCode
{
public:
	IntermediateCode();
	~IntermediateCode();
	IntermediateCode *Load(std::ifstream &, size_t, size_t);
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

