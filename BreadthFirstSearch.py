"""
    Breadth First Search algorithm implementation,
    which includes both iterative and recursive implementations.
"""

"""
    Method to perform BFS algorithm iteratively

    ARGUMENTS:
    graph: graph represented in the form of adjacency list
    startNode: starting node for the BFS 
    goalNode: target node 
"""
def iterativeBFS(graph: dict, startNode: str, goalNode: str):

    #Initializing a list to track visited nodes
    visited = set()

    #Initializing a queue with the start node provided
    queue = [startNode]

    #Traversing through the queue
    while queue:

        #Obtaining front element in the queue
        node = queue.pop(0)

        #Determining whether popped node is target node
        if node == goalNode:
            print(f"Goal node found: {node}")
            return

        #Determining whether node has not popped before to prevent loops
        if node not in visited:

            #Printing current node
            print(f"Current node: {node }")

            #Marking node as visited
            visited.add(node)
            
            #Iterating through current node's neighbors
            for neighbor in graph[node]:

                #Determining whether the neighbor did not be visited before
                if neighbor not in visited:

                    #Appending neighbors to queue for visiting later
                    queue.append(neighbor)
    
    #In the case of unsuccessful search
    print(f"Target node {goalNode} is not included in the graph")


"""
    Method to perform BFS algorithm recursively

    ARGUMENTS:
    graph: graph represented in the form of adjacency list
    startNode: starting node for the BFS 
    goalNode: target node
    visited: list to track visited nodes
"""
def recursiveBFS(graph: dict, startNode: str,  goalNode: str, queue: list = None, visited: list = None):

    #Determining whether visited list is none
    if visited is None:

        #Initializing a list to track visited nodes
        visited = []
    
    #Determining whether queue is none
    if queue is None:

        #Initializing a queue with the start node provided
        queue = [startNode]
        
    #Terminating process in the case of queue is empty
    if not queue:

        #In the case of unsuccessful search
        print(f"Target node {goalNode} is not included in the graph")
        return
    
    #Obtaining front element in the queue
    node = queue.pop(0)

    #Determining whether popped node is target node
    if node == goalNode:
        print(f"Goal node found: {node}")
        return

    #Determining whether node has not popped before to prevent loops
    if node not in visited:

        #Printing current node
        print(f"Current node: {node }")

        #Marking node as visited
        visited.append(node)

        #Iterating through current node's neighbors
        for neighbor in graph[node]:

            #Determining whether the neighbor did not be visited before
            if neighbor not in visited:

                #Appending neighbors to queue for visiting later
                queue.append(neighbor)
    
    #Recursively calling the function with the updated queue and visited list
    recursiveBFS(graph, startNode, goalNode, queue, visited)

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
    iterativeBFS(graph, startNode, goalNode)

    #Test the recursive BFS algorithm
    print("\nTesting Recursive BFS:")
    recursiveBFS(graph, startNode, goalNode)
"""