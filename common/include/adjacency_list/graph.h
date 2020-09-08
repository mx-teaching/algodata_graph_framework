/**
 * @author    Markus Bader
 * @date      2020-09-06
 * Classes to manage the graph
**/

#ifndef ADJAZENCYLIST_GRAPH_H
#define ADJAZENCYLIST_GRAPH_H

#include <vector>
#include <memory>
#include <string>

namespace adjacency_list
{
class Vertex;
typedef std::shared_ptr<Vertex> VertexPtr;
typedef std::shared_ptr<const Vertex> VertexConstPtr;
class Edge;
typedef std::shared_ptr<Edge> EdgePtr;
typedef std::shared_ptr<const Edge> EdgeConstPtr;

/**
 * Vertex on a graph
 **/
class Vertex
{
public:
    Vertex(unsigned long id)  : id(id) {};
    Vertex() {};
    unsigned long id;                /// id
    std::vector<EdgePtr> edges;      /// edges
    double value;                    /// value entry if the vertex is realted to a map
    EdgePtr path;                    /// if a path was found this edge can be used for backdracking or visualization
    bool visited;                    /// flags which can be used by algorithms
    int column;                      /// x
    int row;                         /// y
    std::string label;               /// label
    static VertexPtr createPtr() {
        return VertexPtr(new Vertex());
    }
    static VertexPtr createPtr(unsigned long id) {
        return VertexPtr(new Vertex(id));
    }
};

/**
 * Edge to connect to vertices
 **/
class Edge
{
public:
    unsigned long id;
    double weight;
    VertexPtr src;
    VertexPtr des;
    static EdgePtr createPtr() {
        return EdgePtr(new Edge);
    }
};


/**
 * Helper to reprecent a graph
 **/
typedef  std::shared_ptr<std::vector<adjacency_list::VertexPtr>> GraphPtr;

/**
 * write only the vertices into a file
 * @param graph
 * @param file_name
 **/
void write_vertices(const GraphPtr graph, const std::string &file_name);
/**
 * write only the edge into a file
 * @param graph
 * @param file_name
 * @pre write_vertices
 **/
void write_edges(const GraphPtr graph, const std::string &file_name);
/**
 * reads only the vertices from a file
 * @param file_name
 * @param graph
 * @pre read_vertices
 **/
void read_vertices(const std::string &file_name, GraphPtr graph);
/**
 * reads only the edge from a file
 * @param file_name
 * @param graph
 * @pre read_vertices
 **/
void read_edges(const std::string &file_name, GraphPtr graph);
/**
 * remove the edges in an existing graph
 * @param graph
 **/
void remove_edges(GraphPtr graph);

/**
 * generates a new file ending
 * @param file_name
 **/
std::string getVerticesFilename(const std::string file_name); 
/**
 * generates a new file ending
 * @param file_name
 **/
std::string getEdgesFilename(const std::string file_name);
/**
 * generates a new file ending
 * @param file_name
 **/ 
std::string getPathFilename(const std::string file_name); 
/**
 * generates a new file ending
 * @param file_name
 **/ 
std::string getPathMapFilename(const std::string file_name); 


};
std::ostream& operator<<(std::ostream& os, const adjacency_list::Vertex& vertex);
std::ostream& operator<<(std::ostream& os, const adjacency_list::Edge& edge);

#endif // ADJAZENCYLIST_GRAPH_H
