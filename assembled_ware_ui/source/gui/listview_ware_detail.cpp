/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 07-06-2016
///		Date update	: 07-06-2016
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

#include "listview_ware_detail.h"
#include "delegate_line_edit.h"

namespace assembled_ware
{
/// ############################################################################
///			class listview_ware_detail
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	listview_ware_detail( )
    /// ------------------------------------------------------------------------
    listview_ware_detail::listview_ware_detail(QWidget *parent) :
        QTableView(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~listview_ware_detail( )
    /// ------------------------------------------------------------------------
    listview_ware_detail::~listview_ware_detail( )
    {

    }
    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void listview_ware_detail::initialize( )
    {
		this->init_view( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void listview_ware_detail::init_connections( )
    {
    }

	/// ------------------------------------------------------------------------
	///	init_view( )
	/// ------------------------------------------------------------------------
    void listview_ware_detail::init_view( )
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
/*
		this->setModel(
				application::the_business_logic( ).model_ware( )
					  );
*/
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
    void listview_ware_detail::keyPressEvent( QKeyEvent * event )
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
        QWidget::keyPressEvent( event );
    }

	/// ------------------------------------------------------------------------
	///	resizeEvent( QResizeEvent *event )
	/// ------------------------------------------------------------------------
    void listview_ware_detail::resizeEvent( QResizeEvent *event )
    {
        QTableView::resizeEvent( event );
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================

}//namespace assembled_ware
