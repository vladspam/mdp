#pragma once

#include <vector>
#include "IEnumerator.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MarkovChain 
{
	public ref class Mat
	{
	private:
		// data of matrix
		std::vector<std::vector<double>>  *_mat;

		//size of matrix n*n
		int _size;
	public:
	
		property int Size 
		{
			virtual int get() 
			{
				return _size;
			}
		}

		Mat(int n);
		Mat(array<array<double>^>^ data);
		~Mat();


		array<double> ^ GetRow(int index);
		array<double> ^ operator[] (int i);
		
		//create iterator
		IEnumerator^ GetEnumerator();
		
		virtual String^ ToString() override;
	};
}
