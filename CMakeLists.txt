cmake_minimum_required(VERSION 3.10)
project(Image_Processing)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set compiler flags
set(CMAKE_CXX_FLAGS "-O2 -Wall -Werror -Wno-unused")

# Set the output folder where your program will be created
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Link OpenCV library
link_libraries(${OpenCV_LIBS})

# Libraries
add_subdirectory(lib/Erosion)
add_subdirectory(lib/Dilation)
add_subdirectory(lib/Opening)
add_subdirectory(lib/Closing)
add_subdirectory(lib/Neighbors)
add_subdirectory(lib/Flatzone)

# Exercise 1
add_executable(example_opencv_1 src/exercise1/example_opencv_1.cpp)

# Exercise 2
## Exercise 2a
add_executable(exercise_02a_thresh src/exercise2/exercise_02a_thresh.cpp)

## Exercise 2b
add_executable(exercise_02b_compare src/exercise2/exercise_02b_compare.cpp)

## Exercise 2c
add_executable(exercise_02c_inf src/exercise2/exercise_02c_inf.cpp)
add_executable(exercise_02c_sup src/exercise2/exercise_02c_sup.cpp)

# Exercise 3
## Exercise 3a
add_executable(exercise_03a_erosion src/exercise3/exercise_03a_erosion.cpp)
target_link_libraries(exercise_03a_erosion PUBLIC Erosion)
target_include_directories(exercise_03a_erosion PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Erosion"
)

## Exercise 3b
add_executable(exercise_03b_dilation src/exercise3/exercise_03b_dilation.cpp)
target_link_libraries(exercise_03b_dilation PUBLIC Dilation)
target_include_directories(exercise_03b_dilation PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Dilation"
)

# Exercise 4
## Exercise 4a
add_executable(exercise_04a_opening src/exercise4/exercise_04a_opening.cpp)
target_link_libraries(exercise_04a_opening PUBLIC Opening)
target_include_directories(exercise_04a_opening PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Opening"
)

## Exercise 4b
add_executable(exercise_04b_closing src/exercise4/exercise_04b_closing.cpp)
target_link_libraries(exercise_04b_closing PUBLIC Closing)
target_include_directories(exercise_04b_closing PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Closing"
)

# Exercise 6
## Exercise 6a
add_executable(exercise_06a_closing_opening src/exercise6/exercise_06a_closing_opening.cpp)
target_link_libraries(exercise_06a_closing_opening PUBLIC Closing Opening)
target_include_directories(exercise_06a_closing_opening PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Closing"
        "${PROJECT_SOURCE_DIR}/lib/Opening"
)

## Exercise 6b
add_executable(exercise_06b_opening_closing src/exercise6/exercise_06b_opening_closing.cpp)
target_link_libraries(exercise_06b_opening_closing PUBLIC Closing Opening)
target_include_directories(exercise_06b_opening_closing PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Closing"
        "${PROJECT_SOURCE_DIR}/lib/Opening"
)

# Exercise 11
add_executable(exercise_11a_flatzone src/exercise11/exercise_11a_flatzone.cpp)
target_link_libraries(exercise_11a_flatzone PUBLIC Flatzone)
target_include_directories(exercise_11a_flatzone PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

# Exercise 12
add_executable(exercise_12a_fznumber src/exercise12/exercise_12a_fznumber.cpp)
target_link_libraries(exercise_12a_fznumber PUBLIC Flatzone)
target_include_directories(exercise_12a_fznumber PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

# Exercise 13
## Exercise 13a
add_executable(exercise_13a_minimum src/exercise13/exercise_13a_minimum.cpp)
target_link_libraries(exercise_13a_minimum PUBLIC Flatzone)
target_include_directories(exercise_13a_minimum PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

## Exercise 13b
add_executable(exercise_13b_maximum src/exercise13/exercise_13b_maximum.cpp)
target_link_libraries(exercise_13b_maximum PUBLIC Flatzone)
target_include_directories(exercise_13b_maximum PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

## Exercise 13c
add_executable(exercise_13c_minima src/exercise13/exercise_13c_minima.cpp)
target_link_libraries(exercise_13c_minima PUBLIC Flatzone)
target_include_directories(exercise_13c_minima PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

## Exercise 13d
add_executable(exercise_13d_maxima src/exercise13/exercise_13d_maxima.cpp)
target_link_libraries(exercise_13d_maxima PUBLIC Flatzone)
target_include_directories(exercise_13d_maxima PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

# Segmentation 1
## Segmentation 1a
add_executable(practice_01a_boundary_extraction src/segmentation1/practice_01a_boundary_extraction.cpp)
target_link_libraries(practice_01a_boundary_extraction PUBLIC Erosion)
target_include_directories(practice_01a_boundary_extraction PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Erosion"
)

## Segmentation 1b
add_executable(practice_01b_grassfire_algorithm src/segmentation1/practice_01b_grassfire_algorithm.cpp)
target_link_libraries(practice_01b_grassfire_algorithm PUBLIC Neighbors)
target_include_directories(practice_01b_grassfire_algorithm PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Neighbors"
)

# Segmentation 2
## Segmentation 2a
add_executable(practice_02a_wheel_teeth_count src/segmentation2/practice_02a_wheel_teeth_count.cpp)
target_link_libraries(practice_02a_wheel_teeth_count PUBLIC Opening Flatzone)
target_include_directories(practice_02a_wheel_teeth_count PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Opening"
        "${PROJECT_SOURCE_DIR}/lib/Flatzone"
)

## Segmentation 2b
add_executable(practice_02b_coffee_grains src/segmentation2/practice_02b_coffee_grains.cpp)
target_link_libraries(practice_02b_coffee_grains PUBLIC Erosion Opening)
target_include_directories(practice_02b_coffee_grains PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib/Erosion"
        "${PROJECT_SOURCE_DIR}/lib/Opening"
)
