/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 15-06-2016
///		Date update	: 04-07-2016
///		Comment		:
/// ============================================================================
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>

//#include "application.h"
//#include "business_logic.h"

#include "panel_ware_detail_editor.h"

namespace assembled_ware
{
/// ############################################################################
///			class panel_ware_detail_editor
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	panel_ware_detail_editor( )
    /// ------------------------------------------------------------------------
    panel_ware_detail_editor::panel_ware_detail_editor(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~panel_ware_detail_editor( )
    /// ------------------------------------------------------------------------
    panel_ware_detail_editor::~panel_ware_detail_editor( )
    {

    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail_editor::initialize( )
    {
        this->init_layout( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_layout( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail_editor::init_layout( )
    {
		QHBoxLayout *layout = new QHBoxLayout;

		layout->addWidget( this->widget_ware_detail_name( ), this->_STRETCH_NAME );
		layout->addWidget( this->widget_qty( ), this->_STRETCH_QTY );
		layout->addWidget( this->widget_buttons( ) );

		this->setLayout( layout );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail_editor::init_connections( )
    {
		this->connect(
						this->_btn_add, SIGNAL( pressed( ) ),
						this, SLOT( append_detail( ) )
					 );
    }

    /// ------------------------------------------------------------------------
    /// widget_ware_detail_name( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware_detail_editor::widget_ware_detail_name( )
    {
		QHBoxLayout *layout = new QHBoxLayout;
		layout->setSpacing( 0 );
		layout->setContentsMargins(0,0,0,0);

		QLabel	*label = new QLabel( tr("Detail:"), this );
		layout->addWidget( label, _STRETCH_LABEL );
		this->_txt_ware_detail_name = new QLineEdit;
		layout->addWidget( this->_txt_ware_detail_name, _STRETCH_CONTROL );

		QWidget *widget = new QWidget(this);
		widget->setLayout( layout );

		return widget;
    }

    /// ------------------------------------------------------------------------
    /// widget_qty( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware_detail_editor::widget_qty( )
    {
		QHBoxLayout *layout = new QHBoxLayout;
		layout->setSpacing( 0 );
		layout->setContentsMargins(0,0,0,0);

		QLabel	*label = new QLabel( tr("Qty:"), this );
		layout->addWidget( label, _STRETCH_LABEL );
		this->_num_qty = new QSpinBox;
		layout->addWidget( this->_num_qty, _STRETCH_CONTROL );

		QWidget *widget = new QWidget(this);
		widget->setLayout( layout );

		return widget;
    }

    /// ------------------------------------------------------------------------
    /// widget_qty( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware_detail_editor::widget_buttons( )
    {
		QHBoxLayout *layout = new QHBoxLayout;
		layout->setContentsMargins(0,0,0,0);

		//
		//_btn_add
		//
		this->_btn_add = new QPushButton;
		this->_btn_add->setIcon( QIcon(":/image/images/32x32/list-add.png") );
		this->_btn_add->setToolTip( tr("add ware detail to specification") );
		layout->addWidget( this->_btn_add );
		//
		//_btn_remove
		//
		this->_btn_remove = new QPushButton;
		this->_btn_remove->setIcon( QIcon(":/image/images/32x32/list-remove.png") );
		this->_btn_remove->setToolTip( tr("remove ware detail from specification") );
		layout->addWidget( this->_btn_remove );

		QWidget *widget = new QWidget(this);
		widget->setLayout( layout );

		return widget;
    }


    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void panel_ware_detail_editor::keyPressEvent( QKeyEvent * event )
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
    /// ------------------------------------------------------------------------
    /// append_detail( )
    /// ------------------------------------------------------------------------
	void panel_ware_detail_editor::append_detail( )
	{
		QMessageBox::information( 0, "info", "append_detail( )" );
	}


}//namespace assembled_ware
