class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;

        vector<bool> visited(rooms.size(), false);

        q.push(0);
        while(!q.empty()) {
            int room = q.front(); q.pop();
            visited[room] = true;
            for(int i : rooms[room]) {
                if(visited[i]) continue;
                q.push(i);
                visited[i] = true;
            }
        }

        for(int i = 0; i < rooms.size(); i++) {
            if(visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};