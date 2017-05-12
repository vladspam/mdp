// MarkovChainConsole.cpp : main project file.

#include "stdafx.h"
#include "Mat.h"
#include "MatSerializer.h"

using namespace System;
using namespace MarkovChain;
int main()
{
	Mat^ m = gcnew Mat(3);
	
	for each (array<double>^ var in m)
	{
		String^ s = "";
		for each (auto vr in var)
		{
			s += vr.ToString();
		}
		Console::WriteLine(s);
	}
	MatSerializer^ ser = gcnew MatSerializer();
	String^ s = ser->SerializeToJSON(m);
	Console::WriteLine(s);
	Console::WriteLine(m);
    Console::WriteLine("Hello World");
	Console::ReadKey();
    return 0;
}
