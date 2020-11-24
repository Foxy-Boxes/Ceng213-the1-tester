#include <iostream>

#include "SocialNetworkWrapper.h"
#include <cassert>


int main() {
    SocialNetworkW snetwork;
    //test6

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
    snetwork.print();
    
    snetwork.makeFriends(NOAH,LIAM);
    snetwork.makeFriends(NOAH, EMMA);
    snetwork.makeFriends(IVER,EMMA);
    snetwork.makeFriends(IVIA,LIAM);
    snetwork.print();
    snetwork.likePost(2,NOAH);
    snetwork.likePost(2,LIAM);
    snetwork.likePost(3,LIAM);
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
    snetwork.deleteProfile(EMMA);
    snetwork.print();
    snetwork.deleteProfile(IVER);
    snetwork.print();

    return 0;
}
