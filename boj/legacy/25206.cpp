#include <iostream>
#include <string>

using namespace std;

double guamokpyungjum(string grade) {
    if (grade == "A+") return 4.5;
    if (grade == "A0") return 4.0;
    if (grade == "B+") return 3.5;
    if (grade == "B0") return 3.0;
    if (grade == "C+") return 2.5;
    if (grade == "C0") return 2.0;
    if (grade == "D+") return 1.5;
    if (grade == "D0") return 1.0;
    else return 0;
}

int main() {
    string name, grade;
    double score, totalScore = 0, hakjumtimesguamokpyungjum = 0, averageScore = 0;

    for (short i = 0; i < 20; ++i) {
        cin >> name >> score >> grade;
        if (grade == "P") continue;
        totalScore += score;
        hakjumtimesguamokpyungjum += score*guamokpyungjum(grade);
    } cout << hakjumtimesguamokpyungjum/totalScore;
}