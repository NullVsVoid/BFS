// bfs.cpp

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

// Placeholder for a function that returns whether a node is a value.
bool is_value(int node, const std::vector<std::vector<int>>& graph);

bool breadth_first_search(int start,
                          const std::vector<std::vector<int>>& graph) {
    // A queue is used to manage the nodes to be visited next.
    // BFS uses a FIFO (First In, First Out) strategy for exploring nodes,
    // meaning nodes are explored in theo rder they are discovered.
    std::queue<int> search_queue;

    // An unordered set to keep track of all the nodes that have been visited.
    // This prevents the algorithm from getting stuck in a loop by re-visiting
    // nodes.
    std::unordered_set<int> searched;

    // Start the search with the 'start' node by pushing it onto the queue.
    search_queue.push(start);

    // Continue the search as long as there are unexplored nodes,
    // i.e., the queue is not empty.
    while (!search_queue.empty()) {
        // Retrieve and remove the front element from the queue.
        // This is the next node to be epxlored.
        int node = search_queue.front();
        search_queue.pop();

        // Check if this node has been visited before.
        // If it hasn't been visited ('searched' set does not contain 'node'),
        // then proceed with exploring it.
        if (searched.find(node) == searched.end()) {
            // For debugging purposes, print the node.
            std::cout << node << std::endl;

            // If the 'is_value' condition is satisfied for the node,
            // then we have found what we are searching for, and return true.
            if (is_value(node, graph)) {
                return true;
            } else {
                // If the node does not satisfy the 'is_value' condition,
                // then we add all of its neighbors to the queue for future
                // exploration. This is where the BFS explores breadth by
                // moving to adjacent nodes.
                for (int neighbor : graph[node]) {
                    search_queue.push(neighbor);
                }

                // Mark the current node as visited by adding it to the
                // 'searched' set. This ensures we do not revisit and re-explore
                // this node.
                searched.insert(node);
            }
        }
    }

    // If the function reaches this point, it means we have explored all
    // reachable nodes and have not found the value we are searching for.
    return false;
}

// Checks for condition of node being 42 (example).
bool is_value(int node, const std::vector<std::vector<int>>& graph) {
    return node == 42;
}

int main() {
    std::vector<std::vector<int>> graph = {{1, 2, 3}, {4, 5}, {6}, {7}, {8},
                                           {9},       {},     {},  {},  {}};

    std::cout << breadth_first_search(0, graph) << std::endl;

    // Example of using the is_value function.
    std::vector<std::vector<int>> graph_containing_42 = {
        {1, 2, 3}, {4, 5}, {6}, {7}, {8}, {9}, {}, {}, {}, {42}};

    if (breadth_first_search(0, graph_containing_42)) {
        std::cout << "Found 42!" << std::endl;
    } else {
        std::cout << "42 not found." << std::endl;
    }

    // Example of not finding 42.
    if (breadth_first_search(0, graph)) {
        std::cout << "Found 42!" << std::endl;
    } else {
        std::cout << "42 not found." << std::endl;
    }

    return 0;
}