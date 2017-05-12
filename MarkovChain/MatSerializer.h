#pragma once

#include "MarkovChainMatrix.h"

using namespace System::Xml::Serialization;
using namespace System::Web::Script::Serialization;

namespace MarkovChain {

	public ref class MatSerializer
	{
	private:
		JavaScriptSerializer^ serializer;
	public:
		MatSerializer();

		String^ SerializeToJSON(MarkovChainMatrix^ mat);
		MarkovChainMatrix^ DeserializeFromJSON(String^ json);
	};
}
