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
	HuffmanCodec();
	void coding();
	void decoding();
	void print();
	void treePrint();
private:
	/* 私有成员函数 */
	// 解析文件
	void parseFile();
	// 构建Huffman树
	void buildTree();
	// 遍历huffman树
	void travel(HuffmanNode *head, string code);
	// 凹入表打印
	void concaveTablePrint(HuffmanNode *head,int offset);

	/* 类成员 */ 
	priority_queue<HuffmanNode *, vector<HuffmanNode *>, CmpNode> nodes;
	map<char, int> count;
	map<char, string> dict;
	HuffmanNode *tree;
	ifstream infile;
	ofstream outfile;

	string transfile;
	string codefile;
	string textfile;
	string codeprint;
	string treeprint;
	string huffmantree;
};

#endif