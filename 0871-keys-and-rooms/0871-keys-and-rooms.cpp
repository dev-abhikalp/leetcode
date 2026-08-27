class Solution {
public:
    vector<bool> visited;

    void dfs(int room, vector<vector<int>>& rooms) {
        visited[room] = true;

        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        visited.resize(n, false);

        dfs(0, rooms);

        for (bool room : visited) {
            if (!room)
                return false;
        }

        return true;
    }
};