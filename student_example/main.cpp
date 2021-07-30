#include <iostream>
#include <vector>

using namespace std;

class student{
    public:
    string name;
    double gpa;
    vector<double> classScores;
};

int main(){
    student s;
    s.name = "bob";
    s.gpa = 2.0;
    s.classScores.push_back(4.0);
    s.classScores.push_back(0.0);
    s.classScores.push_back(2.0);
    
    cout << "Student name: " << s.name << endl;
    cout << "GPA: " << s.gpa << endl;
    for(int i = 0; i < s.classScores.size(); i++){
        cout << "class " << i << " score: " << s.classScores.at(i) << endl;
        
    }
    
    return 0;
    
}