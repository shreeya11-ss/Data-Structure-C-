#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
struct tree *create(int data)
{
    struct tree *node;
    node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct tree *insert(struct tree *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void in_order(struct tree *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
    
}
void pre_order(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
    
}
void post_order(struct tree *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}
struct tree *search(struct tree *root,int data){
    if(root==NULL || root->data==data){
        return root;
    }
    if(data>root->data){
        return search(root->right,data);
    }
    else{
        return search(root->left,data);
    }   

}

void main()
{
    struct tree *root = NULL;
    int data, x;
    while(1) 
    {
        printf("Tree Data Structure\n");
        printf("1.insert\n");
        printf("2.inorder\n");
        printf("3.preorder\n");
        printf("4.postorder\n");
        printf("5.search\n");
        printf("choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("enter data:");
            scanf("%d",&data);
            root=insert(root,data);
            break;
        case 2:
            in_order(root);
            break;
        case 3:
            pre_order(root);
            break;
        case 4:
            post_order(root);
            break;
        case 5:
            printf("enter data to search:");
            scanf("%d",&data);
            if(search(root,data)!=NULL){
                printf("Data %d is present in the BST",data);
            } 
            else{
                printf("Data is not present!");
            }
            break;

        default:
            printf("invalid");
            break;
        }
    }
}

   