#pragma once

#include <boost/serialization/split_free.hpp>
#include <boost/serialization/string.hpp>

#include <filesystem>

namespace boost::serialization {

// Tell boost how to store the type by relying on a known type.
template<class Archive>
void save(Archive &ar, std::filesystem::path const &p, unsigned int) {
  auto str = p.string();
  ar << str;
}

// Tell boost how to reconstruct the type.
template<class Archive>
void load(Archive &ar, std::filesystem::path &p, unsigned int) {
  std::string str;
  ar >> str;
  p = std::filesystem::path{str};
}

}// namespace boost::serialization

// Must occur outside of a namespace.
BOOST_SERIALIZATION_SPLIT_FREE(std::filesystem::path)

// The file cannot be split into definition and declaration.
// Or if you do so, both files must be included upon usage.
