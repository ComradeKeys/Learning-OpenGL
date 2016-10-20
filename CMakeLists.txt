cmake_minimum_required(VERSION 3.1)
set(CMAKE_GENERATOR "Ninja")
project("Learning_OpenGL" LANGUAGES CXX VERSION 0.02)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeMods")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
	"${CMAKE_PROJECT_DIR}/src/src/windfall/" ## This filesystem structure is retarded
	${OPENGL_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
)

set(SOURCES
	main.cpp
	src/Display.cpp
	src/Input.cpp
	src/Mesh.cpp
	src/Shader.cpp
        ## You do not include your header file with your sources
)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	${OPENGL_LIBRARIES}
	${SDL2_LIBRARIES}
	${GLEW_LIBRARIES}
	${GLM_LIBRARIES}
)
