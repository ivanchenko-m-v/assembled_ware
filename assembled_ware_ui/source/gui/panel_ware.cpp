/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 31-05-2016
///		Comment		:
/// ============================================================================
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>

//#include "application.h"
//#include "business_logic.h"

#include "panel_ware.h"
#include "listview_ware.h"

namespace assembled_ware
{
/// ############################################################################
///			class panel_ware
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	panel_ware( )
    /// ------------------------------------------------------------------------
    panel_ware::panel_ware(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~panel_ware( )
    /// ------------------------------------------------------------------------
    panel_ware::~panel_ware( )
    {

    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void panel_ware::initialize( )
    {
        this->init_layout( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_layout( )
    /// ------------------------------------------------------------------------
    void panel_ware::init_layout( )
    {
		QVBoxLayout *layout = new QVBoxLayout;
		layout->setMargin(this->_CONTROL_MARGIN);
		layout->setSpacing(this->_CONTROL_SPACE);

		layout->addWidget( this->widget_listview_ware( ), this->_STRETCH_LIST );
		layout->addWidget( this->widget_buttons( ), this->_STRETCH_BUTTONS );

		this->setLayout( layout );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void panel_ware::init_connections( )
    {
    }

    /// ------------------------------------------------------------------------
    /// widget_listview_ware( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware::widget_listview_ware( )
    {
		this->_list_ware = new listview_ware( this );
		return this->_list_ware;
    }

    /// ------------------------------------------------------------------------
    /// widget_buttons( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware::widget_buttons( )
    {
		//
		//_btn_add
		//
		this->_btn_add = new QPushButton;
		this->_btn_add->setIcon( QIcon(":/image/images/32x32/list-add.png") );
		this->_btn_add->setToolTip( tr("add new assembled ware") );

		//
		//_btn_remove
		//
		this->_btn_remove = new QPushButton;
		this->_btn_remove->setIcon( QIcon(":/image/images/32x32/list-remove.png") );
		this->_btn_remove->setToolTip( tr("remove assembled ware") );

		QHBoxLayout *layout = new QHBoxLayout;
		layout->setMargin(this->_CONTROL_MARGIN);
		layout->setSpacing(this->_CONTROL_SPACE);
		layout->addStretch( );
		layout->addWidget( this->_btn_add );
		layout->addWidget( this->_btn_remove );

		QWidget *widget = new QWidget( this );
		widget->setLayout( layout );

		return widget;
    }

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void panel_ware::keyPressEvent( QKeyEvent * event )
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
