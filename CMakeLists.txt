cmake_minimum_required(VERSION 3.10)
project(GeneticPRM)

# Options
set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Path to lib folder")
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src CACHE PATH "Path to source folder")
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test CACHE PATH "Path to source folder")

add_definitions("-D_DISABLE_EXTENDED_ALIGNED_STORAGE")
include_directories(inc)
add_subdirectory(src)
add_subdirectory(tests)  # Agregar la carpeta 'test'

file(GLOB TEST_SOURCES "tests/*.cpp")  # Obtener todos los archivos fuente .cpp en 'test'
file(GLOB SOURCES "src/*.cpp")
foreach(TEST_SOURCE ${TEST_SOURCES})
    # Obtiene el nombre base del archivo sin la extensión
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    # Crea el ejecutable correspondiente
    add_executable(${TEST_NAME} ${TEST_SOURCE} ${SOURCES})
    
endforeach(TEST_SOURCE)
file(GLOB SOURCES "src/*.cpp")




