#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include <functional>
#include <iterator>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // pair<count, val>
        // top k, min heap(Ð¡¸ù¶Ñ)
        using E = std::pair<int, int>;
        std::priority_queue<E, std::vector<E>, std::greater<E>> minHeap;
        map<int, int> counter;

        for (auto e : nums) {
            ++counter[e];
        }

        for (auto& x : counter) {
            auto pair = make_pair(x.second, x.first);
            if (minHeap.size() == k) {
                if (pair < minHeap.top()) continue;
                minHeap.pop();
            }
            minHeap.push(std::move(pair));
        }
        std::vector<int> res(minHeap.size());
        k = res.size();
        while(!minHeap.empty()) {
            res[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
}

int main()
{
    vector<int> num;
    num.push_back(1);

    vector<int> t = topKFrequent(num,1);
    for(int i = 0; i < t.size(); i++)
        cout << t[i] << endl;
    return 0;
}
