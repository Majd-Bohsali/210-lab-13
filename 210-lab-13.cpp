// COMSC210 | Lab 13 | Majd Bohsali
// IDE used: Visual Studio Code

#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
#include <iostream> 
#include <string> 
#include <vector>
using namespace std;

int main() { 
    const int SIZE = 30; 
    vector<double> testScores(SIZE); 
    ifstream inputFile("studentTestScores.txt"); 
    
    if(!inputFile.is_open()) { 
        cerr << "Error in opening file"; 
    }

    // reads file and adds data to array
    string line; 
    int i = 0; 
    while(getline(inputFile, line)) { 
        testScores.at(i) = stod(line);
        i++;
    }
    inputFile.close();

    cout << "Original Test Scores List: ";
    for (double score : testScores) cout << score << " "; cout << endl << endl;
    cout << "Vector Address: " << testScores.data() << endl << endl;  
    cout << "Number of test scores: " << testScores.size() << endl << endl;
    cout << "Highest test score: " << *max_element(testScores.begin(), testScores.end()) << endl << endl;  
    cout << "Lowest test score: " << *min_element(testScores.begin(), testScores.end()) << endl << endl;  
    cout << "Sum of test scores: " << accumulate(testScores.begin(), testScores.end(), 0.0) << endl << endl;
    cout << "Average test score: " << (accumulate(testScores.begin(), testScores.end(), 0.0)/testScores.size()) << endl << endl;
    cout << "Element at index 3: " << testScores.at(3) << endl << endl;
    cout << "Element at front: " << testScores.front() << endl << endl; 
    cout << "Element at back: " << testScores.back() << endl << endl; 

    // makes a copy of the test scorse
    vector<double> testScoresCopy = testScores; 
    // sets all values to 90
    fill(testScoresCopy.begin(), testScoresCopy.end(), 90);
    // Pastes both arrays  
    cout << "Original Test Scores List: ";
    for (double score : testScores) cout << score << " "; cout << endl << endl;
    cout << "Test Scores Copy List - with all values set to 90: ";
    for (double score : testScoresCopy) cout << score << " "; cout << endl << endl; 

    sort(testScores.begin(), testScores.end()); 
    cout << "Test scores sorted: ";
    for (double score : testScores) cout << score << " "; cout << endl << endl;
    sort(testScores.rbegin(), testScores.rend()); 
    cout << "Test scores in reverse: "; 
    for (double score : testScores) cout << score << " "; cout << endl << endl;

    testScoresCopy.swap(testScores);
    cout << "Swapping original test scores and test scores copy (with all values set to 90)" << endl; 
    cout << "Original Test Scores List: ";
    for (double score : testScores) cout << score << " "; cout << endl;
    cout << "Test Scores Copy List: ";
    for (double score : testScoresCopy) cout << score << " "; cout << endl << endl;

    return 0;
}