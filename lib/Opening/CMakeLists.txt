add_library(Opening opening.cpp)
target_link_libraries(Opening PRIVATE Erosion Dilation)
target_include_directories(Opening PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/Erosion"
        "${PROJECT_SOURCE_DIR}/lib/Dilation"
)