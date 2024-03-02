#include "BinaryNode.cpp"

class BinaryTree
{
	private:
		BinaryNode *da_tree;
	public:
		BinaryTree(int);
		~BinaryTree();
};

BinaryTree::BinaryTree(int t_value)
{
	// start by creating the first node
	this->da_tree = new BinaryNode(1);

	// fill out the tree with the nodes
	for(int i {2}; i <= t_value; i++)
	{
		// we are going to start with checking if 
		BinaryNode *which_node {this->da_tree};
		bool empty_node = false;
		do
		{
			// check if opening in the first node or second node
			if(which_node->get_child_one() == nullptr)
			{
				empty_node = true;
				which_node = which_node->get_child_one();
			}
			else if(which_node->get_child_two() == nullptr)
			{
				empty_node = true;
				which_node = which_node->get_child_two();
			}
			else 
			{
				// huh this is hard

			}
			
			
		}while (!(empty_node));

	}


	
}
