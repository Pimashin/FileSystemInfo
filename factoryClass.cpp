//---------------------------------------------------------------------------
#include <iostream>
#include "factoryClass.h"
#include "ntfsClass.h"
#include "exfatClass.h"
#include <cmath>
#include <cstdlib>
#include "string.h"
#include <functional>
#include "fatClass.h"
#include <string>

using namespace std;

typedef struct
{
	BYTE Offset_OEM[3];           // Смещение до имени файловой системы
	char OEM_Name[8];             // Имя файловой системы
} fsOEMname;

factoryClass::factoryClass() { }

fsClass* factoryClass::objCreator(driveClass* driveObj)
{
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart = 0;
	fsOEMname *currentOEM = (fsOEMname*)driveObj->readRecords(sectorOffset, 1024, 1);

	string NAME = currentOEM->OEM_Name;

	if (NAME.compare("MSDOS5.0")==0) {
	return new fatClass(driveObj);
	cout << "FAT"<<endl;
	}


	if (NAME.compare("NTFS    ")==0) {
	return new ntfsClass(driveObj);
	cout << "NTFS"<<endl;
	}

	if (NAME.compare("EXFAT   ")==0) {
	return new exfatClass(driveObj);
	cout << "EXFAT"<<endl;
	}
	 // cout << currentOEM->OEM_Name<<endl;
	}


factoryClass::~factoryClass() { }
