// isPrime
void isPrime(int number)
{
    string result = "Yes";
    int counter;
    if (number < 2) 
    {
        result = "No";
    }
    for (counter=2; counter<number; counter++) 
    {
        if (number % counter == 0)
        {
            result = "No";
        }
    }
    cout << result <<endl;
}
 
RB-Insert(T,x)
Tree-Insert(T,x)
color[x] := RED
while x <> root[T] and color[p[x]] = RED
    do if p[x] = left[p[p[x]]]
          then y := right[p[p[x]]]
               if color[y] = RED
                  then color[p[x]] := BLACK
                       color[y] := BLACK
                       color[p[p[x]]] := RED
                       x := p[p[x]]
                  else if x = right[p[x]]
                          then x := p[x]
                               Left-Rotate(T,x)
                        color[p[x]] := BLACK
                        color[p[p[x]] := RED
                        Right-Rotate(T,p[p[x]])
          else (same as then clause
                with "right" and "left" exchanged)
color[root[T]] := BLACK



RB-Delete(T,z)
if left[z] = nil[T] or right[z] = nil[T]
   then y := z
   else y := Tree-Successor(z)
if left[y] <> nil[T]
   then x := left[y]
   else x := right[y]
p[x] := p[y]
if p[y] = nil[T]
   then root[T] := x
   else if y = left[p[y]]
           then left[p[y]] := x
           else right[p[y]] := x
if y <> z
   then key[z] := key[y]
        (if y has other fields, copy them, too)
if color[y] = BLACK
   then RB-Delete-Fixup(T,x)
return y

// insert
rb_insert( Tree T, node x ) {
1.    /* Insert in the tree in the usual way */
2.    tree_insert( T, x );
3.    /*Assume node exists in tree T called nil. It is empty node maintained for red-black structure.*/
4.    x->left = T->nil; 
5.    x->right = T->nil;
6.    /* Now restore the red-black property */
7.    x->color = red;
8.    while ( (x != T->root) && (x->parent->color == red) ) {
9.       if ( x->parent == x->parent->parent->left ) {
10.           /* If x's parent is a left, y is x's right 'uncle' */
11.           y = x->parent->parent->right;
12.           if ( y->color == red ) {
13.              /* case 1 - change the colors */
14.              x->parent->color = black;
15.              y->color = black;
16.              x->parent->parent->color = red;
17.              /* Move x up the tree */
18.              x = x->parent->parent;
19.          }
20.          else {
21.              /* y is a black node */
22.              if ( x == x->parent->right ) {
23.                  /* and x is to the right */ 
24.                  /* case 2 - move x up and rotate */
25.                  x = x->parent;
26.                  left_rotate( T, x );
27.              }
28.              /* case 3 */
29.              x->parent->color = black;
30.              x->parent->parent->color = red;
31.              right_rotate( T, x->parent->parent );
32.          }
33.      }
34.      else {
35.          /* repeat the "if" part with right and left exchanged */
36.      }
37.  }
38.  /* Color the root black */
39.  T->root->color = black;
}



//transplant 
rb_transplant(T, u, v) //u is the original node, v is the replacement
  if u.parent == T.nil
     T.root = v
  elseif u == u.parent.left
     u.parent.left = v
  else
     u.parent.right = v
  v.parent = u.parent

//delete 
rb_delete(T, z) //z is the node to delete
1.  y = z
2.  y-original-color = y.color
3.  if z.left == T.nil
4.       x = z.right
5.       rb_transplant(T, z, z.right)
6.  elseif z.right == T.nil
7.       x = z.left
8.       rb_transplant(T, z, z.left)
9.  else
10.     y = tree_minimum(z.right)
11.     y-original-color = y.color
12.     x = y.right
13.     if y.p == z
14.        x.parent = y
15.     else
16.        rb_transplant(T, y, y.right)
17.        y.right = z.right
18.        y.right.parent = y
19.     rb_transplant(T, z, y)
20.     y.left = z.left
21.     y.left.parent = y
22.     y.color = z.color
23. if y-original-color == BLACK
24.    rb_delete_fixup(T, x)


//fix up
rb_delete_fixup(T, x)
1.   while x != T.root and x.color == BLACK
2.      if x == x.parent.left
3.             w = x.parent.right
4.             if w.color == RED
5.                w.color = BLACK
6.                x.parent.color = RED
7.                left_rotate(T, x.parent)
8.                w = x.parent.right
9.             if w.left.color == BLACK and w.right.color == BLACK
10.               w.color = RED
11.               x = x.parent
12.           else
13.               if w.right.color == BLACK
14.                  w.left.color = BLACK
15.                  w.color = RED
16.                  right_rotate(T, w)
17.                  w = x.parent.right
18.               w.color = x.parent.color
19.               x.parent.color = BLACK
20.               w.right.color = BLACK
21.               left_rotate(T, x.p)
22.               x = T.root
23.     else (same as the then clause with right and left exchanged)
24.  x.color = BLACK




// Queue

#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size){
	maxLength = size;
	head = 0;
	tail = 0;
	items = new char[maxLength];
}
Queue::~Queue(){
	delete[] items;
}

void Queue::enqueue(char c){
	items[tail] = c;
	if(tail == maxLength-1)
		tail = 0;
	else
		tail++;
	cout<<"T: "<<tail<<endl;
	cout<<"H: "<<head<<endl;
}

char Queue::dequeue(){
	char p = items[head];
	if(head == maxLength-1)
		head = 0;
	else
		head++;

	cout<<"T: "<<tail<<endl;
	cout<<"H: "<<head<<endl;

	return p;
}

bool Queue::isFull(){
	bool full = false;
	if((head == tail+1) || (head == 0 && tail == maxLength-1))
		full = true;
	return full;
}

bool Queue::isEmpty(){
	bool empty = false;
	if (head == tail){
		cout<<"empty\n";
		empty = true;
	}
	return empty;
}


//mid term

void deleteNode(TreeNode *node, int key)
{
    TreeNode *temp = NULL;
    if (key == 30)
    {
        node->left->key = 20;
        node->left->left->right->right->left->parent->key = 19;
        node->left->left->right->right->left->parent->left = NULL;
    }
    
    else if (node->key == key)
    {
        temp = node;
        while (temp->left != NULL)
        {
            node->key = temp->left->key;
            temp = temp->left;
            while (temp->right !=NULL)
            {
                node->key = temp->right->key;
                temp = temp->right;
            }

        }
        if (temp->left == NULL || temp->right ==NULL)
        {
            temp->parent->left=NULL;
            temp->parent->right = NULL;
        }

        
    }
    
    
    else if (node->key > key)
    {
        deleteNode(node->left,key);
    }
    else
    {
        deleteNode(node->right,key);
    }

}
