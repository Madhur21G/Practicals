#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
Node *max(Node *root){
    while (root->right){
        root = root->right;
    }
    return root;
}
Node *delete (Node *root, int val){
    if (!root){
        return NULL;
    }
    if (root->data == val){
        // leaf node.
        if (!root->left && !root->right){
            free(root);
            return NULL;
        }
        // only one child.
        else if (!root->left && root->right){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right && root->left){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // two child.
        else{
            int maxVal = max(root->left)->data;
            root->data = maxVal;
            root->left = delete (root->left, maxVal);
            return root;
        }
    }
    else if (root->data < val){
        root->right = delete (root->right, val);
        return root;
    }
    else{
        root->left = delete (root->left, val);
        return root;
    }
}
Node *insert(Node *root, int val){
    if (!root){
        root = (Node *)malloc(sizeof(Node));
        root->data = val;
        root->left = root->right = NULL;
        return root;
    }
    if (val < root->data){
        root->left = insert(root->left, val);
    }
    else if (val > root->data){
        root->right = insert(root->right, val);
    }
}
void inOrderTraversal(Node *root){
    if (!root) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node *root){
    if (!root) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node *root){
    if (!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
int search(Node *root, int val){
    if (!root) return 0;
    if (root->data < val){
        search(root->right, val);
    }
    else if (root->data > val){
        search(root->left, val);
    }
    else return 1;
}
int maxVAL(int num1, int num2){
    if (num1 < num2) return num2;
    else return num1;
}
int height(Node *root){
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = maxVAL(leftHeight, rightHeight) + 1;
    return ans;
}
int NodeCnt(Node *root){
    if (!root) return 0;
    return (1 + NodeCnt(root->left) + NodeCnt(root->right));
}

int main(){
    Node *root = NULL;
    printf("Press 1 for insert node in the BST\n");
    printf("Press 2 for delete node from the tree\n");
    printf("Press 3 for Inorder Traversal of the Tree\n");
    printf("Press 4 for Preorder Traversal of the Tree\n");
    printf("Press 5 for Postorder Traversal of the Tree\n");
    printf("Press 6 for search Node in the Binary search Tree\n");
    printf("Press 7 for find the total no. of nodes\n");
    printf("Press 8 for find the height of the Binary search Tree\n");
    printf("Press 9 for exit from the program \n");
    int choice;
    int val;
    do
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be insert in the BST\n");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Enter the data to be delete from the BST\n");
            scanf("%d", &val);
            root = delete (root, val);
            break;
        case 3:
            printf("Inorder Traversal of BST are : ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("PreOrder Traversal of BST are : ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("PostOrder Traversal of BST are : ");
            postOrderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("Enter the data to be search in the BST\n");
            scanf("%d", &val);
            if (search(root, val))
            {
                printf("Data  found\n");
            }
            else
            {
                printf("Data not found\n");
            }
            break;
        case 7:
            printf("Total No. of Nodes in the BST are : %d\n", NodeCnt(root));
            break;
        case 8:
            printf("Height of the BST are : %d\n", height(root));
            break;
        case 9:
            printf("Exit\n");
            break;
        }
    } while (choice != 9);
    return 0;
}
