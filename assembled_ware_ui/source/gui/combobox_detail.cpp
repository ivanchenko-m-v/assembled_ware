/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 19-07-2016
///		Date update	: 30-12-2016
///		Comment		:
/// ============================================================================
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>
#include <QCompleter>

#include "application.h"
#include "business_logic.h"

#include "combobox_detail.h"
#include "data_model_ware.h"
#include "data_ware.h"

namespace assembled_ware
{
/// ############################################################################
///			class combobox_detail
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	combobox_detail( )
    /// ------------------------------------------------------------------------
    combobox_detail::combobox_detail(QWidget *parent) :
        QComboBox(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~combobox_detail( )
    /// ------------------------------------------------------------------------
    combobox_detail::~combobox_detail( )
    {

    }
    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// current_ware( )
    /// ------------------------------------------------------------------------
	const data_ware* combobox_detail::current_ware( )
	{
	/*
		QModelIndex idx = this->selectionModel( )->currentIndex( );
		if( !idx.isValid( ) )
		{
			return 0;
		}

		return application::the_business_logic( ).
							model_ware( )->ware( idx.row( ) );
							*/
		return nullptr;
	}

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void combobox_detail::initialize( )
    {
		this->init_view( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void combobox_detail::init_connections( )
    {
    }

	/// ------------------------------------------------------------------------
	///	init_view( )
	/// ------------------------------------------------------------------------
    void combobox_detail::init_view( )
    {
		this->setInsertPolicy( InsertAtTop );
		this->setEditable(true);
/*
		this->addItem( "" );
		this->addItem( "test" );
		this->addItem( "test 1" );
*/
		this->setModel( application::the_business_logic( ).model_ware_search( ) );
/*
		QCompleter *completer = new QCompleter(this->model());
		this->setCompleter(completer);
		*/
	}

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void combobox_detail::keyPressEvent( QKeyEvent * event )
    {
		QComboBox::keyPressEvent( event );
	}

    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
	void combobox_detail::keyReleaseEvent(QKeyEvent *event)
	{
		int n_key = event->key( );
		if( n_key == Qt::Key_Enter || n_key == Qt::Key_Return )
		{
			application::the_business_logic( ).ware_detail_select( this->currentText( ) );
		}
		QComboBox::keyReleaseEvent( event );
	}

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================

}//namespace assembled_ware
