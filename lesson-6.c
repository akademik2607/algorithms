#include<stdio.h>
#include<stdlib.h>
//1.
int MyHash(char* str){
    int i = 0;
    int sum = 0;
    while(str[i] != '\0'){
       sum += str[i];
       i++;
    }
    return sum;
}
//2.
typedef struct Node{
    int data;
    struct Node* Left;
    struct Node* Right;
}Node;
typedef struct Root{

}Root;
int tree(Node* root, int val){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = val;
    if(val < root->data){
        if(root->Left == NULL){
            root->Left = temp;
            temp->Left = NULL;
            temp->Right = NULL;
            return 1;
        }
        tree(root->Left, val);
    }
    else if(root->data <= val){
        if(root->Right == NULL){
            root->Right = temp;
            temp->Left = NULL;
            temp->Right = NULL;
            return 1;
        }
        tree(root->Right, val);
    }
}
//void PrintTree()
int  main(int args, char*argc[]){
    char h []= "Hello!";
    printf("%d", MyHash(h));
    int a = 6;
    Node* r;
    r->data = 3;
    r->Left = NULL;
    r->Right = NULL;
    tree(r, a);
    return 0;
}
