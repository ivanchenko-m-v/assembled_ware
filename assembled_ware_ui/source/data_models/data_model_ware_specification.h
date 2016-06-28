/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 28-06-2016
///		Date update	: 28-06-2016
///		Comment		:
/// ============================================================================

#ifndef __DATA_MODEL_WARE_SPECIFICATION_H__
#define __DATA_MODEL_WARE_SPECIFICATION_H__

#include <QAbstractTableModel>
#include <QList>
#include <QVector>

#include "data_ware.h"

namespace assembled_ware
{

/// ############################################################################
///			class data_model_ware_specification
/// ############################################################################
    class data_model_ware_specification : public QAbstractTableModel
	{

	Q_OBJECT
	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================
	public:
	/// ------------------------------------------------------------------------
        data_model_ware_specification( QObject* pobj = 0 );
	/// ------------------------------------------------------------------------
        virtual ~data_model_ware_specification( );

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================
	public:
	/// ------------------------------------------------------------------------
    const data_ware* ware( int i_row ) const;

	/// ========================================================================
	///		OPERATORS
	/// ========================================================================
	private:
	/// ------------------------------------------------------------------------
        data_model_ware_specification& operator=( const data_model_ware_specification &rhs );

	/// ========================================================================
	///		FUNCTIONS
	/// ========================================================================
	private:
	/// ------------------------------------------------------------------------
		virtual void initialize( void );
	/// ------------------------------------------------------------------------
		virtual void init_columns_header( void )
		{
            this -> _header.append( QObject::tr( "WARE" ) );
        }

	public:
	/// ------------------------------------------------------------------------
		void clear( );
	/// ------------------------------------------------------------------------
		void refresh( const QVector<QVector<QVariant> > &data );
	/// ------------------------------------------------------------------------
        void refresh( data_ware_collection *data );
	/// ------------------------------------------------------------------------
        //void insert( const data_request &request );
	/// ------------------------------------------------------------------------
	/// override
		virtual int rowCount(
								const QModelIndex &/*parent = QModelIndex( )*/
							) const
		{
			return this -> _list.size( );
        }
	/// ------------------------------------------------------------------------
	/// override
		virtual int columnCount(
								const QModelIndex &/*parent = QModelIndex( )*/
							   ) const
		{
			return this -> _header.size( );
		}
	/// ------------------------------------------------------------------------
	/// override
		virtual QVariant headerData(
									int section,
									Qt::Orientation orientation,
									int role/* = Qt::DisplayRole*/
								   ) const
		{
			if( role != Qt::DisplayRole )
			{
				return QVariant( );
			}
			if(
				( section > this -> _header.size( ) ) ||
				( section < 0 )
			  )
			{
				return QVariant( );
			}

			return ( orientation == Qt::Horizontal )
					? ( this -> _header )[section]
					: " ";
		}
	/// ------------------------------------------------------------------------
	/// override
		virtual Qt::ItemFlags flags( const QModelIndex &index ) const;
	/// ------------------------------------------------------------------------
	/// override
		virtual QVariant data(
								const QModelIndex & index,
								int role = Qt::DisplayRole
							 ) const;
	/// ------------------------------------------------------------------------
	/// override
		virtual bool setData(
								const QModelIndex & index,
								const QVariant & value,
								int role = Qt::EditRole
							 );
	/// ------------------------------------------------------------------------
	/// override
		virtual bool insertRows(
								int row, int count,
								const QModelIndex &parent = QModelIndex( )
							   );
	/// ------------------------------------------------------------------------
	/// override
		virtual bool removeRows(
								int row, int count,
								const QModelIndex &parent = QModelIndex( )
							   );

	/// ========================================================================
	///		SLOTS
	/// ========================================================================
	private:
	/// ------------------------------------------------------------------------

	/// ========================================================================
	///			FIELDS
	/// ========================================================================
	private:
		QVector<QString>		_header;
		list_ware				_list;

    };//class data_model_ware_specification
/// ############################################################################

}//namespace assembled_ware

#endif // __DATA_MODEL_WARE_SPECIFICATION_H__
