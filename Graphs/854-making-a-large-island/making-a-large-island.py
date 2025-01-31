class Solution(object):
    def largestIsland(self, grid):
        n = len(grid)
        group_id = [[0] * n for _ in range(n)]
        group_sizes = {}
        current_id = 1
        
        # Assign group IDs and calculate sizes using BFS
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1 and group_id[i][j] == 0:
                    queue = deque()
                    queue.append((i, j))
                    group_id[i][j] = current_id
                    size = 1
                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1 and group_id[nx][ny] == 0:
                                group_id[nx][ny] = current_id
                                queue.append((nx, ny))
                                size += 1
                    group_sizes[current_id] = size
                    current_id += 1
        
        # Determine the maximum initial island size
        initial_max = max(group_sizes.values()) if group_sizes else 0
        
        max_flip = 0
        
        # Check each 0 cell to see the potential maximum island size after flipping
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    neighbors = set()
                    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        nx, ny = i + dx, j + dy
                        if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                            neighbors.add(group_id[nx][ny])
                    total = 1  # The flipped cell itself
                    for gid in neighbors:
                        total += group_sizes.get(gid, 0)
                    if total > max_flip:
                        max_flip = total
        
        return max(initial_max, max_flip)
        