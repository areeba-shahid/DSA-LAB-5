students = []

def add_student(name):
    students.append(name)

def remove_student(name):
    if name in students:
        students.remove(name)
    else:
        print(f"{name} not found in the list.")

def display_students():
    print("List of students:")
    for student in students:
        print(student)


add_student("Alice")
add_student("Bob")
display_students()
remove_student("Alice")
display_students()
