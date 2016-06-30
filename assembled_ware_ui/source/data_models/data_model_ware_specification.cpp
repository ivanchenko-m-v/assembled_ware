/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 28-06-2016
///		Date update	: 28-06-2016
///		Comment		:
/// ============================================================================
#include <QDebug>

#include "data_model_ware_specification.h"

namespace assembled_ware
{

/// ############################################################################
///			class data_model_ware_specification
/// ############################################################################

	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================
	/// ------------------------------------------------------------------------
    ///	data_model_ware_specification( )
	/// ------------------------------------------------------------------------
    data_model_ware_specification::data_model_ware_specification( QObject *pobj/* = 0*/ ) :
		QAbstractTableModel( pobj )
	{
		this->initialize( );
	}

	/// ------------------------------------------------------------------------
    ///	~data_model_ware_specification( )
	/// ------------------------------------------------------------------------
    data_model_ware_specification::~data_model_ware_specification( )
	{
		this->clear( );

        qDebug( ) << "data_model_ware_specification cleared correctly";
	}

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================
	/// ------------------------------------------------------------------------
	///	ware( int i_row )
	/// ------------------------------------------------------------------------
    const data_specification_item* data_model_ware_specification::ware( int i_row ) const
	{
		if( i_row < 0 || i_row >= this->_list.size( ) )
		{
			return 0;
		}
		return this->_list.at( i_row );
	}

	/// ========================================================================
	///		FUNCTIONS
	/// ========================================================================
	/// ------------------------------------------------------------------------
	///	clear( )
	/// ------------------------------------------------------------------------
    void data_model_ware_specification::clear( )
	{
        if( !this->_list.size( ) )
        {
            return;
        }
		this->removeRows( 0, this->_list.size( ) );
		while( this->_list.count( ) )
		{
			data_specification_item *item = this->_list.back();
			this->_list.pop_back( );

			delete item;
		}
		this->_list.clear( );
	}

	/// ------------------------------------------------------------------------
	///	initialize( )
	/// ------------------------------------------------------------------------
    void data_model_ware_specification::initialize( )
	{
		this->init_columns_header( );
	}

	/// ------------------------------------------------------------------------
	///	refresh( const QVector<QVector<QVariant> > &data )
	/// ------------------------------------------------------------------------
    void data_model_ware_specification::refresh(const QVector<QVector<QVariant> > &data)
	{
		this->clear( );

		if( !data.count( ) )
		{
			//if no data
			return;
		}
/*
		this->beginInsertRows( QModelIndex( ), 0, data.count( ) - 1 );

		QVector<QVector<QVariant> >::const_iterator iter;
		for( iter = data.constBegin( ); iter != data.end( ); ++iter )
		{
			data_ware *request = new data_ware( *iter );
			this->_list.append( request );
		}
		this->endInsertRows( );
        */
	}

	/// ------------------------------------------------------------------------
	///	refresh( data_ware_collection *data )
	/// ------------------------------------------------------------------------
    void data_model_ware_specification::refresh(data_specification_collection *data )
	{
		this->clear( );

		if( !data || !data->size( ) )
		{
			//if no data
			return;
		}
		this->beginInsertRows( QModelIndex( ), 0, data->size( ) - 1 );

		this->_list.append( *( data->list( ) ) );
		data->free_data_pointer( );

        this->endInsertRows( );
    }

	/// ------------------------------------------------------------------------
	///	insert(const data_ware &request)
	/// ------------------------------------------------------------------------
/*
    void data_model_ware_specification::insert( const data_ware &request )
    {
		this->beginInsertRows( QModelIndex( ), this->_list.size( ), this->_list.size( ) );

        data_ware *pr = new data_ware( request );
		this->_list.append( pr );

        this->endInsertRows( );
    }
    */

	/// ------------------------------------------------------------------------
	/// virtual
	///	data( )
	/// ------------------------------------------------------------------------
    QVariant data_model_ware_specification::data(
										const QModelIndex &index,
										int /*role //= Qt::DisplayRole*/
									   ) const
	{
		if( !index.isValid( ) )
		{
			return QVariant( );
		}

        data_specification_item* item = this->_list.at( index.row( ) );

		switch( index.column( ) )
		{
            case field_ware:
                return item->_ware.ware( );
			case field_price:
                return item->_ware.sum_total( );
			case field_qty:
				return item->_qty;
			case field_sum:
				return item->_sum;
			default:
				return QVariant( );
		}
		return QVariant( );
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	setData( )
	/// ------------------------------------------------------------------------
    bool data_model_ware_specification::setData(
										const QModelIndex &/*index*/,
										const QVariant &/*value*/,
										int /*role //= Qt::EditRole*/
									  )
	{
		return false;
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	flags( )
	/// ------------------------------------------------------------------------
    Qt::ItemFlags data_model_ware_specification::flags(const QModelIndex &/*index*/) const
	{
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	insertRows( )
	/// ------------------------------------------------------------------------
    bool data_model_ware_specification::insertRows(
								int row, int count,
								const QModelIndex &parent //= QModelIndex( )
										 )
	{
        /*
		if( ( row < 0 ) || ( row > this->_list.size( ) ) )
		{
			return false;
		}
		this->beginInsertRows( parent, row, row + count - 1 );

		for( int i = 0; i < count; i++ )
		{
			data_ware* request = new data_ware;
			this->_list.insert( row + i, request );
		}

		this->endInsertRows( );
        */

		return true;
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	insertRows( )
	/// ------------------------------------------------------------------------
    bool data_model_ware_specification::removeRows(
								int row, int count,
								const QModelIndex &parent //= QModelIndex( )
										 )
	{
        /*
		this->beginRemoveRows( parent, row, row + count - 1 );

		for( int i = 0; i < count; ++i )
		{
			data_ware *item = this->_list.takeAt( row );
			delete item;
		}

		this->endRemoveRows( );
        */

		return true;
	}

}//namespace assembled_ware
