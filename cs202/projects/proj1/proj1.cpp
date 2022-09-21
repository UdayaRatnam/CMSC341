/**********************************
 * File: proj1.cpp
 * Project: CMSC 202 Project 1, Fall 2020
 * Author: Udaya Garapati
 * Date: 9/24/2020
 * Section: 10/15
 * Email: udayag1@umbc.edu
 * 
 * This program takes in a file of three words and determines 
 * if it is an escalator type puzzle where if you drop a letter it can make 
 * the next word until it makes the last word.
 * 
 ***********************************/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Constants
const int MAX_WORDS = 3;
const int MAX_LETTERS = 6;
const int WORD_TWO = 5;
const int WORD_THREE = 4;
const int MAX_DROP_LETTERS = 2;


//Function prototypes
void LoadFile(string dataFile);
void PrintWords(string wordList[], int lenOfList);
int CountLetters(char letter, string str);
bool CheckLength(string str[], int size);
int RemoveRepeating(int characters [], int sizeOfArray);

//Main body of program
int main(){
    
    //variables
    string fileName;//name of inputted file 
    char choice;
    bool anotherFile = true;

    //do while loop that is key to the program
    do{
        //displays a welcome message
        cout <<"Welcome to escalators" <<endl;
        cout <<"What is the file name of the list of words?"<<endl;//asks for a file
        cin >> fileName;//stores the input into fileName
        LoadFile(fileName);//function call to loadFile()


        //Asks the user if they want to check another list of words
        cout <<"Check another list ? (y/n) "<<endl;
        cin >> choice;//stores the input into choice

        //If the user enter "n" then it exits the loop 
        //and displays a thank you message
        if (choice ==  'n'){
            anotherFile = false;
        }

        //This while loop is for input validation making sure
        //the user enters y or n for yes or no
        while (choice != 'y' && choice != 'n'){
            
            cout <<"invalid input"<<endl;
            cout <<"Check another list ? (y/n) "<<endl;
            cin >> choice;
        }

        

    }while(anotherFile);

    cout<<"Thank you for using escalators!"<<endl;
    
    return 0;
 
}

//The LoafFile function takes in the filename inputted by
//the user and displays if the list of words is valid or not
void LoadFile(string dataFile){
    //opening up file
    ifstream inputStream(dataFile);
    string words [MAX_WORDS];//empty list to store the words from file
    //If the file exists..
    if (inputStream.is_open()){
        //stores the words from the file into the list
        for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++){

            inputStream >> words[i];
        }
    }

    //If the file does not exist
    else{
        //displays that no file was found
        cout <<"No file found."<<endl;

    }
    
    //closes the stream of input
    inputStream.close();
    PrintWords(words, sizeof(words)/(sizeof(words[0])));//displays the list of words for the user
    //this function call makes sure all the words have their respectful lengths
    bool validLength = CheckLength(words, sizeof(words)/sizeof(words[0]));
    //If the words are not correct length it lets the user know that it is not an escalator
    if (validLength == false){
        cout <<"Words are not correct length"<<endl;
        cout <<"This list is not valid!"<<endl;
    }
    //If they are the right length then it..
    else{

        //primary stores the first word in the list of words
        string primary = words[0];
        //declared an empty integer array
        int primaryArray[MAX_LETTERS];
        //declared an empty string
        string emptyStr = "";
        //2d array that will have the frequency of each letter
        int letterFreq[MAX_WORDS][MAX_LETTERS];
        //This loop takes in each letter in the first word and converts it to an integer
        for(int i = 0; i < sizeof(primaryArray)/sizeof(primaryArray[0]); i++){
        
            primaryArray[i] = (int) primary[i];
        }
        //declared the variable sizerepresent the size of primary
        int size = sizeof(primaryArray)/sizeof(primaryArray[0]);
        //function call that takes int primary array, and the size of primary array
        //and removes any repeating integers
        size = RemoveRepeating(primaryArray, size);
        
        //I then take the array of integers and accumulate their
        //character versions into a string
        for(int i = 0; i < size; i++){
            emptyStr += (char) primaryArray[i];
        }
        //reinitialize primary in the case that the repeating letters were dropped
        primary = emptyStr;
        
        //I then use primary to compare the three original words
        //of the file to count the frequency of each letter
        for(int i = 0; i < MAX_WORDS; i++){

            for(int j = 0; j < primary.length(); j++){
                //stores the frequency into 2d array
                letterFreq[i][j] = CountLetters(primary[j], words[i]);
            }
        }

        //incrementing variable to count the number of inconsistencies
        //in 2d array
        int inconsistency = 0;
        //nested for loop loops through letterFreq
        //outer loop has MAX_WORD-1 so it doesnt go out of bounds when
        //checking the next row
        for(int i = 0; i < MAX_WORDS - 1; i++){

            for(int j = 0; j < size; j++){

                if (letterFreq[i][j] != letterFreq[i+1][j]){
                    //inconsistency goes up by 1
                    inconsistency++;
                }

            }
        }
        
        //if the number of inconsistencies equals to
        //then the list of words is a valid escalator
        if (inconsistency == MAX_DROP_LETTERS){
            cout <<"This list is valid!"<<endl;

        }
        //otheriwise it does not have correct letter frequency
        //and the list is not valis
        else{
            cout<<"Words do not share appropriate letter frequency!"<<endl;
            cout<<"This list is not valid!"<<endl;
        }
    

        
    }


}

//PrintWords
//Given the list of words and the length of the list
//it displays the word for the user
void PrintWords(string wordList[], int lenOfList){


    for (int i = 0; i < lenOfList; i++){
        cout <<i+1<< "." <<wordList[i]<<endl;
    }
}

//CountLetters
//Given the letter and the string
//it counts the number of occurences of that letter
//in the string
int CountLetters(char letter, string primary){


    int count = 0;
    for (int i = 0; i < primary.length(); i++){
        
        if (letter == primary[i]){
            count++;
        }
    }
    return count;
}

//CheckLength
//Given the list of strings and the size of the list
//the function makes sure that each string is the right length
bool CheckLength(string str[], int size){
    bool isValid = false;

    if ((str[0].length() == MAX_LETTERS) && (str[1].length() == WORD_TWO) && (str[2].length() == WORD_THREE)){
        isValid = true;
    }

    return isValid;
}
//RemoveDuplicates
//Takes in the ascii versions of a character list and the size of it
//and removes any repeating elements and keeps only the unique ones
//it checks to see if an element is equal to another, then shifts it to the left
//and decreases the sizeOfArray since the number of letters will decrease
int RemoveRepeating(int characters [], int sizeOfArray){


    for(int i = 0; i < sizeOfArray; i++){

        int j = 0;
        while (j < i){
            if (characters[i] == characters[j]){
                sizeOfArray--;
                for(int k = i; k < sizeOfArray; k++){
                    characters[k] = characters[k+1];
                }
                i--;
                    
            }
            j++;
        }
    }

    return sizeOfArray;

    


}