#pragma once

#include "fsClass.h"
#include "driveClass.h"

using namespace std;

class exfatClass : public fsClass
{
private:
	DWORD totalClusters;
	DWORD firstDataSector;
public:
	exfatClass(driveClass* driveObj);

	virtual DWORD getFirstClusterNum();
	virtual DWORD getTotalClusters();
	virtual FLOAT getFsClustersOffset();
	virtual string getFsName();

	~exfatClass();
};
