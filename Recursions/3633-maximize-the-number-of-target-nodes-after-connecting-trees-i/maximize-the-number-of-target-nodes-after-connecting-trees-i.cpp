class Solution {
public:
    std::vector<int> findNodesWithinK(const std::vector<std::vector<int>>& adjList, const int k)
    {
        std::vector<int> returnVal;

        for(int start = 0; start < adjList.size(); start++)
        {
            std::queue<std::pair<int, int>> curNodeToParentQ;
            curNodeToParentQ.emplace(std::make_pair(start, -1));

            int valsWithinK = 0;
            int remainingK = k;

            // Since the inputs are trees, there's no risk of a cycle
            // so we don't need to maintain a visited set
            while(curNodeToParentQ.empty() == false && remainingK >= 0)
            {
                int qSize = curNodeToParentQ.size();
                for(int j = 0; j < qSize; j++)
                {
                    int node = curNodeToParentQ.front().first;
                    int parent = curNodeToParentQ.front().second;
                    curNodeToParentQ.pop();
                    ++valsWithinK;

                    for(const int& adjElem : adjList[node])
                    {
                        if(adjElem == parent) continue;

                        curNodeToParentQ.emplace(std::make_pair(adjElem, node));
                    }
                }
                --remainingK;
            }

            returnVal.push_back(valsWithinK);
        }

        return returnVal;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        std::vector<std::vector<int>> edges1AdjList(edges1.size() + 1);

        for(const std::vector<int>& edge : edges1)
        {
            edges1AdjList[edge.front()].emplace_back(edge.back());
            edges1AdjList[edge.back()].emplace_back(edge.front());
        }

        std::vector<std::vector<int>> edges2AdjList(edges2.size() + 1);

        for(const std::vector<int>& edge : edges2)
        {
            edges2AdjList[edge.front()].emplace_back(edge.back());
            edges2AdjList[edge.back()].emplace_back(edge.front());
        }

        std::vector<int> returnVal = findNodesWithinK(edges1AdjList, k);

        // Subtract one, since we will need one step to travel to the node with
        // the most connections from k - 1
        std::vector<int> tree2Vec = findNodesWithinK(edges2AdjList, k - 1);

        int valToAdd = *std::max_element(tree2Vec.begin(), tree2Vec.end());

        for(int& num : returnVal)
        {
            num += valToAdd;
        }

        return returnVal;
    }
};