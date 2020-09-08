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
    bool init(const std::string &file_name);
    bool init(int columns, int rows);
    void create_graph(GraphPtr vertices);
    void create_map_from_vertices(const GraphPtr vertices);
    void draw_path(const GraphPtr vertices, cv::Vec3b color, int thickness = 1);
    void drawData(const std::string &titel = "Map data");
    void drawPic(const std::string &titel = "Map picture");
    void writePic(const std::string &file_name);
    void show();
    int rows() const;
    int cols() const;
private:
    size_t index(int row, int col);
    cv::Mat data;
    cv::Mat pic;
};

};

#endif // ADJAZENCYLIST_MAP_H
