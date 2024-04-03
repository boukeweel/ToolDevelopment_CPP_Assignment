#pragma once
#include <nlohmann/json.hpp>


class JsonToObjLib
{
    struct vec3
    {
        float x, y, z;
    };

    struct Ivec4
    {
        int x, y, z, w;
    };

	struct Block
	{
		bool Opaque;
		std::string Layer;
		std::vector<vec3> position;
	};

    //these 2 I got from julian
    const std::vector<vec3> CUBE_BASE_VERTICES{
        { 0.5f,  0.5f, -0.5f},
        { 0.5f, -0.5f, -0.5f},
        { 0.5f,  0.5f,  0.5f},
        { 0.5f, -0.5f,  0.5f},
        {-0.5f,  0.5f, -0.5f},
        {-0.5f, -0.5f, -0.5f},
        {-0.5f,  0.5f,  0.5f},
        {-0.5f, -0.5f,  0.5f}
    };

    const std::vector<Ivec4> CUBE_BASE_FACES{
        {1, 5, 7, 3},
        {4, 3, 7, 8},
        {8, 7, 5, 6},
        {6, 2, 4, 8},
        {2, 1, 3, 4},
        {6, 5, 1, 2}
    };
public:
	JsonToObjLib() = default;
	~JsonToObjLib() = default;

	nlohmann::json ParseJsonData(std::ifstream& jsonFile);
    void CreateObj(const nlohmann::json& jsonData, std::ofstream& outFile);

	bool isJSONFile(std::string& fileName);
};

