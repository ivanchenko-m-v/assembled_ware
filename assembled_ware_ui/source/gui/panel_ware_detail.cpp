/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 15-06-2016
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

#include "panel_ware_detail.h"
#include "panel_ware_properties.h"
#include "panel_ware_detail_editor.h"
#include "listview_ware_detail.h"

namespace assembled_ware
{
/// ############################################################################
///			class panel_ware_detail
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	panel_ware_detail( )
    /// ------------------------------------------------------------------------
    panel_ware_detail::panel_ware_detail(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~panel_ware_detail( )
    /// ------------------------------------------------------------------------
    panel_ware_detail::~panel_ware_detail( )
    {

    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail::initialize( )
    {
        this->init_layout( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_layout( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail::init_layout( )
    {
		QVBoxLayout *layout = new QVBoxLayout;

		layout->addWidget( this->widget_ware_properties( ), this->_STRETCH_PROPERTIES );
		layout->addWidget( this->widget_detail_editor( ), this->_STRETCH_DETAIL_EDITOR );
		layout->addWidget( this->widget_listview_detail( ), this->_STRETCH_LIST );

		this->setLayout( layout );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void panel_ware_detail::init_connections( )
    {
    }

    /// ------------------------------------------------------------------------
    /// widget_listview_detail( )
    /// ------------------------------------------------------------------------
    QWidget*  panel_ware_detail::widget_listview_detail( )
    {
		QLabel *lbl = new QLabel( tr("Ware detail list:"), this );
		this->_lv_wd = new listview_ware_detail(this);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(lbl, this->_STRETCH_LABEL);
		layout->addWidget(this->_lv_wd, this->_STRETCH_LIST);

		QWidget *wgt = new QWidget;
		wgt->setLayout( layout );

		return wgt;
    }

    /// ------------------------------------------------------------------------
    /// widget_ware_properties( )
    /// ------------------------------------------------------------------------
    QWidget*  panel_ware_detail::widget_ware_properties( )
    {
		this->_panel_prop = new panel_ware_properties;
		return this->_panel_prop;
    }

    /// ------------------------------------------------------------------------
    /// widget_detail_editor( )
    /// ------------------------------------------------------------------------
    QWidget* panel_ware_detail::widget_detail_editor( )
    {
		this->_panel_detail_editor = new panel_ware_detail_editor;
		return this->_panel_detail_editor;
    }

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void panel_ware_detail::keyPressEvent( QKeyEvent * event )
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
