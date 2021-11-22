cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 23)

set(PROJECT_NAME
    math_lib_benchmark
)

set(EXTERN_DIR
    ${CMAKE_SOURCE_DIR}/extern
)

project(${PROJECT_NAME})

# OpenMP
FIND_PACKAGE(OpenMP)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_package(Eigen3 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix_multiply.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        "C:/Program Files (x86)/Intel/oneAPI/mkl/2021.4.0/include"
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        Eigen3::Eigen
        ${EXTERN_DIR}/mkl/mkl_core.lib
        ${EXTERN_DIR}/mkl/mkl_intel_lp64.lib
        ${EXTERN_DIR}/mkl/mkl_intel_thread.lib
        ${EXTERN_DIR}/mkl/libiomp5md.lib
)
