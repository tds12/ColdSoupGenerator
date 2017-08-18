#pragma once

#include "AXFCodeSegment.h"
#include "AXFDataSegment.h"

class AXFile
{
public:
	AXFile();
	~AXFile();
	void Load(const std::string &);
private:
	void ReadHSPHED(std::ifstream &);
	const unsigned int headersize;
	const char magic[4];
	int version;
	int max_val;
	int allsize;
	typedef struct Segment {
		int pointer;
		int size;
	} Segment;
	enum class SegmentIndex {
		CodeSegmentIndex = 0,
		DataSEgmentIndex,
		ObjectTempIndex,
		DebugInfoIndex,
		LibInfoIndex,
		FuncInfoIndex,
		ModInfoIndex,
		LibInfo2Index,
		SegmentMax
	};
	Segment Segments[(int)(SegmentIndex::SegmentMax)];
	Segment SegmentHPIDAT;
	short max_varhpi;
	int bootoption;
	int pointer_runtime;
	AXFCodeSegment *CodeSegment;
	AXFDataSegment *DataSegment;
};

