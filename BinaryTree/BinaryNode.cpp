
class BinaryNode
{

	private:
		BinaryNode* child_one;
		BinaryNode* child_two;
		int value;
	public:
		BinaryNode(int);
		~BinaryNode();
		BinaryNode* get_child_one();
		BinaryNode* get_child_two();
		void set_child_one(BinaryNode *);
		void set_child_two(BinaryNode *);
		int get_value();
		void set_value(int);



};

BinaryNode::BinaryNode(int t_value)
{
	this->value = t_value;
	// point the two Nodes to null
	this->child_one = nullptr;
	this->child_two = nullptr;
}

BinaryNode::~BinaryNode()
{}

BinaryNode* BinaryNode::get_child_one() {return this->child_one;}

BinaryNode* BinaryNode::get_child_two() {return this->child_two;}

void BinaryNode::set_child_one(BinaryNode *t_ptr) {this->child_one = t_ptr;}

void BinaryNode::set_child_two(BinaryNode *t_ptr) {this->child_two = t_ptr;}

int BinaryNode::get_value() {return this->value;}

void BinaryNode::set_value(int t_value) {this->value = t_value;}
