#include<stdio.h>
#include<iostream>
#include<cctype>

using namespace std;

/*Creating a BST from a list of integers*/

struct node{
	int data;
	struct node *left;
	struct node *right;
	
	node() {
		left = right = NULL;
	}
};

//function to insert x into the BST
struct node * insertBST(struct node *root, int x){
	
	struct node *temp = new node;
	temp->data = x;
	
	if(root == NULL)
		root = temp;
	else{
		if(x < root->data)
			root->left = insertBST(root->left, x);
		else
			root->right = insertBST(root->right, x);
	}
	
	return root;
}

//function to print preorder sequence
void printPreorder(struct node *root){
	if(root!=NULL){
		cout<<root->data<<'\t';
	}
	else return;
	printPreorder(root->left);
	printPreorder(root->right);
}

//function to print inorder sequence
void printInorder(struct node *root){
	if(root==NULL) return;
	printInorder(root->left);
	cout<<root->data<<'\t';
	printInorder(root->right);
}


int main(){
	struct node *root = new node;
	int a[8] = {12, 2, 56, 82, 22, 5, 45, 9};
	
	for(int i = 0; i<8; ++i)
		root = insertBST(root, a[i]);
	
	cout<<"Preorder sequence:\n";
	printPreorder(root);
	
	cout<<"\nInorder sequence:\n";
	printInorder(root);
	
	delete root;
	return 0;
}
