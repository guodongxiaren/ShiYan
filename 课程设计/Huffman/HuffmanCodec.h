#ifndef _HUFFMANCODEC_H
#define _HUFFMANCODEC_H

#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "HuffmanNode.h"
#include "HuffmanLeaf.h"
using namespace std;

class HuffmanCodec
{
public:
    /* 静态常量字符串。必须头文件中声明，源文件中初始化 */
    static const string codefile;
    static const string textfile;
    static const string codeprint;
    static const string treeprint;
    static const string huffmantree;

    /* 构造与析构函数 */
    HuffmanCodec();
    ~HuffmanCodec();

    /* 公开成员函数，表示对外可见的只有四个操作 */
    void coding();
    void decoding();
    void print();
    void treePrint();
private:
    /* 私有成员函数 */
    // 解析文件
    void __parseFile();
    // 构建Huffman树
    void __buildTree();
    // 遍历huffman树
    void __travel(HuffmanNode *root, string code);
    // 凹入表打印
    void __concaveTablePrint(HuffmanNode *root,int offset);
    // 释放Huffman树。被析构函数调用
    void __release(HuffmanNode * root);

    /* 类成员 */ 
    // 要编码的文件名
    string transfile;
    // 树结点的优先队列。为了便于构造Huffman树
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CmpNode> nodes;
    // 存储每种字符的个数
    map<char, int> count;
    // 存储每种字符对应的01串
    map<char, string> dict;
    // Huffman树的头结点
    HuffmanNode *tree;
    // 文件输入流，为了读文件
    ifstream infile;
    // 文件输出流，为了写文件
    ofstream outfile;

};

#endif
