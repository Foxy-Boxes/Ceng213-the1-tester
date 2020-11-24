#include <iostream>

#include "LinkedList.h"
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


int main() {
    //various inserts; various deletes (removeNode(const T &data)); print.
    LinkedList<std::string> llist;
    std::string one = "std"
    ,two = "string"
    ,three = "is"
    ,four = "somewhat"
    ,five = "tricky"
    ,six = "hope"
    ,seven = "you"
    ,eight = "got"
    ,nine = "this"
    ,ten ="one"
    ,eleven = "HELP! MEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";//this is not satire it is to make sure this doesnt have short string optimization
    llist.insertAtTheTail(one);//1
    llist.insertAtTheTail(two);//2
    llist.insertAtTheTail(three);//3
    llist.insertAtTheTail(four);//4
    llist.insertAtTheTail(five);//5
    llist.insertAtTheTail(six);//6
    llist.insertAtTheTail(seven);//7
    printLL(llist);
    printLLRev(llist);
    llist.removeNode(five);//6
    std::cout << "Should Not Have : tricky" <<std::endl;
    printLL(llist);
    llist.removeNode(two);//5
    std::cout << "Should Not Have : string" <<std::endl;
    printLL(llist);
    llist.removeNode(eleven);//4
    printLL(llist);
    llist.removeNode(llist.getFirstNode());//3
    std::cout << "Should Not Have : std" <<std::endl;
    printLL(llist);
    llist.insertAtTheHead(eight);
    llist.insertAtTheHead(nine);
    llist.insertAtTheHead(ten);
    LinkedList<std::string> llist2(llist);
    printLL(llist);
    printLL(llist2);
    return 0;
}
