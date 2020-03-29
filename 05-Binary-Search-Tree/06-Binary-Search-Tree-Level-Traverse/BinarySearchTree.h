#pragma once

#include <iostream>
#include <queue>

using namespace std;

// ����������
template<typename Key,typename Value>
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
        destroy(_root);
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

    // �鿴�������������Ƿ���ڼ�key
    bool contain(Key key) {
        return contain(_root, key);
    }

    // �ڶ�����������������key����Ӧ��ֵ��������ֵ������, �򷵻�nullptr
    Value* search(Key key) {
        return search(_root, key);
    }

    // ������������ǰ�����
    void preOrder() {
        preOrder(_root);
    }

    // �������������������
    void inOrder() {
        inOrder(_root);
    }

    // �����������ĺ������
    void postOrder() {
        postOrder(_root);
    }

    // �����������Ĳ������
    void levelOrder() {
        if (_root == nullptr)
            return;

        queue<Node *> q;
        q.push(_root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->key << " ";

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
    }

private:
    // ����nodeΪ���Ķ�����������, ����ڵ�(key, value), ʹ�õݹ��㷨
    // ���ز����½ڵ��Ķ����������ĸ�
    Node* insert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            _count++;
            return new Node(key, value);
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

    // �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�, ʹ�õݹ��㷨
    bool contain(Node* node, Key key) {
        if (node == nullptr) {
            return false;
        }

        if (node->key > key) {
            return contain(node->left, key);
        }
        else if (node->key < key) {
            return contain(node->right, key);
        }
        else {  //node->key == key
            return true;
        }
    }

    // ����nodeΪ���Ķ����������в���key����Ӧ��value, �ݹ��㷨
    // ��value������, �򷵻�nullptr
    Value* search(Node* node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->key > key) {
            return search(node->left, key);
        }
        else if (node->key < key) {
            return search(node->right, key);
        }
        else {  //node->key == key
            return &(node->value);
        }
    }

    // ����nodeΪ���Ķ�������������ǰ�����, �ݹ��㷨
    void preOrder(Node* node) {
        if (node==nullptr) {
            return;
        }

        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // ����nodeΪ���Ķ��������������������, �ݹ��㷨
    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

    // ����nodeΪ���Ķ������������к������, �ݹ��㷨
    void postOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }

    // �ͷ���nodeΪ���Ķ��������������нڵ�
    // ���ú��������ĵݹ��㷨
    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
        _count--;
    }
};