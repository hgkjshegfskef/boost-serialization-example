#include "util.hh"

// Including archive kinds only because we are using them explicitly.
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <fstream>

void save(const Holder &h) {
  std::ofstream file{"tmp"};
  boost::archive::text_oarchive oa{file};
  oa << h;
}

Holder load() {
  std::ifstream file{"tmp"};
  boost::archive::text_iarchive ia{file};
  Holder h;
  ia >> h;
  return h;
}
