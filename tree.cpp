/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define dd double
#define pb push_back
#define mp make_pair

struct TreeNode {
	int val;
	int *left;
	int *right;
};

TreeNode *NewNode(int val)
{
	TreeNode *newNode = NULL;
	newNode->val = val;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}


TreeNode *Insert(TreeNode *root, int val)
{
	if(root == NULL)
	{
		root = NewNode(val);
	}
	else if(root->val >= val) root = Insert(root->left, val);
	else root = Insert(root->right, val);

	return root;
}

TreeNode *Search(TreeNode *root, int val)
{
	if(root == NULL) return NULL;
	else if(root->val == val) return root;
	else if(root->val >= val) return Search(root->left, val);
	else return Search(root->right, val);
}

int FindHeight(TreeNode *root)
{
	if(root == NULL)
		return -1;

	else return max(FindHeight(root->left), FindHeight(root->right))+1;

}

void levelorder(TreeNode *root)
{
	if(root == NULL) return;

	queue<TreeNode *> q;

	q.push(root);

	while(!q.empty())
	{
		TreeNode *curr = q.front();

		cout << curr->val << endl;

		if(curr->left != NULL) q.push(curr->left);
		if(curr->right != NULL) q.push(curr->right);

		q.pop();
	}
}

//Function to visit nodes in Preorder
void Preorder(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%c ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%c ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%c ",root->data); // Print data
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	TreeNode *root = NULL;



	return 0;
}