/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 20-07-2016
///		Comment		:
/// ============================================================================
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>

#include "application.h"
#include "business_logic.h"

#include "listview_ware.h"
#include "delegate_line_edit.h"
#include "data_model_ware.h"
#include "data_ware.h"

namespace assembled_ware
{
/// ############################################################################
///			class listview_ware
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	listview_ware( )
    /// ------------------------------------------------------------------------
    listview_ware::listview_ware(QWidget *parent) :
        QTableView(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~listview_ware( )
    /// ------------------------------------------------------------------------
    listview_ware::~listview_ware( )
    {

    }
    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// current_ware( )
    /// ------------------------------------------------------------------------
	const data_ware* listview_ware::current_ware( )
	{
		QModelIndex idx = this->selectionModel( )->currentIndex( );
		if( !idx.isValid( ) )
		{
			return 0;
		}

		return application::the_business_logic( ).
							model_ware( )->ware( idx.row( ) );
	}

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void listview_ware::initialize( )
    {
		this->init_view( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void listview_ware::init_connections( )
    {
        if( this->selectionModel( ) )
        {
            this->connect(
                       this->selectionModel( ), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
                       this, SLOT( selected_item_changed( ) )
                         );
        }
    }

	/// ------------------------------------------------------------------------
	///	init_view( )
	/// ------------------------------------------------------------------------
    void listview_ware::init_view( )
    {
        this->setShowGrid( true );
		this->setGridStyle( Qt::DotLine );
		this->horizontalHeader( )->setVisible( true );
		this->verticalHeader( )->setVisible( false );

#if QT_VERSION >= 0x050000
		this->horizontalHeader( )->setSectionsClickable( true );
		this->verticalHeader( )->setSectionsClickable( false );
#else
		this->horizontalHeader( )->setClickable( true );
		this->verticalHeader( )->setClickable( false );
#endif

		this->setModel(
				application::the_business_logic( ).model_ware( )
					  );

		this->setSelectionMode( QAbstractItemView::SingleSelection );
		this->setSelectionBehavior( QAbstractItemView::SelectRows );

		this->setItemDelegate( new espira::controls::delegate_line_edit );
	}

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void listview_ware::keyPressEvent( QKeyEvent * event )
    {
        /*
        if( event->key( ) == Qt::Key_N )
        {
            if( event->modifiers( ) & Qt::ControlModifier )
            {
                this->slot_add_request( );
            }
        }
        */
        QTableView::keyPressEvent( event );
    }

	/// ------------------------------------------------------------------------
	///	resizeEvent( QResizeEvent *event )
	/// ------------------------------------------------------------------------
    void listview_ware::resizeEvent( QResizeEvent *event )
    {
        QTableView::resizeEvent( event );

        if( !this->model( ) )
        {
            return;
        }
        if( this->model( )->columnCount( ) < 1 )
        {
			return;
        }
        this->setColumnWidth( 0, this->viewport( )->width( ) );
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
	/// ------------------------------------------------------------------------
	///	selected_item_changed( )
	/// ------------------------------------------------------------------------
    void listview_ware::selected_item_changed( )
    {
        const data_ware *ware = this->current_ware( );
        if( ware != nullptr )
        {
            emit current_ware_changed( ware );
        }
    }

}//namespace assembled_ware
