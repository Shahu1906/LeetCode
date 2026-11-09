
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        // {finish_time, server_id}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        int maxCount = 0;

        for (int i = 0; i < arrival.size(); i++) {

            int time = arrival[i];

            // Release servers whose tasks are completed
            while (!busy.empty() && busy.top().first <= time) {
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // If all servers are busy, drop the request
            if (available.empty())
                continue;

            int start = i % k;

            // Find the next available server
            auto it = available.lower_bound(start);

            // Wrap around if necessary
            if (it == available.end())
                it = available.begin();

            int server = *it;

            available.erase(it);

            // Assign request
            count[server]++;

            maxCount = max(maxCount, count[server]);

            // Calculate when the server becomes free
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount)
                ans.push_back(i);
        }

        return ans;
    }
};
