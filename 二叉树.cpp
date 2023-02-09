
# include "二叉树.h"
 
 
#pragma region 私有成员函数
//添加节点
//key为要插入的值，direction是从左子树插入还是右子树插入，root为从哪个节点插入
void BinaryTree::AddNode(const ElemType key,int direction, BiTree root)
{
    if(direction == 0)
    {
        //从左子树插入
        if(root->left == NULL)
            root->left = new BiNode(key);
        else
            AddNode(key, direction,root->left);
    }
    else if(direction == 1)
    {
        //从右子树插入
        if(root->right == NULL)
            root->right = new BiNode(key);
        else
            AddNode(key, direction,root->right);
    }
}
 
//二叉树的建立，按前序遍历的方式建立二叉树
BiTree BinaryTree::create()
{
     BiTree current = NULL;
     ElemType val;
     cin >> val;//输入键值
     
     if(val == '#')//标识当前子树为空，转向下一节点
     {
         return NULL;
     }
     else
     {   //递归的创建左右子树
         size++;
         current = new BiNode(val);
         current->left = create();
         current->right = create();
         return current;
     }
}
 
//删除二叉树(private 函数)
void BinaryTree ::distroy(BiTree root)
{
    if(root)
    {
        distroy(root->left);
        distroy(root->right);
        delete root;
        root = NULL;
        size = 0;
    }
}
 
//递归得到树的高度
int BinaryTree::getHeight(BiTree root)
{
    if(root == NULL)
        return 0;
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    return (left_height>right_height)? (left_height+1):(right_height+1);
}
 
//前序遍历
void BinaryTree::preOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        cout << root->data << "  -->  ";     //首先打印根节点
        preOrder(root->left);                 //接着遍历左子树
        preOrder(root->right);                 //接着遍历右子树
    }
}
void BinaryTree::notPreOrder(BiTree root){
    stack<BiTree> mystack;
    if(root==NULL)
        return;
    BiTree p = root;
    while(p!=NULL||!mystack.empty()){
        if(p!=NULL){
            cout<<p->data<<"  -->  ";
            mystack.push(p);    //无脑进栈
            p=p->left;          //左孩子重复
        }else{
            //此时是左孩子为null，访问栈顶
            p=mystack.top();
            mystack.pop();
            p=p->right;
            
        }
    }
}
 
//中序遍历
void BinaryTree::inOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        inOrder(root->left);                 //首先遍历左子树
        cout << root->data << "  -->  ";     //接着打印根节点
        inOrder(root->right);                 //接着遍历右子树
    }
}

 
//后序遍历
void BinaryTree::postOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        postOrder(root->left);                 //首先遍历左子树
        postOrder(root->right);                 //接着遍历右子树
        cout << root->data << "  -->  ";     //接着打印根节点
    }
}
void BinaryTree::notPostOrder(BiTree root){
    stack<BiTree> mystack;
    BiTree p = root;
    BiTree r = NULL;
    while(p!=NULL||!mystack.empty()){
        if(p!=NULL){
            mystack.push(p);
            p=p->left;
        }else{
            p=mystack.top();
            if(p->right!=NULL&&p->right!=r){//如果右子树存在，并且没有被访问过，则一路到底
                p=p->right;
                mystack.push(p);
                p=p->left;
            }else{
                mystack.pop();
                cout<<p->data<<"  ---->  ";
                r=p;
                p=NULL;
            }
        }
    }
}

void BinaryTree::levelOrder(BiTree root){
    if(root==NULL)
        return;
    queue<BiTree> que;
    que.push(root);
    while(!que.empty()){
        BiTree tmp = que.front();
        cout<<tmp->data<<" -----> ";
        que.pop();
        if(tmp->left!=NULL)
            que.push(tmp->left);
        if(tmp->right!=NULL)
            que.push(tmp->right);
    }
    
}
#pragma endregion
 
 
#pragma region 公有成员函数
//二叉树的建立
void BinaryTree::Create()
{
    size = 0;
    m_root = create();
}

//删除二叉树
void BinaryTree ::distroy()
{
    distroy(m_root);
}
 
//递归得到树的高度
int BinaryTree::getHeight()
{
    return getHeight(m_root);
}
 
//前序遍历
void BinaryTree::preOrder()
{
    cout << "前序遍历的结果如下："<<endl;
    preOrder(m_root);
    cout << endl;
}
void BinaryTree::notPreOrder(){
    cout<<"非递归前序遍历的结果如下："<<endl;
    notPreOrder(m_root);
    cout<<endl;
}
 
//中序遍历
void BinaryTree::inOrder()
{
    cout << "中序遍历的结果如下："<<endl;
    inOrder(m_root);
    cout << endl;
}
 
//后序遍历
void BinaryTree::postOrder()
{
    cout << "后序遍历的结果如下："<<endl;
    postOrder(m_root);
    cout << endl;
}
void BinaryTree::notPostOrder(){
    cout<<"非递归后续遍历的结果如下："<<endl;
    notPostOrder(m_root);
    cout<<endl;
    
}

void BinaryTree::levelOrder(){
    cout<<"层次遍历的结果如下: "<<endl;
    levelOrder(m_root);
    cout<<endl;
}

 
//获取大小
int BinaryTree::getSize()
{
    //这里是创建时候直接进行了计数
    //也可以利用遍历的方式获取，当节点有值，就加1
    return size;
}
#pragma endregion

//
//int main(){
//    BinaryTree tree = BinaryTree();
//    tree.Create();
//    tree.notPostOrder();
//    tree.postOrder();
//
//}
