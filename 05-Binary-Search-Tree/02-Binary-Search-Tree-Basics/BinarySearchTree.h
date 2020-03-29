#pragma once

#include <iostream>

using namespace std;

// ����������
template<typename Key,typename Value>
class BinarySearchTree {
public:
    // ���캯��, Ĭ�Ϲ���һ�ÿն���������
    BinarySearchTree() {
        _root = nullptr;
        _count = 0;
    }

    ~BinarySearchTree() {
        //TODO
    }

    // ���ض����������Ľڵ����
    int size() {
        return _count;
    }

    // ���ض����������Ƿ�Ϊ��
    bool isEmpty() {
        return _count == 0;
    }

private:
    // �����������еĽڵ�Ϊ˽�еĽṹ��, ��粻��Ҫ�˽�����������ڵ�ľ���ʵ��
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }
    };

    Node* _root;  // ���ڵ�
    int _count;  // �ڵ����
};