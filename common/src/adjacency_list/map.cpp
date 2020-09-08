/**
 * @author    Markus Bader
 * @date      2020-09-06
**/

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "adjacency_list/map.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace adjacency_list;

Map::Map() {
}

bool Map::init (int columns, int rows) {
    data = cv::Mat(columns, rows, CV_8UC1,  cv::Scalar(128));
    pic  = cv::Mat(columns, rows, CV_8UC3,  cv::Scalar(128,128,128));
    return  pic.data;

}
bool Map::init (const std::string &file_name) {
    data = cv::imread(file_name, cv::IMREAD_GRAYSCALE);
    pic = cv::imread(file_name, cv::IMREAD_COLOR);
    return  pic.data;
}
size_t Map::index(int row, int col) {
    return row * data.cols + col;
}
void Map::drawData(const std::string &titel) {
    cv::namedWindow( titel, cv::WINDOW_AUTOSIZE );
    cv::imshow( titel, data );
}
void Map::drawPic(const std::string &titel) {
    cv::namedWindow( titel, cv::WINDOW_AUTOSIZE );
    cv::imshow( titel, pic );
}
void Map::writePic(const std::string &file_name) {
    cv::imwrite(file_name, pic);
}

void Map::show() {
    cv::waitKey(0);
}
int Map::rows() const {
    return data.cols;
}
int Map::cols() const {
    return data.rows;
}

void Map::create_graph(GraphPtr vertices) {

    vertices->resize(data.rows * data.cols);

    unsigned long id = 0;
    for(int r = 0; r < data.rows; r++) {
        for(int c = 0; c < data.cols; c++) {
            adjacency_list::VertexPtr vertex( new adjacency_list::Vertex);
            size_t idx = index(r,c);
            vertex->id = idx;
            vertex->row = r, vertex->column = c;
            vertex->value = data.at<uint8_t>(r,c);
            vertices->at(idx) = vertex;
        }
    }
    for(int r = 0; r < data.rows; r++) {
        for(int c = 0; c < data.cols; c++) {
            size_t idx_src =  index(r,c);
            adjacency_list::VertexPtr vertex = vertices->at(idx_src);
            if(vertex->value > 0) {
                if(c > 0) {
                    size_t idx_des = index(r,c-1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if(c < data.cols-1) {
                    size_t idx_des = index(r,c+1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if(r > 0) {
                    size_t idx_des = index(r-1,c);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if(r < data.rows-1) {
                    size_t idx_des = index(r+1,c);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }

                /// * eight connector
                if((c > 0) & (r > 0)) {
                    size_t idx_des = index(r-1,c-1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1.4;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if((c > 0) & (r < data.rows-1)) {
                    size_t idx_des = index(r+1,c-1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1.4;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if((c < data.cols-1) & (r > 0)) {
                    size_t idx_des = index(r-1,c+1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1.4;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
                if((c < data.cols-1) & (r < data.rows-1)) {
                    size_t idx_des = index(r+1,c+1);
                    adjacency_list::EdgePtr edge( new adjacency_list::Edge);
                    edge->id = id++;
                    edge->weight = 1.4;
                    edge->src = vertices->at(idx_src);
                    edge->des = vertices->at(idx_des);
                    vertex->edges.push_back(edge);
                }
            }
        }
    }

}

void Map::create_map_from_vertices(const GraphPtr vertices) {
    for(const VertexPtr &vertex: *vertices) {
        data.at<uint8_t>(vertex->row, vertex->column) = vertex->value;
        pic.at<cv::Vec3b>(vertex->row, vertex->column) = cv::Vec3b(vertex->value, vertex->value, vertex->value);
    }

}

void Map::draw_path(const GraphPtr vertices, cv::Vec3b color, int thickness) {
    for(const VertexPtr &vertex: *vertices) {
        for(const EdgePtr &edge: vertex->edges) {
            const VertexPtr v0 = edge->src;
            const VertexPtr v1 = edge->des;
            cv::Point p0(v0->column, v0->row);
            cv::Point p1(v1->column, v1->row);
            cv::line(pic, p0, p1, color, thickness);
        }
    }
}
