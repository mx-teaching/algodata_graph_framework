/**
 * @author    Markus Bader
 * @date      2020-09-06
**/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <iomanip>
#include <iostream>
#include "adjacency_list/graph.h"

using namespace adjacency_list;

void adjacency_list::write_vertices(const GraphPtr graph, const std::string &file_name) {
    std::ofstream file (file_name);
    if (file.is_open())
    {
        file << std::setw(10) << "vertex.id"  << "; " << std::setw(10) << "label" << "; ";
        file << std::setw(10) << "value"      << "; ";
        file << std::setw(10) << "column"     << "; " << std::setw(10) << "row"  << std::endl;

        for(const adjacency_list::VertexPtr &vertex: *graph) {
            file << *vertex << std::endl;
        }
        file.close();
    }
}
void adjacency_list::write_edges(const GraphPtr graph, const std::string &file_name) {
    std::ofstream file (file_name);
    if (file.is_open())
    {
        file << std::setw(10)    << "edge.id"    << "; " << std::setw(10) << "weight" << "; ";
        file << std::setw(10)    << "src.id"     << "; " << std::setw(10) << "des.id" << std::endl;
        for(const adjacency_list::VertexPtr &vertex: *graph) {
            for(const adjacency_list::EdgePtr &edge: vertex->edges) {
                file << *edge << std::endl;
            }
        }
        file.close();
    }
}
void adjacency_list::read_vertices(const std::string &file_name, GraphPtr graph) {
    std::ifstream file (file_name);
    unsigned long count = 0;
    if (file.is_open())
    {
        std::string line;
        if ( std::getline (file,line))
        {
            std::cout << "treading first line of " << file_name << " as header" << std::endl;
            std::cout << line << std::endl;
        }
        while(std::getline (file, line)) {
            std::stringstream ss(line);
            VertexPtr vertex = Vertex::createPtr();
            std::string value;
            // id
            std::getline(ss, value, ';');
            vertex->id = std::stoul(value);
            // label
            std::getline(ss, vertex->label, ';');
            // value
            std::getline(ss, value, ';');
            vertex->value = std::stod(value);
            // column
            std::getline(ss, value, ';');
            vertex->column = std::stoi(value);
            // row
            std::getline(ss, value);
            vertex->row = std::stoi(value);
            graph->push_back(vertex);
            count++;
        }
        file.close();
        std::cout << count << " vertices read" << std::endl;
    } else {
        std::cout << "file " << file_name << " not ready!" << std::endl;
    }
}

void adjacency_list::remove_edges(GraphPtr graph) {
    for(const adjacency_list::VertexPtr &vertex: *graph) {
        vertex->edges.clear();
    }
}

void adjacency_list::read_edges(const std::string &file_name, GraphPtr graph) {
    std::ifstream file (file_name);
    std::map<unsigned long, VertexPtr> vertices;
    for(VertexPtr vertex: *graph) {
        vertices[vertex->id] = vertex;
    }
    unsigned long count = 0;
    if (file.is_open()) {
        std::string line;
        if ( std::getline (file, line))
        {
            std::cout << "treading first line of " << file_name << " as header" << std::endl;
            std::cout << line << std::endl;
        }
        while(std::getline (file, line)) {
            std::stringstream ss(line);

            EdgePtr edge = Edge::createPtr();
            std::string value;
            // id
            std::getline(ss, value, ';');
            edge->id = std::stoul(value);
            // weight
            std::getline(ss, value, ';');
            edge->weight = std::stod(value);
            // src.id
            std::getline(ss, value, ';');
            unsigned long src_id = std::stoul(value);
            // des.id
            std::getline(ss, value);
            unsigned long des_id = std::stoul(value);
            auto iterator_vertex_src = vertices.find(src_id);
            if (iterator_vertex_src != vertices.end()) edge->src = iterator_vertex_src->second;
            else std::cout << "vertex " << des_id << " does not exist!" << std::endl;
            auto iterator_vertex_des = vertices.find(des_id);
            if (iterator_vertex_des != vertices.end()) edge->des = iterator_vertex_des->second;
            else std::cout << "vertex " << des_id << " does not exist!" << std::endl;
            edge->src->edges.push_back(edge);
            count++;
        }
        file.close();
        std::cout << count << " edges read" << std::endl;
    } else {
        std::cout << "file " << file_name << " not ready!" << std::endl;
    }
}

std::string adjacency_list::getVerticesFilename(const std::string file_name) {
    size_t lastindex = file_name.find_last_of(".");
    std::string final_name = file_name.substr(0, lastindex) + ".vertices.cvs";
    return final_name;
}
std::string adjacency_list::getEdgesFilename(const std::string file_name) {
    size_t lastindex = file_name.find_last_of(".");
    std::string final_name = file_name.substr(0, lastindex) + ".edges.cvs";
    return final_name;
}
std::string adjacency_list::getPathFilename(const std::string file_name) {
    size_t lastindex = file_name.find_last_of(".");
    std::string final_name = file_name.substr(0, lastindex) + ".path.cvs";
    return final_name;
}

std::ostream& operator<<(std::ostream& os, const Vertex& vertex)
{
    os << std::setw(10) << vertex.id      << "; " << std::setw(10) << vertex.label << "; ";
    os << std::setw(10) << vertex.value   << "; ";
    os << std::setw(10) << vertex.column  << "; " << std::setw(10) << vertex.row;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Edge& edge)
{
    os << std::setw(10) << edge.id      << "; " << std::setw(10) << edge.weight << "; ";
    os << std::setw(10) << edge.src->id << "; " << std::setw(10) << edge.des->id;
    return os;
}
