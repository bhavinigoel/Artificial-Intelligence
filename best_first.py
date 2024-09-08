from queue import PriorityQueue

v = 10
graph = [[] for i in range(v)]

def bestSearch(source, target, n):
    visited = [False] * n
    pq = PriorityQueue()
    pq.put((0, source))
    visited[source] = True

    while not pq.empty():
        u = pq.get()[1]
        print(u, end=" ")

        if u == target:
            break

        for v, c in graph[u]:
            if not visited[v]:
                visited[v] = True
                pq.put((c, v))

    print()

def addedge(x, y, cost):
    graph[x].append((y, cost))
    graph[y].append((x, cost))

# Adding edges
addedge(0, 2, 3)
addedge(0, 1, 6)
addedge(0, 3, 1)

addedge(1, 2, 2)
addedge(1, 3, 6)
addedge(1, 4, 3)
addedge(1, 5, 4)

addedge(2, 4, 4)
addedge(2, 5, 5)

addedge(3, 4, 4)
addedge(3, 5, 7)
addedge(3, 7, 9)

addedge(4, 5, 8)
addedge(4, 6, 9)

addedge(5, 6, 8)
addedge(5, 7, 9)

addedge(6, 7, 9)
addedge(6, 8, 11)
addedge(6, 9, 12)

addedge(7, 8, 14)
addedge(7, 9, 15)

addedge(8, 9, 15)

# Perform best-first search
source = 0
target = 9
bestSearch(source, target, v)
