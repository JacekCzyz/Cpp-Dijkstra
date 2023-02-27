#include "matrix.hpp"
#include "list.hpp"

int main()
{

    // list graf;
    matrix graf;
    graf.read_file("wej.txt");
    graf.print();
    std::cout << "asdasdasdasdsad" << std::endl;
    graf.dijkstra();
    return 0;
}