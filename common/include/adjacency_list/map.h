/**
 * @author    Markus Bader
 * @date      2020-09-06
**/

#ifndef ADJAZENCYLIST_MAP_H
#define ADJAZENCYLIST_MAP_H

#include "adjacency_list/graph.h"
#include <opencv2/core/core.hpp>

namespace adjacency_list
{

/**
* Class to convert graph file to maps (pixelmaps) and back
**/
class Map
{
public:
    Map();
    Map(int rows, int columns, bool color = false);
    void create_graph(GraphPtr vertices);
    void create_map_from_vertices(const GraphPtr vertices);
    void draw_path(const GraphPtr vertices, cv::Vec3b color, int thickness = 1);
    
    cv::Mat &getMat() {
        return data;        
    }
    const cv::Mat &getMat() const {
        return data;        
    }
private:
    size_t index(int row, int col);
    cv::Mat data;
};

};

#endif // ADJAZENCYLIST_MAP_H
