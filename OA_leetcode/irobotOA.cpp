#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int,int>> P;
bool uniquepath(vector<vector<int>>& grid, int k){
    int m = grid.size(), n = grid[0].size();
    //BFS
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> visited(m,vector<bool>(n,false));

    priority_queue<P, vector<P>, greater<P>> pq; // min heap : (cost , (x,y)) 
    pq.push(make_pair(0,make_pair(0,0)));
    
    while(!pq.empty()){
        int size = pq.size();
        for(int i = 0 ; i < size; ++i){
            P t = pq.top();pq.pop();
            if(t.first > k) return false;
            for(auto dir : dirs){
                int x = t.second.first + dir[0],y = t.second.second + dir[1]; // new coordinate
                if(x < 0 || y < 0 || x >= m || y >= n ||grid[x][y] == 1 || visited[x][y]) continue;
                pq.push(make_pair(t.first+1,make_pair(x,y)));
                visited[x][y] = true;
            }
        }
    }

    return visited[m-1][n-1] ? true : false;
    
    
}
int main(){
    vector<vector<int>> grid = {{0,0,0,0,0,0}, {1,1,1,1,0,0},{0,0,0,0,0,0},{0,0,1,1,1,1},{0,0,0,0,0,0}};
    bool out = uniquepath(grid, 15);
    cout << out;
}































#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}



















/*
 * Complete the 'find_nth_element' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER nthElement
 *  2. INTEGER_SINGLY_LINKED_LIST head
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int find_nth_element(int nthElement, SinglyLinkedListNode* head) {
    if(!head) return -1;
    SinglyLinkedListNode* first = head;
    SinglyLinkedListNode* second = head;
    int count = 0;
    while(nthElement>0 && second->next){
        nthElement--;
        second = second->next;
    }
    if(nthElement != 0) return -1;
    // int count = nthElement+1;
    while(second->next){

        first = first->next;
        second = second->next;
    }
    
    cout << second->data;
    return first->data;
}

int main()