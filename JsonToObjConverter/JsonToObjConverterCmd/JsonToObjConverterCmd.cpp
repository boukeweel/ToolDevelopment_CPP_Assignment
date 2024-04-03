// JsonToObjConverter.cpp : Defines the entry point for the application.
//
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include "JsonToObjLib.h"


using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <Input_fileName + path>  <Output_fileName> <OutPut_Filepath>" << "\n";
		return 1;
	}

	std::string fileName = argv[1];
	std::string outputFilename = argv[2];
	std::string outputPath = argv[3];

	JsonToObjLib lib;
	if(!lib.isJSONFile(fileName))
	{
		std::cout << "The file is not a JSON file." << "\n";
		return 1;
	}

	std::ifstream jsonFile(fileName);
	if (!jsonFile.is_open()) {
		std::cerr << "Error: Unable to open file " << fileName << "\n";
		return 1;
	}

	nlohmann::json jsonData{ lib.ParseJsonData(jsonFile) };
	jsonFile.close();

	std::string fullOutputPath = outputPath + "/" + outputFilename + ".obj";

	std::ofstream outputFile(fullOutputPath);
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to open output file " << fullOutputPath << "\n";
		return 1;
	}

	lib.CreateObj(jsonData, outputFile);
	
	std::cout << "Created the obj " << outputFilename << " in file path " << outputPath << "\n";
	
	outputFile.close();
	return 0;
}
