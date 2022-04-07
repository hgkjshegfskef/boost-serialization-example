#include "holder.hh"

// Must include the archive kinds with BOOST_CLASS_EXPORT_IMPLEMENT!
// Other choice can be: binary_iarchive, binary_oarchive
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

// To serialize shared_ptr, we include a shared_ptr.hpp.
// This is also the case for other containers: string, vector, map.
// You MUST include them when you want to serialize a container.
// However, note that not all containers have an include, and not
// all standard types are supported by boost serializer.
#include <boost/serialization/shared_ptr.hpp>

Holder::Holder(std::shared_ptr<Base> base) : base_ptr{std::move(base)} {}

template<class Archive>
void Holder::serialize(Archive &ar, unsigned int) {
  ar &base_ptr;
}

// Must occur outside of a namespace, inside class source file.
BOOST_CLASS_EXPORT_IMPLEMENT(Holder)
