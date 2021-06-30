#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value)
{
	struct node* temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node* insert (struct node* root, int value)
{
	struct node* temp = root;
	if(temp == NULL)
	{
		temp = createNode(value);
	}
	else if(value >= temp->data)
	{
		temp->right = insert(temp->right, value);
	}
	else
	{
		temp->left = insert(temp->left, value);
	}
	return temp;
}

void preOrder(struct node* root)
{
	if(root->left != NULL)
	{
		preOrder(root->left);
	}

	if(root->right != NULL)
	{
		preOrder(root->right);
	}
	printf("%d ", root->data);
}

void inOrder(struct node* root)
{
	if(root->left != NULL)
	{
		inOrder(root->left);
	}
	printf("%d ", root->data);
	if(root->right != NULL)
	{
		inOrder(root->right);
	}
}

void postOrder(struct node* root)
{
	if(root->left != NULL)
	{
		postOrder(root->left);
	}
	if(root->right != NULL)
	{
		postOrder(root->right);
	}
	printf("%d ", root->data);
}

int searchInBST(struct node* root, int value)
{
	if(root->data == value)
	{
		return 1;
	}
	if(root->right != NULL && (root->data < value))
	{
		return searchInBST(root->right, value);
	}
	if(root->left != NULL && (root->data > value))
	{
		return searchInBST(root->left, value);
	}
	return 0;
}

int main()
{
	int n;

	printf("Enter the number of element to add in binary search tree: ");
	scanf("%d", &n);


	int data;
	struct node *root = NULL;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}

	// preOrder traversal
	preOrder(root);

	// inOrder traversal
	printf("\n");
	inOrder(root);

	// postOrder traversal
	printf("\n");
	postOrder(root);


	printf("\nEnter the elements which you want to search: ");
	int val;
	scanf("%d", &val);
	if(searchInBST(root, val))
	{
		printf("ELEMENT FOUND\n");
	}
	else
	{
		printf("ELEMENT NOT FOUND\n");
	}

	return 0;
}
