#include <iostream>
#include <fstream>
using namespace std;

// TODO
void QuickSort(int arr[], int left, int right){
    if(left>=right) return;
    int pivot = arr[(left+right)/2];
    int i = left; int j = right;
    while(i<=j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    QuickSort(arr,left,j);
    QuickSort(arr,i,right);
    }
}


void QuickSort(int arr[], int N) {
	// TODO
QuickSort(arr,0,N-1);

}

void insertionSort(int arr[], int start, int end){
    // TODO
	if (end <= 0) return;
	insertionSort(arr, 0, end-1);
	int last = arr[end];
	int j = end - 1;

	while (j >= 0 && arr[j] > last) {
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;

}

void swap(int arr[], int num1, int num2){
    int temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
}

void selectionSort(int arr[], int start, int end){
    // TODO
if (start == end) return;
int k = start;
int min = start;
while (k <= end) {
	if (arr[min] > arr[k]) min = k;		
    k++;
}

swap(arr[min], arr[start]);
selectionSort(arr, start + 1, end);

}

void print(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ifstream ifs;
	int i = 0;
	int N;
	
	ifs.open(argv[1]);
	if (!ifs) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	ifs >> N;
	int* arr = new int[N];
	while (ifs >> arr[i]) {
		i++;
	}
	QuickSort(arr, N);
	print(arr, N);
	return 0;
}

//----------------------------------------------------------------------------------------//
#include <iostream>  
#include <fstream>
using namespace std;

class Adjacency
{
private:
	int* arr;
	int size;
public:
	Adjacency() {}
	Adjacency(int v) {
		arr = new int[v];
		size = 0;
	}
	void init(int v) {
		arr = new int[v];
		size = 0;
	}
	void push(int v) {
		arr[size] = v;
		size++;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << "-> " << arr[i];
		}
		cout << endl;
	}
	void printArray() {
		for (int i = 0; i < size - 1; i++) {
			cout << arr[i] << " ";
		}
		cout << arr[size - 1] << endl;
	}
	int getSize() {return size;}
	int getElement(int idx) {return arr[idx];}
};

class Graph
{
private:
	int V;   
	Adjacency* adj;

public:
	Graph(int V) {
		this->V = V;
		adj = new Adjacency[V];
		for (int i = 0; i < V; i++) {
			adj[i].init(V);
		}
	}

	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
	void DFSUtil(int v, bool visited[], Adjacency* arr);
	Adjacency* DFS(int v);

	void printGraph() {
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
};

void Graph::DFSUtil(int v, bool visited[], Adjacency* arr) {
	//Use Adjacency->push(...) to add v to Adjacency
	//Use Adjacency->getSize() to get number of element in Adjacency list
	//Use Adjacency->getElement(index) to access to Adjacency list
	// TODO
visited[v] = true;
	arr->push(v);

	for (int i = 0; i < adj[v].getSize(); i++) {
		if (visited[adj[v].getElement(i)] == false) {
			DFSUtil(adj[v].getElement(i), visited, arr);
		}
	}

}

Adjacency* Graph::DFS(int v) {
	Adjacency* arr = new Adjacency(V);
	// TODO
bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	DFSUtil(v, visited ,arr);
	return arr;

}

int main(int argc, char* argv[]) {
	ifstream inFile;
	int V, visited;

	inFile.open(argv[1]);
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	inFile >> V >> visited;
	Graph g(V);
	Adjacency* arr = new Adjacency(V);
	int v, u;
	try {
		while (inFile >> u) {
			inFile >> v;
			g.addEdge(v, u);
		}
	}
	catch (char const* s) {
		printf("An exception occurred. Exception type: %s\n", s);
	}
	g.printGraph();
	arr = g.DFS(visited);
	arr->printArray();
	inFile.close();
	return 0;
}

//------------------------------------------------------------------------------------//
#include <iostream>  
#include <fstream>
#include <list>
using namespace std;

class Adjacency
{
private:
	int* arr;
	int size;
public:
	Adjacency() {}
	Adjacency(int v) {
		arr = new int[v];
		size = 0;
	}
	void init(int v) {
		arr = new int[v];
		size = 0;
	}
	void push(int v) {
		arr[size] = v;
		size++;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << "-> " << arr[i];
		}
		cout << endl;
	}
	void printArray() {
		for (int i = 0; i < size - 1; i++) {
			cout << arr[i] << " ";
		}
		cout << arr[size - 1] << endl;
	}
	int getSize() {return size;}
	int getElement(int idx) {return arr[idx];}
};

