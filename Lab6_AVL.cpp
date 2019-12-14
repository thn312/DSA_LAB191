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
};

template <typename T>
class AVLtree
{
    node<T> *root = NULL;
   
	
   int number_of_node(node<T>* &root) {
		int count1 = 1;
	
		if (root == NULL) return 0;
		count1 += number_of_node(root->left);
		count1 += number_of_node(root->right);
		return count1;
	}
	
	
    // TODO ID: 452
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
	
	// ID: 453
	node<T>* minRight(node<T>* root) {
		node<T>* temp = root;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}
	node<T>* remove(node<T>* &root, int data) {
		if (root == NULL) return root;

		if (data < root->data) root->left = remove(root->left, data);
		else if (data > root->data) root->right = remove(root->right, data);
		else {
			if ((root->left == NULL) || (root->right == NULL)) {
				node<T>* temp = root->left ? root->left : root->right;

				if (temp == NULL) {
					temp = root;
					root = NULL;
				}
				else *root = *temp;

				free(temp);
			}
			else {
				node<T>* temp = minRight(root->right);
				root->data = temp->data;
				root->right = remove(root->right, temp->data);
			}
		}
		if (root == NULL) return root;

		root->balance = max(height(root->left), height(root->right)) + 1;
		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
		if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}
 
	
void traverse_RNL(node<T>* &root, node<T>* &subroot){
    if(root != NULL){
        traverse_RNL(root->right,subroot);
        add2(subroot,root->data);
        traverse_RNL(root->left,subroot);
    }
}

void add2(node<T>* &root, T data){
    if(root == NULL){
        root = new node<T>(data);
    }
    else add2(root->right,data);
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

    void traverse_LNR(void f(node<T> *, void *), void *params = 0)
    {
        // TODO
	f(root,params);

    }
    void print()
    {
        print(root);
    }
	
    T *search_max(bool f(node<T> *, void *), void *params = 0)
    {
        // TODO
traverse_RNL(root,subroot);
while(subroot){
    if(f(subroot,params)){
        return &subroot->data;
    }
    subroot=subroot->right;
}
return NULL;

    }
	
   int number_of_node()
    {
       // TODO
return number_of_node(root);
    }

    int height()
    {
       // TODO
return height(root);

    }

};


class LinkList
{
public:
    int data;
    LinkList *next;

    LinkList(int data)
    {
        this->data = data;
        next = 0;
    }
    void add(int data)
    {
        LinkList *temp = this;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new LinkList(data);
        temp = 0;
        return;
    }
};

template <typename T>
void toLinkList(node<T> *subroot, void *param)
{
    // TODO
LinkList *p = static_cast<LinkList*>(param);
	if (subroot) {
		toLinkList(subroot->left, param);
		p->add(subroot->data);
		toLinkList(subroot->right, param);
	}


}

template<typename T>
bool div_98(node<T> *subroot, void *params)
{
    // TODO
if(subroot->data % 98 == 0) return true;
return false;

}

int main(int argc, char* argv[]) {
	return 0;
}
