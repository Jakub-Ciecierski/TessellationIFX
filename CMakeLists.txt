cmake_minimum_required(VERSION 3.3)
set(PROJECT_NAME "Tessellation")
project(${PROJECT_NAME})

#---------------------------------
# MACROS
#---------------------------------

MACRO(FIND_INCLUDE_DIR return_list regex)
    FILE(GLOB_RECURSE new_list ${regex})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        string(REGEX MATCH ^.*/include dir ${file_path})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()


#---------------------------------
# COMPILE FLAGS
#---------------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#---------------------------------
# PROJECT
#---------------------------------

# INCLUDE AUTOMATIC SEARCH
FIND_INCLUDE_DIR(INC_DIRS ./include/*.h)
include_directories(${INC_DIRS} res/)

# SOURCES AUTOMATIC SEARCH
file(GLOB_RECURSE SRC_FILES src/*.cpp)
set(SOURCE_FILES )

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SRC_FILES} res)

add_custom_command(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res/shaders/
)

# COPY RESOURCES
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
)

#---------------------------------
# EXTERNALS LOCAL
#---------------------------------

#add_subdirectory(dependencies/assimp-3.1.1)
add_subdirectory(
        dependencies/glfw-3.1.2
        dependencies/glm)
add_subdirectory(dependencies/SOIL)


link_directories(dependencies/soil/lib)
include_directories(
        dependencies/glfw-3.1.2/include
        dependencies/glm/include
        dependencies/SOIL/src)

target_link_libraries(${PROJECT_NAME} glfw SOIL
        ${GLFW_LIBRARIES})

#---------------------------------
# EXTERNALS GLOBAL
#---------------------------------

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})
