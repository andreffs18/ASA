#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Author{
	int is_paul;
	vector<int> coauthors;
	public:
		Author(){
			is_paul = false;
		}
		void im_paul(){
			is_paul = true;
		}
		int get_coauthors(int i){
			return coauthors[i];
		}
		void add_coauthor(int i){
			coauthors.push_back(i);
		}
		bool has_coauthor(int i){
			return (find(coauthors.begin(), coauthors.end(), i) != coauthors.end());
		}
		int total_coauthors(){
			return coauthors.size();
		}
};

int n, r;
int paul;
int a, ca;

vector<Author*> author;
queue<int> q;
vector<int> dist;

bool is_connected(int x, int y){
	return author[x]->has_coauthor(y);
}

int main(){
	// scans first two integers (number of people and number of relations)
	scanf("%u %u", &n, &r);

	// creates amount of authors
	for(int i = 0; i < n; i++)
		author.push_back(new Author());
	
	// scans and sets paul erdos number
	scanf("%u", &paul);
	author[paul-1]->im_paul();

	// scans #r relations of coauthors
	for(int i = 0; i < r; i++){
		scanf("%u %u", &a, &ca);
		author[a-1]->add_coauthor(ca-1);
	}



	for(int i = 0; i < n; i++){
		cout << "coauthors of " << i+1 << ":\n\t";
		for(int j = 0; j < author[i]->total_coauthors(); j++){
			cout << author[i]->get_coauthors(j) << " ";
		} 
		cout << endl;
	}


	// keeps track os explored vertices
	bool *explored = new bool[n];
	for(int i = 0; i < n; i++)
		explored[i] = false; 

	// set paul vertice as first in the queue
	q.push(paul-1);
	explored[paul-1] = true;

	// print notification
	cout << "BFS starting in vertice " << paul << endl;

	// Unless the queue is empty
	while (!q.empty()){
		// Pop the vertex from the queue
		int v = q.front();
		q.pop();

		// display the explored vertices
		cout << v << endl;

		// From the explored vertex v try to explore all the
		// connected vertice s
		for (int w = 0; w < n; w++){
			if(w == v) continue;	
			// Explores the vertex w if it is connected to v
			// and and if it is unexplored
			if (is_connected(v, w) && !explored[w]) {
				cout << "adding w" << endl;
				// adds the vertex w to the queue
				q.push(w);
				explored[w] = true;
			}
		}
	}
	cout << endl;
}
