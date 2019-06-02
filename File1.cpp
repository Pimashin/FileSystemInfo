#pragma hdrstop
#pragma argsused

#include <iostream>
#include <windows.h>
#include <string>

#include "driveClass.h"
#include "fsClass.h"
#include "factoryClass.h"
#include <stdio.h>

 int _tmain(int argc, _TCHAR* argv[])
{
using namespace std;
	// ”знаем у пользовател€ им€ интересующего диска
	wstring diskLetter = L"";
	cout << endl << "Write the Letter of your Disk: ";
	diskLetter += L"\\\\.\\";
	diskLetter += cin.get();
	diskLetter += L":";

	driveClass* driveObj = new driveClass(diskLetter.c_str());
	fsClass* fsObj = factoryClass::objCreator(driveObj);

	fsObj->getAttributes();

	fsObj->setNumOfClustersToRead();
	fsObj->setFirstClusterToRead();
	fsObj->readClusters();

	system("pause");
	return 0;
}
