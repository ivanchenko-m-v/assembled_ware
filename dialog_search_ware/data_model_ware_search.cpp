/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 12-12-2016
///		Date update	: 12-12-2016
///		Comment		:
/// ============================================================================
#include <QDebug>

#include "data_model_ware_search.h"

namespace assembled_ware
{

/// ############################################################################
///			class data_model_ware_search
/// ############################################################################

	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================
	/// ------------------------------------------------------------------------
    ///	data_model_ware_search( )
	/// ------------------------------------------------------------------------
    data_model_ware_search::data_model_ware_search( QObject *pobj/* = 0*/ ) :
		QAbstractTableModel( pobj )
	{
		this->initialize( );
	}

	/// ------------------------------------------------------------------------
    ///	~data_model_ware_search( )
	/// ------------------------------------------------------------------------
    data_model_ware_search::~data_model_ware_search( )
	{
		this->clear( );

        qDebug( ) << "data_model_ware_search cleared correctly";
	}

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================
	/// ------------------------------------------------------------------------
	///	ware( int i_row )
	/// ------------------------------------------------------------------------
    const data_ware* data_model_ware_search::ware( int i_row ) const
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
    void data_model_ware_search::clear( )
	{
        if( !this->_list.size( ) )
        {
            return;
        }
		this->removeRows( 0, this->_list.size( ) );
		while( this->_list.count( ) )
		{
			data_ware *w = this->_list.back();
			this->_list.pop_back( );
			delete w;
		}
		this->_list.clear( );
	}

	/// ------------------------------------------------------------------------
	///	initialize( )
	/// ------------------------------------------------------------------------
    void data_model_ware_search::initialize( )
	{
		this->init_columns_header( );
	}

	/// ------------------------------------------------------------------------
	///	refresh( const QVector<QVector<QVariant> > &data )
	/// ------------------------------------------------------------------------
    void data_model_ware_search::refresh(const QVector<QVector<QVariant> > &data)
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
    void data_model_ware_search::refresh( data_ware_collection *data )
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
    void data_model_ware_search::insert( const data_ware &request )
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
    QVariant data_model_ware_search::data(
										const QModelIndex &index,
										int /*role //= Qt::DisplayRole*/
									   ) const
	{
		if( !index.isValid( ) )
		{
			return QVariant( );
		}

        data_ware* ware = this->_list.at( index.row( ) );
        return ware->to_string( );

        /*
		switch( index.column( ) )
		{
            case data_ware::num_field_ware_id:
                return ware->ware_id( );
			case data_ware::num_field_hash:
                return ware->hash( );
			case data_ware::num_field_ware:
				return ware->ware( );
			default:
				return QVariant( );
		}
		return QVariant( );
		*/
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	setData( )
	/// ------------------------------------------------------------------------
    bool data_model_ware_search::setData(
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
    Qt::ItemFlags data_model_ware_search::flags(const QModelIndex &/*index*/) const
	{
		return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	}

	/// ------------------------------------------------------------------------
	/// virtual
	///	insertRows( )
	/// ------------------------------------------------------------------------
    bool data_model_ware_search::insertRows(
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
    bool data_model_ware_search::removeRows(
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
