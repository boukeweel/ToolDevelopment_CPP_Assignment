// ToolAssignment.cpp : Defines the entry point for the application.
//

#include "ToolAssignment.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void JsonToObj(const nlohmann::json& jsonData, const std::string& filename)
{
	//this code does not work but it generates a obj file soooooo its something


	std::ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "Error: Unable to open output file " << filename << std::endl;
		return;
	}


	int vertexIndex = 1;
	for (const auto& layer : jsonData) {
		outputFile << "# Layer: " << layer["layer"] << std::endl;
		for (const auto& position : layer["positions"]) {
			outputFile << "v " << position[0] << " " << position[1] << " " << position[2] << std::endl;
			++vertexIndex;
		}
	}

	// Write faces (assuming each group of vertices forms a quad)
	int numVerticesPerLayer = vertexIndex - 1;
	int faceIndex = 1;
	for (int i = 0; i < jsonData.size(); ++i) {
		outputFile << "# Faces for Layer: " << jsonData[i]["layer"] << std::endl;
		for (int j = 0; j < jsonData[i]["positions"].size() - 1; j += 2) {
			outputFile << "f ";
			outputFile << faceIndex << " " << faceIndex + 1 << " " << faceIndex + numVerticesPerLayer + 1 << " " << faceIndex + numVerticesPerLayer << std::endl;
			faceIndex++;
		}
		faceIndex++; // Skip to next quad
	}
}

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

	JsonToObj(jsonData, fullOutputPath);

	return 0;
}
