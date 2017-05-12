#pragma once


public interface struct IEnumerator {
	bool MoveNext();
	property Object^ Current {
		Object^ get();
	}
	void Reset();
};