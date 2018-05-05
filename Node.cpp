#include "Node.h"

Node::Node(unsigned short nodes_numbers_in_graph, short color_nb) : m_lines(nodes_numbers_in_graph)
{
    m_color=rand()%color_nb ; // random color initialization
}

Node::~Node()
{
    //dtor
}

void Node::add_line_to (unsigned short new_neighboring_node)
{
    m_lines[new_neighboring_node] = 1 ;
}

bool Node::is_connected_to (short stranger_node)
{
    return m_lines[stranger_node];
}

void Node::print ()
{
    for (unsigned short i=0; i<m_lines.size() ; i++)
    {
        std::cout << " " << m_lines[i] ;
    }
}
