#include "SocialNetworkWrapper.h"



void SocialNetworkW::addProfile(const std::string &firstname, const std::string &lastname, const std::string &email) {
    s.addProfile(firstname,lastname,email);
    isThereABrokenLink(s.profiles);
}

void SocialNetworkW::addPost(const std::string &message, const std::string &email) {
    s.addPost(message,email);
    isThereABrokenLink(s.posts);
}

void SocialNetworkW::deleteProfile(const std::string &email) {
    s.deleteProfile(email);
    //unfortunately i cant test the links inside the function
    isThereABrokenLink(s.posts);
    isThereABrokenLink(s.profiles);
}

void SocialNetworkW::makeFriends(const std::string &email1, const std::string &email2) {
    s.makeFriends(email1,email2);
    isThereABrokenLink(s.profiles);
}

void SocialNetworkW::likePost(int postId, const std::string &email) {
    s.likePost(postId,email);
    isThereABrokenLink(s.posts);
}

void SocialNetworkW::unlikePost(int postId, const std::string &email) {
    s.unlikePost(postId,email);
    isThereABrokenLink(s.posts);
}

LinkedList<Profile *> SocialNetworkW::getMutualFriends(const std::string &email1, const std::string &email2) {
    LinkedList<Profile *> mutuals = s.getMutualFriends(email1,email2);
    isThereABrokenLink(s.profiles);
    isThereABrokenLink(mutuals);
    return mutuals;
}

LinkedList<Post *> SocialNetworkW::getListOfMostRecentPosts(const std::string &email, int k) {
    LinkedList<Post *> recentPosts = s.getListOfMostRecentPosts(email,k);
    isThereABrokenLink(s.posts);
    isThereABrokenLink(recentPosts);
    return recentPosts;
}

void SocialNetworkW::print() const {
    std::cout << "# Printing the social network ..." << std::endl;

    std::cout << "# Number of profiles is " << s.profiles.getNumberOfNodes() << ":" << std::endl;
    s.profiles.print();

    std::cout << "# Number of posts is " << s.posts.getNumberOfNodes() << ":" << std::endl;
    s.posts.print();

    std::cout << "# Printing is done." << std::endl;
}
