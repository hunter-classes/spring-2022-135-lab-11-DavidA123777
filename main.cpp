#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"
#include <sstream>

int main(){
std::cout << "\nTask A illustrates functionality of getusername and get full name \n" << std::endl;
  Profile p1("marco", "Marco");//create an object of type profile
      std::cout << p1.getUsername() << std::endl; // marco
      std::cout << p1.getFullName() << std::endl; // Marco (@marco)
//tests for task A getUsername and getFullName of profile objects
      p1.setDisplayName("Marco Rossi");
      std::cout << p1.getUsername() << std::endl; // marco
      std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)

      Profile p2("tarma1", "Tarma Roving");
      std::cout << p2.getUsername() << std::endl; // tarma1
      std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)
std::cout << "\nTask B illustrates functionality of addUser and outputs true 1 if it can add that user and 0 false if it cannot\n" << std::endl;

      Network nw;//creates an object network
        std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
        std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

//checks if you can add these users to Network nw

        std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
        std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
        std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)
std::cout << std::endl;

//it would look messy if I outputted this for loop
        /*for(int i = 2; i < 20; i++){
            std::cout << nw.addUser("mario" + std::__cxx11::to_string(i),
            "Mario" + std::__cxx11::to_string(i)) << std::endl;  // true (1)

             std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;*/     // false (0)
 std::cout << "Task C illustrates functionality of follow and printDot to output all users created and who follows who \n" << std::endl;

nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
//adds users if they don't already exist and the other criteria are met
    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");
//allows these users to follow each other if both users exist
    // add a user who does not follow others
    nw.addUser("wario", "Wario");
//this user is added yet doesn't follow anyone

    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::__cxx11::to_string(i);
        std::string dspn = "Mario " + std::__cxx11::to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

//prints all users followed by who follows who
    nw.printDot();





std::cout << "\nTask D prints the post history of a user and those that the user follows in reverse chronological order\n" << std::endl;

Network pw;
    pw.addUser("mario", "Mario");
      pw.addUser("luigi", "Luigi");
      pw.addUser("yoshi", "Yoshi");

      pw.follow("mario", "luigi");
      pw.follow("luigi", "mario");
      pw.follow("luigi", "yoshi");
      pw.follow("yoshi", "mario");


      // write some posts
      pw.writePost("mario", "It's a-me, Mario!");
      pw.writePost("luigi", "Hey hey!");
      pw.writePost("mario", "Hi Luigi!");
      pw.writePost("yoshi", "Test 1");
      pw.writePost("yoshi", "Test 2");
      pw.writePost("luigi", "I just hope this crazy plan of yours works!");
      pw.writePost("mario", "My crazy plans always work!");
      pw.writePost("yoshi", "Test 3");
      pw.writePost("yoshi", "Test 4");
      pw.writePost("yoshi", "Test 5");

      std::cout << std::endl;
      std::cout << "======= Mario's timeline =======" << std::endl;
      pw.printTimeline("mario");
      std::cout << std::endl;

      std::cout << "======= Yoshi's timeline =======" << std::endl;
      pw.printTimeline("yoshi");
      std::cout << std::endl;


  return 0;
}
