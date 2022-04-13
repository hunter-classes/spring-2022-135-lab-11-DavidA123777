#pragma once
#include <iostream>
#include "profile.h"


struct Post {
  std::string username;
  std::string message;
};




class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
  bool following[MAX_USERS][MAX_USERS];   // mapping integer ID -> Profile
  static const int MAX_POSTS = 100;
  int numPosts;
  Post posts[MAX_POSTS];

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (std::string usrn);
  std::string finduser(int id);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(std::string usrn, std::string dspn);
  void print();
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  bool writePost(std::string usrn, std::string msg);
  bool printTimeline(std::string usrn);
};
