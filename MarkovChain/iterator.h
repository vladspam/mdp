#pragma once

#include "MarkovChainMatrix.h"
#include "IEnumerator.h"

using namespace MarkovChain;

ref struct iterator : IEnumerator {
	iterator(MarkovChainMatrix^ _mat) {
		mat = _mat;
		currentIndex = -1;
	}

	virtual bool MoveNext() {
		if (currentIndex < mat->Size - 1) {
			currentIndex++;
			return true;
		}
		return false;
	}

	property Object^ Current {
		virtual Object^ get() {

			return mat[currentIndex];
		}
	};

	virtual void Reset() {}
	~iterator() {}

	MarkovChainMatrix^ mat;
	int currentIndex;
};

