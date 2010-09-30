     /* example.i */
     %module avl
     %{
     /* Put header files here or function declarations like below */
     extern struct node *root;
     extern struct node *temp;
     %}
     
     extern void inserts(int n);
     extern struct node *find_pos(int n, struct node *parent);
     extern int counts(struct node *p);
     extern void rot_l(struct node *piv, struct node *lr);
     extern void rot_r(struct node *piv, struct node *rr);
     extern void bf(struct node *p);
     extern void tra(struct node *t);
     extern void starts();
     extern void del_min();
     extern void deletes(int i);
     extern void prints();
     
