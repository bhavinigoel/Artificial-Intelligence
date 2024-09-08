
graph = {

  'A':['B','C','D'],
  'B':['C','D','E' ,'F'],
  'C':['E', 'F','G'],
  'D':['E', 'F','G','H'],
  'E':[ 'F','G','H'],
   'F': ['G','H'],
   'G':['H','I','J'],
   'H':['I','J'],
   'I':[],
   'J':[]

}

def dfs(graph, start):
    visited = set() 
    def visit(node):
        if node not in visited:
            visited.add(node)
            print(node,end=" ")  # Process the node
            for neighbor in graph[node]:
                visit(neighbor)
    
    visit(start)

def main():
   
    dfs(graph, 'A')

if __name__ == "__main__":
    main()
