#include "Mat.h"

Mat::Mat(int n) 
{
	_size = n;
	_mat = new std::vector<std::vector<double>>(_size, std::vector<double>(_size));
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
			_mat->at(i)[j] = i*_size + j;
	}
}

Mat::Mat(array<array<double>^>^ data)
{
	_size = data->Length;
	_mat = new std::vector<std::vector<double>>(_size, std::vector<double>(_size));

	for (int i = 0; i < _size; i++)
	{
		if (_size != data[i]->Length)
		{
			throw gcnew Exception("Wrong data. It must be matrix N*N");
		}
		else
		{
			for (int j = 0; j < _size; j++)
				_mat->at(i)[j] = data[i][j];
		}
	}
}

Mat::~Mat()
{
	delete _mat;
}

array<double>^ Mat::GetRow(int index)
{
	if (index < 0 || index >= _size)
	{
		throw gcnew Exception("Out of range.");
	}
	array<double> ^ result = gcnew array<double>(_size);

	for (int j = 0; j < _size; j++)
	{
		result[j] = _mat->at(index)[j];
	}
	return result;
}