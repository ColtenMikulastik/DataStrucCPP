#include "BinaryNode.cpp"

class BinarySearchTree
{
	private:
		BinaryNode *root;
		void recersive_delete(BinaryNode *);
	public:
		BinarySearchTree(int);
		void append_node(int);
		~BinarySearchTree();
};

BinarySearchTree::BinarySearchTree(int t_value)
{
	this->root = new BinaryNode(t_value);
}

BinarySearchTree::~BinarySearchTree()
{
	BinaryNode *start = this->root;
	
	// recersively search for leaf
	recersive_delete(start);
}

void BinarySearchTree::recersive_delete(BinaryNode *leaf)
{
	// search down each leg calling function on each non empty leg
	if(leaf->get_child_one() != nullptr) { recersive_delete(leaf->get_child_one()); }
	else if(leaf->get_child_two() != nullptr) { recersive_delete(leaf->get_child_two()); }
	delete leaf;
}

void BinarySearchTree::append_node(int t_value)
{
	BinaryNode *place = this->root;
	
	// check value size to go left or right
	bool place_found = false;
	while(!place_found)
	{




	}
}
