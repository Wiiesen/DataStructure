
#include<iostream>
#include<string>

using namespace std;

#include"HuffTree.h"

int main() {
    int i = 0;

    cout << "**************************" << endl
         << "1)创建一棵哈夫曼树:" << endl
         << "**************************" << endl;
    string studentArray[5] = {"A", "B", "C", "D", "E"};
    int weightStudent[5] = {20, 14, 13, 10, 21};
    HuffTree<string> huffTree(studentArray, weightStudent, 5);//创建一棵哈夫曼树。
    cout << "**************************" << endl
        << "2)哈夫曼树叶结点编码:" << endl
        << "**************************" << endl;
    huffTree.hfCoding(huffTree.getHaffumanRoot(), 0);

    return 0;
}