class Graph
{
private:
	int V;   
	Adjacency* adj;

public:
	Graph(int V) {
		this->V = V;
		adj = new Adjacency[V];
		for (int i = 0; i < V; i++) {
			adj[i].init(V);
		}
	}

	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
	Adjacency* BFS(int v);

	void printGraph() {
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
};

Adjacency* Graph::BFS(int v)
{
	/*
	Using list<int> queue to store vertex
	Some useful method:
	- <list object>.push_back(...)
	- <list object>.front()
	- <list object>.pop_front()
	- <list object>.push_back(...)
	*/
		bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	Adjacency* arr = new Adjacency(V);
	list<int> queue;

	visited[v] = true;
	queue.push_back(v);

	while (!queue.empty()) {
		v = queue.front();

		queue.pop_front();
		arr->push(v);
		for (int i = 0; i < adj[v].getSize(); i++) {
			if (visited[adj[v].getElement(i)] == false) {
				visited[adj[v].getElement(i)] = true;
				queue.push_back(adj[v].getElement(i));
			
			}
		}

	}
	return arr;
}

int main(int argc, char* argv[]) {
	ifstream inFile;
	int V, visited;

	inFile.open(argv[1]);
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	inFile >> V >> visited;
	Graph g(V);
	Adjacency* arr = new Adjacency(V);
	int v, u;
	try {
		while (inFile >> u) {
			inFile >> v;
			g.addEdge(v, u);
		}
	}
	catch (char const* s) {
		printf("An exception occurred. Exception type: %s\n", s);
	}
	g.printGraph();
	arr = g.BFS(visited);
	arr->printArray();
	inFile.close();
	return 0;
}
 //---------------------------------------------------------------------------------------//
 #include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<list>
using namespace std; 

class Graph 
{ 
	int V; 

	list<int> *adj; 

	vector<int> indegree; 

	void alltopologicalSortUtil(vector<int>& res, bool visited[]); 

public: 
	Graph(int V); 

	void addEdge(int v, int w); 

	void alltopologicalSort(); 
    Graph(){
        V = 0;
        adj = NULL;
    } 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 

	for (int i = 0; i < V; i++) 
		indegree.push_back(0); 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 

	indegree[w]++; 
} 

void Graph::alltopologicalSortUtil(vector<int>& res, bool visited[]) 
{ 
		bool flag = false;

	for (int i = 0; i < V; i++)
	{
		if (indegree[i] == 0 && !visited[i])
		{
		
			list<int>::iterator j;
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]--;

			res.push_back(i);
			visited[i] = true;
			alltopologicalSortUtil(res, visited);


			visited[i] = false;
			res.erase(res.end() - 1);
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]++;

			flag = true;
		}
	}
	if (!flag)
	{
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
} 

void Graph::alltopologicalSort() 
{ 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	vector<int> res; 
	alltopologicalSortUtil(res, visited); 
} 

int main(int argc, char** argv) 
{ 
	ifstream inFile;
    string input;
    
    inFile.open(argv[1]);

    if(!inFile)
	{
        cout<<"Unable to open file"<<endl;
        exit(1);
    }

	Graph g; 
    int numNodes;
	int count = 0;
	while (getline(inFile, input)) 
	{
		if(count == 0) {numNodes = stoi(input); g = (numNodes); count++; continue;}
		stringstream s(input);
		int src, dst;
		s >> src >> dst;
        g.addEdge(src, dst);
	}

	cout << "All Topological sorts\n"; 

	g.alltopologicalSort(); 

	return 0; 
} 

//----------------------------------------------------------------------------------//

#include<iostream> 
#include <list> 
#include <limits.h> 
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Graph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public: 
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
    Graph(){
        V = 0;
        adj = NULL;
    }
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
} 

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
	if(visited[v] == false) 
	{ 
		visited[v] = true; 
		recStack[v] = true; 

		list<int>::iterator i; 
		for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		{ 
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
				return true; 
			else if (recStack[*i]) 
				return true; 
		} 

	} 
	recStack[v] = false;
	return false; 
} 

bool Graph::isCyclic() 
{ 
	// TODO
bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 

} 

int main(int argc, char** argv) 
{ 
    ifstream inFile;
    string input;
    
    inFile.open(argv[1]);

    if(!inFile)
	{
        cout<<"Unable to open file"<<endl;
        exit(1);
    }

	Graph g; 
    int numNodes;
	int count = 0;
	while (getline(inFile, input)) 
	{
		if(count == 0) {numNodes = stoi(input); g = (numNodes); count++; continue;}
		stringstream s(input);
		int src, dst;
		s >> src >> dst;
        g.addEdge(src, dst);
	}

	if(g.isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
		
	return 0; 
} 
