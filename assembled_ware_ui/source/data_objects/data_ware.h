///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 02-06-2016
///		Comment		:
/// ============================================================================
#ifndef __DATA_WARE_H__
#define __DATA_WARE_H__

#include <QDebug>
#include <QString>
#include <QDate>
#include <QTime>
#include <QVector>
#include <QVariant>

#include "data_collection.h"

namespace assembled_ware
{

/// ############################################################################
///			class data_ware
/// ############################################################################
    class data_ware
	{
    public:
        enum field_data_ware : int
        {
            num_field_ware_id = 0,	//ID,
            num_field_hash = 1,		//HASH,
            num_field_ware = 2,		//WARE,
            fields_count = 3		//
        };
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
	public:
    /// ------------------------------------------------------------------------
        data_ware( )
        { }

    /// ------------------------------------------------------------------------
		explicit
        data_ware( const data_ware &rhs ) :
            _x_ware_id(rhs._x_ware_id),
            _x_hash(rhs._x_hash),
            _x_ware(rhs._x_ware)
        { }

     /// ------------------------------------------------------------------------
		explicit
        data_ware( const QVector<QVariant> &row )
        {
            if( row.size( ) < fields_count )
            {
                this->clear_data( );
            }
            this->_x_ware_id = row[num_field_ware_id].toString( );
            this->_x_hash = row[num_field_hash].toString( );
            this->_x_ware = row[num_field_ware].toString( );
        }

    /// ------------------------------------------------------------------------
        ~data_ware( )
		{
            qDebug( ) << "deleted : " << this->to_string( );
		}

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
	public:
    /// ------------------------------------------------------------------------
		void clear_data( )
		{
            this->_x_ware_id.clear( );
            this->_x_hash.clear( );
            this->_x_ware.clear( );
         }

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
	public:
    /// ------------------------------------------------------------------------
    ///	ware_id
        const QString& ware_id( ) const
        { return this->_x_ware_id; }

        void ware_id( const QString &x_ware_id )
        { this->_x_ware_id = x_ware_id; }

    /// ------------------------------------------------------------------------
    ///	hash
        const QString& hash( ) const
        { return this->_x_hash; }

        void hash( const QString &x_hash )
        { this->_x_hash = x_hash; }

    /// ------------------------------------------------------------------------
    ///	ware
        const QString& ware( ) const
        { return this->_x_ware; }

        void ware( const QString &x_ware )
        { this->_x_ware = x_ware; }

    /// ------------------------------------------------------------------------
    ///	to_string
        QString to_string( ) const
        {
            return this->_x_hash + " | " + this->_x_ware;
        }
    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
	public:
        data_ware& operator=( const data_ware &rhs )
		{
			if( this == &rhs )
			{
				return *this;
			}
            this->_x_ware_id = rhs._x_ware_id;
            this->_x_hash = rhs._x_hash;
            this->_x_ware = rhs._x_ware;

			return *this;
		}

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
	private:
        QString _x_ware_id{""};	//ID,
        QString _x_hash{""};	//HASH,
        QString _x_ware{""};	//WARE

    };//class data_ware
/// ############################################################################
/// ----------------------------------------------------------------------------

/// ############################################################################
///			data_ware_collection
/// ############################################################################
///
    using data_ware_collection = espira::data_objects::data_collection<data_ware>;
    using list_ware = espira::data_objects::list_object<data_ware>;

/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __DATA_WARE_H__
