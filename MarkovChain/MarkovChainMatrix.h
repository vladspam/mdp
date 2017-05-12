#pragma once

#include <vector>
#include "IEnumerator.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace MarkovChain 
{
	public ref class MarkovChainMatrix
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

		MarkovChainMatrix(int n);
		MarkovChainMatrix(array<array<double>^>^ data);
		~MarkovChainMatrix();


		array<double> ^ GetRow(int index);
		array<double> ^ operator[] (int i);
		
		//create iterator
		IEnumerator^ GetEnumerator();
		
		virtual String^ ToString() override;
	};
}
