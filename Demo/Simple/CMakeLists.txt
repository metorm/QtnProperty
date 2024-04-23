cmake_minimum_required(VERSION 3.18)

project(QtnPropertyDemoSimple)

# if you are writing a regular project, simply remove the if()/endif() lines (but keep the inside lines)
if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    find_package(Qt5 REQUIRED COMPONENTS Core Widgets LinguistTools)
    find_package(QtnProperty REQUIRED)
endif()

set(DemoSimple_SRC main.cpp)

add_executable(DemoSimple ${DemoSimple_SRC})
target_link_libraries(DemoSimple PRIVATE Qt::Core Qt::Widgets)
if(PROJECT_IS_TOP_LEVEL)
    target_link_libraries(DemoSimple PRIVATE QtnProperty::QtnProperty)
else()
    target_link_libraries(DemoSimple PRIVATE QtnProperty)
endif()

add_custom_command(TARGET DemoSimple POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:DemoSimple> $<TARGET_FILE_DIR:DemoSimple>
                COMMAND_EXPAND_LISTS)

get_target_property(qmake_exec_filepath Qt5::qmake IMPORTED_LOCATION)
message(STATUS "QMake path: ${qmake_exec_filepath}")
get_filename_component(qt_exec_bin_dir "${qmake_exec_filepath}" DIRECTORY)
find_program(windeployqt_exec_filepath windeployqt HINTS "${qt_exec_bin_dir}")
message(STATUS "windeployqt path: ${windeployqt_exec_filepath}")

add_custom_command(TARGET DemoSimple POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
        env PATH="${qt_exec_bin_dir}"
        "${windeployqt_exec_filepath}" "--no-compiler-runtime" "$<TARGET_FILE:DemoSimple>"
        COMMENT "Running windeployqt..."
        )