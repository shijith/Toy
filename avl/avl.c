#include<stdio.h>
#include<stdlib.h>
/* Program - AVL Tree
notes: temp golbal pointer used as a traverser in find_pos, so put it
in correct position before calling find_pos.
	 */

struct node{
				int data;
				struct node *left;
				struct node *right;
				struct node *parent;
}*root, *temp;

struct node *find_pos(int n, struct node *parent)
{
				if(temp) {
					if(temp -> data > n){
									if(temp -> left) {
													parent = temp;
													temp = temp -> left;
									}	else
													return parent;
					}	else if(temp -> data < n) {
									if(temp -> right) {
													parent = temp;
													temp = temp -> right;
									}
									else
													return parent;
					} else
									return parent;
					find_pos(n, parent);
				} else
									return parent;

}

rot_l(struct node *piv, struct node *r)
{
				r -> right = piv -> left;
				piv -> left = r;
				piv -> parent = r -> parent;
				r -> parent = piv;

				if(r -> right) 
								r -> right -> parent = r;

				if(piv -> parent) {
								if(piv -> data > piv -> parent -> data) 
												piv -> parent -> right = piv;	
								else
												piv -> parent -> left = piv;
				} else
								root = piv;

}

rot_r(struct node *piv, struct node *r)
{
				r -> left = piv	-> right;
				piv -> right = r;
				piv -> parent = r -> parent;
				r -> parent = piv;

				if(r -> left) 
								r -> left -> parent = r;

				if(piv -> parent) {
								if(piv -> data > piv -> parent -> data) 	
												piv -> parent -> right = piv;
								else
												piv -> parent -> left = piv;
    		}	else
								root = piv;
}


int counts(struct node *p)
{
				int l,r;
				if(p) {
								 l = 1 + counts(p -> left);
								 r = 1 + counts(p -> right);
								 return l>r?l:r;
				} else
					 return 0;
}



void bf(struct node *p)
{
				struct node *l, *r;
				int bal;
				if(p) {
						bal = counts(p -> left) - counts(p -> right);
						if(bal == 2 || bal == -2) {
								printf("%d %d\n", p -> data, bal);
								if(bal == 2) {
										if(l = p -> left) {
												bal = counts(l -> left) - counts(l -> right);
														if(bal >= 0)
																rot_r(p -> left, p);
														else {	
																rot_l(p -> left -> right, p -> left);
																rot_r(p -> left, p); 	
														}
										}
								} else {
										if(r = p -> right) {
												bal = counts(r -> left) - counts(r -> right);
												if(bal > 0) {
														rot_r(p -> right -> left, p -> right);
														rot_l(p -> right, p);
												} else
														rot_l(p -> right, p);
										}
								}
						} else
								bf(p -> parent);
			}
}


void tra(struct node *t)
{
				if(t) {
								printf("%d \n", t -> data);
								tra(t -> left);
								tra(t -> right);
				}
}

void inserts(int n)
{
				struct node *p, *par;
				temp = root;
				par = find_pos(n, root);
				p = (struct node *)malloc(sizeof(struct node));
				p -> data = n;
				p -> left = 0;
				p -> right = 0;
				p -> right = 0;
				p -> parent = temp;
				if ( temp -> data > n)
								temp -> left = p;
				if (temp -> data < n)
								temp -> right = p;
				bf(temp);
}


void starts()
{
				root = (struct node *)malloc(sizeof(struct node));
				root -> data = 10;
				root -> left = 0;
				root -> left = 0;
				root -> parent = 0;
				printf("Root initialized to %d\n", root -> data);


}
void del_min()
{
				struct node *del = temp, *par;
				temp = temp -> right;
				par = find_pos(0, del);

				del -> data = temp -> data;
				if(par -> right == temp)
					par -> right = 0;
				else
					par -> left = 0;
				free(temp);

}

void deletes(int n)
{
				struct node *par = 0;
				temp = root;
				par = find_pos(n, root);
				if(temp -> data == n) {
								if( par -> left == temp){
												if(temp -> right == 0)
																par ->left = temp -> left;
												else if(temp -> left == 0)
																par ->left = temp -> right;
												else {
																del_min();
												}
								} else if(par -> right == temp) {
												if(temp -> right == 0)
																par ->right = temp -> left;
												else if(temp -> left == 0)
																par ->right = temp -> right;
												else {
																del_min();
												}
								}	else {
												printf("root changed\n");
												if(root -> right == 0)
																root = root -> left;
												else
																del_min();

								}
								
				} 
				bf(par);
				
}
main()
{
				int i, d = 3, a[] = {4, 3, 12, 13, 9};
				starts();
				for(i = 0; i < 5; i++) {
								printf("Inserting %d\n", a[i]);
								inserts(a[i]);
								tra(root);
				}
				printf("Deleting %d\n", d);
				deletes(d);
				tra(root);
}
