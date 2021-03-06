cmake_minimum_required(VERSION 2.8.4)
project(sample)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (NOT WIN32)
set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw)
endif (NOT WIN32)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
if (WIN32)
  include_directories("C:/GLFW/include" "C:/glm" "C:/glew/include")
  link_directories("C:/glew/lib/Release/x64" "C:/GLFW/lib-mingw" )
else (WIN32)
  find_package (glfw3 REQUIRED)
  find_package (GLM REQUIRED)
  find_package (GLEW REQUIRED STATIC)
endif (WIN32)
if (APPLE)
  include_directories(/usr/local/include)
  find_library(COCOA_LIBRARY Cocoa REQUIRED)
  find_library(IOKIT_LIBRARY IOKit REQUIRED)
  find_library(COREVID_LIBRARY CoreVideo REQUIRED)
endif (APPLE)

set(SOURCE_FILES main.cpp "My_Objects/Table Parts/Table_Top.cpp" "My_Objects/Table Parts/Table_Leg.cpp" "My_Objects/Table.cpp" "My_Objects/Table Parts/Table_Crossbar.cpp" "My_Objects/Table Parts/Table_Bottom_Bar.cpp" "My_Objects/Table Parts/Table_Wall.cpp"
"My_Objects/Window.cpp" "My_Objects/Window Parts/Window_Beam.cpp" "My_Objects/Window Parts/Window_Glass.cpp" "My_Objects/Computer Parts/Computer_Connector.cpp"
"My_Objects/AllComputer.cpp" "My_Objects/Computer Parts/compFrame.cpp" "My_Objects/Computer Parts/compFrame1.cpp" "My_Objects/Computer Parts/Computer.cpp" "My_Objects/Computer Parts/ComputerBack.cpp"
"My_Objects/Computer Parts/ComputerStand.cpp" "My_Objects/Computer Parts/Screen.cpp" "My_Objects/Keyboard Parts/Keys.cpp" "My_Objects/AllKeyboard.cpp" "My_Objects/Keyboard Parts/Keyboard.cpp")

## "sample" is the name of the executable
add_executable(sample ${SOURCE_FILES})
  target_link_libraries (sample
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          ${GLEW_LIBRARY}
          ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})
if (WIN32)
  target_link_libraries (sample
          ${OPENGL_LIBRARIES} glfw3 glew32s glu32 opengl32)
endif (WIN32)

if (UNIX)
  target_link_libraries (sample
          ${OPENGL_LIBRARIES}
          ${GLFW3_LIBRARY}
          ${GLEW_LIBRARY}
          Xxf86vm pthread Xrandr Xinerama Xi Xcursor)
endif (UNIX)