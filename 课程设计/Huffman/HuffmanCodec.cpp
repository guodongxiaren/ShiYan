#include "HuffmanCodec.h"
#include <iomanip>
#include <cstdlib>

/////////////////////////////////////////////////////
// HuffmanCodec
/////////////////////////////////////////////////////
/* 
 * 静态常量字符串
 * 用于存储要读写的文件名:
 */
const string HuffmanCodec::codefile = "codefile.txt";
const string HuffmanCodec::huffmantree = "huffmantree.txt";
const string HuffmanCodec::textfile = "textfile.txt";
const string HuffmanCodec::codeprint = "codeprint.txt";
const string HuffmanCodec::treeprint = "treeprint.txt";

/* 
 * 构造函数
 */
HuffmanCodec::HuffmanCodec()
{
    transfile = "tobetrans.txt";
    tree = 0;

}

/* 
 * 析构函数
 */
HuffmanCodec::~HuffmanCodec()
{
    __release(tree);
}

/////////////////////////////////////////////////////
//公开成员函数
/////////////////////////////////////////////////////

/*
 * C：编码 
 */
void HuffmanCodec::coding()
{
    __parseFile();
    __buildTree();
    __travel(tree, "");
    infile.open(transfile.c_str());
    outfile.open(codefile.c_str());
    if (!infile)
    {
        cerr<<"error:"<<transfile<<"文件不存在"<<endl;
        exit(-1);
    }
    if (!outfile)
    {
        cerr<<"error: unable to open output file: "<<codefile<<endl;
        exit(-1);
    }

    cout<<"正在对文件"<<transfile<<"中的正文进行编码..."<<endl;
    string str;
    string code;
    while (getline(infile, str))
    {
        unsigned size = str.size();
        for (unsigned i = 0; i < size; i++)
        {
            char key = str[i];
            code = dict[key];
            outfile<<code;
        }
    }
    cout<<"译码结果已存入文件"<<codefile<<"中。"<<endl;

    cout<<"正在将建好的哈夫曼树存入文件"<<huffmantree<<"中..."<<endl;
    outfile.close();
    outfile.open(huffmantree.c_str());
    map<char, string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++)
    {
        outfile<<it->first<<" "<<it->second<<endl;

    }
    cout<<"已存入。"<<endl;
    infile.close();
    outfile.close();
}

/*
 * D：译码 
 */
void HuffmanCodec::decoding()
{
    cout<<"正在利用已建好的哈夫曼树对文件"<<codefile<<"进行译码..."<<endl;
    infile.open(codefile.c_str());
    outfile.open(textfile.c_str());
    if (!infile)
    {
        cerr<<"error: unable to open input file: "<<codefile<<endl;
        exit(-1);
    }
    if (!outfile)
    {
        cerr<<"error: unable to open output file: "<<textfile<<endl;
        exit(-1);
    }
    string line;
    while (getline(infile, line))
    {
        HuffmanNode *node = tree;
        unsigned size = line.size();
        for (unsigned i = 0; i < size; i++)
        {
            if (line[i] == '0')
            {
                node = node->getLeft();
            }
            else 
            {
                node = node->getRight();
            }
            if (node->isLeaf())
            {
                outfile<<((HuffmanLeaf *)node)->getData();
                node = tree;
            }
        }
    }
    infile.close();
    outfile.close();
    cout<<"结果已存入"<<textfile<<"中。"<<endl;
}

/*
 * P:打印代码文件
 */
void HuffmanCodec::print()
{
    cout<<"即将打印代码文件"<<codefile<<",每行50个代码。"<<endl;
    infile.open(codefile.c_str());
    outfile.open(codeprint.c_str());
    if (!infile)
    {
        cerr<<"error: unable to open input file: "<<codefile<<endl;
        exit(-1);
    }
    if (!outfile)
    {
        cerr<<"error: unable to open output file: "<<codeprint<<endl;
        exit(-1);
    }
    char str[55];
    while (!infile.eof())
    {
        infile.read(str, 50);
        int size = (int)infile.gcount();
        str[size] = '\0';
        cout<<str<<endl;
        outfile<<str<<endl;
    }
    infile.close();
    outfile.close();
    cout<<"同时此字符形式的编码文件已写入文件"<<codeprint<<"中。"<<endl;
}

