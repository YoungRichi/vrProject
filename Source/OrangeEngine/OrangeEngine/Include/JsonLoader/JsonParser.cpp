#include "../Unity/Unity.h"
#include "JsonParser.h"



JsonParser::JsonParser()
{
	json j;

	j["BigRich"] = { {"Toronto", "somewhere"}, {"streetNumber", 1} };
	j["Maksim"] = { {"Toronto", "elsewhere"}, {"streetNumber", 2} };
	j["Xian"] = { {"Toronto", "downthere"}, {"streetNumber", 3} };

	ofstream o("Orange.json");
	o << j << std::endl;

	std::ifstream i("Orange.json");
	json z;
	i >> z;

	cout << z << endl;
}


JsonParser::~JsonParser()
{
}
