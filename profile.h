#pragma once
#include <iostream>
#include <string>

class Profile{
private:
  std::string username;
  std::string displayname;
public:
  Profile(std::string usrn,std::string dspn);
  Profile();
  std::string getUsername();
  std::string getFullName();
  void setDisplayName(std::string dspn);
};
