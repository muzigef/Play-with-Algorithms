#pragma once

#include <iostream>

using namespace std;

// 二分搜索树
template<typename Key,typename Value>
class BinarySearchTree {
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
};