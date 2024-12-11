def search_student(name):
    if name in students:
        print(f"{name} found at index {students.index(name)}")
    else:
        print(f"{name} is not in the list.")

# Example usage:
add_student("John")
search_student("John")
search_student("Alice")
