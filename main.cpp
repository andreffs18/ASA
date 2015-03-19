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
#include <vector>
#include <queue>

using namespace std;

/********************************************************************
	Class and global variables
*********************************************************************/
class Author{
private:
	vector<int> coauthors;
	int _distance;
public:
	Author(){}
	int get_coauthor(int i){ return coauthors[i]; }
	void add_coauthor(int i){ coauthors.push_back(i); }
	bool has_coauthor(int i){
		return (find(coauthors.begin(), coauthors.end(), i) != coauthors.end());
	}
	int total_coauthors(){ return coauthors.size(); }
	int get_distance(){ return _distance; }
	void set_distance(int value){ _distance = value; }
};

int n, r;	// n - number of nodes, r - number of vertices (relations)
int paul;	// number corresponding to the origin of the graph (Paul erdos)
// global control variable to check if index node was already checked
bool *visited = new bool[n];
// global array of objects "authors"
vector<Author*> author;
// global queue "q"
queue<int> q;

/********************************************************************
	vector Author handling
	Wrappers around the vector Author
*********************************************************************/
// prints graph state
void print_graph(){
	for(int i = 0; i < n; i++){
		cout << i << ": ";
		for(int j = 0; j < author[i]->total_coauthors(); j++){
			cout << author[i]->get_coauthor(j) << " ";
		}
		cout << endl;
	}
}
// creates new instance of an author in authors vector
void add_node(){
	author.push_back(new Author);
}
// adds coathor to authors "x" list
void add_vertice(int x, int y){
	author[x]->add_coauthor(y);
}
// check is author "x" has coauthor "y"
bool is_connected(int x, int y){
	return author[x]->has_coauthor(y) || author[y]->has_coauthor(x);
}
// set some dependencies
// -> visited, populated array with all entries = False (control)
// -> dist, populates array with all entries = 0 (control)
void set_dependencies(){
	for(int i = 0; i < n; i++){
		visited[i] = false;
		//dist[i] = 0;
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
		cout << a << " " << ca << endl;
		add_vertice(a-1, ca-1);
	}

	// sets control variables to false, 0, what not
	set_dependencies();

	// print_graph();
	// set paul vertice as first in the queue
	queue_push(paul);
	author[paul]->set_distance(0);

	// print notification
	cout << "BFS starting in vertice " << paul << endl;

	int distance = 0;

	// Unless the queue is empty
	while (!queue_is_empty()){
		// Mark and pop the vertex from the queue
		int v = queue_pop();
		// display the visited vertices
		// cout << "Pop from queue " << v << endl;

		distance = 	author[v]->get_distance();

		// From the visited vertex v try to explore all the connected vertice s
		for(int w = 0; w < n; w++){
			// if the current v is the same as the one we are searching
			// or if both are not connected, just skip
			if(w == v || !is_connected(v, w)) continue;
			// if still not visited, go ahead and add it to the queue
			if(!visited[w]){
				// cout << "adding " << w << " to queue" << endl;
				queue_push(w);
				author[w]->set_distance(distance+1);
				// dict[w] = 1;
			}

		}
	}

	// print qtd of nodes p/distance
	for(int i = 0; i < n; i++)
		cout << "Author " << i+1 << " - " << author[i]->get_distance() << endl;
}
