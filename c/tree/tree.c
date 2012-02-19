#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *new_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p -> data = data;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}

struct node *insert(struct node *link, int data)
{
	if(link == NULL)
		link = new_node(data);
	else {
		if(link -> data > data)
			link -> left = insert(link -> left, data);
		else
			link -> right = insert(link -> right, data);
	}
	
	return link;
}

void traverse(struct node *link)
{
	if(link) {
		traverse(link -> left);
		printf("%d ", link -> data);
		traverse(link -> right);
	}
}

int max(int a, int b)
{
	if(a < b)
		a = b;
	return a;
}

void view_balance(struct node *link)
{
	if(link) {
		printf("node %d balance %d\n", link -> data, height(link -> left) - height(link -> right));
		view_balance(link -> left);
		view_balance(link -> right);
	}
}

int height(struct node *link)
{
	int hgt = 0;
	if(link) {
		hgt = 1 + max(height(link -> left), height(link -> right));
	}
	
	return hgt;
}


main()
{
	int value[] = {5,2,3,7,4,2,7,1,10,0}, i = 0, hgt, bal;
	struct node *root = NULL;
	
	while(value[i])
		root = insert(root, value[i++]);

	traverse(root);

	hgt = height(root);
	printf("\nheight %d\n", hgt);

	view_balance(root);

}
