#pragma once
#include <string>
#include <nlohmann/json.hpp>

class JsonToObjConverter
{
public:
	void JsonToObj(const nlohmann::json& jsonData, std::ofstream& outputFile);
};
