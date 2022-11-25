#include <iostream>
#include"list.h"

class Test {
    int data{};
public:
    void inc_data() {
        ++data;
    }
    void inc_data_on_2() {
        data += 2;
    }

    int get_data() {
        return data;
    }
};

int main() {
    List binari_tree;
    binari_tree.push_back(5);
    binari_tree.push_back(20);
    binari_tree.push_back(30);
    binari_tree.push_back(47);
    binari_tree.print();
    List new_list{ binari_tree };

}