#include<stdio.h>
#include<stdlib.h>

int flag=0;

// DLL node for Tree with left_link value and right_link
struct node{
	int value;
	struct node *ltree,*rtree;
};

typedef struct node* NODE;

// create a node
NODE getnode(){
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	x->ltree=x->rtree=NULL;
	return x;
}

// create a BST for the given values
NODE create(int item,NODE root){
	NODE temp,cur,prev;
	int i;
	temp=getnode();		// create node
	temp->value=item;	// store value

	// if empty tree then new node itself is ROOT of BST
	if(root==NULL){
		root=temp;
		return root;
	}

	prev=NULL;
	cur=root;

	// find the leaf node
	while (cur!=NULL){
		prev=cur;
		if(temp->value==cur->value){
			flag=1;
			break;
		}
		// condition to choose left or right subtree
		cur=(temp->value<cur->value)?cur->ltree:cur->rtree;
	}
	if(flag==0&&temp->value<prev->value)
		// if new node smaller than ROOT then make it as left child
		prev->ltree=temp;
		// otherwise if new node greater than ROOT then make it as right child
	else if(flag==0&&temp->value>prev->value)
		prev->rtree=temp;
	return root;
}

// Recursive INORDER traversal function
void in(NODE IN){
	// if tree is not empty then traverse
	if(IN!=NULL){
		in(IN->ltree);			// left child
		printf("%d\t",IN->value);	// Root
		in(IN->rtree);			// right child
	}
}

// Recursive PREORDER traversal function
void pre(NODE PRE){
	// if tree is not empty then traverse
	if(PRE!=NULL){
		printf("%d\t",PRE->value);	// Root
		pre(PRE->ltree);		// left child
		pre(PRE->rtree);		// right child
	}
}

// Recursive POSTORDER traversal function
void post(NODE POST){
	// if tree is not empty then traverse
	if(POST!=NULL){
		post(POST->ltree);		// left child
		post(POST->rtree);		// right child
		printf("%d\t",POST->value);	// Root
	}
}

// Binary Search on BST for given Key element
void search(NODE root){
	int item,found=0;
	NODE cur;
	printf("Enter the element to be searched : ");
	scanf("%d",&item);			// read key
	
	// check for empty tree
	if(root==NULL)
		printf("tree is empty\n");
	
	// for non-empty tree search for key in BST
	cur=root;
	
	// repeat until end
	while(cur!=NULL){
		// check key and root value is same SUCESSFULL SEARCH
		if(item==cur->value){
			found=1;		// set flag
			printf("Found key %d in tree\n",cur->value);
		}
		
		// check key is greater than root value then choose right subtree
		if(item<cur->value)
			cur=cur->ltree;
		else
			// otherwise choose left subtree
			cur=cur->rtree;
	}

	// if found flag is Zero then UNSUCESSFULL SEARCH
	if(found==0)
		printf("Key not found\n");
}

int main(){
	int choice,item,n,i;
	NODE root=NULL;
	printf("\n1. Create BST of N Integers \
		\n2. BST Traversal \
		\n3. Binary Search \
		\n4. Exit"
	);

	while(1){
		printf("\n> ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nEnter number elements : ");
				scanf("%d",&n);
				printf("Enter the item(s) to be inserted : \n");
				
				for(i=0;i<n;i++){
					scanf("%d",&item);
					root=create(item,root);
				}
				
				break;
			case 2:
				// check for empty tree
				if(root==NULL){
					printf("Tree is empty\n");
					break;
				}else{
					// for non-empty tree traverse BST
					printf("\n\nPREORDER traversal\n");
					pre(root);
					printf("\n\nINORDER traversal\n");
					in(root);
					printf("\n\nPOSTORDER traversal\n");
					post(root);
				}
				break;
			case 3:
				search(root);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Choice !\n");
		}
	}
}
