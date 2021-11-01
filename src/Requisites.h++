#pragma once

class Course; // fixes Course including this file.
class Registry; // fixes Registry including this file
#include "Referred.h++"
#include "Requisite.h++"
#include "Plan.h++"

#include <istream>
#include <vector>

class Requisites : public Referred {
    std::vector < Requisite > requisites;
protected:
    virtual std::istream &extract ( std::istream &istream ) override;
public:
    Requisites ( ) noexcept = default;
    Requisites ( Requisites const & ) noexcept = default;
    Requisites ( Requisites && ) noexcept = default;
    Requisites ( std::vector < Requisite > const &requisites ) noexcept : requisites ( requisites ) { }
    virtual ~Requisites ( ) = default;

    bool const meetsRequisite ( Course const & ) const noexcept;

    Requisites &operator = ( Requisites const & ) noexcept = default;
    Requisites &operator = ( Requisites && ) noexcept = default;

};
