def create_grid(rows, cols):
    return [[0 for _ in range(cols)] for _ in range(rows)]

def add_row(grid, row):
    grid.append(row)

def add_column(grid):
    for row in grid:
        row.append(0)

def display_grid(grid):
    for row in grid:
        print(row)

def sum_grid(grid):
    total_sum = sum(sum(row) for row in grid)
    return total_sum

# Example usage:
grid = create_grid(2, 3)
display_grid(grid)
add_row(grid, [1, 2, 3])
add_column(grid)
display_grid(grid)
print(f"Sum of all elements: {sum_grid(grid)}")
