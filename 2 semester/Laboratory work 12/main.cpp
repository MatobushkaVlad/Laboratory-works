#include <iostream>
#include <memory> 
#include <string>
#include <vector>
#define MY_DEBUG

class Student
{
public:
	Student(const std::string& name)
	{
		m_student = name;
#ifdef MY_DEBUG
		std::cout << "Constructor: Student" << std::endl;
#endif
	}
	~Student()
	{
#ifdef MY_DEBUG
		std::cout << "Destructor: Student " << std::endl;
#endif
	}

	std::string NameStudent() { return m_student; }
	std::shared_ptr<Teacher> GetTeacher() { m_teacher; }

	void AddTeacher(std::shared_ptr<Teacher>& teacher)
	{
		m_teacher = teacher;
	}

private:
	std::string m_student;
	std::weak_ptr<Teacher> m_teacher;
};


class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_teachers = name;
#ifdef MY_DEBUG
		std::cout << "Constructor: Teacher" << std::endl;
#endif
	}
	~Teacher()
	{
#ifdef MY_DEBUG
		std::cout << "Destructor: Teacher " << std::endl;
#endif
	}

	friend void Student_Teacher(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S)
	{
		T->AddStudent(S);
		S->AddTeacher(T);
	}
	std::string NameTeacher() { return m_teachers; }

	void AddStudent(std::shared_ptr<Student>& student)
	{
		m_students.push_back(student);
	}

	void AllStudents()
	{
		if (!m_students.empty())
		{
			std::cout << m_teachers << " students: " << std::endl;
			for (const auto& Student : m_students)
			{
				std::cout << Student->NameStudent() << std::endl;
			}
		}
	}
private:
	std::string m_teachers;
	std::vector<std::shared_ptr<Student>> m_students;
};


int main()
{
	auto teacher0{ std::make_shared<Teacher>("Ivan Vladimirovich") };
	auto student1{ std::make_shared<Student>("Petr") };
	auto student2{ std::make_shared<Student>("Alexandr") };
	auto student3{ std::make_shared<Student>("Samuil") };

	Student_Teacher(teacher0, student1);
	Student_Teacher(teacher0, student2);
	Student_Teacher(teacher0, student3);

	teacher0->AllStudents();
}