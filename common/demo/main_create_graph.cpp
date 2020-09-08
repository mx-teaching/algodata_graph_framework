#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
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
        maze_source.getMat() = cv::imread(map_name, cv::IMREAD_GRAYSCALE);   // Read the file

        if(! maze_source.getMat().data )                              // Check for invalid input
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
    
    adjacency_list::Map maze_destination(maze_source.getMat().cols, maze_source.getMat().rows, true);
    maze_destination.create_map_from_vertices(vertices);  
    maze_destination.draw_path(vertices, cv::Vec3b(255,0,0));
    
    cv::namedWindow( "shows graph and path if it exists", cv::WINDOW_AUTOSIZE );
    cv::imshow( "shows graph and path if it exists", maze_destination.getMat() ); 
    cv::waitKey(0);
    return 0;
}
