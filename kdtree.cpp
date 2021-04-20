// /* \author Aaron Brown */
// // Quiz on implementing kd tree

// #include "../../render/render.h"
// #include <math.h>
// // Structure to represent node of kd tree
// struct Node
// {
// 	std::vector<float> point;
// 	int id;
// 	Node* left;
// 	Node* right;

// 	Node(std::vector<float> arr, int setId)
// 	:	point(arr), id(setId), left(NULL), right(NULL)
// 	{}
// };

// struct KdTree
// {
// 	Node* root;

// 	KdTree()
// 	: root(NULL)
// 	{}
// 	void Inserthelper(Node *&root, int depth, std::vector<float> point, int id ){
// 		if(root == NULL){
// 			root = new Node(point, id);
// 		}
// 		else{
			
// 			int x_y = depth % 2;
// 			if( point[x_y] < root->point[x_y] ) 
// 				Inserthelper(root->left, depth + 1, point, id);
// 			else
// 				Inserthelper(root->right, depth + 1, point, id);
// 		}
// 	}

// 	void insert(std::vector<float> point, int id)
// 	{
// 		// TODO: Fill in this function to insert a new point into the tree
// 		// the function should create a new node and place correctly with in the root 
// 		Inserthelper(root, 0 , point, id);

// 	}

// 	void SearchHelper(std::vector<float> target, float distanceTol, Node* root ,int depth, std::vector<int>& ids){
// 		if(root != NULL){
// 			if( (root->point[0] >= (target[0]-distanceTol)) && (root->point[0] <= (target[0]+distanceTol)) && (root->point[1] >= (target[1]-distanceTol)) && (root->point[1] <= (target[1]+distanceTol))){
// 				float distance = sqrt((root->point[0] - target[0]) * (root->point[0] - target[0]) + (root->point[1] - target[1]) * (root->point[1] - target[1]));
// 				if(distance < distanceTol)
// 					ids.push_back(root->id);
// 			}
// 			if( (target[depth % 2] - distanceTol) < root->point[depth % 2])
// 				SearchHelper(target, distanceTol , root->left, depth+1, ids);
// 			if( (target[depth % 2] + distanceTol) > root->point[depth%2] )
// 				SearchHelper(target, distanceTol , root->right, depth+1, ids);
// 		}
		
// 	}
// 	// return a list of point ids in the tree that are within distance of target
// 	std::vector<int> search(std::vector<float> target, float distanceTol)
// 	{
// 		std::vector<int> ids;
// 		SearchHelper(target, distanceTol, root, 0, ids);
// 		return ids;
// 	}
	
	

// };

// int main() {
    
// }




// A C++ program to demonstrate operations of KD tree 
// #include<bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std; 

  
int k = 2; 
  
// A structure to represent node of kd tree 
struct Node 
{ 
    vector<int> point;
    Node *left, *right; 
}; 
  
// A method to create a node of K D tree 
struct Node* newNode(vector<int> arr) 
{ 
    struct Node* temp = new Node; 
    int k = arr.size();
    for (int i=0; i<k; i++) 
       temp->point.push_back(arr[i]); 
  
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Inserts a new node and returns root of modified tree 
// The parameter depth is used to decide axis of comparison 
Node *insertRec(Node *root, vector<int> point, unsigned depth) 
{ 
    // Tree is empty? 
    if (root == NULL) 
       return newNode(point); 
  
    // Calculate current dimension (cd) of comparison 
    unsigned cd = depth % k; 
  
    // Compare the new point with root on current dimension 'cd' 
    // and decide the left or right subtree 
    if (point[cd] < (root->point[cd])) 
        root->left  = insertRec(root->left, point, depth + 1); 
    else
        root->right = insertRec(root->right, point, depth + 1); 
  
    return root; 
} 
  
// Function to insert a new point with given point in 
// KD Tree and return new root. It mainly uses above recursive 
// function "insertRec()" 
Node* insert(Node *root, vector<int> point) 
{ 
    return insertRec(root, point, 0); 
} 
  
// A utility method to determine if two Points are same 
// in K Dimensional space 
bool arePointsSame(vector<int> point1, vector<int> point2) 
{ 
    // Compare individual pointinate values 
    for (int i = 0; i < k; ++i) 
        if (point1[i] != point2[i]) 
            return false; 
  
    return true; 
} 
  
// Searches a Point represented by "point[]" in the K D tree. 
// The parameter depth is used to determine current axis. 
bool searchRec(Node* root, vector<int> point, unsigned depth) 
{ 
    // Base cases 
    if (root == NULL) 
        return false; 
    if (arePointsSame(root->point, point)) 
        return true; 
  
    // Current dimension is computed using current depth and total 
    // dimensions (k) 
    unsigned cd = depth % k; 
  
    // Compare point with root with respect to cd (Current dimension) 
    if (point[cd] < root->point[cd]) 
        return searchRec(root->left, point, depth + 1); 
  
    return searchRec(root->right, point, depth + 1); 
} 
  
// Searches a Point in the K D tree. It mainly uses 
// searchRec() 
bool search(Node* root, vector<int> point) 
{ 
    // Pass current depth as 0 
    return searchRec(root, point, 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    struct Node *root = NULL; 
    // int points[][k] 
    vector<vector<int>> points = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}}; 
    
    int n = points.size();
  
    for (int i=0; i<n; i++) 
       root = insert(root, points[i]); 
  
    vector<int> point1 = {10, 19}; 
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n"; 
  
    vector<int> point2 = {12, 19}; 
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n"; 
  
    return 0; 
} 