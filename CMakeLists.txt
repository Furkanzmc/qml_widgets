cmake_minimum_required(VERSION 3.16)
project(
  qml_widgets
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_EXAMPLES "Build examples." OFF)

if(NOT DEFINED PLUGIN_INSTALL_DIR)
  set(PLUGIN_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/qml_widgets")
endif()

find_package(
  QT NAMES Qt6 Qt5
  COMPONENTS Core Quick Widgets
  REQUIRED)

find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS Core Quick Widgets
  REQUIRED)

message("[qml_widgets] Found Qt version ${QT_VERSION}")

set(PLUGIN_DIR "${PLUGIN_INSTALL_DIR}/qml/Qml/Widgets")

message("[qml_widgets] Installing plugin to '${PLUGIN_INSTALL_DIR}'")

set(source_files
    src/ZWidget.cpp
    src/ZLayouts.cpp
    src/ZGroupBox.cpp
    src/ZInputDialog.cpp
    src/ZMenuBar.cpp
    src/ZMainWindow.cpp
    src/ZComboBox.cpp
    src/ZListModel.cpp
    src/ZPalette.cpp
    src/plugin.cpp)

qt_add_qml_module(
  qml_widgets
  OUTPUT_DIRECTORY
  qml/Qml/Widgets
  VERSION
  1.0
  URI
  "Qml.Widgets"
  SOURCES
  ${source_files}
  NO_GENERATE_PLUGIN_SOURCE
  CLASS_NAME
  QmlWidgetsPlugin
  PLUGIN_TARGET
  qml_widgets)

target_compile_definitions(
  qml_widgets
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(
  qml_widgets PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
                      Qt${QT_VERSION_MAJOR}::Widgets)

include_directories(${Qt${QT_VERSION_MAJOR}Quick_PRIVATE_INCLUDE_DIRS})
include_directories(./src)

install(
  TARGETS qml_widgets
  RUNTIME DESTINATION "${PLUGIN_DIR}"
  BUNDLE DESTINATION "${PLUGIN_DIR}"
  LIBRARY DESTINATION "${PLUGIN_DIR}")

if(BUILD_EXAMPLES)
  message("[qml_widgets] Building examples.")
  add_subdirectory(examples/)
endif()
