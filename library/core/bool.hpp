/*
	MIT License

	Copyright (c) 2020 Feral Language repositories

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so.
*/

#ifndef LIBRARY_CORE_BOOL_HPP
#define LIBRARY_CORE_BOOL_HPP

#include "VM/VM.hpp"

// logical functions

var_base_t * bool_lt( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		vm.fail( fd.src_id, fd.idx, "expected boolean argument for logical less than, found: %s",
			 vm.type_name( fd.args[ 1 ] ).c_str() );
		return nullptr;
	}
	return BOOL( fd.args[ 0 ] )->get() < BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_gt( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		vm.fail( fd.src_id, fd.idx, "expected boolean argument for logical greater than, found: %s",
			 vm.type_name( fd.args[ 1 ] ).c_str() );
		return nullptr;
	}
	return BOOL( fd.args[ 0 ] )->get() > BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_le( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		vm.fail( fd.src_id, fd.idx, "expected boolean argument for logical less than or equal, found: %s",
			 vm.type_name( fd.args[ 1 ] ).c_str() );
		return nullptr;
	}
	return BOOL( fd.args[ 0 ] )->get() <= BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_ge( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		vm.fail( fd.src_id, fd.idx, "expected boolean argument for logical greater than or equal, found: %s",
			 vm.type_name( fd.args[ 1 ] ).c_str() );
		return nullptr;
	}
	return BOOL( fd.args[ 0 ] )->get() >= BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_eq( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		return vm.fals;
	}
	return BOOL( fd.args[ 0 ] )->get() == BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_ne( vm_state_t & vm, const fn_data_t & fd )
{
	if( !fd.args[ 1 ]->istype< var_bool_t >() ) {
		return vm.tru;
	}
	return BOOL( fd.args[ 0 ] )->get() != BOOL( fd.args[ 1 ] )->get() ? vm.tru : vm.fals;
}

var_base_t * bool_not( vm_state_t & vm, const fn_data_t & fd )
{
	return BOOL( fd.args[ 0 ] )->get() ? vm.fals : vm.tru;
}

#endif // LIBRARY_CORE_BOOL_HPP