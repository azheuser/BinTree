#include "BinTree.hpp"

int main()
{
    BinaryTree<int> bt;

    for(int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        bt.insert(num);
    }


}
