cmake_minimum_required(VERSION 3.10)
project(display_cloud)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -O3 -Wall -pthread")

include(FindPkgConfig)
find_package(PkgConfig)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)

EXECUTE_PROCESS(
  COMMAND pkg-config --variable=host_bins Qt5Core
  OUTPUT_VARIABLE Qt5BIN
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)
include_directories(${YAML_CPP_INCLUDEDIR})
list(APPEND ALL_TARGET_LIBRARIES ${YAML_CPP_LIBRARIES})

include(cmake/global_definition.cmake)

qt5_wrap_cpp(MOC_FILES include/mainwindow.h
  component/parse_data_form/parse_data_form.h
  component/viewer/pclview/pclview.cpp)

file(GLOB_RECURSE WIDGETS_SRCS "widgets/*.cpp")
file(GLOB_RECURSE PROCESS_SRCS "process/*.cpp")

# qt_widgets
add_executable(display_cloud
  src/main.cpp

  src/mainwindow.cpp

  component/parse_data_form/parse_data_form.cpp
  component/viewer/pclview/pclview.cpp

  ${WIDGETS_SRCS}

  ${PROCESS_SRCS}

  ${MOC_FILES}
)

target_link_libraries(display_cloud

  ${PCL_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${YAML_CPP_LIBRARIES}
  "libvtkGUISupportQt-7.1.so"
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::OpenGL)
