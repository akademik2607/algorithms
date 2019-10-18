#include<stdio.h>

int way = 0;
typedef struct Node{
    int data;
    int use;
    struct Node* top;
    struct Node* down;
    struct Node* left;
    struct Node* right;
}Node;

int FindInGraph(Node *start, int val){
    if(start->data == val)
        return 1;
    start->use = 1;
    if(start->top != NULL && start->top->use != 1){
        way++;
        if(FindInGraph(start->top, val))
            return 1;
    }
    if(start->down != NULL && start->down->use != 1){
        way++;
        if(FindInGraph(start->down, val))
            return 1;
    }
    if(start->right != NULL && start->right->use != 1){
        way++;
        if(FindInGraph(start->right, val))
            return 1;
    }
    if(start->left != NULL && start->left->use != 1){
        way++;
        if(FindInGraph(start->left, val))
            return 1;
    }
        way--;
        return 0;


}
int main(int args, char** argc){
    Node n1, n2, n3, n4, n5, n6;
    n1.data = 2;
    n1.top = NULL;
    n1.down = NULL;
    n1.left = &n2;
    n1.right = &n3;

    n2.data = 4;
    n2.top = &n4;
    n2.down = NULL;
    n2.left = &n5;
    n2.right = &n1;

    n3.data = 6;
    n3.top = NULL;
    n3.down = NULL;
    n3.left = &n1;
    n3.right = NULL;

    n4.data = 8;
    n4.top = &n6;
    n4.down = &n2;
    n4.left = NULL;
    n4.right = NULL;

    n5.data = 10;
    n5.top = NULL;
    n5.down = NULL;
    n5.left = NULL;
    n5.right = &n2;

    n6.data = 12;
    n6.top = NULL;
    n6.down = &n4;
    n6.left = NULL;
    n6.right = NULL;
    int result = FindInGraph(&n1, 12);
    printf("Result = %d\n way = %d", result, way);
    return 0;
}
