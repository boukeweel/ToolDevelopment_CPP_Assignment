cmake_minimum_required (VERSION 3.16)

project ("JsonToObjConverter" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
	json
	GIT_REPOSITORY "https://github.com/nlohmann/json.git"
	GIT_TAG v3.11.3 #version
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(json)
# Include sub-projects.
add_subdirectory ("JsonToObjConverterCmd")
add_subdirectory("JsonToObjLib")
#add_subdirectory("jsonToObjForm")

