/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 19-07-2016
///		Date update	: 19-07-2016
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
#include "data_model_detail_search.h"
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

		this->addItem( "" );
		this->addItem( "test" );
		this->addItem( "test 1" );

		QCompleter *completer = new QCompleter(this->model());
		this->setCompleter(completer);
	}

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void combobox_detail::keyPressEvent( QKeyEvent * event )
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
        QComboBox::keyPressEvent( event );
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================

}//namespace assembled_ware
