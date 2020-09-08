include_directories(include)

if (WIN32)
    find_package( OpenCV REQUIRED PATHS ${PROJECT_SOURCE_DIR}/3rdParty/OpenCV)
endif (WIN32)
if (UNIX)
    find_package( OpenCV REQUIRED)
endif (UNIX)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(demo)


