import java.util.*;

public class Solution {
    class Pair {
        long first;
        long second;
        
        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    public long[] dijkstra(HashMap<Integer, ArrayList<Pair>> adj, int src, int n) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.first, b.first));
        long[] dist = new long[n];
        boolean[] visited = new boolean[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        dist[src] = 0;
        pq.add(new Pair(0, src));

        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            long currWt = top.first;
            int currNode = (int) top.second;

            if (visited[currNode]) {
                continue;
            }

            visited[currNode] = true;

            if (!adj.containsKey(currNode)) {
                continue; // Skip if there are no neighbors for this node
            }

            for (Pair neighbor : adj.get(currNode)) {
                int nextNode = (int) neighbor.first;
                long nextWt = neighbor.second;

                if (dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.add(new Pair(dist[nextNode], nextNode));
                }
            }
        }

        return dist;
    }

    public boolean[] findAnswer(int n, int[][] edges) {
        int E = edges.length;

        HashMap<Integer, ArrayList<Pair>> adj = new HashMap<>();
        for (int[] edge : edges) { // graph adj
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!adj.containsKey(u))
                adj.put(u, new ArrayList<>());
            if (!adj.containsKey(v))
                adj.put(v, new ArrayList<>());

            adj.get(u).add(new Pair(v, w));
            adj.get(v).add(new Pair(u, w));
        }

        long[] fromSrc = dijkstra(adj, 0, n);// -> starting from 0
        long[] fromDest = dijkstra(adj, n - 1, n); // -> reverse way -> n-1;

        boolean[] result = new boolean[E]; // -> res

        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            long distFromSrc = fromSrc[u]; // x
            long distFromDest = fromDest[v]; // y

            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }

            distFromSrc = fromSrc[v]; // x
            distFromDest = fromDest[u]; // y
            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }
        }

        return result;
    }
}