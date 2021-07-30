#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <unordered_set>
#include <stdio.h> 

using namespace std;

void cipher(vector<char> backletter, string enckey){
    int length = enckey.length();
    
            for (int d = 0; d < length; d++) {
                int c = enckey.at(d);
                if (islower(c)) {
                    enckey.at(d) = toupper(c);
                }   
            }
            
            vector<char> keyvec(enckey.begin(), enckey.end());
    
            unordered_set<int> s;
            auto end = copy_if(keyvec.begin(), keyvec.end(), keyvec.begin(),
                [&s](int const &i) {
                return s.insert(i).second;
            });
         
            keyvec.erase(end, keyvec.end());
            reverse(keyvec.begin(), keyvec.end());
            
            for (int b=0; b < keyvec.size(); b++){
                for(int a = 0; a<backletter.size(); a++){
                    if (backletter.at(a) == keyvec.at(b)){
                        backletter.erase(backletter.begin()+a);
                    }
                }
                backletter.insert(backletter.begin(), keyvec.at(b));
            }
            
    for(int i = 0; i < backletter.size(); i++){
                    cout << backletter.at(i) << " ";
                }
                cout << endl;
    //return backletter;
}
 
int main(int argc, char* argv[]){
    
    bool encrypt = false;
    
    bool decrypt = false;
    
    string enckey;
    string line;
    string writeline;
    vector<char> letters;
            for(int a = 0;a<26;a++){
                letters.push_back('A'+ a);
            }
    
    
    
    
    for(int i = 0; i < argc; i++){
        
        if(strcmp(argv[i], "-k")==0){
            enckey.assign(argv[i+1]);
            
            vector<char> backletter;
            for(int a = 25; a>=0; a--){
                backletter.push_back(letters.at(a));
            }
            /*
            int length = enckey.length();
    
            for (int d = 0; d < length; d++) {
                int c = enckey.at(d);
                if (islower(c)) {
                    enckey.at(d) = toupper(c);
                }   
            }
            
            vector<char> keyvec(enckey.begin(), enckey.end());
    
            unordered_set<int> s;
            auto end = copy_if(keyvec.begin(), keyvec.end(), keyvec.begin(),
                [&s](int const &i) {
                return s.insert(i).second;
            });
         
            keyvec.erase(end, keyvec.end());
            reverse(keyvec.begin(), keyvec.end());
            
            for (int b=0; b < keyvec.size(); b++){
                for(int a = 0; a<backletter.size(); a++){
                    if (backletter.at(a) == keyvec.at(b)){
                        backletter.erase(backletter.begin()+a);
                    }
                }
                backletter.insert(backletter.begin(), keyvec.at(b));
            }*/
            cipher(backletter, enckey);
        }
        
        
        if(strcmp(argv[i], "-e")==0){
            encrypt = true;
            
            vector<char> backletter;
            //enckey =
           /*for(int a = 25; a>=0; a--){
                backletter.push_back(letters.at(a));
            }
            */
            ofstream out("output.txt");
            ifstream input ("input.txt");
            
            cipher(backletter, enckey);
            
            
                
            if (input.is_open()){
            
                
                while (getline (input,line)){
                /*
                vector<char> linevec(line.begin(), line.end());
                int longth = line.length();
                
                
                
                for(int i=0; i < longth; i++){
                    int c = linevec.at(i);
                    
                    if(islower(c)){
                        linevec.at(i) = toupper(c);
                        for(int a =0; a < backletter.size(); a++){
                            if(linevec.at(i) == letters.at(a)){
                                c = backletter.at(a);
                                linevec.at(i) = tolower(c);
                            }
                        }
                    }
                    if(isupper(c)){
                        for(int a =0; a < backletter.size(); a++){
                            if(linevec.at(i) == letters.at(a)){
                                linevec.at(i) = backletter.at(a);
                            }
                        }
                    }
                }
                
                for(i=0; i < longth; i++){
                    writeline.at(i) = linevec.at(i);
                }
                out << writeline; */
                
                /*for(int i = 0; i < line.size(); i++){
                    cout << line.at(i) << " ";
                }*/
                
                /*
                for(int i=0; i < line.length(); i++){
                    int c = line.at(i);
                    
                    if(islower(c)){
                        line.at(i) = toupper(c);
                        for(int a =0; a < backletter.size(); a++){
                            if(line.at(i) == letters.at(a)){
                                c = backletter.at(a);
                                line.at(i) = tolower(c);
                            }
                        }
                    }
                    if(isupper(c)){
                        for(int a =0; a < backletter.size(); a++){
                            if(line.at(i) == letters.at(a)){
                                line.at(i) = backletter.at(a);
                            }
                        }
                    }
                }*/
                
                for(int i=0; i < line.length(); i++){
                    int c = line.at(i);
                    line.at(i) = toupper(c);
                    
                    for(int a =0; a < backletter.size(); a++){
                            if(line.at(i) == letters.at(a)){
                                line.at(i) = backletter.at(a);
                            }
                    }
                }
                
                for(int i = 0; i < line.size(); i++){
                    cout << line.at(i) << " ";
                }
                cout << endl;
                out << line;
            }  
            
            
        }
        
        }
        
        /*if(strcmp(argv[i], "-d")==0){
            decrypt = true;
            
            ofstream out("output.txt");
            ifstream input ("input.txt");
            if (input.is_open()){
                while (getline (input,line)){
                    for (int i=0; i < line.size(); i++){
                        for(int a =0; a< 26; a++){
                            if(line.at(i) == backletter.at(a)){
                            line.at(i) = letters.at(a);
                            }
                        }
                    out << line;
                    }
                
                }  
            }  
        }*/
        
        else{
            
        }
    }
    
    
    return 0;
}
