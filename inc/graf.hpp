#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>

class graph
{
protected:
    int num_vertices, num_edges, num_start;

public:
    graph(){};
    explicit graph(int ver, int edg, int start)
    {
        this->num_vertices = ver;
        this->num_edges = edg;
        this->num_start = start;
    };
    virtual ~graph(){};
    int ret_vert() { return num_vertices; };
    int ret_edg() { return num_edges; };
    int ret_start() { return num_start; };
    virtual const int read_file(const char *nazwa) = 0;
    virtual const int print() = 0;
    virtual const int dijkstra() = 0;
};