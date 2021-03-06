/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 31-05-2016
///		Comment		:
/// ============================================================================
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>

//#include "application.h"
//#include "business_logic.h"

#include "widget_central.h"
#include "panel_ware.h"
#include "panel_ware_detail.h"

namespace assembled_ware
{
/// ############################################################################
///			class widget_central
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	widget_central( )
    /// ------------------------------------------------------------------------
    widget_central::widget_central(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~widget_central( )
    /// ------------------------------------------------------------------------
    widget_central::~widget_central( )
    {

    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void widget_central::initialize( )
    {
        this->init_layout( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_layout( )
    /// ------------------------------------------------------------------------
    void widget_central::init_layout( )
    {
		QHBoxLayout *layout = new QHBoxLayout;

		layout->addWidget( this->widget_panel_ware( ), this->_STRETCH_PANEL_WARE );
		layout->addWidget( this->widget_panel_ware_detail( ), this->_STRETCH_PANEL_WARE_DETAIL );

		this->setLayout( layout );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void widget_central::init_connections( )
    {
    }

    /// ------------------------------------------------------------------------
    /// widget_panel_ware( )
    /// ------------------------------------------------------------------------
    QWidget* widget_central::widget_panel_ware( )
    {
		this->_panel_ware = new panel_ware(this);
		return this->_panel_ware;
    }

    /// ------------------------------------------------------------------------
    /// widget_panel_ware_detail( )
    /// ------------------------------------------------------------------------
    QWidget* widget_central::widget_panel_ware_detail( )
    {
		this->_panel_ware_detail = new panel_ware_detail(this);
		return this->_panel_ware_detail;
    }

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void widget_central::keyPressEvent( QKeyEvent * event )
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

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================

}//namespace assembled_ware
