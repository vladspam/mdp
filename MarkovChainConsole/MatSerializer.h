#pragma once

#include "Mat.h"

using namespace System::Xml::Serialization;
using namespace System::Web::Script::Serialization;

namespace MarkovChain {

	public ref class MatSerializer
	{
	private:
		JavaScriptSerializer^ serializer;
	public:
		MatSerializer();

		String^ SerializeToJSON(Mat^ mat);
		Mat^ DeserializeFromJSON(String^ json);
	};
}
