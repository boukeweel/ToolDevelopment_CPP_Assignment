#include "JsonToObjConverter.h"

#include <iostream>
#include <fstream>

void JsonToObjConverter::JsonToObj(const nlohmann::json& jsonData, std::ofstream& outputFile)
{
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
