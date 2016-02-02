// binary

leaves: 2^H
 
// search
Tree_Search(x, k) //x is the node to evaluate and k is the value being searched for.
  if x==NIL 
    print("node not found")
  else
    if x.key == k
      return x
    if x.key > k
      return Tree_Search(x.left, k) //call Tree_Search again evaluating left branch only
    else
      return Tree_Search(x.right, k) //call Tree_Search again evaluating right branch onl

// insert
Tree_Insert(T, z)
  x = T.root
  P = NIL  //P is a tree node
  while(x != NIL){
    P = x  //store current root of the tree
     if z.key < x.key
       x = x.left
     else
       x = x.right
  }   
  z.p = P //set the parent of the new node
  if P == NIL  //tree is empty
    T.root = z
  else if z.key < P.key
    P.left = z   
  else
    P.right = z
    

// min
Tree_minimum(x)
  while x.left != NIL
    x = x.left
  return x
  
//or recursive
int min(node *n)
{
	if(n->left != NULL)
	{
		return min(n->left);
	}
	else
	{
		return n;
	}
}

// max
Tree_maximum(x)
  while x.right != NIL
    x = x.right
  return x
    
//or recursive
int max(node *n)
{
	if(n->right != NULL)
	{
		return max(n->right);
	}
	else
	{
		return n;
	}
}
// print
printNode(x){
  if x.left != NULL
    printNode(x.left);
  cout<<x.key<<endl;
  if x.right != NULL
    printNode(x.right);
}

//preorder
printNodePreorder(x){
  cout<<x.key<<endl;
  if x.left != NULL
    printNodePreorder(x.left);
  if x.right != NULL
    printNodePreorder(x.right);
}


//postorder
printNodePostorder(x){
  if x.left != NULL
    printNodePostorder(x.left);
  if x.right != NULL
    printNodePostorder(x.right);
  cout<<x.key<<endl; 
}


// is BST
bool isBST(TreeNode* node) 
{ 
    while (node->left != NULL || node->right !=NULL)
    {
        int x = node->key;
        int y = x;
        
        if (node->left->key < y && node->right->key > y)
        {
            node = node->left;
            y = node->key;
            if (node->right->key > x)
            {
                return false;
            }
        }
        return true;
    }
    return true;
}


//or / maybe

bool isBST(TreeNode* node) 
{ 
    if (node == NULL) 
    return true;
    
    else if (node->left != NULL && node->left->key < node->key) 
    return true; 
     
    else if (node->right != NULL && node->right->key >= node->key) 
    return true; 
   
    else if (isBST(node->left) == true && isBST(node->right) == true) 
    return true; 

    else
    return false; 
}


//has .path sum
bool hasPathSum(TreeNode *node, int sum)
{
    if(node != NULL)
    {
        if(sum == node->key)
        return true;
        if(sum < node->key)
        return hasPathSum(node->left,sum);
        else
        return hasPathSum(node->right,sum);
    }
    else
    return false;
}

// double tree
void doubleTree(TreeNode *node) { 
    TreeNode* oldLeft;
    TreeNode* newNode = new(struct TreeNode);
    
    if (node == NULL) return;
    
    doubleTree(node->left); 
    doubleTree(node->right);
    
    oldLeft = node->left; 
    
    newNode->key = node->key;
	newNode->left = NULL;
	newNode->right = NULL;
	
    node->left = newNode; 
    node->left->left = oldLeft;
} 

// if same tree
bool sameTree(TreeNode *node1, TreeNode *node2)
{
    if(node1 == NULL && node2 ==NULL)
    return true;
    if(node1 !=NULL && node2 != NULL)
    return((node1->key == node2->key) && (sameTree(node1->left,node2->left)) && (sameTree(node1->right,node2->right)));
    return false;
}




// Red-black Tree

// left rotation
void Rotate_Left(Tree* tree, TreeNode *node)
{
    TreeNode *y = NULL;
    y=node->right;
    node->right = y->left;
    if(y->left == NULL)
    {
        y->left->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == NULL)
    {
        tree->root = y;
    }
    else if(node==node->parent->left)
    {
        node->parent->left = y;
    }
        else
        {
            node->parent->right = y;
        }
    y->left = node;
    node->parent = y;
}



// right rotation
void Rotate_Right(Tree* tree, TreeNode *node)
{
    TreeNode *x = NULL;
    x=node->left;
    node->left = x->right;
    if(x->right == NULL)
    {
        x->right->parent = node;
    }
    x->parent = node->parent;
    if(node->parent == NULL)
    {
        tree->root = x;
    }
    else if(node==node->parent->right)
    {
        node->parent->right = x;
    }
        else
        {
            node->parent->left = x;
        }
    x->right = node;
    node->parent = x;
}


// whole left rotate

void LeftRotate(node* &tree, node* x)
{
    node *y = NULL;
    y=x->right;
    x->right = y->left;
    if(y->left == NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL)
    {
        tree->root = y;
    }
    else if(x==x->parent->left)
    {
        x->parent->left = y;
    }
        else
        {
            x->parent->right = y;
        }
    y->left = x;
    x->parent = y;
}

// whole right rotate

void RightRotate(node* &tree, node* y)
{
    node *x = NULL;
    x=y->left;
    y->left = x->right;
    if(y->right == NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == NULL)
    {
        tree->root = x;
    }
    else if(y==y->parent->right)
    {
        y->parent->right = x;
    }
        else
        {
            y->parent->left = x;
        }
    x->right = y;
    y->parent = x;
}



//enqueue

void Queue::enqueue(node *newNode)
{
    if (head == NULL) 
    {
        head = newNode;
    } 
    else 
    {
        tail->next = newNode;
    }
    tail = newNode;
}

//dequeue

node* Queue::dequeue()
{
    if (head == NULL)
    {
        return NULL;
    }

    else if (tail == head) 
    {
        tail = NULL;
    }
    head = head->next;
    return head;
}
