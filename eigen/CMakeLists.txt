cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 23)

set(PROJECT_NAME
    math_lib_benchmark
)

set(EXTERN_DIR
    ${CMAKE_SOURCE_DIR}/extern
)

set(OpenMP_CXX_FLAGS "/openmp")

project(${PROJECT_NAME})

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
