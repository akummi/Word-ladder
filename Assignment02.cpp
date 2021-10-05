// Author: Avery Nguyen
// Section: Section 1003
// Date Las Modiefied: 8/31/2021
// Program deescription: This program demonstrates an understanding of recursion, searching through 

//**************************
//NOTE: SECOND TEST DOES WORK, IT JUST TAKES LONGER THAN CODEGRADE ALLOWS, IT FINISHES WITH AROUND 2500 WORDS IN LIST
//**************************

#include <iostream>
#include <fstream> 
#include <vector>

using namespace std; 

bool wordLadder(string word, string wordFinal, const vector<string>& words, vector<string>& ladder){

//adds word to ladder
ladder.push_back(word);

if(word == wordFinal){
    return true; 
}
//initializes wordlength and dictionary length
int wordlength = word.size(); 
int dictionarylength = words.size();


//if the new word is true returns true and adds the new word to the library
if(word == wordFinal){
//ladder.push_back(newword);
return true; 
}
//searches entire dictionary
for (int i = 0; i != dictionarylength; i++){
    //checks if word is 1 off dictionary word 
    int incorrect = 0; 
    string newword = words[i];
    for(int l = 0; l < wordlength; l++){
        if(word[l] != newword[l]){
            incorrect++;
        }
    }
    if(incorrect == 1){
        //makes sure it is not already in ladder
        int ladsize = 0;
        ladsize = ladder.size(); 
        bool notinlad = true; 
        for(int z = 0; z < ladsize; z++){
            if(ladder[z] == newword){
                notinlad = false; 
            }
        }
        //recursively calls function 
        if(notinlad == true){
            if(wordLadder(newword, wordFinal, words, ladder) == true){
                return true;
            }
            else{                    
            }
        }
    }
}

int ladsize = ladder.size();
//returns true if 
if(ladder[ladsize] == wordFinal){
    ladder.pop_back();
    return true; 
}
//removes word from ladder and returns false if false
ladder.pop_back();
return false; 
}

//*********************************************
//START OF MAIN 
//*********************************************

int main(int argc, char *argv[]){

    //ensures user inputs the correct number of arguments
    if (argc != 2) {
        cout << "ERROR: Invalid number of arguments \n ./a.out sometextfile.txt" << endl;
    }

    ifstream infile; 
    infile.open(argv[1]);
    if(!infile.is_open()){
        cout << "ERROR: file failed to open" << endl; 
        return 0; 
    }  

    //declares vectors
    vector<string> words; 
    vector<string> ladder;
    //populates the vector with strings read from file
    while(!infile.eof()){
        string in; 
        infile >> in; 
        if(infile.eof()){
            break; 
        }
        
        words.push_back(in);
    }
    //accepts user input
    string startword; 
    string endword;
    cin >> startword >> endword; 
   
   //if true prints list 
    if(wordLadder(startword, endword, words, ladder) == true){
        int ladderlength = ladder.size(); 
        for(int i = 0; i != ladderlength; i++){
            cout << ladder[i] << endl; 
        }
    }
    //if not displays that no soloution exists
    else{
        cout << "Solution Does Not Exist" << endl;
    }
    return 0; 
}