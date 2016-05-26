/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 26-05-2016
///		Comment		:
/// ============================================================================
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QIcon>
#include <QMessageBox>

#include <stdexcept>

#include "application.h"
#include "business_logic.h"

namespace assembled_ware
{
		bool application::_is_logic_initialized = false;
/// ############################################################################
///			class application
/// ############################################################################
	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================

	/// ------------------------------------------------------------------------
	///	application( int & argc, char ** argv )
    /// ------------------------------------------------------------------------
	application::application( int & argc, char ** argv ) :
        QApplication( argc, argv )
	{
		this->initialize( );
	}


    /// ------------------------------------------------------------------------
	///	~application( )
    /// ------------------------------------------------------------------------
	application::~application( )
	{
		this->closeAllWindows( );

         //close all threads
		if( application::_is_logic_initialized )
		{
			the_business_logic( ).exit( );
		}

        qDebug( ) << "application object destroyed correctly";
    }

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================

    /// ========================================================================
	///		FUNCTIONS
    /// ========================================================================
	/// -----------------------------------------------------------------------
	///	the_business_logic( )
    /// -----------------------------------------------------------------------
    business_logic& application::the_business_logic( )
	{
		static business_logic logic;

        return logic;
    }
	/// -----------------------------------------------------------------------
	///	the_app_log( )
    /// -----------------------------------------------------------------------
	espira::utils::application_log& application::the_app_log( )
	{
		static espira::utils::application_log app_log;

        return app_log;
	}

    /// ------------------------------------------------------------------------
    ///	authorize( )
    /// ------------------------------------------------------------------------
    void application::authorize( )
    {
    }

	/// ------------------------------------------------------------------------
	///	initialize( )
    /// ------------------------------------------------------------------------
	void application::initialize( )
	{
		try
		{
            this->setWindowIcon(
							*( new QIcon( ":/image/images/app_icon.png" ) )
							   );
            this->load_translation( );
            this->load_config( );
            this->init_logic( );

			//cleanup and save config on quit
            this->connect(
                         this, SIGNAL(aboutToQuit( )),
                         this, SLOT(save_config( ))
                         );
		}
		catch( std::exception &ex )
		{
			QMessageBox::critical(
									0,
									QObject::tr( "app init error" ),
									QString::fromUtf8( ex.what( ) )
								  );
		}
		catch( ... )
		{
			QMessageBox::critical(
									0,
									QObject::tr( "critical" ),
									QObject::tr(
												"unexpected error while "
												"program initializing"
												)
								  );
		}
	}

    /// ------------------------------------------------------------------------
	///	init_logic( )
    /// ------------------------------------------------------------------------
    void application::init_logic( )
    {
        if( !application::_is_logic_initialized )
		{
			application::_is_logic_initialized = true;
			//init logic dynamic memory allocated objects
			the_business_logic( ).init( );
		}
    }

    /// ------------------------------------------------------------------------
	///	load_translation( )
    /// ------------------------------------------------------------------------
    void application::load_translation( )
    {
        this->_translator.load(
                        "russian.lng",
                        QApplication::applicationDirPath( )
                       );
        //translation
        this->installTranslator( &( this->_translator ) );
    }

	/// ------------------------------------------------------------------------
	///	load_config( )
    /// ------------------------------------------------------------------------
	void application::load_config( )
	{
        this->_params.parse_cfg_file(
                     QDir::currentPath( )+"/app_assembled_ware.cfg"
                    );
    }

    /// ========================================================================
	///		SLOTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	save_config( )
    /// ------------------------------------------------------------------------
    void application::save_config( )
    {
        try
        {
            this->_params.save_cfg_file( QDir::currentPath( )+"/app_assembled_ware.cfg" );
        }
        catch( std::exception &ex )
		{
			QMessageBox::critical(
									0,
									QObject::tr( "app exit error" ),
									QString::fromUtf8( ex.what( ) )
								  );
		}
		catch( ... )
		{
			QMessageBox::critical(
									0,
									QObject::tr( "critical" ),
									QObject::tr(
												"unexpected error while "
												"program exiting"
												)
								  );
        }
    }

/// ############################################################################

}//namespace assembled_ware
