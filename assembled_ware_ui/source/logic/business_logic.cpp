/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 30-12-2016
///		Comment		:
/// ============================================================================
#include <QDebug>
#include <QMessageBox>
#include <QStringList>

#include "application.h"
#include "business_logic.h"

#include "data_model_ware.h"
#include "data_model_ware_specification.h"
#include "data_ware.h"

#include "ware_name_text2.h"
#include "qt_redis_sync_connection.h"

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

		this->init_model_ware_search( );

		this->init_model_ware_specification( );
    }

    /// ------------------------------------------------------------------------
	///	init_model_ware( )
    /// ------------------------------------------------------------------------
    void business_logic::init_model_ware( )
    {
        if( this->_model_ware != nullptr )
        {
            delete _model_ware;
            this->_model_ware = nullptr;
        }
        this->_model_ware = new data_model_ware;
		this->ware_select( );
	}

    /// ------------------------------------------------------------------------
	///	init_model_ware_search( )
    /// ------------------------------------------------------------------------
	void business_logic::init_model_ware_search( )
	{
        if( this->_model_ware_search != nullptr )
        {
            delete _model_ware_search;
            this->_model_ware_search = nullptr;
        }
        this->_model_ware_search = new data_model_ware;
	}

    /// ------------------------------------------------------------------------
	///	init_model_ware_specification( )
    /// ------------------------------------------------------------------------
	void business_logic::init_model_ware_specification( )
	{
		if( this->_model_specification != nullptr )
		{
			delete _model_specification;
			this->_model_specification = nullptr;
		}
		this->_model_specification = new data_model_ware_specification;
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
        if( this->_model_specification != nullptr )
        {
			delete _model_specification;
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
			p_coll->append( new data_ware( {"1", "hash_1", "assembled ware 1", "A001-9876", "9785911360597", "30", "320.28"} ) );
			p_coll->append( new data_ware( {"2", "hash_2", "assembled ware 2", "A002-7593", "9785911360697", "30", "1320.28"} ) );
			p_coll->append( new data_ware( {"3", "hash_3", "assembled ware 3", "A003-2346", "9785911460597", "20", "123.28"} ) );
			p_coll->append( new data_ware( {"4", "hash_4", "assembled ware 4", "A004-2784", "9786911460597", "45", "12330.28"} ) );
			p_coll->append( new data_ware( {"5", "hash_5", "assembled ware 5", "A005-2479", "9785911760597", "20", "5678.28"} ) );
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
    /// ------------------------------------------------------------------------
	///	ware_detail_select( const QString &text )
    /// ------------------------------------------------------------------------
	void business_logic::ware_detail_select( const QString &text )
	{
		//1.преобразовать набранный пользователем текст в ключи
		rele_auto::ware_name_text2 w_text{text};
		//2.проверить существование ключа
		rele_auto::qt_redis_sync_connection cnn( "localhost", 6379 );
		cnn.execute("exists " + w_text);
		if(
			cnn.reply_type( ) == rele_auto::qt_redis_reply_type::integer  &&
			cnn.result_integer( ) == 0
		  )
		{
			//3.если ключа нет - добавить
			cnn.execute("sinterstore " + w_text + " " + w_text.atom_keys_text( ) );
		}
		//если ключ есть или добавлены атомарные ключи
		if( cnn.result_integer( ) > 0 )
		{
			//4.сделать выборку
			cnn.execute("sort " + w_text + " ALPHA GET # GET *->n GET *->p BY *->n");
			//вывести в отладку
			if( cnn.reply_type( ) == rele_auto::qt_redis_reply_type::array )
			{

				//5.наполнить модель данных data_model_detail_search
				data_ware_collection *p_coll = nullptr;
				try
				{
					//get data collection from data provider
					p_coll = new data_ware_collection;
					const rele_auto::qt_redis_reply &reply = cnn.result( );
					for( int i = 0; i < reply.size( ) / 3; ++i )
					{
						p_coll->append( new data_ware( {
														QString::number(i*3),
														"",
														reply.at(i*3 + 1),
														reply.at(i*3),
														"",
														"",
														reply.at(i*3 + 2)
														}
													 )
									 );
					}
					//refresh data model
					this->_model_ware_search->refresh( p_coll );

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
									"business_logic::ware_detail_select( )"
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
								"business_logic::ware_detail_select( )"
								":\n\t unknown error while wares select"
								 );
					qDebug( ) << s_msg;
					QMessageBox::critical( 0, QObject::tr( "critical" ), s_msg );
				}
			}
		}
	}



/// ############################################################################

}//namespace assembled_ware
