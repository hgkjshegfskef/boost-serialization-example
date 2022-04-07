#include "base.hh"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

Base::~Base() = default;

template<class Archive>
void Base::serialize(Archive &ar, unsigned /*version*/) {}

// If your abstract base class is split across header and source file,
// you MUST explicitly instantiate serialize()!
// You CANNOT use macros like in Holder or DerivedOne.

template void Base::serialize<boost::archive::text_iarchive>(
	boost::archive::text_iarchive &ar,
	const unsigned int file_version);
template void Base::serialize<boost::archive::text_oarchive>(
	boost::archive::text_oarchive &ar,
	const unsigned int file_version);
