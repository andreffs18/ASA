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
#include <iostream>		// for std::cout and endl,
#include <vector>		// for list declaration
#include <limits.h>  	// for INT_MAX
#include <stdio.h>		// standard library

using namespace std;
/********************************************************************
	Class and global variables
*********************************************************************/

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int n, e;	// v - number of locals, e - number of costs (edges)
int source;	// int number corresponding to the source of the graph

/********************************************************************
	Main program
*********************************************************************/
int main(){
	// scans first two integers (total of localities and total of costs)
	scanf("%u %u", &n, &e);
	// scans company's place? (source)
	scanf("%u", &source);
	source = source-1;

	Edge edges[e];
	int dist[n], aux[n];
	bool impossible[n], force_break;

	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
		aux[i] = INT_MAX;
		impossible[i] = false;
	}
	dist[source] = 0;
	aux[source] = 0;

	// scans all costs per location and populates graph
	for (int i = 0; i < e; i++){
		int u, v, w;  // a & b are elements in the graph (the previews "node") w is the cost
		scanf("%u %u %u", &u, &v, &w);
		edges[i].u = u-1;
		edges[i].v = v-1;
		edges[i].w = w;
	}

	// runs Bellman Ford algorithm
	for(int i = 1; i < n-1; i++){
		force_break = true;

		for(int j = 0; j < e; j++){
			Edge e = edges[j];
			if(dist[e.u] == INT_MAX) continue;
			if(dist[e.v] > dist[e.u] + e.w){
				dist[e.v] = dist[e.u] + e.w;
				aux[e.v] = aux[e.u] + e.w;
				force_break = false;
			}
		}
		if(force_break) break;
	}

	for(int counter = 0; counter < 2; counter++){
		for(int j = 0; j < e; j++){
			Edge e = edges[j];
			if(dist[e.u] == INT_MAX) continue;
			if(aux[e.v] > aux[e.u] + e.w){
				aux[e.v] = aux[e.u] + e.w;

				if(!impossible[e.v]){
					impossible[e.v] = true;
					counter = 0;
				}
			}
		}
	}

	for(int j = 0; j < n; j++){
        if(j == source)
            cout << "0" << endl;
        else if(impossible[j])
            cout << "I" << endl;
        else if(dist[j] == INT_MAX)
            cout << "U" << endl;
        else
            cout << dist[j] << endl;
   	}
}
