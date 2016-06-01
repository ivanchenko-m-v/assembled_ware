///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 01-06-2016
///		Date update	: 01-06-2016
///		Comment		:
/// ============================================================================

#include <QList>

#ifndef __DATA_COLLECTION_H__
#define __DATA_COLLECTION_H__
namespace espira
{

namespace data_objects
{
/// ############################################################################
///			list_object
/// ############################################################################
    template<typename DATA_OBJECT>
    using list_object = QList<DATA_OBJECT*>;

/// ############################################################################
///			data_collection
/// ############################################################################

    template<typename DATA_OBJECT>
    class data_collection
    {
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    /// ------------------------------------------------------------------------
        data_collection( const data_collection &rhs );
    public:
    /// ------------------------------------------------------------------------
        data_collection( ) :
            _data( 0 )
        { }
    /// ------------------------------------------------------------------------
        virtual ~data_collection( )
        { this->free( ); }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    public:
    /// ------------------------------------------------------------------------
        int size( ) const
        {
            if( !this->_data )
            {
                return 0;
            }
            return this->_data->size( );
        }

    /// ------------------------------------------------------------------------
        void free_data_pointer( )
        {
            if( !this->_data )
            {
                return;
            }
            //free pointer to list
            //but save pointers on list elements
            delete _data;
            this->_data = 0;
        }

    /// ------------------------------------------------------------------------
        void free( )
        {
            if( !this->_data )
            {
                return;
            }
            while( this->_data->size( ) )
            {
                //get last element
                DATA_OBJECT *r = this->_data->last( );
                //remove last element from list
                this->_data->removeLast( );
                //delete last element
                delete r;
            }
            delete _data;

            this->_data = 0;
        }

    /// ------------------------------------------------------------------------
        void append( DATA_OBJECT *r )
        {
            if( !this->_data )
            {
                this->_data = new list_object;
            }
            this->_data->append( r );
        }

    /// ------------------------------------------------------------------------
        list_object* list( )
        { return this->_data; }

    /// ------------------------------------------------------------------------
        using  iterator = list_object::iterator;
    /// ------------------------------------------------------------------------
        iterator begin( )
        {
            return this->_data->begin( );
        }

    /// ------------------------------------------------------------------------
        iterator end( )
        {
            return this->_data->end( );
        }

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        data_collection& operator=( const data_collection &rhs );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
        list_object	*_data;

    };//class data_collection
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace data_objects

}//namespace espira

#endif // __DATA_COLLECTION_H__

