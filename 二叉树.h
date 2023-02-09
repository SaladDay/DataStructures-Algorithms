#include <iostream>
#include<queue>
#include<stack>
using namespace std;
 
typedef char ElemType;
 
//定义树的节点
typedef struct BiNode
{
    ElemType data;            //节点的数据类型
    BiNode * left;            //左子树
    BiNode * right;            //右子树
    BiNode(ElemType val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}BiNode,*BiTree;
 
 
//二叉树类
class BinaryTree
{
public:
    void Create();                //递归的创建二叉树的节点
    int getSize();                //递归得到树的节点数目
    int getHeight();            //递归得到树的高度
     void preOrder();            //前序遍历
    void notPreOrder();         //非递归前序遍历
     void inOrder();            //中序遍历
     void postOrder();            //后序遍历
    void notPostOrder();
    void levelOrder(); //层次遍历
     void distroy();            //删除二叉树
    int treeSize();             //计算二叉树的节点数量
 
private:
    BiTree create();                        //递归的创建二叉树的节点
    void preOrder(BiTree root);                //前序遍历
    void notPreOrder(BiTree root);
    void inOrder(BiTree root);                //中序遍历
    void postOrder(BiTree root);            //后序遍历
    void notPostOrder(BiTree root);
    void levelOrder(BiTree root);
    void distroy(BiTree root);                //摧毁树
    int getHeight(BiTree root);                //递归得到树的高度
    void AddNode(const ElemType key,int direction, BiTree root);         //添加节点
    int treeNum(BiTree root);
    BiTree m_root;      //根节点
    int size;            //节点总数
};
