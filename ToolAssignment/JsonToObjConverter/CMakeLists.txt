add_library(JsonToObjConverter STATIC "JsonToObjConverter.cpp")
target_link_libraries(JsonToObjConverter PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(JsonToObjConverter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")