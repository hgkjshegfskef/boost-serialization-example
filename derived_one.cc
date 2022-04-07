#include "derived_one.hh"
#include "filesystem_path_archive.hh"

// Must include the archive kinds with BOOST_CLASS_EXPORT_IMPLEMENT!
// Other choice can be: binary_iarchive, binary_oarchive
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>

DerivedOne::DerivedOne(std::filesystem::path p) : path{std::move(p)} {}

void DerivedOne::foo() {}

template<class Archive>
void DerivedOne::serialize(Archive &ar, unsigned int) {
  // You must start with base object in derived classes.
  ar &boost::serialization::base_object<Base>(*this);
  // Boost knows how to serialize this due to filesystem_path_archive.hh
  ar &path;
}

// Must occur outside of a namespace, inside class source file.
BOOST_CLASS_EXPORT_IMPLEMENT(DerivedOne)
