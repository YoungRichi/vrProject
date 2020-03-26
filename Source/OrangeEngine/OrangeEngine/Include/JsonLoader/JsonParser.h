#pragma once
#include "json.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;
class JsonParser
{
public:
	JsonParser();
	~JsonParser();
};

