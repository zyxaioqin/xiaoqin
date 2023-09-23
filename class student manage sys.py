class StudentManagementSystem:
    def __init__(self):
        self.students = {}  # 用字典来存储学生信息

    def add_student(self, student_id, name, age):
        if student_id not in self.students:
            self.students[student_id] = {'name': name, 'age': age}
            print(f"学生 {name} 添加成功！")
        else:
            print(f"学生 ID {student_id} 已存在，请使用其他 ID。")

    def remove_student(self, student_id):
        if student_id in self.students:
            removed_student = self.students.pop(student_id)
            print(f"学生 {removed_student['name']} 已从系统中移除。")
        else:
            print(f"学生 ID {student_id} 不存在。")

    def update_student(self, student_id, name, age):
        if student_id in self.students:
            self.students[student_id] = {'name': name, 'age': age}
            print(f"学生 ID {student_id} 信息已更新。")
        else:
            print(f"学生 ID {student_id} 不存在。")

    def get_student_info(self, student_id):
        if student_id in self.students:
            student_info = self.students[student_id]
            print(f"学生 ID: {student_id}")
            print(f"姓名: {student_info['name']}")
            print(f"年龄: {student_info['age']}")
        else:
            print(f"学生 ID {student_id} 不存在。")

    def list_all_students(self):
        if not self.students:
            print("暂无学生信息。")
        else:
            print("所有学生信息：")
            for student_id, student_info in self.students.items():
                print(f"学生 ID: {student_id}")
                print(f"姓名: {student_info['name']}")
                print(f"年龄: {student_info['age']}")
                print("---------------------")

def main():
    sms = StudentManagementSystem()

    while True:
        print("\n学生信息管理系统")
        print("1. 添加学生")
        print("2. 删除学生")
        print("3. 更新学生信息")
        print("4. 查看学生信息")
        print("5. 列出所有学生")
        print("6. 退出")

        choice = input("请选择操作（1/2/3/4/5/6）：")

        if choice == '1':
            student_id = input("请输入学生 ID: ")
            name = input("请输入学生姓名: ")
            age = input("请输入学生年龄: ")
            sms.add_student(student_id, name, age)
        elif choice == '2':
            student_id = input("请输入要删除的学生 ID: ")
            sms.remove_student(student_id)
        elif choice == '3':
            student_id = input("请输入要更新信息的学生 ID: ")
            name = input("请输入学生新姓名: ")
            age = input("请输入学生新年龄: ")
            sms.update_student(student_id, name, age)
        elif choice == '4':
            student_id = input("请输入要查看信息的学生 ID: ")
            sms.get_student_info(student_id)
        elif choice == '5':
            sms.list_all_students()
        elif choice == '6':
            print("谢谢使用学生信息管理系统，再见！")
            break
        else:
            print("无效的选项，请重新选择。")

if __name__ == "__main__":
    main()
