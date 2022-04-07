# Boost Serialization minimal example with polymorphism, abstract base class, container, smart pointer, separate header and source files, custom save and load functions

Layout:

* `main.cc` -- main()
* `util.cc` -- saving to and loading from `tmp` file
* `base.cc` -- abstract base class, split into header and source
* `derived_one.cc` -- derived from `Base`
* `holder.cc` -- holds a smart pointer, `shared_ptr`, to `Base`
* `filesystem_path_archive.hh` -- custom serialization for `std::filesystem::path`

The sample is documented, see the files directly. It:
* shows how to explicitly instantiate `serialize()` functions in an abstract base class implementation
* shows that to serialize a container, e.g. `std::shared_ptr` or `std::string`, you need to include that container from boost serialization headers
* shows how to serialize a normal class, e.g. `Holder`, including a derived class, e.g. `DerivedOne`, that is split into header and source
* shows how to write custom serialize and deserialize functions for classes that cannot be edited, e.g. `std::filesystem::path`
* shows that archivers, e.g. `text_iarchive`, `text_oarchive`, must be included with normal classes' source files, besides places where they are explicitly required by the user
