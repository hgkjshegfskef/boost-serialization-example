#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/export.hpp>

class Base {
 public:
  virtual ~Base() = 0;

  virtual void foo() = 0;

 protected:
  // OR: use the rule of zero (remove the next 5 lines)
  Base() = default;
  Base(Base const &) = default;
  Base(Base &&) = default;
  Base &operator=(Base &&) = default;
  Base &operator=(Base const &) = default;

 private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &ar, unsigned /*version*/);
};

// Do NOT use BOOST_SERIALIZATION_ASSUME_ABSTRACT if your
// abstract base class is split across header and source file!

// If the abstract base class is header-only, you can use it.
// However, in that case do not explicitly instantiate serialize()
// (see source file).
