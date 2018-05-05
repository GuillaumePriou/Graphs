#include "Graph.h"

#include <iostream>
#include <cstdlib>

using namespace std ;

Graph::Graph(unsigned short nodes_number, double density, short available_colors_number) : m_nodes_number(nodes_number), m_density(density), m_available_colors_number(available_colors_number)
{

    // Create the nodes
    for (short i=0; i<nodes_number ; i++)
        m_nodes_list.push_back(Node(nodes_number, available_colors_number));

    // Create line between nodes
    short lines_nb = m_density*m_nodes_number*(m_nodes_number-1)/2; // Calculate the number of lines between nodes according to graph density

    cout << "Number of lines = " << lines_nb << endl ;

    short start_node, end_node ;

    // Create lines between nodes
    for (short line=0; line<lines_nb ; line++)
    {
        //cout << "Arrete n°" << i << " :" << endl;
        do
        {
            start_node = std::rand()%nodes_number;
            end_node   = rand()%nodes_number;
        } while (   start_node == end_node // No loopback accepted
                 || m_nodes_list[start_node].is_connected_to(end_node) != 0  // and the line should not already exist
                 );

        m_nodes_list[start_node].add_line_to(end_node) ;
        m_nodes_list[end_node].add_line_to(start_node) ;
    }
}

Graph::~Graph()
{
    //dtor
}

void Graph::print()
{
    for (unsigned short i=0; i<m_nodes_number; i++)
    {
        cout << "node " << i << " : ";
        m_nodes_list[i].print();
        cout << endl;
    }

}
