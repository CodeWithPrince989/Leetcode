class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        //Use comma instead of dot, and match variable name 'lambda'
        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };

        sort(begin(logs), end(logs), lambda);

        int q = queries.size();
        vector<int> result(q);

        vector<pair<int, int>> timeIndex(q);
        for(int i = 0; i < q; i++) {
            timeIndex[i] = {queries[i], i};
        }

        // Fix 2: Complete the sort function
        sort(begin(timeIndex), end(timeIndex));

        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        for(auto [time, idx] : timeIndex) {
            int start = time - x;
            int end = time;

            while(j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }
            
            while(i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0) {
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            // Fix 3: Store the result for the original query index
            result[idx] = n - mp.size();
        }

        // Fix 4: Return the result vector
        return result;
    }
};