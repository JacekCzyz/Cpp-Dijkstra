#pragma once
#include <memory>
#include <cstdlib>
#include "graf.hpp"

struct edge
{
    int from, to, weight;
};

struct node
{
    int num, weight;
    struct node *next;
};

class list : public graph
{
    node *lists(int dest, int weig, node *head) // wskaźnik na tablicę wskaźników, wskazujących na 3-elementowe tablice(krawędzi)->[od, do, waga]
    {
        node *nnode = new node;
        nnode->num = dest;
        nnode->weight = weig;
        nnode->next = head;
        return nnode;
    }

public:
    node **head;

    list() : graph(){};
    explicit list(int vert, int edg, int start) : graph(vert, edg, start){};

    // explicit list(int vert, int edg, edge edges[]) : graph(vert, edg)
    // {
    //     head=new node*[num_vertices];
    //     for(int i=0; i<num_vertices; i++)
    //     {
    //         head[i]=nullptr;    //inicjuje 'heady' dla wsyzstkich wierzchołków
    //     }
    //     for(int i=0; i<num_edges; i++)
    //     {
    //         int src=edges[i].from;
    //         int dest=edges[i].to;
    //         int wigh=edges[i].weight;

    //         node* newnode=lists(dest, wigh, head[src]);
    //         head[src]=newnode;
    //     }
    // };
    virtual ~list(){};
    const int read_file(const char *nazwa) override;
    const int print() override;
    const int dijkstra() override;
};
