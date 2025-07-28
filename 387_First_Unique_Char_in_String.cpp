class Solution {
public:
    int firstUniqChar(string s) {//TC=O(n), SC=O(n)
        unordered_map<char, int> map;
        queue<int> q;

        for(int i=0; i<s.length(); i++) {
            if(map.find(s[i]) == map.end()) {
                q.push(i);
            }
            map[s[i]]++;

            while (q.size() > 0 && map[s[q.front()]] > 1 ) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};