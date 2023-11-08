"""
    Depth First Search algorithm implementation,
    which includes both iterative and recursive implementations.
"""

"""
    Method to perform DFS algorithm iteratively

    ARGUMENTS:
    graph: graph represented in the form of adjacency list
    startNode: starting node for the BFS 
    goalNode: target node 
"""
def iterativeDFS(graph: dict, startNode: str, goalNode: str):

    #Initializing a list to track visited nodes
    visited = set()

    #Initializing a stack with the start node provided
    stack = [startNode]

    #Traversing through the stack
    while stack:

        #Obtaining last element in the stack
        node = stack.pop()

        #Determining whether node has not popped before to prevent loops
        if node not in visited:

            #Printing current node
            print(f"Current node: {node }")
        
            #Marking node as visited
            visited.add(node)

            #Determining whether added node is target node
            if node == goalNode:
                print(f"Goal node found: {node}")
                return
            
            #Iterating through current node's neighbors
            for neighbor in graph[node]:

                #Determining whether the neighbor did not be visited before
                if neighbor not in visited:

                    #Appending neighbors to stack for visiting later
                    stack.append(neighbor)
    
    #In the case of unsuccessful search
    print(f"Target node {goalNode} is not included in the graph")

"""
    Method to perform DFS algorithm recursively

    ARGUMENTS:
    graph: graph represented in the form of adjacency list
    startNode: starting node for the BFS 
    goalNode: target node
    visited: list to track visited nodes
"""
def recursiveDFS(graph: dict, startNode: str,  goalNode: str, stack: list = None, visited: list = None):

    #Determining whether visited list is none
    if visited is None:

        #Initializing a list to track visited nodes
        visited = []
    
    #Determining whether stack is none
    if stack is None:

        #Initializing a queue with the start node provided
        stack = [startNode]
        
    #Terminating process in the case of stack is empty
    if not stack:

        #In the case of unsuccessful search
        print(f"Target node {goalNode} is not included in the graph")
        return
    
    #Obtaining last element in the stack
    node = stack.pop()

    #Determining whether node has not popped before to prevent loops
    if node not in visited:

        #Printing current node
        print(f"Current node: {node }")

        #Marking node as visited
        visited.append(node)

        #Determining whether added node is target node
        if node == goalNode:
            print(f"Goal node found: {node}")
            return

        #Iterating through current node's neighbors
        for neighbor in graph[node]:

            #Determining whether the neighbor did not be visited before
            if neighbor not in visited:

                #Appending neighbors to queue for visiting later
                stack.append(neighbor)
    
    #Recursively calling the function with the updated queue and visited list
    recursiveDFS(graph, startNode, goalNode, stack, visited)

"""
Driver test function
if __name__ == "__main__":

    #Sample graph represented as an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['A', 'D', 'E'],
        'C': ['A', 'F'],
        'D': ['B'],
        'E': ['B', 'F'],
        'F': ['C', 'E']
    }

    #Define the start and goal nodes
    startNode = 'A'
    goalNode = 'F'

    #Test the iterative BFS algorithm
    print("Testing Iterative BFS:")
    iterativeDFS(graph, startNode, goalNode)

    #Test the recursive BFS algorithm
    print("\nTesting Recursive BFS:")
    recursiveDFS(graph, startNode, goalNode)
"""