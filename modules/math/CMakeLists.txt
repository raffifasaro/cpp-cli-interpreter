add_library(math STATIC eval_math.cpp)

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)
