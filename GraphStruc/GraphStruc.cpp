#include <iostream>


/* 
 * the plan is that we have a graph with nodes
 * the nodes need to be connected with pointers to other nodes
 * then we need to keep a record of what nodes are connected to each other
 */


class GraphStruc
{
	private:
		Node* nodes;
		int node_count;
		// this might need to be just a const size for now
		bool adj_matrix [1][1];

	public:
		GraphStruc()
		{
			std::cout << "Creating a Graph!" << std::endl;
			
		}
		~GraphStruc()
		{
			std::cout << "Removing Graph!" << std::endl;
		}
};

int main()
{
	GraphStruc test;
	return 0;
}


