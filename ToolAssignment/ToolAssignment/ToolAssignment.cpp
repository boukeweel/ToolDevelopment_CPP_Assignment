// ToolAssignment.cpp : Defines the entry point for the application.
//

#include "ToolAssignment.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "JsonToObjConverter.h"

int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <Input_fileName + path>  <Output_fileName> <OutPut_Filepath>" << std::endl;
		return 1;
	}

	std::string fileName = argv[1];
	std::string outputFilename = argv[2];
	std::string outputPath = argv[3];

	std::ifstream jsonFile(fileName);
	if (!jsonFile.is_open()) {
		std::cerr << "Error: Unable to open file " << fileName << std::endl;
		return 1;
	}

	nlohmann::json jsonData;
	try
	{
		jsonData = nlohmann::json::parse(jsonFile);
	}
	catch (nlohmann::json::parse_error& e)
	{
		std::cerr << " error parsing json file " << e.what() << std::endl;
	}
	jsonFile.close();

	//do something with to output the file
	std::string fullOutputPath = outputPath + "/" + outputFilename + ".obj";

	std::ofstream outputFile(fullOutputPath);
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to open output file " << fullOutputPath << std::endl;
		return;
	}

	JsonToObjConverter converter;
	converter.JsonToObj(jsonData, outputFile);

	return 0;
}
