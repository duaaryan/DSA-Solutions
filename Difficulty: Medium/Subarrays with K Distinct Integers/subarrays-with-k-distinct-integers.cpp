class Solution {
    int atMost(const vector<int>& arr, int limit) {
        unordered_map<int, int> freq;
        int left = 0;
        int answer = 0;
        int n = arr.size();

        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;

            while (static_cast<int>(freq.size()) > limit) {
                int outgoing = arr[left];
                freq[outgoing]--;

                if (freq[outgoing] == 0) {
                    freq.erase(outgoing);
                }

                left++;
            }

            // Every start from left through right gives a valid subarray.
            answer += right - left + 1;
        }

        return answer;
    }

public:
    int exactlyK(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
};