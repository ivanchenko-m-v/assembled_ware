///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 24-06-2016
///		Comment		:
/// ============================================================================
#ifndef __DATA_WARE_H__
#define __DATA_WARE_H__

#include <QDebug>
#include <QString>
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
            num_field_article = 3,	//ARTICLE,
            num_field_barcode = 4,	//BARCODE,
            num_field_percent = 5,	//PERCENT,
            num_field_sum = 6,		//SUM,
            fields_count = 7		//
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
			_x_ware(rhs._x_ware),
			_x_article(rhs._x_article),
			_x_barcode(rhs._x_barcode),
			_x_percent(rhs._x_percent),
			_x_sum_total(rhs._x_sum_total)
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
			this->_x_article = row[num_field_article].toString( );
			this->_x_barcode = row[num_field_barcode].toString( );
			this->_x_percent = row[num_field_percent].toString( );
			this->_x_sum_total = row[num_field_sum].toString( );
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
			this->_x_article.clear( );
			this->_x_barcode.clear( );
			this->_x_percent.clear( );
			this->_x_sum_total.clear( );
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
    ///	article
        const QString& article( ) const
        { return this->_x_article; }

        void article( const QString &x_article )
        { this->_x_article = x_article; }

    /// ------------------------------------------------------------------------
    ///	barcode
        const QString& barcode( ) const
        { return this->_x_barcode; }

        void barcode( const QString &x_barcode )
        { this->_x_barcode = x_barcode; }

    /// ------------------------------------------------------------------------
    ///	percent
        const QString& percent( ) const
        { return this->_x_percent; }

        void percent( const QString &x_percent )
        { this->_x_percent = x_percent; }

    /// ------------------------------------------------------------------------
    ///	sum_total
        const QString& sum_total( ) const
        { return this->_x_sum_total; }

        void sum_total( const QString &x_sum_total )
        { this->_x_sum_total = x_sum_total; }

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
			this->_x_article = rhs._x_article;
			this->_x_barcode = rhs._x_barcode;
			this->_x_percent = rhs._x_percent;
			this->_x_sum_total = rhs._x_sum_total;

			return *this;
		}

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
	private:
		QString _x_ware_id{""};		//ID,
		QString _x_hash{""};		//HASH,
        QString _x_ware{""};		//WARE
        QString _x_article{""};		//ARTICLE,
        QString _x_barcode{""};		//BARCODE,
        QString _x_percent{""};		//PERCENT,
        QString _x_sum_total{""};	//SUM,

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
