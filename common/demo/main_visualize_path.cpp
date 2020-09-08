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
    maze_source.init(map_name);

    if(! maze_source.init(map_name) )    {
        std::cout <<  "Could not open or find the maze image" << std::endl ;
        return -1;
    }


    adjacency_list::GraphPtr vertices( new std::vector<adjacency_list::VertexPtr>);
    adjacency_list::read_vertices(adjacency_list::getVerticesFilename(map_name), vertices);
    adjacency_list::read_edges(adjacency_list::getPathFilename(map_name), vertices);
    maze_source.draw_path(vertices, cv::Vec3b(255,0,0), 4);

    maze_source.drawPic("Map with path");
    maze_source.writePic(adjacency_list::getPathMapFilename(map_name));
    maze_source.show();
    return 0;
}
