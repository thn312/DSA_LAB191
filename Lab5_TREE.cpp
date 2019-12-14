#include <iostream>
#include <fstream>

using namespace std;

class Node 
{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

};

class BinaryTree
{
    private:
    Node* root = NULL;

    bool insert(Node* &root, int value) {
		if (root == NULL) {
			root = new Node();
			root->data = value;
			return true;
		}
		else if (root->data > value) {
			return insert(root->left, value);
		}
		else return insert(root->right, value);
    }

    // TODO ID:445
    bool find(Node* &root, int value){
		if (root == NULL) return 0;

		if (value < root->data) return find(root->left, value);

		else if (value > root->data) return find(root->right, value);

		else return root;
}
    // TODO ID: 446
    bool insert(Node* &root, int value) {
		if (root == NULL) {
			root = new Node();
			root->data = value;
			return true;
		}
		else if (root->data > value) return insert(root->left, value);
		else return insert(root->right, value);

}
    // TODO ID: 448
    void inOrder(Node* &root) {
		if (root != NULL) {
			inOrder(root->left);
			cout << root->data;
			inOrder(root->right);
			
		}
	}
    
    void insert(Node* &root, int* arr, int size, int index) {
		if(index < size){
			Node* p = new Node();
			p->data = arr[index];
			root = p;
			
			insert(root->left,arr,size,2*index+1);
			insert(root->right,arr,size,2*index+2);
		}
	}
  
    //TODO ID: 449   
    int height(Node* &root) {
		  if(root == NULL) return 0;
		  if(root->left==NULL && root->right ==NULL) return 0;
		  int static h1 =0;
		  int static h2 =0;
		  h1 = height(root->left)+1;
		  h2 = height(root->right)+1;
		  h1>=h2?h1:h1=h2;
		  return h1;
    }
    
    //TODO ID: 450
    	bool find(Node* &root, int value) {
		if (root == NULL) return 0;

		if (value < root->data) return find(root->left, value);

		else if (value > root->data) return find(root->right, value);

		else return root;
	}

	int find_and_add(Node* &root, int value) {
		int static sum = 0;
		if (value < root->data) {
			sum += root->data;
			return find_and_add(root->left, value);
		}
		else if (value > root->data) {
			sum += root->data;
			return find_and_add(root->right, value);

		}
		int temp = sum + value;
		sum = 0;
		return temp;
	}
  
    public:

    bool insert(int value)
    {
        return insert(root, value);
    }

   	void insert(int* arr, int size) {
		// TODO
    insert(root,arr,size,0);
  	}
    bool find(int value)
    {
        // TODO
    return find(root,value);

    }
    void inOrder()
	  {
		// TODO
    inOrder(root);
	}
	
    void find_and_add(int value)
    {
      // TODO
 if(find(root, value)==0) cout <<"Cannot find!" <<endl;
else cout << find_and_add(root, value) <<endl;

    }
  
};

int main(int argc, char* argv[]) {
	BinaryTree bt;
	ifstream inFile;
	int val;
    char command;
	inFile.open(argv[1]);
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (inFile >> command) {
		switch(command)
        {
            case 'i':   // Insert value to BST
                inFile >> val;
                bt.insert(val);
                break;            
            case 'f':
                inFile >> val;
                cout << bt.find(val) << endl;
                break;
        }
	}

    inFile.close();
    return 0;
    
}
