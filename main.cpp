#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c : num){
            cnt[c - '0']++;
        }

        string lp, rp;
        for (char c : num) {
            for (int j = 9; j >= 0; j--) {
                if (cnt[j] > 1 && (j > 0 || lp.size())) {
                    lp += ('0' + j);
                    rp += ('0' + j);
                    cnt[j] -= 2;
                    break;
                }
            }
        }

        for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                lp += ('0' + i);
                break;
            }
        }

        reverse(rp.begin(), rp.end());
        return lp + rp;
    }
};

int main() {
    Solution solution;
    string num = "7634784554"; // Change this number to your desired input
    string result = solution.largestPalindromic(num);
    cout << "Largest Palindromic Number: " << result << endl;
    cout << "Number of elements: " << result.length();
    return 0;
}
