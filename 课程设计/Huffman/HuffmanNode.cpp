#include "HuffmanNode.h"
/////////////////////////////////////////////////////
// HuffmanNode
/////////////////////////////////////////////////////

void HuffmanNode::setWeight(int weight)
{
    this->weight = weight;
}

int HuffmanNode::getWeight()const
{
    return weight;
}

HuffmanNode *HuffmanNode::getLeft()
{
    return left;
}

HuffmanNode *HuffmanNode::getRight()
{
    return right;
}

bool HuffmanNode::isLeaf()
{
    if (left == 0 && right == 0)
        return true;
    return false;
}

