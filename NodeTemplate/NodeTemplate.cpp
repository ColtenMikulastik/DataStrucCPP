#include<iostream>
using namespace std;

template <typename T>

class NodeTemplate 
{
public:
    T data;
    NodeTemplate<T>** children;
    int numChildren;
    int capacity;

    NodeTemplate(T value, int initialCapacity = 10)
    {
        data = value;
        numChildren = 0;
        capacity = initialCapacity;
        // creates a array of pointers on the heap
        children = new NodeTemplate<T>*[capacity];
    }

    // destructor - deletes all of its child nodes, and array that holds them
    ~NodeTemplate()
    {
        // loops through the array to delete nodes in the indexs
        for(int i = 0; i < numChildren; i++){
            delete children[i];
        }
        // deletes the array itself
        delete[] children;
    }

    // adding a child node to the array of children, automatically resizing the array if needed.
    void addChild(NodeTemplate<T>* child)
    {
        // are the number of connected nodes at capacity
        if(numChildren == capacity)
        {
            // multipying capacity by two
            capacity *= 2;
            // creating a new array to store pointers
            NodeTemplate<T>** temp = new NodeTemplate<T>*[capacity];
            // loop through the array, and deep copy pointers
            // (don't delete old ones so that they don't become unallocated)
            for(int i = 0; i < numChildren; i++)
            {
                temp[i] = children[i];
            }
            delete[] children;
            children = temp;
        }
        // add argument node
        children[numChildren] = child;
        numChildren++;
    }

    NodeTemplate<T>** getChildren()
    {
        return children;
    }

    int getNumChildren()
    {
        return numChildren;
    }

    T getData()
    {
        return data;
    }
};

int main(){
    
    NodeTemplate<double>* root = new NodeTemplate<double>(1.2);
    NodeTemplate<double>* child1 = new NodeTemplate<double>(2.3);
    NodeTemplate<double>* child2 = new NodeTemplate<double>(3.4);

    root->addChild(child1);
    root->addChild(child2);

    NodeTemplate<double>* grandchild1 = new NodeTemplate<double>(4.7);
    NodeTemplate<double>* grandchild2 = new NodeTemplate<double>(5.6);
    child1->addChild(grandchild1);
    child1->addChild(grandchild2);

    cout << "Root data: " << root->getData() << endl;
    cout << "Root has " << root->getNumChildren() << " children\n";
    NodeTemplate<double>** rootChildren = root->getChildren();
    for(int i = 0; i < root->getNumChildren(); i++)
    {
        cout << "Child " << i + 1 << " data: " << rootChildren[i]->getData() << "\n";
    }

    cout << "\n";

    cout << "Child 1 data: " << child1->getData() << endl;
    cout << "Child 1 has " << child1->getNumChildren() << " children\n";
    NodeTemplate<double>** child1Children = child1->getChildren();
    for(int i = 0; i < child1->getNumChildren(); i++)
    {
        cout << "Grandchild " << i + 1 << " data: " << child1Children[i]->getData() << "\n";
    }

    delete root; // cleaning the memory

    return 0;
}
