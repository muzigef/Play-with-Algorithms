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

    // ����С�����㷨,����Student֮��ıȽϷ�ʽ
    // ���������ȣ��������ֵ���ĸ������
    // ����������ȣ�������͵Ŀ�ǰ
    bool operator<(const Student& otherStudent) {
        return _score != otherStudent._score ?
            _score < otherStudent._score:_name < otherStudent._name;
    }

    // ����С�����㷨,����Student֮��ıȽϷ�ʽ
    // ���������ȣ��������ֵ���ĸ������
    // ����������ȣ�������ߵĿ�ǰ
    bool operator>(const Student& otherStudent) {
        return _score != otherStudent._score ?
            _score > otherStudent._score : _name < otherStudent._name;
    }

    // ����<<����, ����Studentʵ���Ĵ�ӡ�����ʽ
    //��Ϊ��ĳ�Ա������ʱ�������Ĭ��Ϊ�����������
    //���������Ϊfriend�����ֳ��˳�Ա������,�޷���������Ҳ��ã�
    //Ȼ���ڵ���cin >> obj ���� cout << obj ��ʱ�������ȴ�ǲ��������Ҳ�
    friend ostream& operator<<(ostream &os, const Student &student) {
        os << "Student: " << student._name << " " << student._score << endl;
        return os;
    }

public:
    string _name;
    int _score;
};