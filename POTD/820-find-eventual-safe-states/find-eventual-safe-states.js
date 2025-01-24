/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    let n = graph.length;
    
    // Step 1: Reverse the Graph
    let reverseGraph = Array.from({ length: n }, () => []);
    let inDegree = new Array(n).fill(0); // To store in-degree for the reversed graph

    for (let src = 0; src < n; src++) {
        for (let dest of graph[src]) {
            reverseGraph[dest].push(src); // Reverse the direction
        }
        inDegree[src] = graph[src].length; // Out-degree in original graph
    }

    // Step 2: Initialize queue with terminal nodes
    let queue = [];
    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 0) { // Terminal nodes in original graph
            queue.push(i);
        }
    }

    // Step 3: Process nodes in BFS
    let safeNodes = [];

    while (queue.length > 0) {
        let node = queue.shift();
        safeNodes.push(node); // This node is safe
        
        for (let neighbor of reverseGraph[node]) {
            inDegree[neighbor]--; // Remove edge
            if (inDegree[neighbor] === 0) { // Becomes a terminal node
                queue.push(neighbor);
            }
        }
    }

    // Step 4: Sort and return result
    return safeNodes.sort((a, b) => a - b);
};

// Example Test Cases
console.log(eventualSafeNodes([[1,2],[2,3],[5],[0],[5],[],[]])); // Output: [2,4,5,6]
console.log(eventualSafeNodes([[1,2,3,4],[1,2],[3,4],[0,4],[]])); // Output: [4]
