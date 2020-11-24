
template <class T>
class LinkedList;
template <class T>
class Node;
#include <iostream>
#include <cassert>


template<typename T>
void printLL(LinkedList<T>& ll){
    std::cout << "Printing in Order" << std::endl;

    if (ll.isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T>* node = ll.getFirstNode();

    while (node) {
        std::cout << *node << "  ";
        node = node->next;
    }
    std::cout<<std::endl;
}

template<typename T>
void printLLRev(LinkedList<T>& ll){
    std::cout << "Printing in Reverse" << std::endl;

    if (ll.isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T>* node = ll.getLastNode();

    while (node) {
        std::cout << *node << "  ";
        node = node->prev;
    }
    std::cout<<std::endl;
}

template<typename T>
void isThereABrokenLink(LinkedList<T>& ll){
    Node<T>* head_ = ll.getFirstNode();
    Node<T>* tail_ = ll.getLastNode();
    if (ll.isEmpty()) {
        if(head_!=tail_){
            std::cerr << "YOU HAVE AN EMPTY LIST BUT HEAD AND TAIL ARE NOT THE SAME!" << std::endl;
            assert(!tail_);//tail should be null
            assert(!head_);//head should be null
            //use gdb and find what is the data that is causing this.
        }
        
        return;
    }

    Node<T>* node = tail_,*firstNode;
    int size = ll.getNumberOfNodes(),csize;
    csize = size;
    int previousNullCount=0,nextNullCount = 0;
    uint8_t headReached=0,tailReached=0;
    while (node) {
        
        size--;
        nextNullCount += !(node->next);
        headReached = headReached ^ (head_==node);
        firstNode = node;
        node = node->prev;
        if((!node||!size) && (node || size)){
            //BROKEN LINK IF THIS IS FIRED
            std::cerr << "Number of nodes don't match when traversing list backwards!" << std::endl;
            assert((node&&size) || (!node && !size));
            //use gdb and find what is the data that is causing this.
        }
    }
    if(!headReached){
        //BROKEN LINK IF THIS IS FIRED
        std::cerr << "When traversing list backwards we cant reach head!" << std::endl;
        assert(firstNode==head_);
    }
    node=head_;
    // previousNullCount = 0;
    while (node) {
        
        csize--;
        previousNullCount += !(node->prev);
        tailReached = tailReached ^ (tail_==node);
        firstNode = node;
        node = node->next;
        if((!node||!csize) && (node || csize)){
            //BROKEN LINK IF THIS IS FIRED
            std::cerr << "Number of nodes don't match when traversing list forward!" << std::endl;
            assert((node&&size) || (!node && !size));
            //use gdb and find what is the data that is causing this.
        }
    }
    //BROKEN LINK IF THIS IS FIRED
    assert(nextNullCount+previousNullCount == 2);//You have more than two nulls in your linked list if this is fired

    std::cout<<std::endl;
}