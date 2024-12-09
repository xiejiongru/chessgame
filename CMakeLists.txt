cmake_minimum_required(VERSION 3.22)

# 项目信息
project(chess LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用现代 OpenGL
cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE "GLVND")

# 添加包含路径（当前文件夹）
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/glfw3" ${CMAKE_PREFIX_PATH})

# 设置 GLFW 的目录
set(GLFW_DIR "/usr/lib/x86_64-linux-gnu/cmake/glfw3")

# 查找 GLFW
find_package(GLFW REQUIRED PATHS ${GLFW_DIR})
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


# 添加可执行文件
add_executable(chess 
    main.cpp 
    chessboard.h chessboard.cpp
    piece.h piece.cpp
    pawn.h pawn.cpp
    rook.h rook.cpp
    bishop.h bishop.cpp
    knight.h knight.cpp
    king.h king.cpp
    queen.h queen.cpp
    game.h game.cpp
    camera.h camera.cpp
)

# 链接库
target_link_libraries(chess 
    OpenGL::GL 
    OpenGL::GLU 
    GLEW::GLEW 
    GLFW::GLFW 
    GLUT::GLUT
)
