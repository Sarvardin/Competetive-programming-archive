class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF = 10e4;

        vector<int> distance(n+1, INF);

        distance[k] = 0;

        for(int i = 1; i <= n-1; i++) {
            for(auto t : times) {
                
                int a = t[0], b = t[1], w = t[2];
                if(distance[a] != INF) {
                    distance[b] = min(distance[b], distance[a] +w);
                }
            }
        }
        
        int result = *max_element(distance.begin()+1, distance.end());
        if(result != INF) {
            return result;
        }
        return -1;


    }
};