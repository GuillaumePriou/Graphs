#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"


class Graph
{
    public:
        Graph(unsigned short nodes_number, double density, short available_colors_number);
        virtual ~Graph();

        void print () ;

    protected:

    private:
        unsigned short m_nodes_number ;
        double m_density ;
        short m_available_colors_number ;
        std::vector<Node> m_nodes_list ;
};

#endif // GRAPH_H
