#include <bits/stdc++.h>
#include<iostream>
#define COUNT 5
using namespace std;

struct Node {
	int key;
    	/*double obj_value;
    	std::vector<double> obj_coeffs;
    	std::vector<int> variables_used; 
	int n;*/
    	Node* left;
    	Node* right;
};


struct Node* newNode(int key) //, int obj_value, vector<double> obj_coeffs, vector<int> variables_used, int n, int k)
{
    	Node* node = new Node;
	node->key = key;
    	/*node->obj_value = obj_value;
    	node->obj_coeffs = obj_coeffs;
	node->variables_used = variables_used;
	node->n = n;
	node->k = k;
	*/
    	node->left = NULL;
    	node->right = NULL;
    	return node;
}
struct Node* SearchNode(int key, struct Node* ptr){
	if (ptr->key == key){
		return ptr;
	}
	else if(ptr->left->key == key){
		return ptr->left;
	}
	else if(ptr->right->key == key){
		return ptr->right;
	}
	else if (ptr->left != NULL and ptr->right != NULL){
		Node *l = SearchNode(key, ptr->left);
                Node *r = SearchNode(key, ptr->right);
		if(l != NULL)
			return l;
		else if(r != NULL)
			return r;
		else
			return NULL;
	}
	else{
		return NULL;
	}
}

struct Node* insertNode(struct Node* root, int expand_key ,int key )//,double obj_value, vector<double> obj_coeffs, vector<int> variables_used, int n, int k){
{
    	Node* node = newNode(key);// ,obj_value, obj_coeffs, variables_used, n, k);
    	if (root == NULL){
        	root = node;
		return root;
	}
	else{
		Node* expand_node = SearchNode(expand_key, root);
        	if(expand_node == NULL){
			cout<<"In Insert Node expand key" <<expand_key<< "is not found";
			return NULL;
		}
		else{
			if(expand_node->left == NULL){
				expand_node->left = node;
				return expand_node;
			}
			else{
				expand_node->right = node;
				return expand_node;
			}
		}
	}
}

void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";

    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}
