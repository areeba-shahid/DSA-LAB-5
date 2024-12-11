import time

nums = []
for i in range(1, 101):
    start_time = time.time()
    nums.append(i)
    end_time = time.time()
    print(f"Time to append {i}: {end_time - start_time:.10f} seconds")
