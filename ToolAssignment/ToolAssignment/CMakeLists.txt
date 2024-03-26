# CMakeList.txt : CMake project for ToolAssignment, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ToolAssignment "ToolAssignment.cpp" "ToolAssignment.h")
target_link_libraries(ToolAssignment PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ToolAssignment PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
