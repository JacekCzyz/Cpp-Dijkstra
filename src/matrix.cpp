#include "matrix.hpp"
const int INFINITY = 2147483000; // max integer

const int matrix::print()
{
    for (int i = 0; i < ret_vert(); i++)
    {
        for (int j = 0; j < ret_vert(); j++)
        {
            std::cout << neigh_mat[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

const int matrix::read_file(const char *nazwa)
{
    std::ifstream input(nazwa);
    if (!input.is_open())
    {
        std::cout << "file did not open" << std::endl;
    }
    int from, to, weight;
    input >> num_edges >> num_vertices >> num_start; // first line of text file
    neigh_mat = std::make_unique<std::unique_ptr<int[]>[]>(num_vertices);

    for (int j = 0; j < num_vertices; j++)
    {
        neigh_mat[j] = std::move(std::make_unique<int[]>(num_vertices));
        for (int k = 0; k < num_vertices; k++)
        {
            neigh_mat[j][k] = 0;
        }
    }
    for (int i = 0; i < num_edges; i++)
    {
        input >> from >> to >> weight;
        neigh_mat[from][to] = weight;
    }
    input.close();
    return 0;
}

const int matrix::dijkstra()
{
    int verts = num_vertices;
    // int edg = mgraph.ret_edg();
    int start = num_start;

    int *dist = new int(verts); // tablica z kosztami dojscia
    int *prev = new int(verts); // tablica z numerem poprzedniego wierzcholkiem

    bool *checked = new bool(verts); // czy wierzcholek sprawdzony

    // int cur_num;
    // int cur_weig;
    std::cout << start << std::endl;
    for (int i = 0; i < verts; i++)
    {
        if (i != start)
        {
            dist[i] = INFINITY;
            prev[i] = -1;
            checked[i] = false;
        }
        else
        {
            dist[i] = 0;
            prev[i] = -1;
            checked[i] = false;
        }
    }

    // print();

    for (int i = 0; i < verts; i++)
    {
        for (int j = 0; j < verts; j++)
        {
            if (neigh_mat[i][j] != 0)
            {
                if (checked[i] == false && dist[j] > dist[i] + neigh_mat[i][j])
                {
                    dist[j] = dist[i] + neigh_mat[i][j];
                    prev[j] = i;
                }
            }
        }
        checked[i] = true;
    }

    for (int i = 0; i < verts; i++)
    {
        std::cout << i << ": "
                  << "(" << dist[i] << ", " << prev[i] << ")" << std::endl; // jeszcze obczaić czy się kupska trzyma
    }

    return 0;
}