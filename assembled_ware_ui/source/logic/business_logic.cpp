/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 06-06-2016
///		Comment		:
/// ============================================================================
#include <QDebug>
#include <QMessageBox>
#include <QStringList>

#include "application.h"
#include "business_logic.h"

#include "data_model_ware.h"
#include "data_ware.h"

namespace assembled_ware
{

/// ############################################################################
///			class business_logic
/// ############################################################################

	/// ========================================================================
	///		CONSTRUCTORS/DESTRUCTOR
	/// ========================================================================

	/// ========================================================================
	///		PROPERTIES
	/// ========================================================================

	/// ========================================================================
	///		OPERATORS
	/// ========================================================================

	/// ========================================================================
	///		FUNCTIONS
	/// ========================================================================
    /// ------------------------------------------------------------------------
    ///	init_data_models( )
    /// ------------------------------------------------------------------------
    void business_logic::init_data_models( )
    {
		this->init_model_ware( );
    }

    /// ------------------------------------------------------------------------
	///	init_model_ware( )
    /// ------------------------------------------------------------------------
    void business_logic::init_model_ware( )
    {
        this->_model_ware = new data_model_ware;
        this->ware_select( );
    }

    /// ------------------------------------------------------------------------
    ///	free_memory( )
    /// ------------------------------------------------------------------------
    void business_logic::free_memory( )
    {
        if( this->_model_ware != nullptr )
        {
            delete _model_ware;
        }
    }

	/// ------------------------------------------------------------------------
	///	init( )
    /// ------------------------------------------------------------------------
	void business_logic::init( )
	{
		try
		{
            //this->init_db_path( );
            this->init_data_models( );
		}
		catch( std::exception &ex )
		{
			QString s_msg(
							"business_logic::init( )"
							":\n\t" + QString::fromUtf8( ex.what( ) )
						 );
			qDebug( ) << s_msg;
			QMessageBox::critical( 0, QObject::tr( "critical" ), s_msg );
		}
		catch( ... )
		{
			QString s_msg(
						"business_logic::init( )"
						":\n\t unknown error while initialize business logic"
						 );
			qDebug( ) << s_msg;
			QMessageBox::critical( 0, QObject::tr( "critical" ), s_msg );
		}
	}
	/// ------------------------------------------------------------------------
	///	exit( )
    /// ------------------------------------------------------------------------
	void business_logic::exit( )
	{
        this->free_memory( );

		qDebug( ) << "correctly exiting business logic";
	}

///|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
///
/// BLOCK ware
///
///|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    /// ------------------------------------------------------------------------
	///	ware_select( )
    /// ------------------------------------------------------------------------
    void business_logic::ware_select( )
    {
        data_ware_collection *p_coll = nullptr;
        try
		{
			//get data collection from data provider
			p_coll = new data_ware_collection;
			p_coll->append( new data_ware( {"1", "hash_1", "assembled ware 1"} ) );
			p_coll->append( new data_ware( {"2", "hash_2", "assembled ware 2"} ) );
			p_coll->append( new data_ware( {"3", "hash_3", "assembled ware 3"} ) );
			p_coll->append( new data_ware( {"4", "hash_4", "assembled ware 4"} ) );
			p_coll->append( new data_ware( {"5", "hash_5", "assembled ware 5"} ) );
			//refresh data model
			this->_model_ware->refresh( p_coll );

			p_coll->free_data_pointer( );
		}
		catch( std::exception &ex )
		{
            if( p_coll )
            {
                delete p_coll;
                p_coll = nullptr;
            }
			QString s_msg(
							"business_logic::ware_select( )"
							":\n\t" + QString::fromUtf8( ex.what( ) )
						 );
			qDebug( ) << s_msg;
			QMessageBox::critical( 0, QObject::tr( "critical" ), s_msg );
		}
		catch( ... )
		{
            if( p_coll )
            {
                delete p_coll;
                p_coll = nullptr;
            }
			QString s_msg(
						"business_logic::ware_select( )"
						":\n\t unknown error while wares select"
						 );
			qDebug( ) << s_msg;
			QMessageBox::critical( 0, QObject::tr( "critical" ), s_msg );
		}
    }

///|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
///
/// BLOCK ware_detail
///
///|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


/// ############################################################################

}//namespace assembled_ware
