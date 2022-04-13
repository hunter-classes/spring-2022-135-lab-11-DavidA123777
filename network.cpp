#include <iostream>
#include <string>
#include "network.h"

int Network::findID(std::string usrn) {
  int id = -1;
  for (int i = 0; i < MAX_USERS; i++){
    if (usrn == profiles[i].getUsername()){
      id = i;
      return id;
    }//if the user exists their id is returned as index value of the array
  }
  return id;
}//else -1 is returned


std::string Network::finduser(int id) {
    std::string usrn = profiles[id].getUsername();
    return usrn;//finds the users username given their id
}








  Network::Network() {
numUsers = 0;//initialize num users to 0
for (int i = 0; i < MAX_USERS; i++){
  for (int j = 0; j < MAX_USERS; j++){
    following[i][j] = false;
  }//initialize all arrays in multidimensional array to false
}
numPosts = 0;//start the number of posts variable at 0
  }

  bool Network::addUser(std::string usrn, std::string dspn){
int x = findID(usrn);//if the user does not exists and it is not an empty string and the number of users are less than 20 then add a new user
if ((usrn != "") && (x == -1)  && (numUsers < 20)){
  Profile new_user(usrn, dspn);
  profiles[numUsers] = new_user;
  numUsers += 1;
  return true;

}
else{
  return false;
}
return false;
  }

void Network::print(){
  for (int i = 0; i < numUsers; i++){
    std::cout << profiles[i].getFullName() << std::endl;
}}//prints full name of all users


bool Network::follow(std::string usrn1, std::string usrn2){
  if ((findID(usrn1) != -1) && (findID(usrn2) != -1)){
    int x = findID(usrn1);
    int y = findID(usrn2);
    following[x][y] = true;
    return true;
  }//if the two users exist and are passed into this function true is returned and those two characters now follow each other
  return false;
}//else return false


void Network::printDot(){//prints out all user's first names
  for (int i = 0; i < numUsers; i++){
    std::cout << "\"@" << profiles[i].getUsername() <<  '"' << std::endl;
  }

  //prints out who is following who

  for(int r = 0; r < numUsers; r++){
    for (int c = 0; c < numUsers; c++){
      if (following[r][c] == true){
        std::cout << "\"@" << profiles[r].getUsername() <<  '"' <<  " -> \"@" << profiles[c].getUsername() <<  '"' << std::endl;
      }
    }
  }
}







bool Network::writePost(std::string usrn, std::string msg){
//finds the users id placement
int x = findID(usrn);
if ((x!= -1) && (numPosts < MAX_POSTS)){
//if the id is part of the array and the number of posts is less than the max number of posts
  posts[numPosts] = {usrn, msg};
//add a post by that user into the posts array
  numPosts++;
  //increment number of posts
  return true;
}//return true if you can add a post and false otherwise
return false;





}

bool Network::printTimeline(std::string usrn){
std::string arr[20] = {usrn};
//create a string array to store all users a specific user follows
int x = findID(usrn);
//have x represent the id of the user we put as a parameter
std::string y;
//initialize string variable y
int count = 1;
//start count at 1 since the first element of the array is the user paramter

  for (int j = 0; j < MAX_USERS; j++){
    if (following[x][j] == true){
      y = finduser(j);
      arr[count] = y;
//loop through multidimensional array to find out who the user follows
//then append that user onto the array and increment count to change index position of array
      count++;
    }
  }

int z = 0;//initialize z
int value = 0;//this determines if function outputs post history or not

for (int i = numPosts-1; i >= 0; i--){
//decrement through the posts array
  for (int p = 0; p < numUsers; p++){// loop through all the elements of the array of users that the user follows including the user
  if (posts[i].username == arr[p]){// if the posts username is the same as one of the users in the array
    z = findID(arr[p]);
//find the id of the person in the string array
    std::cout << profiles[z].getFullName() << ": " << posts[i].message << std::endl;
//print out the users full name and their post message
//increment value to show that post history can indeed be made
   value++;
  }
}

}//determines if function can create post history or not
if (value > 0){
  return true;
}
return false;
}
