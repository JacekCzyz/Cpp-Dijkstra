#pragma once
#include "graf.hpp"
#include <memory>
#include <cstdlib>

class matrix : public graph
{
public:
    std::unique_ptr<std::unique_ptr<int[]>[]> neigh_mat; // wskaźnik na tablicę wzkaźników na tablicę intów. Dane typu int mówią o wadze krawędzi

    matrix() : graph(){};
    explicit matrix(int vert, int edg, int start) : graph(vert, edg, start){};
    virtual ~matrix(){};
    const int read_file(const char *nazwa) override;
    const int print() override;
    const int dijkstra() override;
};
