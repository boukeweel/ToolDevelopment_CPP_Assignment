cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED Core)
find_package(Qt6 REQUIRED Gui)
find_package(Qt6 REQUIRED Widgets)

qt_add_executable(JsonToObjForm
    JsonToObjForm.cpp
    main.cpp
    JsonToObjForm.h
    jsontoobjform.ui

)


set_target_properties(JsonToObjForm PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(JsonToObjForm PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

target_link_libraries(JsonToObjForm PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#target_link_libraries(JsonToObjForm PRIVATE ObjLib)


#install(TARGETS ObjViewerForm DESTINATION bin)
