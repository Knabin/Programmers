#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, vector<string>> reportMap;
    unordered_map<string, int> countMap;
    vector<string> overK;
    vector<int> answer;

    // 각 unordered_map을 초기화한다.
    for (auto id : id_list) {
        reportMap[id] = vector<string>{};
        countMap[id] = 0;
    }

    for (auto item : report) {
      auto id = item.substr(0, item.find(' '));
      auto reported = item.substr(item.find(' ') + 1);

      if (find(reportMap[id].begin(), reportMap[id].end(), reported) != reportMap[id].end()) {
        continue;
      }
      reportMap[id].push_back(reported);
      countMap[reported]++;
    }

    // countMap에서 k 이상인 애들을 찾고
    for (auto item : countMap) {
        if (item.second >= k) {
          overK.push_back(item.first);
        }
    }

    // 그걸 다시 reportMap에서 찾는다.
    for (auto id : id_list) {
      int count = 0;
      
      // overK에 있는 애를 쥐고 있다면 count 증가
      for (auto over : overK) {
        if (find(reportMap[id].begin(), reportMap[id].end(), over) != reportMap[id].end()) {
          count++;
        }
      }

      answer.push_back(count);
    }

    return answer;
}