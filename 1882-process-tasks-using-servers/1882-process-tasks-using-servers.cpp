
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, server_index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // {free_time, weight, server_index}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have completed their tasks
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [freeTime, weight, idx] = busy.top();
                busy.pop();

                available.push({weight, idx});
            }

            // If no server is available, jump to the earliest free time
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, weight, idx] = busy.top();
                    busy.pop();

                    available.push({weight, idx});
                }
            }

            // Select the server with minimum weight, then minimum index
            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;

            // Server becomes free after processing this task
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
