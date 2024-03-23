add_library(Closing closing.cpp)
target_link_libraries(Closing PRIVATE Erosion Dilation)
target_include_directories(Closing PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/Erosion"
        "${PROJECT_SOURCE_DIR}/lib/Dilation"
)