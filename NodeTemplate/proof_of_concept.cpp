#include <iostream>
#include "NodeTemplate.cpp"

using namespace std;

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
