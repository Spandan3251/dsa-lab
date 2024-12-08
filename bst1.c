#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node* createnode(int data)
{
    node *newnode;//Creating a node pointer
    newnode=(node*)malloc(sizeof(node));//Allocating memory to the heap
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(1);
    }
    newnode->data=data;//setting the data
    newnode->left=NULL;//Setting the left and right children to NULL
    newnode->right=NULL;
    return newnode;
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

node* search(node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
        return root;
    else if(root->data>key)
        return search(root->left,key);
    else
        return search(root->right,key);
}
 
 //Iterative format
 node *searchItr(node *root,int key)
 {
    while(root!=NULL)
    {
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
 }

 //inserting a node
 void insert(node *root,int key)
 {
    node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
             printf("%d already in BST,cannot be inserted",key);
             return;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
        node *new=createnode(key);
        if(key>prev->data){
            prev->right=new;
        }
        else{
            prev->left=new;
        }
    }
int main()
{
    /*
    //Creating 1st node
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    //Creating 2nd node
    node *p1;
    p1=(node*)malloc(sizeof(node));
    p1->data=4;
    p1->left=NULL;
    p1->right=NULL;

    //Creating 3rd node
    node *p2;
    p2=(node*)malloc(sizeof(node));
    p2->data=6;
    p2->left=NULL;
    p2->right=NULL;
*/
//Constructing the tree
//      4
//     / \
//    2   6
//   / \
//  1   3


    node *p =createnode(4);
    node *p1=createnode(2);
    node *p2=createnode(6);
    node *p3=createnode(1);
    node *p4=createnode(3);

    //Linking two chidren with root node
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

   /* preorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    */

   /*
   node *s=searchItr(p,4);
   if(s!=NULL)
   {
    printf("\n found=%d",s->data);
   }
   else
   {
    printf("\n not found");
   }
   */

    insert(p, 6);
    printf("%d",p->right->right->data);
    return 0;


}
