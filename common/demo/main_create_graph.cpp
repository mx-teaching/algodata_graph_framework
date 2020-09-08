#include <iostream>

#include "adjacency_list/map.h"


int main( int argc, char** argv )
{
    if( argc != 2)
    {
        std::cout <<" Usage: " << argv[0] << " file" << std::endl;
        return -1;
    }

    std::string map_name = argv[1];
    adjacency_list::Map maze_source;
    { 
        if(! maze_source.init(map_name) )                              // Check for invalid input
        {
            std::cout <<  "Could not open or find the maze image" << std::endl ;
            return -1;
        }

        
        adjacency_list::GraphPtr vertices( new std::vector<adjacency_list::VertexPtr>);
        maze_source.create_graph(vertices); 
        
        adjacency_list::write_vertices(vertices, adjacency_list::getVerticesFilename(map_name));
        adjacency_list::write_edges(vertices, adjacency_list::getEdgesFilename(map_name));
    }
    
    adjacency_list::GraphPtr vertices( new std::vector<adjacency_list::VertexPtr>);
    adjacency_list::read_vertices(adjacency_list::getVerticesFilename(map_name), vertices);
    adjacency_list::read_edges(adjacency_list::getPathFilename(map_name), vertices);
    
    adjacency_list::Map maze_destination;
    maze_destination.init(maze_source.cols(), maze_source.rows());
    maze_destination.create_map_from_vertices(vertices);  
    maze_destination.draw_path(vertices, cv::Vec3b(255,0,0));
    
    maze_destination.drawData();
    maze_destination.show();
    return 0;
}