/*
 * T:打印Huffman树
 */
void HuffmanCodec::treePrint()
{
    cout<<"正在打印哈夫曼树。将已在内存中的哈夫曼树以\"凹入表\"形式显示在终端上。"<<endl;
    outfile.open(treeprint.c_str());
    if (!outfile)
    {
        cerr<<"error: unable to open output file: "<<treeprint<<endl;
        exit(-1);
    }
    __concaveTablePrint(tree, 0);
    cout<<"同时此字符形式的哈夫曼树已经写入文件"<<treeprint<<"中。"<<endl;
    outfile.close();
}

///////////////////////////////////////////////////////
// 私有成员函数
///////////////////////////////////////////////////////
void HuffmanCodec::__parseFile()
{
    cin.get();
    bool flag;
    char name[20];
    do
    {
        cout<<"请输入要编码的文件名，默认为tobetrans.txt（直接回车）："<<endl;
        flag = false;
        fgets(name, sizeof(name), stdin);
        if (name[0] != '\n')
            transfile = string(name);
        else
            transfile = string("tobetrans.txt");
        infile.open(transfile.c_str());
        if (!infile)
        {
            cerr<<"error:"<<transfile<<"文件不存在"<<endl;
            flag = true;
        }

    }while(flag);
    string str;
    while (getline(infile, str))
    {
        unsigned size = str.size();
        for (unsigned i = 0; i < size; i++)
        {
            char key = str[i];
            if(count.find(key) != count.end())
                count[key]++;
            else
                count[key] = 1;
        }
    }
    infile.close();
}

void HuffmanCodec::__buildTree()
{
    for (map<char ,int>::iterator it = count.begin(); it != count.end(); it++)
    {
        HuffmanLeaf *leaf = new HuffmanLeaf((*it).first, (*it).second);
        nodes.push(leaf);
    }

    while (nodes.size() > 1)
    {
        HuffmanNode *node1 = nodes.top();
        nodes.pop();
        HuffmanNode *node2 = nodes.top();
        nodes.pop();

        int weight = node1->getWeight() + node2->getWeight();
        HuffmanNode *newNode = new HuffmanNode(weight, node1, node2);
        nodes.push(newNode);
    }
    tree = nodes.top();
}

void HuffmanCodec::__travel(HuffmanNode *root, string code)
{
    if (root->isLeaf())
    {
        char key = ((HuffmanLeaf *)root)->getData();
        dict[key] = code;
        return;
    }
    string tmpcode = code;
    __travel(root->getLeft(), tmpcode.append("0"));
    __travel(root->getRight(), code.append("1"));
}

void HuffmanCodec::__concaveTablePrint(HuffmanNode *root, int offset)
{
    if (!root)
    {
        return;
    }

    cout<<setw(offset + 2)<<setiosflags(ios::right);
    cout<<root->getWeight();
    if (root->isLeaf())
        cout<<"  "<<((HuffmanLeaf *)root)->getData();
    cout<<endl;

    outfile<<setw(offset + 2)<<setiosflags(ios::right);
    outfile<<root->getWeight()<<endl;
    if (root->isLeaf())
        outfile<<":"<<((HuffmanLeaf *)root)->getData();
    outfile<<endl;

    __concaveTablePrint(root->getLeft(), offset + 2);
    __concaveTablePrint(root->getRight(), offset + 2);
}

void HuffmanCodec::__release(HuffmanNode *root)
{
    if (!root)
        return;
    __release(root->getLeft());
    __release(root->getRight());
    delete root;
}
