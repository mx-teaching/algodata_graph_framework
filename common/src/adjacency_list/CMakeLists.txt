add_library(adjacency_list SHARED graph.cpp map.cpp)
target_link_libraries (adjacency_list ${OpenCV_LIBS})
