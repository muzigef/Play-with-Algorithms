#pragma once

#include <iostream>
#include <queue>
#include <cassert>

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

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
        destroy(_root);
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

    // 二分搜索树的前序遍历
    void preOrder() {
        preOrder(_root);
    }

    // 二分搜索树的中序遍历
    void inOrder() {
        inOrder(_root);
    }

    // 二分搜索树的后序遍历
    void postOrder() {
        postOrder(_root);
    }

    // 二分搜索树的层序遍历
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

    // 寻找二分搜索树的最小的键值
    Key minimum() {
        assert(!isEmpty());
        Node* minNode = minimum(_root);
        return minNode->key;
    }

    // 寻找二分搜索树的最大的键值
    Key maximum() {
        assert(!isEmpty());
        Node* minNode = maximum(_root);
        return minNode->key;
    }

    // 从二分搜索树中删除最小值所在节点
    void removeMin() {
        if (_root) {
            _root = removeMin(_root);
        }
    }

    // 从二分搜索树中删除最大值所在节点
    void removeMax() {
        if (_root) {
            _root = removeMax(_root);
        }
    }

    // 从二分搜索树中删除键值为key的节点
    void remove(Key key) {
        _root = remove(_root, key);
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

    // 对以node为根的二叉搜索树进行前序遍历, 递归算法
    void preOrder(Node* node) {
        if (node==nullptr) {
            return;
        }

        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 对以node为根的二叉搜索树进行中序遍历, 递归算法
    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

    // 对以node为根的二叉搜索树进行后序遍历, 递归算法
    void postOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }

    // 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
        _count--;
    }

    // 返回以node为根的二分搜索树的最小键值所在的节点
    Node* minimum(Node* node) {
        if (node->left == nullptr) {
            return node;
        }

        return minimum(node->left);
    }

    // 返回以node为根的二分搜索树的最大键值所在的节点
    Node* maximum(Node* node) {
        if (node->right == nullptr) {
            return node;
        }

        return maximum(node->right);
    }

    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根,，只要变更了树都需要返回
    Node* removeMin(Node* node) {
        if (node->left==nullptr) {
            Node* rightNode = node->right;
            delete node;
            _count--;

            return rightNode;
        }

        node->left = removeMin(node->left);

        return node;
    }

    // 删除掉以node为根的二分搜索树中的最大节点
    // 返回删除节点后新的二分搜索树的根,，只要变更了树都需要返回
    Node* removeMax(Node* node) {
        if (node->right == nullptr) {
            Node* leftNode = node->left;
            delete node;
            _count--;

            return leftNode;
        }

        node->right = removeMin(node->right);

        return node;
    }

    // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (node->key == key) {
            // 待删除节点左子树为空的情况
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                delete node;
                _count--;
                return rightNode;
            }

            // 待删除节点右子树为空的情况
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                _count--;
                return leftNode;
            }

            // 待删除节点左右子树均不为空的情况

            // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
            // 用这个节点顶替待删除节点的位置
            Node *successor = new Node(minimum(node->right));
            _count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            _count--;

            return successor;
        }
        else if (node->key < key) {
            node->right = remove(node->right, key);
        }
        else {
            node->left = remove(node->left, key);
        }

        return node;
    }

};