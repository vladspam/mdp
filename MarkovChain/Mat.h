#pragma once
#include <vector>

using namespace System::Runtime::InteropServices;

public class Mat 
{
private:
	// data of matrix
	std::vector<std::vector<double>>  *_mat;

	//size of matrix n*n
	int _size;
public:
	Mat(int n);
	Mat(array<array<double>^>^ data);
	~Mat();


	array<double> ^ GetRow(int index);
	array<double> ^ operator[] (int i);
};