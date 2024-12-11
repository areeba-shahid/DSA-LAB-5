nums = [10, -5, 15, -20, 30, 5, -10]

# (a) Remove all negative numbers
nums = [num for num in nums if num >= 0]
print(f"After removing negatives: {nums}")

# (b) Find the maximum and minimum values
max_val = max(nums)
min_val = min(nums)
print(f"Max value: {max_val}, Min value: {min_val}")

# (c) Compute the average of the elements
avg_val = sum(nums) / len(nums)
print(f"Average value: {avg_val}")
