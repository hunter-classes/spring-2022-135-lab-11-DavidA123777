#include <iostream>
#include <string>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn) {
  username = usrn;
  displayname = dspn;//constructor
}
Profile::Profile() {
  username = "";
  displayname = "";//empty default constructor if no paramters are passed
}
std::string Profile::getUsername() {
  return username;//returns private variable username
}

 std::string Profile::getFullName() {
   std::string name = displayname + " (@" + username + ") ";
   return name;// returns full name
 }
 void Profile::setDisplayName(std::string dspn) {
   displayname = dspn;//change display name
 }
