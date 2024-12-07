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
    model_loader.h model_loader.cpp
)

# 查找 OpenGL 和 GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# 链接库
target_link_libraries(chess 
    OpenGL::GL 
    OpenGL::GLU 
    GLUT::GLUT
)
