/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 30-12-2016
///		Comment		:
/// ============================================================================
#ifndef __BUSINESS_LOGIC_H__
#define __BUSINESS_LOGIC_H__

#include "application.h"
#include <QDate>

namespace assembled_ware
{

	class data_model_ware;
	class data_model_ware_specification;
/// ############################################################################
///			class business_logic
/// ############################################################################
	class business_logic
	{
	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================
	private:
	/// ------------------------------------------------------------------------
		business_logic( const business_logic &rhs );

	public:
	/// ------------------------------------------------------------------------
		business_logic( )
		{ }

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================
	public:
    /// ------------------------------------------------------------------------
    /// model_ware
        data_model_ware* model_ware( ) const
        { return this->_model_ware; }
    /// model_ware_search
        data_model_ware* model_ware_search( ) const
        { return this->_model_ware_search; }
    /// ------------------------------------------------------------------------
    /// model_ware_specification
        data_model_ware_specification* model_ware_specification( ) const
        { return this->_model_specification; }

    /// ========================================================================
	///		FUNCTIONS
	/// ========================================================================
	private:
	/// ------------------------------------------------------------------------
        void init_data_models( );
    /// ------------------------------------------------------------------------
        void free_memory( );
    /// ------------------------------------------------------------------------
		void init_model_ware( );
		void init_model_ware_search( );
		void init_model_ware_specification( );

	public:
	/// ------------------------------------------------------------------------
		void init( );
	/// ------------------------------------------------------------------------
		void exit( );
	/// ------------------------------------------------------------------------
		void ware_select( );
		void ware_detail_select( const QString &text );


	/// ========================================================================
	///		OPERATORS
	/// ========================================================================
	private:
		business_logic& operator=( const business_logic &rhs );

	/// ========================================================================
	///		FIELDS
	/// ========================================================================
	private:
		data_model_ware *_model_ware = nullptr;
		data_model_ware *_model_ware_search = nullptr;
		data_model_ware_specification *_model_specification = nullptr;

	};//class business_logic

/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __BUSINESS_LOGIC_H__
