#ifndef _HUFFMANLEAD_H
#define _HUFFMANLEAD_H

#include "HuffmanNode.h"
class HuffmanLeaf:public HuffmanNode
{
public:
    HuffmanLeaf(char _data, int weight):HuffmanNode(weight, 0, 0),data(_data){}
    void setData(char data);
    char getData();
private:
    char data;
};
#endif