#include "list.hpp"
const int INFINITY = 2147483000; // max integer

const int list::print()
{
    for (int i = 0; i < num_vertices; i++)
    {
        std::cout << i << ": ";
        node *ptr = head[i];
        if (ptr == nullptr)
        {
            std::cout << "---";
        }
        while (ptr != nullptr)
        {
            std::cout << "->"
                      << "(dest:" << ptr->num << ", weight:" << ptr->weight << ")";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    return 0;
}

const int list::read_file(const char *nazwa)
{
    std::ifstream input(nazwa);
    if (!input.is_open())
    {
        std::cout << "file did not open" << std::endl;
    }

    int from, to, weight;
    input >> num_edges >> num_vertices >> num_start; // first line of text file

    head = new node *[num_vertices];

    for (int i = 0; i < num_vertices; i++)
    {
        head[i] = nullptr; // inicjuje 'heady' dla wsyzstkich wierzchołków
    }
    for (int i = 0; i < num_edges; i++)
    {
        input >> from >> to >> weight;
        int src = from;
        int dest = to;
        int wigh = weight;

        node *newnode = lists(dest, wigh, head[src]);
        head[src] = newnode;
    }
    input.close();
    return 0;
}

void check(node *head, int *dist, int *prev, int i, bool *checked)
{
    int cur_num = head->num;
    int cur_weig = head->weight;

    std::cout << "CHECK I:" << i << " NUM:" << cur_num << " WEIG:" << cur_weig << " CHECKED?:" << checked[i] << std::endl;

    if (checked[i] == false && (dist[cur_num]) > (dist[i] + cur_weig))
    {
        dist[cur_num] = dist[i] + cur_weig;
        prev[cur_num] = i;
        // std::cout<<"dupa"<<i<<":"<<dist[cur_num]<<" "<<prev[cur_num] <<std::endl;
    }
    if (head->next != nullptr)
        check(head->next, dist, prev, i, checked);
    checked[i] = true;
}

const int list::dijkstra()
{
    int verts = num_vertices;
    // int edg = lgraph.ret_edg();
    int start = num_start;

    int *dist = new int(verts); // tablica z kosztami dojscia
    int *prev = new int(verts); // tablica z numerem poprzedniego wierzcholkiem

    bool *checked = new bool(verts); // czy wierzcholek sprawdzony

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

    // int cur_num;
    // int cur_weig;

    for (int i = 0; i < verts; i++)
    {
        std::cout << "sraie" << std::endl;
        check(head[i], dist, prev, i, checked);

        std::cout << "jajco:" << i << std::endl;
        for (int i = 0; i < verts; i++)
        {
            std::cout << i << ": "
                      << "(" << dist[i] << ", " << prev[i] << ")" << std::endl; // jeszcze obczaić czy się kupska trzyma
        }
    }
    return 0;
}