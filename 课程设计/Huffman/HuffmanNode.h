#ifndef _HUFFMANNODE_H
#define _HUFFMANNODE_H

class HuffmanNode
{
public:
    HuffmanNode(int _w, HuffmanNode *_l, HuffmanNode *_r):weight(_w),left(_l),right(_r){}

    int getWeight()const;
    HuffmanNode *getLeft();
    HuffmanNode *getRight();
    void setWeight(int weight);
    bool isLeaf();
protected:
    int weight;
    HuffmanNode *left;
    HuffmanNode *right;
};

struct CmpNode
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->getWeight() > b->getWeight();
    }

};
#endif