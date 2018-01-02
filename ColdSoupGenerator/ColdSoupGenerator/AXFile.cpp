
#include<string>
#include<fstream>

#include "AXFile.h"



AXFile::AXFile() :
	magic{ 'H', 'S', 'P', '3' },
	headersize(sizeof(char)*4+sizeof(int)*22+sizeof(short)*2)
{
}


AXFile::~AXFile()
{
}

void AXFile::Load(const std::string &filename)
{
	std::ifstream axfile;
	axfile.open(filename, std::ios::binary);
	this->ReadHSPHED(axfile);
	axfile.close();
}

void AXFile::ReadHSPHED(std::ifstream &axfile)
{
	axfile.seekg(std::fstream::end);
	unsigned int filesize = static_cast<unsigned int>(axfile.tellg());
	axfile.clear();
	axfile.seekg(std::fstream::beg);
	if (filesize < headersize)
		return;
	for (int i = 0; i <= 3; i++) {
		char d;
		axfile.read((char *)&d, sizeof(d));
		if (d != this->magic[i])
			return;
	}
	axfile.read((char*)&this->version, sizeof(version));
	axfile.read((char*)&this->max_val, sizeof(max_val));
	axfile.read((char*)&this->allsize, sizeof(allsize));
	for (int i = 0; i <= (int)SegmentIndex::SegmentMax; i++) {
		axfile.read((char*)&Segments[i].pointer, sizeof(Segments[i].pointer));
		axfile.read((char*)&Segments[i].size, sizeof(Segments[i].size));
	}
	axfile.read((char*)&SegmentHPIDAT.pointer, sizeof(SegmentHPIDAT.pointer));
	{
		short d;
		axfile.read((char*)&d, sizeof(d));
		SegmentHPIDAT.size = d;
	}
	axfile.read((char*)&max_varhpi, sizeof(max_varhpi));
	axfile.read((char*)&bootoption, sizeof(bootoption));
	axfile.read((char*)&pointer_runtime, sizeof(pointer_runtime));
}

