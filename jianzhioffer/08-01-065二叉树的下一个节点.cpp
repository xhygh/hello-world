/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

*/

/************
本题需要通过画图找到所有可能的情况，然后编写代码。
考察了应聘者对于中序遍历的理解。
运行时间：1ms
占用内存：500k
***********/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//指向父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        /*
        *画图，分情况考虑每种节点的下一个节点；
        *if node有r：next node = r的最左边的子节点
        *if node无r： if node 是其父的l，则next node=father node
        *			 if node 是其父的r，麻烦了，画图可知，此时该node所在的左子树遍历完成
        *             所以next node=该左子树的父节点，寻找规则，沿着父节点向上找，找到第一个nodeA是另一nodeB的左孩子，
        *             则nodeB就是 我们要找的next node。
        *
        */
        if(pNode==nullptr)
            return nullptr;
        TreeLinkNode* tmp = nullptr;
        if(pNode->right!=nullptr){//如果有右子树
            tmp = pNode->right;
            while(tmp->left)
                tmp = tmp->left;
            return tmp;
        }
        else{//如果没有右子树
            tmp = pNode;
            TreeLinkNode *parent = pNode->next;
            while(parent!=nullptr && tmp==parent->right){
                tmp = parent;
                parent = parent->next;
            }
            return parent;//如果没有右子树，且pNode是左孩子，直接返回pNode的父节点
        }
    }
};
