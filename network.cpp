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

  Network::Network() {
numUsers = 0;//initialize num users to 0
for (int i = 0; i < MAX_USERS; i++){
  for (int j = 0; j < MAX_USERS; j++){
    following[i][j] = false;
  }//initialize all arrays in multidimensional array to false
}
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
