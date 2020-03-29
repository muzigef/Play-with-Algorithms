#pragma once

#include <iostream>

using namespace std;

// ����������
template<typename Key, typename Value>
class BinarySearchTree {
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

    // ������������в���һ���µ�(key, value)���ݶ�
    void insert(Key key, Value value) {
        _root = insert(_root, key, value);
    }

private:
    // ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
    // ���ز����½ڵ��Ķ����������ĸ�
    Node* insert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            _count++;
            return new Node(key, value);;
        }

        if (key > node->key) {
            //Ҫ�����صĽڵ㸳ֵ��node->right
            node->right = insert(node->right, key, value);
        }
        else if (key < node->key) {
            //Ҫ�����صĽڵ㸳ֵ��node->left
            node->left = insert(node->left, key, value);
        }
        else {  // key == node->key
            node->value = value;
        }

        return node;
    }
};