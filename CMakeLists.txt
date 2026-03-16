cmake_minimum_required(VERSION 4.1.1)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(2 LANGUAGES CXX)

add_executable(2
    main.cpp
    repository.h
    entity.h
    controller.h
    #math.cpp
)

set(MODULE_INTERFACE_FILES
    #${MODULE_LIB_DIR1}/utils.cppm
    #math.cppm
)

source_group("Module Interfaces" FILES ${MODULE_INTERFACE_FILES})
target_sources(2 PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS
    #${MODULE_LIB_DIR1}
    ${CMAKE_CURRENT_SOURCE_DIR}
    FILES ${MODULE_INTERFACE_FILES}
)

target_compile_features(2 PRIVATE cxx_std_23)

#
target_link_libraries(2 PRIVATE pqxx)
