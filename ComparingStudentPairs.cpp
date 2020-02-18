#include <iostream>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long factorial = n;
    for (int i = n-1; i > 1; i--) {
        factorial *= i;
    }
    return factorial;
}
int combination(int n, int r) { // Returns n choose r
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main() {
    // Input 
    int nStudents = 18;
    int nQuestions = 10;
    int studPairs = combination(nStudents, 2);
    char responses[nStudents][nQuestions]; 
    char answerkey[nQuestions];
    cout << "Enter all student responses." << endl;
    for (int i = 0; i < nStudents; i++) {
        for (int j = 0; j < nQuestions; j++) {
            cin >> responses[i][j];
        }
    }
    cout << "Enter the answer key for the test." << endl;
    for (int i = 0; i < nQuestions; i++) {
        cin >> answerkey[i];
    }

    // Comparing Answers
    int** studComparisons = new int*[studPairs]; // To output: Student1 #, Student2 #, #ofSharedCorrectAnswers, #ofSharedWrongAnswers
    int counter = 0;
    int sharedCorrect, sharedWrong;
    for (int i = 0; i < nStudents-1; i++) { // Stop before reaching the last student
        for (int j = i+1; j < nStudents; j++) { // Two for loops to compare two students each. Student #'s are one greater than their index.
            sharedCorrect = 0;
            sharedWrong = 0;
            for (int q = 0; q < nQuestions; q++) {
                if (responses[i][q] == responses[j][q]) {
                    if (responses[i][q] == answerkey[q])
                        sharedCorrect++;
                    else
                        sharedWrong++;
                }
            }
            studComparisons[counter] = new int[4];
            studComparisons[counter][0] = i+1;
            studComparisons[counter][1] = j+1;
            studComparisons[counter][2] = sharedCorrect;
            studComparisons[counter][3] = sharedWrong; 
            // studComparisons[counter] = {(i+1), (j+1), sharedCorrect, sharedWrong}; // For some reason this line doesn't work.
            counter++;
        }
    }

    // Output
    // Want to output: Student1 #, Student2 #, #ofSharedCorrectAnswers, #ofSharedWrongAnswers
    for (int i = 0; i < studPairs; i++) {
        cout << studComparisons[i][0] << "," << studComparisons[i][1] << "," << studComparisons[i][2] << "," << studComparisons[i][3] << endl;
    }
}