#include<iostream>
using namespace std;

template <typename T>

class NodeTemplate {
public:
    T data;
    NodeTemplate<T>** children;
    int numChildren;
    int capacity;

    NodeTemplate(T value, int initialCapacity = 10){
        data = value;
        numChildren = 0;
        capacity = initialCapacity;
        children = new NodeTemplate<T>*[capacity];
    }

    // destructor - recursively deletes all of its child nodes
    ~NodeTemplate(){
        for(int i = 0; i < numChildren; i++){
            delete children[i];
        }
        delete[] children;
    }

    // adding a child node to the array of children, automatically resizing the array if needed.
    void addChild(NodeTemplate<T>* child){
        if(numChildren == capacity){
            capacity *= 2;
            NodeTemplate<T>** temp = new NodeTemplate<T>*[capacity];
            for(int i = 0; i < numChildren; i++){
                temp[i] = children[i];
            }
            delete[] children;
            children = temp;
        }
        children[numChildren] = child;
        numChildren++;
    }

    NodeTemplate<T>** getChildren(){
        return children;
    }

    int getNumChildren(){
        return numChildren;
    }

    T getData(){
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
    for(int i = 0; i < root->getNumChildren(); i++){
        cout << "Child " << i + 1 << " data: " << rootChildren[i]->getData() << "\n";
    }

    cout << "\n";

    cout << "Child 1 data: " << child1->getData() << endl;
    cout << "Child 1 has " << child1->getNumChildren() << " children\n";
    NodeTemplate<double>** child1Children = child1->getChildren();
    for(int i = 0; i < child1->getNumChildren(); i++){
        cout << "Grandchild " << i + 1 << " data: " << child1Children[i]->getData() << "\n";
    }

    delete root; // cleaning the memory

    return 0;
}