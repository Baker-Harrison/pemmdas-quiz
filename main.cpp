#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;



double modulusQuiz();
double pemmdasQuiz();
void printScores(vector<double> modulus, vector<double> pemmdas);

int main()
{
    srand(time(0));
    char selection;
    vector<double> modulusScores;
    vector<double> pemmdasScores;

    
    do {
        cout << "Welcome to PEMMDAS practice.  " << endl
            << endl
            << "Select a menu option to proceed: " << endl
            << "1  Modulus Practice" << endl
            << "2  PEMMDAS Practice" << endl
            << "3  Score Report" << endl
            << "4  Exit" << endl;
        cin >> selection;

        double tempScore = 0.0;
        switch (selection) {
        case '1': tempScore = modulusQuiz();
            modulusScores.push_back(tempScore);
            break;
        case '2': tempScore = pemmdasQuiz();
            pemmdasScores.push_back(tempScore);
            break;
        case '3': printScores(modulusScores, pemmdasScores);
            break;
        case '4': return 0;
        default:
            cout << " Please enter a valid entry.";
        }
    } while (true);


}


double modulusQuiz() {
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;


    while (times > 0) {
        int num1 = rand() % 10;
        int num2 = rand() % 9 + 1;
        int answer = 0;

        cout << "What is:" << endl
            << num1 << " % " << num2 << endl;
        cin >> answer;
        if (answer == (num1 % num2)) {
            cout << "That's right!" << endl;
            score++;
        }
        else {
            cout << "No, the answer is " << (num1 % num2) << endl;

        }
        times--;

    }

    double percent = score / static_cast<double>(total) * 100;
    cout << "You scored " << score << " out of " << total << endl
        << "That's " << percent << "%." << endl;

    return percent;
}

double pemmdasQuiz() {




    return 0;
}

void printScores(vector<double> modulus, vector<double> pemmdas) {
    int modCount = 1, pemCount = 1;
    cout << "Your percentages on modulus quizzes are:" << endl;
    for (double percent : modulus) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }
    cout << endl << endl;
    cout << "Your percentages on PEMMDAS quizzes are:" << endl;
    for (double percent : pemmdas) {
        cout << modCount << ":\t" << percent << endl;
        modCount++;
    }



}