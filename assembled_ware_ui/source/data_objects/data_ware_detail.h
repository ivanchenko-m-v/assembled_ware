///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 22-06-2016
///		Date update	: 22-06-2016
///		Comment		:
/// ============================================================================
#ifndef __DATA_WARE_DETAIL_H__
#define __DATA_WARE_DETAIL_H__

#include <QDebug>
#include <QString>
#include <QVector>
#include <QVariant>

#include "data_collection.h"

namespace assembled_ware
{

/// ############################################################################
///			class data_ware_detail
/// ############################################################################
    class data_ware_detail
	{
    public:
        enum field_data_ware_detail : int
        {
            num_field_id = 0,			//ID,
            num_field_hash = 1,			//HASH,
            num_field_ware_detail = 2,	//WARE_DETAIL,
            num_field_price = 3,		//PRICE,
            fields_count = 4			//
        };
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
	public:
    /// ------------------------------------------------------------------------
        data_ware_detail( )
        { }

    /// ------------------------------------------------------------------------
		explicit
        data_ware_detail( const data_ware_detail &rhs ) :
            _x_ware_detail_id(rhs._x_ware_detail_id),
            _x_hash(rhs._x_hash),
            _x_ware_detail(rhs._x_ware_detail),
            _x_price(rhs._x_price)
        { }

     /// ------------------------------------------------------------------------
		explicit
        data_ware_detail( const QVector<QVariant> &row )
        {
            if( row.size( ) < fields_count )
            {
                this->clear_data( );
            }
            this->_x_ware_detail_id = row[num_field_id].toString( );
            this->_x_hash = row[num_field_hash].toString( );
            this->_x_ware_detail = row[num_field_ware_detail].toString( );
            this->_x_price = row[num_field_price].toString( );
        }

    /// ------------------------------------------------------------------------
        ~data_ware_detail( )
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
            this->_x_ware_detail_id.clear( );
            this->_x_hash.clear( );
            this->_x_ware_detail.clear( );
            this->_x_price.clear( );
         }

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
	public:
    /// ------------------------------------------------------------------------
    ///	ware_detail_id
        const QString& ware_detail_id( ) const
        { return this->_x_ware_detail_id; }

        void ware_detail_id( const QString &x_ware_id )
        { this->_x_ware_detail_id = x_ware_id; }

    /// ------------------------------------------------------------------------
    ///	hash
        const QString& hash( ) const
        { return this->_x_hash; }

        void hash( const QString &x_hash )
        { this->_x_hash = x_hash; }

    /// ------------------------------------------------------------------------
    ///	ware_detail
        const QString& ware_detail( ) const
        { return this->_x_ware_detail; }

        void ware_detail( const QString &x_ware_detail )
        { this->_x_ware_detail = x_ware_detail; }

    /// ------------------------------------------------------------------------
    ///	price
        const QString& price( ) const
        { return this->_x_price; }

        void price( const QString &x_price )
        { this->_x_price = x_price; }

    /// ------------------------------------------------------------------------
    ///	to_string
        QString to_string( ) const
        {
            return this->_x_hash + " | " + this->_x_ware_detail;
        }
    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
	public:
        data_ware_detail& operator=( const data_ware_detail &rhs )
		{
			if( this == &rhs )
			{
				return *this;
			}
            this->_x_ware_detail_id = rhs._x_ware_detail_id;
            this->_x_hash = rhs._x_hash;
            this->_x_ware_detail = rhs._x_ware_detail;
            this->_x_price = rhs._x_price;

			return *this;
		}

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
	private:
        QString _x_ware_detail_id{""};	//ID,
        QString _x_hash{""};			//HASH,
        QString _x_ware_detail{""};		//WARE_DETAIL
        QString _x_price{""};			//PRICE

    };//class data_ware_detail
/// ############################################################################
/// ----------------------------------------------------------------------------

/// ############################################################################
///			data_ware_detail_collection
/// ############################################################################
///
    using data_ware_detail_collection = espira::data_objects::data_collection<data_ware_detail>;
    using list_ware = espira::data_objects::list_object<data_ware_detail>;

/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __DATA_WARE_DETAIL_H__
