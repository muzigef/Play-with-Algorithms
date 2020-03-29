#include <string>
#include <iostream>

using namespace std;

class Student {
public:
    Student(string name,int score) {
        _name = name;
        _score = score;
    }

    ~Student() {}

    // 重载小于运算法,定义Student之间的比较方式
    // 如果分数相等，则按照名字的字母序排序
    // 如果分数不等，则分数低的靠前
    bool operator<(const Student& otherStudent) {
        return _score != otherStudent._score ?
            _score < otherStudent._score:_name < otherStudent._name;
    }

    // 重载小于运算法,定义Student之间的比较方式
    // 如果分数相等，则按照名字的字母序排序
    // 如果分数不等，则分数高的靠前
    bool operator>(const Student& otherStudent) {
        return _score != otherStudent._score ?
            _score > otherStudent._score : _name < otherStudent._name;
    }

    // 重载<<符号, 定义Student实例的打印输出方式
    //作为类的成员函数的时候，类对象默认为操作符的左参
    //如果不声明为friend，就又成了成员函数了,无法把类对象当右参用，
    //然而在调用cin >> obj 或者 cout << obj 的时候，类对象却是操作符的右参
    friend ostream& operator<<(ostream &os, const Student &student) {
        os << "Student: " << student._name << " " << student._score << endl;
        return os;
    }

public:
    string _name;
    int _score;
};