#include <iostream>

#include "SocialNetworkWrapper.h"
template<typename T>
void printPtr(LinkedList<T*>&& ll){
    std::cout << "Printing in Order" << std::endl;

    if (ll.isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T*>* node = ll.getFirstNode();

    while (node) {
        std::cout << *node->data << "  ";
        node = node->next;
    }
    std::cout<<std::endl;
}

int main() {
    SocialNetworkW snetwork;
    //custom test amalgamation of 6 and 9

    snetwork.print();

    std::string NOAH = "noah@brown.com";
    std::string EMMA = "emma@johnson.com";
    std::string IVER = "oliver@martinez.com";
    std::string LIAM = "liam@smith.com";
    std::string IVIA = "olivia@williams.com";
    

    snetwork.addProfile("noah", "brown", NOAH);
    snetwork.addProfile("emma", "johnson", EMMA);
    snetwork.addProfile("oliver", "martinez", IVER);
    snetwork.addProfile("liam", "smith", LIAM);
    snetwork.addProfile("olivia", "williams", IVIA);
    snetwork.print();

    snetwork.addPost("Hello! My name is liam smith.", LIAM);
    snetwork.addPost("Hello! My name is olivia williams.", IVIA);
    snetwork.addPost("Hello! My name is noah brown.", NOAH);
    snetwork.addPost("Hello! My name is emma johnson.", EMMA);
    snetwork.addPost("Hello! My name is oliver martinez.", IVER);
    snetwork.addPost("Hello again! My name is still liam smith.", LIAM);
    snetwork.print();
    printPtr(snetwork.getListOfMostRecentPosts(LIAM,2));
    
    snetwork.makeFriends(NOAH,LIAM);
    snetwork.makeFriends(NOAH, EMMA);
    snetwork.makeFriends(IVIA,EMMA);
    snetwork.makeFriends(IVER,EMMA);
    snetwork.makeFriends(IVIA,LIAM);
    snetwork.print();
    printPtr(snetwork.getMutualFriends("liam@smith.com", "emma@johnson.com"));

    snetwork.likePost(5,EMMA);
    snetwork.likePost(5,IVER);
    snetwork.likePost(2,IVIA);
    snetwork.print();
    snetwork.unlikePost(5,IVER);
    snetwork.unlikePost(2,IVIA);
    snetwork.print();
    snetwork.deleteProfile(LIAM);
    snetwork.print();
    snetwork.deleteProfile(IVIA);
    snetwork.print();
    snetwork.deleteProfile(NOAH);
    snetwork.print();

    return 0;
}

