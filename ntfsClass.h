#pragma once

#include "fsClass.h"
#include "driveClass.h"

using namespace std;

class ntfsClass : public fsClass
{
public:
	ntfsClass(driveClass* driveObj);

	virtual DWORD getFirstClusterNum();
	virtual DWORD getTotalClusters();
	virtual FLOAT getFsClustersOffset();
	virtual string getFsName();

	~ntfsClass();
};
