cmake_minimum_required(VERSION 3.5)
set(CMAKE_GENERATOR "Ninja")
project("Learning_OpenGL" LANGUAGES CXX VERSION 0.02)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeMods")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
        ${INCLUDE_DIR}
	${INCLUDE_DIR}/windfall/}
	${OPENGL_INCLUDE_DIRS}
	${SDL2_INCLUDE_DIRS}
	${GLEW_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
)

set(SOURCES
	main.cpp
	src/windfall/Display.cpp
	src/windfall/Input.cpp
	src/windfall/Mesh.cpp
	src/windfall/Shader.cpp
	include/windfall/Display.h
	include/windfall/Input.h
	include/windfall/Mesh.h
	include/windfall/Scene.h
	include/windfall/SceneManager.h
	include/windfall/Shader.h
)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
	${OPENGL_LIBRARIES}
	${SDL2_LIBRARIES}
	${GLEW_LIBRARIES}
	${GLM_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)

