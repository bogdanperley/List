#include "list.h"
#include <iostream>

List::~List() {
    clear();
}


List::List(const List& copy_list) {
    auto it = copy_list.node_;
    while  ( it != nullptr ) {
        push_back(it->data);
        it = it->next;
    }

}


void List::push_back(int val) {
    Node* node = new Node{};
    node->data = val;
    if (node_ == nullptr) {
        node_ = node;
        return;
    }
    auto iteration = node_;

    while (iteration->next != nullptr) {
        iteration = iteration->next;
    }

    iteration->next = node;
    node->prev = iteration;
}

void List::print() {
    if (node_ == nullptr) {
        std::cout << "List empty!" << "\n";
        return;
    }
    auto iteration = node_;

    while (iteration != nullptr) {
        std::cout << iteration->data << "->";
        iteration = iteration->next;
    }
    std::cout << "\n";
}

void List::push_front(int val) {
    Node* node = new Node{};
    node->data = val;
    if (node_ != nullptr) {
        node->next = node_;
        node_->prev = node;
    }
    node_ = node;
}

void List::pop_back() {
    if (node_ == nullptr) {
        return;
    }

    auto iteration = node_;
    while (iteration->next != nullptr) {
        iteration = iteration->next;
    }
    if (iteration->prev != nullptr) {
        iteration->prev->next = nullptr; // UB

    }
    else {
        node_ = nullptr;
    }
    delete iteration;
}

void List::pop_front() {
    if (node_ == nullptr) { // empty list
        return;
    }
    auto temp{ node_ };
    node_ = node_->next;
    delete temp;
}

Node* List::find_node(int val) {
    auto temp{ node_ };

    while (temp != nullptr) {
        if (temp->data == val) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void List::insert_node(Node* position, int val) {
    if (position == nullptr || node_ == nullptr) {
        return;
    }

    Node* node = new Node{};
    node->data = val;
     
    node->next = position;
    node->prev = position->prev;
    position->prev = node;

    if (position == node_) {
        node_ = node;
        return;
    }

    node->prev->next = node;
    // if (position == node_) { // one node and at first
    //   node_->prev = node;
    //   node->next = node_;
    //   node_ = node;
    //   return;
    // }
    // if (position->next == nullptr) { // last node
    //     node->next = position;
    //     node->prev = position->prev;
    //     position->prev->next = node;
    //     position->prev = node;
    //     return;
    //   }

    //   node->next = position;
    //   node->prev = position->prev;
    //   position->prev->next = node;
    //   position->prev = node;
}

void List::delete_node(Node* position)
{
    if (position == nullptr || node_ == nullptr) {// pos invalid or list empty
        return;
    }

    if (position == node_) { // first or one node in list 
       auto temp{ node_ };
       node_ = node_->next;
       delete temp;
       return;
    }

    if (position->prev != nullptr && position->next != nullptr)//  pos in the middle
    {  auto prev_node{ position->prev }; auto next_node{ position->next };
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete position;
        return;
    }

    if (position->next == nullptr && position->prev != nullptr) { // pos in the last
        position->prev->next = nullptr;
        delete position;
    }


}

void List::clear()
{
   /* 
   if (node_ == nullptr) {
        return;
    
    }
    */
     
    while (node_ != nullptr) {
        auto node_prev = node_;
        node_ = node_->next;
        delete node_prev;
    }




}
