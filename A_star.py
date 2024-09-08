import heapq

def astar_algorithm(graph, heuristic, start, goal):
    open_list = []

    heapq.heappush(open_list, (0 + heuristic[start], start))
    
    # Cost from start to current node
    g_cost = {node: float('inf') for node in graph}
    g_cost[start] = 0
    
    # Path tracking
    came_from = {}
    
    while open_list:
        current_f, current = heapq.heappop(open_list)
        
        if current == goal:
            # Reconstruct path if goal is reached
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, g_cost[goal]
        
        # Explore neighbors
        if current not in graph:
            continue
        
        for neighbor, weight in graph[current]:
            if neighbor not in g_cost:
                # Initialize g_cost for neighbor if not present
                g_cost[neighbor] = float('inf')
                
            tentative_g = g_cost[current] + weight
            
            if tentative_g < g_cost[neighbor]:
                g_cost[neighbor] = tentative_g
                f_cost = g_cost[neighbor] + heuristic[neighbor]
                heapq.heappush(open_list, (f_cost, neighbor))
                came_from[neighbor] = current
    
    return None, float('inf')  # If there's no path

# Graph representation using adjacency list
graph = {
    0: [(2, 3), (1, 6), (3, 1)],
    1: [(2, 2), (3, 6), (4, 3), (5, 4)],
    2: [(4, 4), (5, 5)],
    3: [(4, 4), (5, 7), (7, 9)],
    4: [(5, 8), (6, 9)],
    5: [(6, 8), (7, 9)],
    6: [(7, 9), (8, 11), (9, 12)],
    7: [(8, 14), (9, 15)],
    8: [(9, 15)]
}

# Heuristic values
heuristic = {
    0: 15,
    1: 13,
    2: 13,
    3: 12,
    4: 10,
    5: 9,
    6: 7,
    7: 6,
    8: 5,
    9: 0
}

# Example usage
start_node = 0
goal_node = 9
path, cost = astar_algorithm(graph, heuristic, start_node, goal_node)

if path:
    print(f"Path found: {path}")
    print(f"Cost of the path: {cost}")
else:
    print("No path found")
