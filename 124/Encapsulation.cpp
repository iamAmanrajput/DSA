#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    // Setter for name
    void setName(string n)
    {
        name = n;
    }

    // Getter for name
    string getName()
    {
        return name;
    }

    // Setter for age
    void setAge(int a)
    {
        if (a > 0)
            age = a;
        else
            cout << "Invalid age!" << endl;
    }

    // Getter for age
    int getAge()
    {
        return age;
    }
};

int main()
{
    Student s1;

    s1.setName("Aman");
    s1.setAge(22);

    cout << "Name: " << s1.getName() << endl;
    cout << "Age: " << s1.getAge() << endl;

    return 0;
}
