class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        // Max heap: (count, char)
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, count] : freq) {
            pq.push({count, ch});
        }

        string result = "";
        pair<int, char> prev = {0, '#'}; // store last used character

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            result += ch;
            count--;
            
            // Push the previous char back if it still has a remaining count
            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = {count, ch};
        }

        // If the result length doesn't match input, it's impossible
        if (result.size() != s.size()) {
            return "";
        }
        return result;
    }
};