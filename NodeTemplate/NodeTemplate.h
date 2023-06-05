#ifndef NODETEMPLATE_H
#define NODETEMPLATE_H

template <typename Data>
class NodeTemplate
{
    private:
        Data x;
        NodeTemplate *nextNode;

    public:
};


//these are old function's that I might need to implement

//NodeTemplate<Data>(NodeTemplate<Data>* t_nextNode, Data t_x);
//void setx(Data t_x);
//void setptr(NodeTemplate<Data>* t_nextNode);
//Data getx();
// I have to put this here cause vs is dumb
//NodeTemplate<Data>* getptr();
//~NodeTemplate<Data>();

#endif
