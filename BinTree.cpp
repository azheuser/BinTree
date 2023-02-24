#include "BinTree.hpp"

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(): _root(0) {}

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree & rhs)
{ copy(_root, rhs._root); }


template<typename elemType>
inline BinaryTree<elemType>::
~BinaryTree() { clear(); }

template<typename elemType>
inline BinaryTree<elemType> &
BinaryTree<elemType>::
operator=(const BinaryTree & rhs)
{
    if(this != &rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

template<typename elemType>
inline std::ostream & operator<<
    (std::ostream & os, const BinaryTree<elemType> & bt)
{
    os << "Tree: " << std::endl;
    bt.print(os);
    return os;
}

template<typename elemType>
inline void
BinaryTree<elemType>::
insert(const elemType & elem)
{
    if(!_root) {
        _root = new BTnode<elemType>(elem);
    } else {
        _root->insert_value(elem);
    }
//    return;
}

template<typename valType>
inline BTnode<valType>::
BTnode(const valType & val)
    : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}

template<typename elemType>
void BinaryTree<elemType>::
remove(const elemType & elem)
{
    if(_root) {
        if(_root->_val == elem) {
            remove_root();
        } else {
            _root->remove_value(elem, _root);
        }
    }
//    return;
}

template<typename elemType>
void BinaryTree<elemType>::
remove_root()
{
    if(!_root) { return; }
    BTnode<elemType> * tmp = _root;
    if(_root->_rchild) {
        _root = _root->_rchild;
        if(tmp->_lchild) {
            BTnode<elemType> * lc = tmp->_lchild;
            BTnode<elemType> * newlc = _root->_lchild;
            if(!newlc) {
                _root->_lchild = lc;
            } else {
                BTnode<elemType>::lchild_leaf(lc, newlc);
            }
        }
    } else {
        _root = _root->_lchild;
    }
    delete tmp;
//    return;
}

template<typename elemType>
void BinaryTree<elemType>::
clear(BTnode<elemType> * pt)
{
    if(pt) {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
//    return;
}

template<typename valType>
void BTnode<valType>::
insert_value(const valType & val)
{
    if(val == _val) {
        _cnt++;
        return;
    }
    if(val < _val) {
        if(!_lchild) {
            _lchild = new BTnode(val);
        } else {
            _lchild->insert_value(val);
        }
    } else {
        if(!_rchild) {
            _rchild = new BTnode(val);
        } else {
            _rchild->insert_value(val);
        }
    }
//    return;
}

template<typename valType>
void BTnode<valType>::
lchild_leaf(BTnode * leaf, BTnode * subtree)
{
    while(subtree->_lchild) {
        subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;
//    return;
}

template<typename valType>
void BTnode<valType>::
remove_value(const valType & val, BTnode<valType> *& prev)
{
    if(val < _val) {
        if(!_lchild) { return; }
        else { _lchild->remove_value(val, _lchild); }
    } else if(val > _val) {
        if(!_rchild) { return; }
        else { _rchild->remove_value(val, _rchild); }
    } else {
        if(_rchild) {
            prev = _rchild;
            if(_lchild) {
                if(!prev->_lchild) {
                    prev->_lchild = _lchild;
                } else {
                    BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
                }
            }
        } else { prev = _lchild; }
        delete this;
    }
//    return;
}

template<typename valType>
void BTnode<valType>::
preorder(BTnode<valType> * pt, std::ostream & os)
const
{
    if(pt) {
        display_val(pt, os);
        if(pt->_lchild) { preorder(pt->_lchild, os); }
        if(pt->_rchild) { preorder(pt->_rchild, os); }
    }
//    return;
}

template<typename valType>
void BTnode<valType>::
inorder(BTnode<valType> * pt, std::ostream & os)
const
{
    if(pt) {
        if(pt->_lchild) { preorder(pt->_lchild, os); }
        display_val(pt, os);
        if(pt->_rchild) { preorder(pt->_rchild, os); }
    }
//    return;
}

template<typename valType>
void BTnode<valType>::
postorder(BTnode<valType> * pt, std::ostream & os)
const
{
    if(pt) {
        if(pt->_lchild) { preorder(pt->_lchild, os); }
        if(pt->_rchild) { preorder(pt->_rchild, os); }
        display_val(pt, os);
    }
//    return;
}
