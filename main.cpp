#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

double modulusQuiz();
double pemmdasQuiz();
void printScores(vector<double> modulus, vector<double> pemmdas);
int generateNumber(int start, int end);
double evaluateAddSub(string& expression, size_t& pos);
double evaluateMulDivMod(string& expression, size_t& pos);
double evaluateNumber(string& expression, size_t& pos);
double evaluateExpression(string expression);



int main()
{
    srand(time(0));
    char selection;
    vector<double> modulusScores;
    vector<double> pemmdasScores;



    do
    {
        cout << "Welcome to PEMMDAS practice.  " << endl
             << endl
             << "Select a menu option to proceed: " << endl
             << "1  Modulus Practice" << endl
             << "2  PEMMDAS Practice" << endl
             << "3  Score Report" << endl
             << "4  Exit" << endl;
        cin >> selection;

        double tempScore = 0.0;
        switch (selection)
        {
        case '1':
            tempScore = modulusQuiz();
            modulusScores.push_back(tempScore);
            break;
        case '2':
            tempScore = pemmdasQuiz();
            pemmdasScores.push_back(tempScore);
            break;
        case '3':
            printScores(modulusScores, pemmdasScores);
			cout << endl;
            break;
        case '4':
            return 0;
        default:
            cout << " Please enter a valid entry.";
        }
    } while (true);
}

double modulusQuiz()
{
    int times = 0;
    int score = 0;
    cout << "How many problems would you like to solve?" << endl;
    cin >> times;
    int total = times;

    while (times > 0)
    {
        int num1 = rand() % 10;
        int num2 = rand() % 9 + 1;
        int answer = 0;

        cout << "What is:" << endl
             << num1 << " % " << num2 << endl;
        cin >> answer;
        if (answer == (num1 % num2))
        {
            cout << "That's right!" << endl;
            score++;
        }
        else
        {
            cout << "No, the answer is " << (num1 % num2) << endl;
        }
        times--;
    }

    double percent = score / static_cast<double>(total) * 100;
    cout << "You scored " << score << " out of " << total << endl
         << "That's " << percent << "%." << endl;

    return percent;
}

double pemmdasQuiz()
{

    int numberOfProblems;
    int numberOfProblemsCorrect = 0;

    double answer;
    const string operators[8] = {"*", "/", "+", "-", "%"};

    cout << "Enter how many problems you want to solve: ";
    cin >> numberOfProblems;

	vector<char> characters;
	string expression;
	for (int i = 0; i < numberOfProblems; i++)
    {
		expression = std::to_string(generateNumber(1, 9)) + " " + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " " + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " " +   operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " " + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " "  + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " "   + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " "   + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9)) + " "    + operators[generateNumber(0, 4)] + " " +
	                         std::to_string(generateNumber(1, 9));

        cout << expression << endl;
        cout << "Answer here: ";
        cin >> answer;

        double correctAnswer = evaluateExpression(expression);

        // cout << "Correct Answer: " << correctAnswer << endl;
        if (answer == correctAnswer)
        {
            cout << "Correct" << endl;
            numberOfProblemsCorrect += 1;
        }
        else
        {
            cout << "Incorrect" << endl;
        }
    }
    double percent = numberOfProblemsCorrect / static_cast<double>(numberOfProblems) * 100;
    cout << "You scored " << numberOfProblemsCorrect << " out of " << numberOfProblems << endl
         << "That's " << percent << "%." << endl;
    return percent;
}

void printScores(vector<double> modulus, vector<double> pemmdas)
{
    int modCount = 1, pemCount = 1;
    cout << "Your percentages on modulus quizzes are:" << endl;
    for (double percent : modulus)
    {
        cout << modCount << ":\t" << percent << "%" << endl;
        modCount++;
    }
    cout << endl
         << endl;
    cout << "Your percentages on PEMMDAS quizzes are:" << endl;
    for (double percent : pemmdas)
    {
        cout << modCount << ":\t" << percent << "%" << endl;
        modCount++;
    }
}

int generateNumber(int start, int end)
{
    int randomNumber = (rand() % end) + start;
    return randomNumber;
}



double evaluateAddSub(string& expression, size_t& pos)
{
    double result = evaluateMulDivMod(expression, pos);
    while (pos < expression.length()) {
        while (pos < expression.length() && isspace(expression[pos])) pos++; // Skip whitespace
        if (pos >= expression.length()) break;
        char op = expression[pos];
        if (op != '+' && op != '-') break;
        pos++;
        while (pos < expression.length() && isspace(expression[pos])) pos++; // Skip whitespace
        double right = evaluateMulDivMod(expression, pos);
        if (op == '+') result += right;
        if (op == '-') result -= right;
    }
    return result;
}
double evaluateMulDivMod(string& expression, size_t& pos)
{
    double result = evaluateNumber(expression, pos);
    while (pos < expression.length()) {
        while (pos < expression.length() && isspace(expression[pos])) pos++; // Skip whitespace
        if (pos >= expression.length()) break;
        char op = expression[pos];
        if (op != '*' && op != '/' && op != '%') break;
        pos++;
        while (pos < expression.length() && isspace(expression[pos])) pos++; // Skip whitespace
        double right = evaluateNumber(expression, pos);
        if (op == '*') result *= right;
        if (op == '/') result = static_cast<int>(result) / static_cast<int>(right);
        if (op == '%') result = static_cast<int>(result) % static_cast<int>(right);
    }
    return result;
}
double evaluateNumber(string& expression, size_t& pos)
{
    double result = 0;
    while (pos < expression.length() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        if (expression[pos] == '.') {
            pos++;
            double decimal_place = 0.1;
            while (pos < expression.length() && isdigit(expression[pos])) {
                result += (expression[pos] - '0') * decimal_place;
                decimal_place *= 0.1;
                pos++;
            }
            break;
        } else {
            result = result * 10 + (expression[pos] - '0');
            pos++;
        }
    }
    return result;
}
double evaluateExpression(string expression)
{
    size_t pos = 0;
    return evaluateAddSub(expression, pos);
}
