class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        
    def find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    
    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] < self.rank[pb]:
            self.parent[pa] = pb
        elif self.rank[pa] > self.rank[pb]:
            self.parent[pb] = pa
        else:
            self.parent[pb] = pa
            self.rank[pa] += 1
        return True

class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        # DSU for connectivity
        dsu = DSU(n)
        for u, v, _ in edges:
            dsu.union(u, v)
        
        # For each component, compute the AND over all edges in that component.
        # Initialize a dictionary to hold the AND value for each component.
        comp_and = {}
        for u, v, w in edges:
            comp = dsu.find(u)  # same as dsu.find(v)
            if comp in comp_and:
                comp_and[comp] &= w
            else:
                comp_and[comp] = w
        
        res = []
        for s, t in query:
            # if s and t are not connected, no valid walk exists.
            if dsu.find(s) != dsu.find(t):
                res.append(-1)
            else:
                comp = dsu.find(s)
                # If a component had no edges (isolated vertex), we can consider the trivial walk.
                # Depending on problem conventions, a trivial walk (with no edges) might have cost 0.
                # Here we assume that if there is at least one edge in the component, we use the computed AND;
                # otherwise, we return 0.
                if comp in comp_and:
                    res.append(comp_and[comp])
                else:
                    res.append(0)
        return res