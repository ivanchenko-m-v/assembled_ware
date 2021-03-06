/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 12-12-2016
///		Date update	: 12-12-2016
///		Comment		:
/// ============================================================================
#ifndef __LINE_EDIT_WARE_SEARCH_H__
#define __LINE_EDIT_WARE_SEARCH_H__

#include <QLineEdit>

namespace rele_auto
{

/// ############################################################################
///			class line_edit_ware_search
/// ############################################################################
    class line_edit_ware_search : public QLineEdit
	{
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        line_edit_ware_search( const line_edit_ware_search &rhs );

	public:
        /// --------------------------------------------------------------------
        line_edit_ware_search( );
        /// --------------------------------------------------------------------
        virtual ~line_edit_ware_search( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:

	public:

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    private:

	public:

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        line_edit_ware_search& operator=( const line_edit_ware_search &rhs );

	public:

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:

	};//class line_edit_ware_search
/// ############################################################################
/// ----------------------------------------------------------------------------
///
}//namespace rele_auto

#endif //__LINE_EDIT_WARE_SEARCH_H__
