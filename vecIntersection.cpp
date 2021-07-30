// Given two vector of strings, return a vector that contains unique strings common to both (intersection)
//Emily Schadt 5/28/21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> findCommon(vector<string>& v1, vector<string>& v2);

int main() {
	vector<string> vec1{"C++", "is", "a", "general", "purpose", "programming", "language", "with", "a", "bias", "towards", "systems", "programming"};
	vector<string> vec2{"As", "artificial", "intelligence", "systems", "learn", "a", "language", "they", "exhibit", "the", "same", "biases", "as", "humans", "do" };
	vector<string> vec3 = findCommon(vec1, vec2);
	for (auto& word: vec3) {
		cout << word << " "; // Output - a language systems
	}
	cout << endl;
}

vector<string> findCommon(vector<string>& v1, vector<string>& v2) {
	vector<string> res;
	
	// Your code here
	
	//iterates through the elements of both vectors and adds the matching ones to res
	for(int i = 0; i < v1.size(); i++){
		for(int z = 0; z < v2.size(); z++){
			if(v1.at(i) == v2.at(z)){
					res.push_back(v1.at(i));
			}
		}
	}
	
	//deletes repeating elements in the res vector
	auto end = res.end();
	for (auto i = res.begin(); i != end; ++i) {
		end = remove(i + 1, end, *i);
	}
	res.erase(end, res.end());

	return res;
}
