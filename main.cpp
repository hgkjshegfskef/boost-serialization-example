#include "derived_one.hh"
#include "holder.hh"
#include "util.hh"

#include <cassert>
#include <filesystem>
#include <iostream>
#include <memory>

int main() {
  try {
	std::filesystem::path p{"foobar"};
	std::cout << "Saving filesystem::path: " << p << '\n';
	Holder h{std::make_shared<DerivedOne>(p)};
	save(h);
	auto result = load();
	assert(result.base_ptr);
	assert(dynamic_cast<DerivedOne *>(result.base_ptr.get()));
	auto pp = dynamic_cast<DerivedOne *>(result.base_ptr.get())->path;
	std::cout << "Loading filesystem::path: " << pp;
	assert(!pp.compare("foobar"));
  } catch (std::exception const &ex) {
	std::cerr << "exception: " << ex.what() << '\n';
  }
}
