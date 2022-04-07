#pragma once

#include "base.hh"

#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>

#include <memory>

class Holder {
 public:
  explicit Holder(std::shared_ptr<Base> base = {});

  std::shared_ptr<Base> base_ptr;

 private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &ar, unsigned /*version*/);
};

// Must occur outside of a namespace, inside class header.
BOOST_CLASS_EXPORT_KEY(Holder)
