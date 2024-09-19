cmake_minimum_required(VERSION 3.15)
project(TextEditorCPP)

# Set the C++ standard to 23
set(CMAKE_CXX_STANDARD 23)

# Set wxWidgets installation path (use the path from brew --prefix)
set(wxWidgets_ROOT_DIR /opt/homebrew/opt/wxwidgets)

# Find the wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include the wxWidgets use file
include(${wxWidgets_USE_FILE})

# Add the source files
add_executable(TextEditorCPP WIN32 MACOSX_BUNDLE main.cpp)

# Link the wxWidgets libraries
target_link_libraries(TextEditorCPP ${wxWidgets_LIBRARIES})
