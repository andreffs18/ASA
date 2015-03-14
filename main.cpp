#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

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
		void add_coauthor(int i){
			coauthors.push_back(i);
		}
};

int n, r;
int paul;
int a, ca;

vector<Author*> author;
vector<int> stack;




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
	for(int i=0; i<r; i++){
		scanf("%u %u", &a, &ca);
		author[a-1]->add_coauthor(ca-1);
	}






	// // create a file-reading object
	// std::ifstream fin;
	// fin.open("input.txt"); // open a file
	// if(!fin.good()) return 1; // exit if file not found

	// // read each line of the file
	// while(!fin.eof()){
	// 	// read an entire line into memory
	// 	char buf[MAX_CHARS_PER_LINE];
	// 	fin.getline(buf, MAX_CHARS_PER_LINE);
		
	// 	// parse the line into blank-delimited tokens
	// 	int n = 0; // a for-loop index
	// 	// array to store memory addresses of the tokens in buf
	// 	const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

	// 	// parse the line
	// 	token[0] = strtok(buf, DELIMITER); // first token

	// 	if(token[0]){ // zero if line is blank
	// 		for (n = 1; n < MAX_TOKENS_PER_LINE; n++){
	// 			token[n] = strtok(0, DELIMITER); // subsequent tokens
	// 			if (!token[n]) break; // no more tokens
	// 		}

	// 		// process (print) the tokens
	// 		for (int i = 0; i < n; i++) // n = #of tokens
	// 			std::cout << "Token[" << i << "] = " << token[i] << std::endl;
	// 		std::cout << std::endl;
	// 	  }
	// }
}
