#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"



TEST_CASE("Checks the getUsername function"){
  Profile prof1("Jackson", "Jack");
  CHECK((prof1.getUsername()) == "Jackson");
}

TEST_CASE("Checks the getFullName function"){
  Profile prof2("Jackson", "Jack");
  CHECK((prof2.getFullName()) == "Jack (@Jackson) " );
}

TEST_CASE("Tests changing the displayname from Jack to John"){
Profile prof3("Jackson", "Jack");
  prof3.setDisplayName("John");
  CHECK((prof3.getFullName()) == "John (@Jackson) ");
}

TEST_CASE("Tests the add user function when a user already exists"){
  Network nw;
  CHECK(nw.addUser("mario", "MARIO") == 1);
  CHECK(nw.addUser("mario", "MArio") == 0);
}

TEST_CASE("Tests the follow function"){
  Network nw;
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  CHECK(nw.follow("mario", "luigi") == 1);
}
TEST_CASE("Tests the follow function when the username doesn't exist"){
Network nw;
CHECK(nw.follow("mario", "wario") == 0);

}

TEST_CASE("Tests the write post function"){
  Network nw;
  nw.addUser("mario", "M");
  CHECK(nw.writePost("mario", "Mario") == 1);
  CHECK(nw.writePost("Wario", "wario") == 0);

}
TEST_CASE("Tests the write post function if numPosts is maxed out"){
  Network nw;
  nw.addUser("mario", "M");
  for (int i = 0; i < 99; i++){
    nw.writePost("mario", "Mario");}
  CHECK(nw.writePost("mario", "M") == 1);
  CHECK(nw.writePost("mario", "MA") == 0);
}

TEST_CASE("tests printTimeline functionality"){
  Network pw;
  pw.addUser("mario", "Mario");
  pw.addUser("luigi", "Luigi");
  pw.addUser("yoshi", "Yoshi");

  pw.follow("mario", "luigi");


  pw.writePost("mario", "It's a-me, Mario!");
  CHECK(pw.printTimeline("mario") == 1);
  CHECK(pw.printTimeline("John Cena") == 0);
}
