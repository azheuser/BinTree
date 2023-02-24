//
// Created by PanRui on 2023/1/27.
//

#ifndef BINTREE_BINTREE_HPP
#define BINTREE_BINTREE_HPP

#include <iostream>

template<typename valType>
class BTnode;

template<typename elemType>
class BinaryTree;

template<typename elemType>
class BinaryTree {
    friend class BTnode<elemType>;
  public:
    BinaryTree();
    BinaryTree(const BinaryTree &);

    explicit BinaryTree(BTnode<elemType> * root);

    virtual ~BinaryTree();
    BinaryTree & operator=(const BinaryTree &);
    friend std::ostream & operator<<(std::ostream &, const BinaryTree<elemType> &);

//public:
    bool empty() { return _root == 0; }
    void clear()
    {
        if(_root) {
            clear(_root);
            _root = 0;
        }
    }
    void insert(const elemType & elem);
    void remove(const elemType & elem);
    void remove_root();

  private:
    BTnode<elemType> * _root;

//private:
    void clear(BTnode<elemType> *);

    void copy(BTnode<elemType> * tar, BTnode<elemType> * src);
};

template<typename valType>
class BTnode {
    friend class BinaryTree<valType>;
  public:
    explicit BTnode(const valType & val);
//public:
    void insert_value(const valType &);
    void remove_value(const valType & val, BTnode *& prev);
    static void lchild_leaf(BTnode * leaf, BTnode * subtree);
    void preorder(BTnode * pt, std::ostream & os) const;
    void inorder(BTnode * pt, std::ostream & os) const;
    void postorder(BTnode * pt, std::ostream & os) const;
  private:
    valType _val;
    int _cnt;
    BTnode * _lchild;
    BTnode * _rchild;
};

#endif //BINTREE_BINTREE_HPP
