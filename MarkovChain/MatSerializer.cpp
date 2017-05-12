#include "stdafx.h"
#include "MatSerializer.h"


namespace MarkovChain {

	MatSerializer::MatSerializer()
	{
		serializer = gcnew JavaScriptSerializer();
	}

	String ^ MatSerializer::SerializeToJSON(MarkovChainMatrix ^ mat)
	{
		array<array<double>^>^ a = gcnew array<array<double>^>(mat->Size);
		for (int i = 0; i < a->Length; i++) {
			a[i] = mat[i];
		}		

		String^ result = serializer->Serialize(a);
		return result;
	}

	MarkovChainMatrix ^ MatSerializer::DeserializeFromJSON(String ^ json)
	{
		MarkovChainMatrix^ mat;
		array<array<double>^>^ data = serializer->Deserialize<array<array<double>^>^>(json);
		mat = gcnew MarkovChainMatrix(data);
		return mat;
	}
}