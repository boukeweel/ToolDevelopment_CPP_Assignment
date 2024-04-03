#include "JsonToObjLib.h"
#include <fstream>
#include <iostream>

nlohmann::json JsonToObjLib::ParseJsonData(std::ifstream& jsonFile)
{
	nlohmann::json jsonData;
	try
	{
		jsonData = nlohmann::json::parse(jsonFile);
	}
	catch (nlohmann::json::parse_error& e)
	{
		std::cerr << " error parsing json file " << e.what() << "\n";
	}

	return jsonData;
}

void JsonToObjLib::CreateObj(const nlohmann::json& jsonData, std::ofstream& outFile)
{

	//this code is made with julian's code on the side as a refrence
	//this is becuase I never worked with obj file's before and was not aware how to create one, that worked
	std::vector<Block> Blocks;
	Blocks.reserve(jsonData.size());

	for (const auto& data : jsonData)
	{
		Block block;
		block.Opaque = data["opaque"];
		block.Layer = data["layer"];

		for (const auto& position : data["positions"])
		{
			vec3 vector{ position[0],position[1],position[2] };
			block.position.emplace_back(vector);
		}

		Blocks.push_back(block);
	}

	std::string obj;

	int cubeIndex{ 0 };

	for (const auto& block : Blocks)
	{
		obj += "o " + block.Layer + "\n";

		for (const auto& position : block.position)
		{
			for (const auto& cubeBeseVertex : CUBE_BASE_VERTICES)
			{
				obj += "v " + std::to_string(position.x + cubeBeseVertex.x)
					+  ' '  + std::to_string(position.z + cubeBeseVertex.y)
					+  ' '  + std::to_string(position.y + cubeBeseVertex.z) + "\n";
			}
		}

		for (size_t i = 0; i < block.position.size(); ++i)
		{
			for (const auto& cubeBaseFace : CUBE_BASE_FACES)
			{
				obj += "f " + std::to_string(cubeIndex + cubeBaseFace.x)
					+  ' '  + std::to_string(cubeIndex + cubeBaseFace.y)
					+  ' '  + std::to_string(cubeIndex + cubeBaseFace.z)
					+  ' '  + std::to_string(cubeIndex + cubeBaseFace.w) + "\n";
			}
			cubeIndex += 8;
		}
	}

	outFile << obj;
}

bool JsonToObjLib::isJSONFile(std::string& fileName)
{
	const size_t dotPosition = fileName.find_last_of('.');
	if (dotPosition != std::string::npos) {
		const std::string extension = fileName.substr(dotPosition);
		return (extension == ".json");
	}
	return false;
}

