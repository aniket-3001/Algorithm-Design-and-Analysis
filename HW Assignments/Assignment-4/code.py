from collections import defaultdict, deque

def topological_sort(graph):
    in_degree = defaultdict(int)
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1
    
    queue = deque([node for node in graph if in_degree[node] == 0])
    topo_order = []
    
    while queue:
        node = queue.popleft()
        topo_order.append(node)
        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return topo_order if len(topo_order) == len(graph) else None

def find_cut_vertices(graph, start_node, end_node):
    topo_order = topological_sort(graph)
    if topo_order is None:
        return "Graph has a cycle"
    
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)
    cuts = []

    for node in graph:
        for neighbor in graph[node]:
            out_degree[node] += 1
            in_degree[neighbor] += 1

    for node in topo_order:
        in_count = in_degree[node]
        out_count = out_degree[node]
        short_cuts = in_count + out_count
        
        # Check if the current node is an (s, t)-cut vertex
        if node != start_node and node != end_node and short_cuts > 0:
            cuts.append(node)

        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            out_degree[node] -= 1

    return cuts

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E'],
    'D': [],
    'E': ['F'],
    'F': [],
}

start_node = 'A'
end_node = 'F'
result = find_cut_vertices(graph, start_node, end_node)
print("Cut vertices:", result)