/********************************************************************
Projecto de ASA, 2014-2015 2' Semestre
LEIC - IST @ ALAMEDA

Grupo 162
Francisco Dias, Nº 75328
Andre Silva, Nº 75455
*********************************************************************/

/********************************************************************
	includes & defines
*********************************************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/********************************************************************
	Class and global variables
*********************************************************************/
class Author{
private:
	vector<int> coauthors;
public:
	Author(){}
	int get_coauthor(int i){ return coauthors[i]; }
	void add_coauthor(int i){ coauthors.push_back(i); }
	bool has_coauthor(int i){
		return (find(coauthors.begin(), coauthors.end(), i) != coauthors.end());
	}
	int total_coauthors(){ return coauthors.size(); }
};

int n, r;	// n - number of nodes, r - number of vertices (relations)
int paul;	// number corresponding to the origin of the graph (Paul erdos)
// global control variable to check if index node was already checked
bool *visited;
int *dist;
// global array of objects "authors"
vector<Author*> author;
// global queue "q"
queue<int> q;

/********************************************************************
	vector Author handling
	Wrappers around the vector Author 
*********************************************************************/
// creates new instance of an author in authors vector
void add_node(){
	author.push_back(new Author);
}
// adds coathor to authors "x" list
void add_vertice(int x, int y){
	author[x]->add_coauthor(y);
	author[y]->add_coauthor(x);
}
// check is author "x" has coauthor "y"
bool is_connected(int x, int y){
	return author[x]->has_coauthor(y);
}
// set some dependencies
// -> visited, populated array with all entries = False (control)
// -> dist, populates array with all entries = 0 (control)
void set_dependencies(){
	visited = new bool[n]; 
	dist = new int[n];

	for(int i = 0; i < n; i++){
		visited[i] = false; 
		dist[i] = INT_MAX;
	}
}

/********************************************************************
	Queue handling
	Wrappers around queue "q" 
*********************************************************************/
// returns true is queue is empty
bool queue_is_empty(){
	return q.empty();
}
// add int to the queue array 
void queue_push(int x){
	q.push(x);
	visited[x] = true;
}
// pop top value from queue
int queue_pop(){
	int v = q.front(); q.pop();
	return v;
}

/********************************************************************
	Main program
*********************************************************************/
int main(){
	// scans first two integers (number of people and number of relations)
	// creates amount of authors
	scanf("%u %u", &n, &r);
	for(int i = 0; i < n; i++) add_node();
	
	// scans paul erdos number
	scanf("%u", &paul); paul -= 1;

	// scans #r relations of coauthors
	for(int i = 0; i < r; i++){
		int a, ca;
		scanf("%u %u", &a, &ca);
		add_vertice(a-1, ca-1);
	}

	// sets control variables to false, infinity, what not
	set_dependencies();

	// set paul vertice as first in the queue
	queue_push(paul);
	dist[paul] = 0;

	// Unless the queue is empty
	while (!queue_is_empty()){
		// Mark and pop the vertex from the queue
		int u = queue_pop();

		// From the visited vertex v try to explore all the connected vertice s
		for(int v = 0; v < author[u]->total_coauthors(); v++){
			// get adj coauthor
			int c = author[u]->get_coauthor(v);
			if(!visited[c]){
				queue_push(c);
				dist[c] = dist[u] + 1;
			}
		}
	}

	// sort array ascending
	sort(dist, dist + n);

	// get biggest distance between paul's and nodes
	int c = dist[n-1];
	printf("%d\n", c);

	// print qtd of nodes p/distance
	for(int i = 1, c = 1; i < n; i++, c++){
		if(i+1 > n || dist[i] != dist[i+1]){
			printf("%d\n", c);
			c = 0;
		}
	}	
}
