class Solution:
    def dfs(self,node,rooms,vis):
        vis[node]=True
        for i in rooms[node]:
            if not vis[i]:
                vis[i]=True
                self.dfs(i,rooms,vis)
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vis=[False]*len(rooms)
        self.dfs(0,rooms,vis)
        if False in vis:
            return False
        return True
        