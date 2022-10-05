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

struct Node {
	int val;
	Node *left;
	Node *right;
};

Node *getNewNode(int val) {

	Node *newNode = new Node();
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;

}

Node *insertNode(Node *root, int val) {

	if(root == NULL) {
		root = getNewNode(val);
	}
	else if(val <= root->val) root->left = insertNode(root->left, val);
	else root->right = insertNode(root->right, val);
	return root;
}

void leverOrder(Node *root) {
	if(root == NULL) return;
	queue<Node *> q;
	q.push(root);

	while(!q.empty()) {

		Node *top = q.front();
		cout << top->val << endl;

		if(top->left) q.push(top->left);
		if(top->right) q.push(top->right);

		q.pop();

	}
}

void preOrder(Node *root) {
	if(root == NULL) return;

	cout << root->val << endl;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root) {
	if(root == NULL) return;

	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}

void postOrder(Node *root) {
	if(root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Node *root = NULL;
	cout << "Enter 8 numbers to construct the BST: "<< endl;
	for(int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		root = insertNode(root, a);
	}

	cout << "Level order traversal of the tree: " << endl;
	
	leverOrder(root);

	cout << "Pre order traversal of the tree: " << endl;
	
	preOrder(root);

	cout << "Inorder traversal of the tree: " << endl;
	
	inOrder(root);

	cout << "Post order traversal of the tree: " << endl;
	
	postOrder(root);

	return 0;
}