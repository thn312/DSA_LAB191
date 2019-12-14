#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>
#include <time.h>

using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *left = NULL;
    node<T> *right = NULL;
    int balance = 0;
    node(T data)
    {
        this->data = data;
    };

    // you can implement other relevant things here
    // TODO



};

template <typename T>
class AVLtree
{
    node<T> *root = NULL;
    
    // you can implement other relevant things here
    // TODO
int height(node<T> *root) {
		return (root==NULL)?-1:root->balance;
	}
	int max(int a, int b) {
		return (a >= b) ? a : b;
	}
	node<T>* rightRotate(node<T>* root) {
		node<T>* temp = root->left;
		root->left = temp->right;
		temp->right = root;

		root->balance = max(height(root->left), height(root->right)) + 1;
		temp->balance = max(height(temp->left), root->balance) + 1;
		return temp;
	}
	node<T>* leftRotate(node<T>* root) {
		node<T>* temp = root->right;
		root->right = temp->left;
		temp->left = root;

		root->balance = max(height(root->left), height(root->right)) + 1;
		temp->balance = max(height(temp->right), root->balance) + 1;
		return temp;
	}
	node<T>* RLrotate(node<T>* root) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	node<T>* LRRotate(node<T>* root) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	node<T>* add(node<T>* &root, int data) {
		if (root == NULL) {
			root = new node<T>(data);
			root->balance = 0;
			root->left = root->right = NULL;
		}
		else if (data < root->data) {
			root->left = add(root->left, data);

			if (height(root->left) - height(root->right) == 2) {
				if (data < root->left->data) root = rightRotate(root);
				else root = RLrotate(root);
			}
		}

		else if(data >= root->data){
			root->right = add(root->right, data);
			
			if (height(root->left) - height(root->right) == -2) {
				if (data >= root->right->data) root = leftRotate(root);
				else root = LRRotate(root);
			}
		}

		root->balance = max(height(root->left), height(root->right)) + 1;
		return root;

	}


    void print(node<T> *&subroot)
    {
        if (subroot == 0)
        {
            cout << '*';
            return;
        }
        cout << subroot->data;
        cout << '(';
        print(subroot->left);
        cout << '|';
        print(subroot->right);
        cout << ')';
        return;
    }

public:
    AVLtree() {}

    // the add function:
    bool add(T &data)
    {
        // TODO
return add(root,data);

    }

    void print()
    {
        print(root);
    }
};


int main(int argc, char* argv[]) {
    ifstream inFile;
	int i;
	inFile.open(argv[1]);
	AVLtree<int> *a=new AVLtree<int>;

	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while(inFile>>i){
		a->add(i);
	}
    a->print();
	inFile.close();
	return 0;
}
