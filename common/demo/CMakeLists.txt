add_executable(demo_opencv main_demo_opencv.cpp)
target_link_libraries (demo_opencv ${OpenCV_LIBS})

add_executable(create_graph main_create_graph.cpp)
target_link_libraries (create_graph ${OpenCV_LIBS} adjacency_list)

add_executable(visualize_path main_visualize_path.cpp)
target_link_libraries (visualize_path ${OpenCV_LIBS} adjacency_list)
