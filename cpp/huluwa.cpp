/**
 * Author: Hongbo Liu <lhbf@qq.com>
 * Date  : 2023-08-15 18:45:47
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> res;
int N = 6;

void buildStrategy(int idx, int sum, vector<int> cur) {
  if (idx == N && sum == 6) {
    res.push_back(cur);
    return;
  }

  if (idx >= N) {
    return;
  }

  for (int i = idx + 1; i >= 0; i--) {
    if (sum + i <= idx + 1) {
      auto tmp = cur;
      tmp.push_back(i);
      buildStrategy(idx+1, sum + i, tmp);
    }
  }
}

// For each strategy:
// size is 6
// sum of elements == 6
// element value <= index
vector<vector<int>> allStrategies(int n) {
  N = n;

  buildStrategy(0, 0, {});

  return res;
}

double calcProbability(const vector<int>& strategy) {
  double prob = 0.0;

  int try_cnt = 0;
  double succ_prob = 1.0 / (N+1);
  for (size_t i = 0; i < strategy.size(); ++i) {
    double live_grandpa_prob = (N-i) * 1.0 / N;
    double save_prob = strategy[i] * succ_prob;

    prob += pow(1 - succ_prob, try_cnt) * live_grandpa_prob * save_prob;

    try_cnt += strategy[i];
  }

  return prob;
}

void dumpVec(const vector<int>& v) {
  for (auto n : v) {
    std::cout << n << " ";
  }
}

void dumpResult() {
  vector<int> max_strategy;
  double max_prob = 0.0;
  for (const auto& v : res) {
    dumpVec(v);

    double cur_prob = calcProbability(v);
    std::cout << "\tProbability: " << cur_prob << std::endl;

    if (cur_prob > max_prob) {
      max_prob = cur_prob;
      max_strategy = v;
    }
  }

  std::cout << "Strategy numbers: " << res.size() << std::endl;
  std::cout << "Max probability: " << max_prob << std::endl;
  std::cout << "Best strategy: ";
  dumpVec(max_strategy);
}

int main(int argc, char *argv[]) {
  allStrategies(6);
  dumpResult();
  return 0;
}
