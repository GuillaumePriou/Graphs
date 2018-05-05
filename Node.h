#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cstdlib>
#include <iostream>

class Node
{
    public:
        Node(unsigned short nodes_numbers_in_graph, short color);
        virtual ~Node();

        void add_line_to (unsigned short new_neighboring_node) ;
        bool is_connected_to (short stranger_node) ;
        void print () ;

    protected:

    private:
        /*
            Holds the color of this node :
            2 = blue
            1 = red
            3 = green
            ...
        */
        short m_color;

        /*
            Holds the connections between this node and any other node in graph :
            1 = a directed line go to the other node
            0 = no line go to the other node

            Example : line[0] = 1 means this node has a line going to node 0

        */
        std::vector<bool> m_lines ;
};

#endif // NODE_H
