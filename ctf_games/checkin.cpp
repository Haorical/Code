#include <iostream>
#include <queue>
using namespace std;
#define emp -1
struct Node {
    char value;
    Node *left;
    Node *right;
};

Node* createNode() {
    Node *node = new Node;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//采用递归实现
void createFullBT_DFS(Node *&root, char numbers[], int len, int i) {
    if(i <= len) {
        root->value = numbers[i - 1];
        if(2 * i <= len && numbers[2 * i - 1] != emp) {
            root->left = createNode();
            createFullBT_DFS(root->left, numbers, len, 2 * i);
        }
        if((2 * i + 1) <= len && numbers[2 * i] != emp) {
            root->right = createNode();
            createFullBT_DFS(root->right, numbers, len, 2 * i + 1);
        }
    }
}

//采用队列实现；
void createFullBT_queue(Node *&root, char numbers[], int len) {
    if(len == 0)
        return;
    else {
        queue<Node *> Q;
        int i = 0;
        root = createNode();
        root->value = numbers[i++];
        Q.push(root);
        while(!Q.empty()) {
            Node *temp = Q.front();
            Q.pop();
            if(i < len) {
                if(numbers[i] != emp) {
                    temp->left = createNode();
                    temp->left->value = numbers[i];
                    Q.push(temp->left);
                }
                i++;
            }
            if(i < len) {
                if(numbers[i] != emp) {
                    temp->right = createNode();
                    temp->right->value = numbers[i];
                    Q.push(temp->right);
                }
                i++;
            }
        }
    }
}

void preOrder(Node *root) {
    if(root != NULL) {
        cout << root->value; // << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void order(Node *root){
    if(root != NULL) {       
        order(root->left);
        cout << root->value; // << " ";
        order(root->right);
    }   
}
void postorder(Node *root){
    if(root != NULL) {       
        postorder(root->left);
        
        postorder(root->right);
        cout << root->value; // << " ";
    }   
}


int main() {
    char numbers[63]={'c','u','m','t','c','t','f','{','3','0','0','6','2','f','6','8','4','3','f','1','b','8','6','4','c','5','3','e','5','1','5','7','a','0','f','f','3','a','a','2','}','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'};
    //char numbers[] = {}; 已知完全二叉树的层序遍历，构建完成二叉树。
    int len = 15;
    //递归实现
    //Node *root = createNode();
    //createFullBT_DFS(root, numbers, len, 1);
    //队列实现
    Node *root = NULL;
    createFullBT_queue(root, numbers, len);
    //验证建树是否正确；
    preOrder(root);
    cout<<endl;
    order(root);
    cout<<endl;
    postorder(root);
    system("pause");
    return 0;
}
