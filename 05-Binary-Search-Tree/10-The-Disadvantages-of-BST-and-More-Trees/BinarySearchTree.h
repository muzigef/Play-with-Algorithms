#pragma once

#include <iostream>

using namespace std;

// 二分搜索树
template<typename Key,typename Value>
class BinarySearchTree {
private:
    // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
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

    Node* _root;  // 根节点
    int _count;  // 节点个数

public:
    // 构造函数, 默认构造一棵空二分搜索树
    BinarySearchTree() {
        _root = nullptr;
        _count = 0;
    }

    ~BinarySearchTree() {
        //TODO
    }

    // 返回二分搜索树的节点个数
    int size() {
        return _count;
    }

    // 返回二分搜索树是否为空
    bool isEmpty() {
        return _count == 0;
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value) {
        _root = insert(_root, key, value);
    }

    // 查看二分搜索树中是否存在键key
    bool contain(Key key) {
        return contain(_root, key);
    }

    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回nullptr
    Value* search(Key key) {
        return search(_root, key);
    }

private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node* insert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            _count++;
            return new Node(key, value);
        }

        if (key > node->key) {
            //要将返回的节点赋值给node->right
            node->right = insert(node->right, key, value);
        }
        else if (key < node->key) {
            //要将返回的节点赋值给node->left
            node->left = insert(node->left, key, value);
        }
        else {  // key == node->key
            node->value = value;
        }

        return node;
    }

    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
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

    // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回nullptr
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
};