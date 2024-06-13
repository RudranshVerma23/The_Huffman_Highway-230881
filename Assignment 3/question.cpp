#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    string course;
    int marks;

    Student(string n, int r, string c, int m)
        : name(n), roll(r), course(c), marks(m) {}
};

class Node {
public:
    Student student;
    Node* left;
    Node* right;

    Node(Student s) : student(s), left(nullptr), right(nullptr) {}
};

class StudentRecordManage {
private:
    Node* Root = nullptr;

    Node* Insert(Node* root, Student stud) {
        if (root == nullptr)
            return new Node(stud);
        if (stud.roll > root->student.roll)
            root->right = Insert(root->right, stud);
        else
            root->left = Insert(root->left, stud);
        return root;
    }

    void printAllSubtree(Node* curr) {
        if (curr != nullptr) {
            printAllSubtree(curr->left);

            cout << "Student Name: " << curr->student.name << endl;
            cout << "Student Roll Number: " << curr->student.roll << endl;
            cout << "Student's Course: " << curr->student.course << endl;
            cout << "Student's Total Marks: " << curr->student.marks << endl;

            printAllSubtree(curr->right);
        }
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr) root = root->left;
        return root;
    }

    Node* Delete(Node* root, int roll) {
        if (root == nullptr) return root;
        if (roll < root->student.roll)
            root->left = Delete(root->left, roll);
        else if (roll > root->student.roll)
            root->right = Delete(root->right, roll);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->student = temp->student;
            root->right = Delete(root->right, temp->student.roll);
        }
        return root;
    }

    Node* search(Node* root, int roll) {
        if (root == nullptr || root->student.roll == roll) return root;
        if (roll > root->student.roll)
            return search(root->right, roll);
        return search(root->left, roll);
    }

public:
    void createStudentRecord(Student stud) {
        Root = Insert(Root, stud);
    }

    void deleteStudentRecord(int r) {
        Root = Delete(Root, r);
    }

    bool searchStudentRecord(int r) {
        return search(Root, r) != nullptr;
    }

    void showStudentRecord(int r) {
        Node* curr = search(Root, r);
        if (curr) {
            cout << "Student Name: " << curr->student.name << endl;
            cout << "Student Roll Number: " << curr->student.roll << endl;
            cout << "Student's Course: " << curr->student.course << endl;
            cout << "Student's Total Marks: " << curr->student.marks << endl;
        } else {
            cout << "Student record not found." << endl;
        }
    }

    void checkAllStudentRecords() {
        printAllSubtree(Root);
    }
};

int main() {
    StudentRecordManage IITK;

    IITK.createStudentRecord(Student("Rudransh Verma", 230881, "CSE", 100));
    IITK.showStudentRecord(230881);

    IITK.createStudentRecord(Student("Katy Perry", 230879, "ECE", 40));
    IITK.createStudentRecord(Student("Rahul Singh", 230883, "ME", 61));

    cout << "All Student Records:" << endl;
    IITK.checkAllStudentRecords();

    cout << "Deleting record with roll number 230882" << endl;
    IITK.deleteStudentRecord(230883);

    cout << "All Student Records after deletion:" << endl;
    IITK.checkAllStudentRecords();

    return 0;
}
