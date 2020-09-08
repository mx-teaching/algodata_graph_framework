add_library(adjacency_list STATIC graph.cpp map.cpp)
target_link_libraries (adjacency_list ${OpenCV_LIBS})
