add_library(Flatzone flatzone.cpp)
target_link_libraries(Flatzone PRIVATE Neighbors)
target_include_directories(Flatzone PRIVATE
        "${PROJECT_SOURCE_DIR}/lib/Neighbors"
)