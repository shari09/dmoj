#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
// typeof vector<vector<string>> vss;

bool solutionFound{false};

//check if the substitution is valid
bool valid(string sequence, string from, unsigned int index) {
  if (from.length() > sequence.length() || index >= sequence.length()) {
    return false;
  }
  for (unsigned int i = 0; i < from.length(); i++) {
    if (sequence[index++] != from[i]) {
      return false;
    }
  }
  return true;
}

void display(vs order, vi subNum, vi posApplied) {
  for (unsigned int i = 0; i < order.size(); i++) {
    cout << subNum[i] << ' ' << posApplied[i] << ' ' << order[i] << '\n';
  }
}

void findSteps(string substitutions[3][2],
               vs order,
               vi subNum, vi posApplied,
               int steps,
               string sequence, string f) {
  if (sequence.compare(f) == 0 && steps == 0) {
    solutionFound = true;
    display(order, subNum, posApplied);
    return;
  }
  if (steps > 0 && !solutionFound) {
    for (unsigned int i = 0; i < 3; i++) {
      string from = substitutions[i][0];
      string to = substitutions[i][1];

      for (unsigned int j = 0; j < f.length(); j++) {
        if (valid(sequence, from, j) && !solutionFound) {

          sequence.replace(j, from.length(), to);
          order.push_back(sequence);
          subNum.push_back(i+1);
          posApplied.push_back(j+1);

          findSteps(substitutions, order, subNum, posApplied, steps-1, sequence, f);

          sequence.replace(j, to.length(), from);
          order.pop_back();
          subNum.pop_back();
          posApplied.pop_back();
        }
      }
    }


  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //getting input
  string substitutions[3][2];
  int steps{};
  string initialSequence{}, finalSequence{};

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 2; j++) {
      cin >> substitutions[i][j];
    }
  }
  cin >> steps >> initialSequence >> finalSequence;

  vs order{};
  vi subNum{};
  vi posApplied{};
  findSteps(substitutions, order, subNum, posApplied, steps, initialSequence, finalSequence);


  return 0;
}
