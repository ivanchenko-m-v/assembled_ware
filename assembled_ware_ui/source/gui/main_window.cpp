///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 26-05-2016
///		Comment		:
/// ============================================================================
#include <QApplication>
#include <QDesktopWidget>
#include <QSize>

//#include "application.h"

#include "main_window.h"
#include "widget_central.h"

namespace assembled_ware
{

/// ############################################################################
///			class main_window
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

	///-------------------------------------------------------------------------
	///	main_window( )
    ///-------------------------------------------------------------------------
    main_window::main_window( QWidget *parent ) :
		QMainWindow( parent )
	{
		this->initialize( );
	}


    ///-------------------------------------------------------------------------
    ///	~main_window( )
    ///-------------------------------------------------------------------------
    main_window::~main_window( )
	{
	}

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    ///-------------------------------------------------------------------------
    ///	initialize( )
    ///-------------------------------------------------------------------------
    void main_window::initialize( )
	{
        QString s_title( tr("assembled ware specifications application") );
        this->setWindowTitle( s_title );

		//normalize size
		this->normalize_size( );
		//center window
		this->window_center( );

		//_workspace
        this->_workspace = new widget_central( this );
		this->setCentralWidget( this->_workspace );
	}

	///------------------------------------------------------------------------
	///	normalize_size( )
    ///-------------------------------------------------------------------------
	void  main_window::normalize_size( )
	{
		this->setMinimumSize( this->_MIN_WINDOW_WIDTH, this->_MIN_WINDOW_HEIGHT );

		QSize sz = QApplication::desktop( )->size( );
		if(
			( this->width( ) > sz.width( ) ) ||
			( this->height( ) > sz.height( ) )
		  )
		{
			this->resize( sz.width( ), sz.height( ) );
		}
	}

	///------------------------------------------------------------------------
	///	window_center( )
    ///-------------------------------------------------------------------------
    void main_window::window_center( )
	{
		QSize sz = QApplication::desktop( )->size( );
		this->move(
					( sz.width( ) - this->frameGeometry( ).width( ) )/2,
					( sz.height( ) - this->frameGeometry( ).height( ) )/2
				  );
	}

    ///------------------------------------------------------------------------
    ///	append_title_text( )
    ///-------------------------------------------------------------------------
    void main_window::append_title_text( const QString &text )
    {
        QString wtitle( this->windowTitle( ) + "-[" + text + "]" );
        this->setWindowTitle( wtitle );
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================

/// ############################################################################

}//namespace assembled_ware
