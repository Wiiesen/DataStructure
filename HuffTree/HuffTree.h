
#ifndef DATASTRUCTURE_HUFFTREE_H
#define DATASTRUCTURE_HUFFTREE_H
const int maxLeafNode = 10;  //10只是示例性的数据，可以根据实际问题具体定义
const int maxTreeNode = maxLeafNode * 2 - 1;

template<class T>
struct HFNode   //哈夫曼树的结点结构
{
    T data;      // 树结点信息
    int weight;  // 叶子结点权重
    int lchild, rchild, parent;  //结点的左右孩子/父结点的存储位置
};

template<class T>                        //定义模板类HuffTree
class HuffTree {
public:
    HuffTree() { numLeafNode = 0; }           //无参构造函数
    HuffTree(T node[], int w[], int n);     //有参构造函数
    ~HuffTree() {}                          //析构函数为空
    HFNode<T> *getHaffumanRoot();          //获取哈夫曼树的根结点
    void hfCoding(HFNode<T> *, int);        //哈夫曼树编码

private:
    HFNode<T> hNode[maxTreeNode];         //存放结点元素的数据
    void selectMinWeight(int &, int &);      //查找哈夫曼树中权值最小的两个根结点，然后取回这两个结点的下标值
    int numLeafNode;                //叶子结点个数
};

#endif //DATASTRUCTURE_HUFFTREE_H
