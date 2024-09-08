import numpy as np
import heapq

size = 28
adj_matrix = np.zeros((size, size), dtype=int)

char_to_index = {chr(i): i - ord('a') for i in range(ord('a'), ord('z') + 1)}
char_to_index[' '] = 26
char_to_index['.'] = 27

def get_index(char):
    return char_to_index.get(char, -1)

# Sample text
text = ("Everything was in confusion in the Oblonskys' house. The wife had discovered "
        "that the husband was carrying on an intrigue with a French girl, who had been "
        "a governess in their family, and she had announced to her husband that she could "
        "not go on living in the same house with him. This position of affairs had now "
        "lasted three days, and not only the husband and wife themselves, but all the members "
        "of their family and household, were painfully conscious of it")

for i in range(len(text) - 1):
    current_char = text[i]
    next_char = text[i + 1]
    current_index = get_index(current_char)
    next_index = get_index(next_char)
    if current_index != -1 and next_index != -1:
        adj_matrix[current_index][next_index] += 1

# Print the adjacency matrix
print("Adjacency Matrix:")
for row in adj_matrix:
    print(" ".join(map(str, row)))


def best_first_search(start_char):
    start_index = get_index(start_char)
    if start_index == -1:
        print("Start character not in map")
        return

    open_list = []
    heapq.heappush(open_list, (0, start_index))  # (heuristic, index)
    
    visited = set()
    came_from = {start_index: None}

    print("Best-First Search starting from 'e':")

    while open_list:
        _, current = heapq.heappop(open_list)

        if current in visited:
            continue
        visited.add(current)

 
        if current < 26:
            print(chr(current + ord('a')), end=' ')
        elif current == 26:
            print(' ', end=' ')
        elif current == 27:
            print('.', end=' ')
        

        for neighbor, count in enumerate(adj_matrix[current]):
            if count > 0 and neighbor not in visited:
           
                heuristic = -count
                heapq.heappush(open_list, (heuristic, neighbor))
                if neighbor not in came_from:
                    came_from[neighbor] = current

best_first_search('e')
    
    
