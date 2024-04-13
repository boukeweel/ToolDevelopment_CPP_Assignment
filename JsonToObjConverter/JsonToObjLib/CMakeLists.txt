add_library(JsonToObjLib STATIC "JsonToObjLib.cpp")

target_link_libraries(JsonToObjLib PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(JsonToObjLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


