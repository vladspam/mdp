#include "Stdafx.h"
#include "MarkovChainMatrix.h"
#include "iterator.h"


namespace MarkovChain
{
	array<double>^ MarkovChainMatrix::operator[](int i)
	{
		return GetRow(i);
	}

	MarkovChainMatrix::MarkovChainMatrix(int n)
	{
		_size = n;
		_mat = new std::vector<std::vector<double>>(Size, std::vector<double>(Size));
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
				_mat->at(i)[j] = i*Size + j;
		}
	}

	MarkovChainMatrix::MarkovChainMatrix(array<array<double>^>^ data)
	{
		_size = data->Length;
		_mat = new std::vector<std::vector<double>>(Size, std::vector<double>(Size));

		for(int i = 0; i < Size; i++)
		{
			if (_size != data[i]->Length)
			{
				throw gcnew Exception("Wrong data. It must be matrix N*N");
			}
			else
			{
				for (int j = 0; j < Size; j++)
					_mat->at(i)[j] = data[i][j];
			}
		}

	}

	MarkovChainMatrix::~MarkovChainMatrix()
	{
		delete _mat;
	}

	array<double>^ MarkovChainMatrix::GetRow(int index)
	{
		if (index < 0 || index >= Size) \
		{
			throw gcnew Exception("Out of range.");
		}
		array<double> ^ result = gcnew array<double>(Size);

		for (int j = 0; j < Size; j++)
		{
			result[j] = _mat->at(index)[j];
		}
		return result;
	}

	IEnumerator ^ MarkovChainMatrix::GetEnumerator()
	{
		return gcnew iterator(this);
	}

	String ^ MarkovChainMatrix::ToString()
	{
		String^ result = "";

		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				result += "\t" + _mat->at(i)[j];
			}
			result += "\n";
		}
		return result;
	}
}