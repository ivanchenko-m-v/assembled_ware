/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 07-06-2016
///		Date update	: 07-06-2016
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

#include "panel_ware_properties.h"

namespace assembled_ware
{
/// ############################################################################
///			class panel_ware_properties
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	panel_ware_properties( )
    /// ------------------------------------------------------------------------
    panel_ware_properties::panel_ware_properties(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~panel_ware_properties( )
    /// ------------------------------------------------------------------------
    panel_ware_properties::~panel_ware_properties( )
    {

    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// initialize( )
    /// ------------------------------------------------------------------------
    void panel_ware_properties::initialize( )
    {
        this->init_layout( );

        this->init_connections( );
    }

    /// ------------------------------------------------------------------------
    /// init_layout( )
    /// ------------------------------------------------------------------------
    void panel_ware_properties::init_layout( )
    {
		QVBoxLayout *layout = new QVBoxLayout;
		//
		//_txt_ware_name
		//
		QLabel *lbl = new QLabel( tr("Ware name:"), this );
		this->_txt_ware_name = new QLabel;
		QHBoxLayout *hl = new QHBoxLayout;
		hl->addWidget( lbl, 50, Qt::AlignLeft|Qt::AlignVCenter );
		hl->addWidget( this->_txt_ware_name, 50, Qt::AlignLeft|Qt::AlignVCenter );
		layout->addLayout( hl );
		//
		//_txt_article
		//
		lbl = new QLabel( tr("Article:"), this );
		this->_txt_article = new QLabel;
		hl = new QHBoxLayout;
		hl->addWidget( lbl, 50, Qt::AlignLeft|Qt::AlignVCenter );
		hl->addWidget( this->_txt_article, 50, Qt::AlignLeft|Qt::AlignVCenter );
		layout->addLayout( hl );
		//
		//_txt_barcode
		//
		lbl = new QLabel( tr("Bar-code:"), this );
		this->_txt_barcode = new QLabel;
		hl = new QHBoxLayout;
		hl->addWidget( lbl, 50, Qt::AlignLeft|Qt::AlignVCenter );
		hl->addWidget( this->_txt_barcode, 50, Qt::AlignLeft|Qt::AlignVCenter );
		layout->addLayout( hl );
		//
		//_txt_percent
		//
		lbl = new QLabel( tr("Margin Percent:"), this );
		this->_txt_percent = new QLineEdit;
		hl = new QHBoxLayout;
		hl->addWidget( lbl, 50, Qt::AlignLeft|Qt::AlignVCenter );
		hl->addWidget( this->_txt_percent, 50, Qt::AlignLeft|Qt::AlignVCenter );
		//
		//_txt_sum
		//
		lbl = new QLabel( tr("Ware price total:"), this );
		this->_txt_sum = new QLineEdit;
		hl->addWidget( lbl, 50, Qt::AlignLeft|Qt::AlignVCenter );
		hl->addWidget( this->_txt_sum, 50, Qt::AlignLeft|Qt::AlignVCenter );
		layout->addLayout( hl );

		this->setLayout( layout );
    }

    /// ------------------------------------------------------------------------
    /// init_connections( )
    /// ------------------------------------------------------------------------
    void panel_ware_properties::init_connections( )
    {
    }

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    /// keyPressEvent ( QKeyEvent * event )
    /// ------------------------------------------------------------------------
    void panel_ware_properties::keyPressEvent( QKeyEvent * event )
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
