#pragma once

#include "base.hh"

#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>

#include <filesystem>
#include <string>

class DerivedOne final : public Base {
 public:
  explicit DerivedOne(std::filesystem::path p = {});

  void foo() override;

  // Boost doesn't know how to serialize this, see filesystem_path_archive.hh
  std::filesystem::path path;

 private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &ar, unsigned /*version*/);
};

// Must occur outside of a namespace, inside class header.
BOOST_CLASS_EXPORT_KEY(DerivedOne)
