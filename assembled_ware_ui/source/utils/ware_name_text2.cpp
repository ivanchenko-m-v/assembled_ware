
/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 18-03-2016
///		Date update	: 30-12-2016
///		Comment		:
/// ============================================================================

#include "ware_name_text2.h"
#include <QRegExp>
#include <QStringList>

namespace rele_auto
{
/// ############################################################################
///			class ware_symbol_replacer
/// ############################################################################
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    ware_symbol_replacer::ware_symbol_replacer( )
    {
		this->init( );
    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	init( )
    /// ------------------------------------------------------------------------
    void ware_symbol_replacer::init( )
    {
		//init symblols exchange table
		//АВЕЁКМНОРСТХ - symblols to replace
		QString s_replacing{QString::fromStdWString(L"АВЕЁКМНОРСТХ")};
		//ABEEKMHOPCTX - symbols to substitute
		QString s_subst{QString::fromStdWString(L"ABEEKMHOPCTX")};

		auto it_k = s_replacing.begin( );
		auto it_v = s_subst.begin( );
		for( ; it_k != s_replacing.end( ); ++it_k, ++it_v )
		{
			this->_letters_table.insert( *it_k, *it_v );
		}
    }
    /// ------------------------------------------------------------------------
	///	replace( )
    /// ------------------------------------------------------------------------
	void ware_symbol_replacer::replace( QString &s )
	{
		for( QChar &symbol : s )
		{
			if( symbol.isLetter( ) && this->_letters_table.contains( symbol ) )
			{
				symbol = this->_letters_table[symbol];
			}
		}
	}

    /// ------------------------------------------------------------------------
	///	the_ware_symbol_replacer( )
    /// ------------------------------------------------------------------------
	ware_symbol_replacer& the_ware_symbol_replacer( )
	{
		static ware_symbol_replacer replacer;
		return replacer;
	}

/// ############################################################################
///			class ware_specsymbol_replacer
/// ############################################################################
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    ware_specsymbol_replacer::ware_specsymbol_replacer( )
    {
		this->init( );
    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	init( )
    /// ------------------------------------------------------------------------
    void ware_specsymbol_replacer::init( )
    {
		QString s_replacing{QString::fromStdWString(L"123456789PЗ")};
		//ABEEKMHOPCTYX - symbols to substitute
		QString s_subst[] = {
								QString::fromStdWString(L"o"), //1
								QString::fromStdWString(L"d"), //2
								QString::fromStdWString(L"t"), //3
								QString::fromStdWString(L"r"), //4
								QString::fromStdWString(L"p"), //5
								QString::fromStdWString(L"h"), //6
								QString::fromStdWString(L"s"), //7
								QString::fromStdWString(L"v"), //8
								QString::fromStdWString(L"e"), //9
								QString::fromStdWString(L"rz"),//Р
								QString::fromStdWString(L"zm") //З
							};

		auto it_k = s_replacing.begin( );
		auto it_v = s_subst;
		for( ; it_k != s_replacing.end( ); ++it_k, ++it_v )
		{
			this->_spec_table.insert( *it_k, *it_v );
		}
	}

    /// ------------------------------------------------------------------------
	///	replace( )
    /// ------------------------------------------------------------------------
	void ware_specsymbol_replacer::replace( QString &s, QChar delimeter/*= QChar( ':' )*/ )
	{
		QRegExp rx( QString::fromStdWString( L"([1-9]) *[\"'«]?([PЗ])[»'\"]" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		int pos = -1;
		while( (pos = rx.indexIn( s ))!= -1 )
		{
			s.replace(
					pos, rx.matchedLength( ),
					this->_spec_table[rx.cap(1)[0]] + this->_spec_table[rx.cap(2)[0]] + delimeter
					 );
		}
	}

    /// ------------------------------------------------------------------------
	///	the_ware_specsymbol_replacer( )
    /// ------------------------------------------------------------------------
	ware_specsymbol_replacer& the_ware_specsymbol_replacer( )
	{
		static ware_specsymbol_replacer replacer;
		return replacer;
	}

/// ############################################################################
///			class ware_name_text2
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
	///	ware_name_text2( )
    /// ------------------------------------------------------------------------
	ware_name_text2::ware_name_text2( const QString &text ) :
		QString( text )
	{
		//prepare symbols combinations
		this->prepare( );
	}

    /// ------------------------------------------------------------------------
	///	~ware_name_text2( )
    /// ------------------------------------------------------------------------
	ware_name_text2::~ware_name_text2( )
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
    /// ------------------------------------------------------------------------
	///	prepare( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::prepare( )
	{
		//#1
		//# 1) Переводим все символы в верхний регистр
		QString tmp_s{this->toUpper( )};
		this->swap( tmp_s );
		//#2
		//# 2) Заменяем схожие по начертанию буквы из кириллицы на латиницу
		this->replace_letters( );
		//#поиск строк, похожих на тип контактов c указанием их количества
		//#... 2 "З | 1"З | 1НЗ | 2"З | 2НЗ | 3Р | 4"З | 4НЗ | 5"З | 6"З ...
		//#на шаге 5) такие последовательсти "превратятся" в "Q[0-9]H?[P3]"
		//#-----------------------------------------------------------------
		//#3
		//# 3) Заменяем символы Р(лат) или З(рус) в кавычках с цифрой перед
		//# ними на цифру и Р(или З) без кавычек и без пробела между ними. В
		//# конце полученной последовательности поставить пробел-разделитель
		//$str =~ s/(?<=[1-9]) *["'«]([PЗ])[»'"]/$1 /g if $str =~ m/["'«]/;
		this->replace_num_quot_P3( );
		//#4
		//замена небуквоцифр на пробел
		this->replace_not_alnum( );
		//костыль для 'ПМЛ'
		this->replace_PML_C_RTL( );
		//#5
		//# 5) Далее рассматриваем буквенноцифровые фрагменты по отдельности
		//# и формируем ключи выходного хэша слов IDX
		this->parse_words( );
		//удалить дубликаты слогов
		this->remove_duplicates( );
	}

    /// ------------------------------------------------------------------------
	///	replace_letters( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::replace_letters( )
	{
		the_ware_symbol_replacer( ).replace( *this );
	}

    /// ------------------------------------------------------------------------
	///	replace_num_quot_P3( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::replace_num_quot_P3( )
	{
		//find quotes
		QRegExp rx_quot( QString::fromStdWString( L"[\"'«]" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		if( rx_quot.indexIn( *this ) == -1 )
		{
			//matches not found - nothing to do
			return;
		}

		//# 3) Заменяем символы Р(лат) или З(рус) в кавычках с цифрой перед
		//# ними на цифру и Р(или З) без кавычек и без пробела между ними. В
		//# конце полученной последовательности поставить пробел-разделитель
		//$str =~ s/(?<=[1-9]) *["'«]([PЗ])[»'"]/$1 /g if $str =~ m/["'«]/;
		QRegExp rx( QString::fromStdWString( L"([1-9]) *[\"'«]([PЗ])[»'\"]" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		int pos = -1;
		while( (pos = rx.indexIn( *this ))!= -1 )
		{
			this->replace(
					pos, rx.matchedLength( ),
					rx.cap(1) + rx.cap(2) + QString::fromStdWString( L" " )
						 );
		}

	}

    /// ------------------------------------------------------------------------
	///	replace_PML_C_PTL( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::replace_PML_C_RTL( )
	{
		//find 'ПМЛ'
		if( !this->contains( QString::fromStdWString( L"ПMЛ" ), Qt::CaseInsensitive ) )
		{
			//matches not found - nothing to do
			return;
		}

		QRegExp rx( QString::fromStdWString( L" C PTЛ" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		int pos = -1;
		while( (pos = rx.indexIn( *this ))!= -1 )
		{
			this->replace(
					pos, rx.matchedLength( ),
					QString(" ") + this->_SYLLABLE_DELIMETER
						 );
		}
	}

    /// ------------------------------------------------------------------------
	///	replace_not_alnum( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::replace_not_alnum( )
	{
		//сначала меняем символ подчёркивания
		QRegExp rx_( QString::fromStdWString( L"_+" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		this->replace( rx_, QString::fromStdWString( L" " ) );
		//потом все остальные "небуквоцифры"
		QRegExp rx( QString::fromStdWString( L"\\W+" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		this->replace( rx, QString::fromStdWString( L" " ) );
	}

	void ware_name_text2::parse_words( )
	{
		this->_syllables = this->split( QString::fromStdWString( L" " ), QString::SkipEmptyParts );

		QRegExp rx( QString::fromStdWString( L"^([1-9])(H?[PЗ])$" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		for( QString &s : this->_syllables )
		{
			if( s.contains( rx ) )
			{
				//# количество и тип контактов заменить на спецключ "Q[1-9]H?[P3]"
				this->replace_spec( s );
			}
			else
			{
				//# отделяем слова от чисел, вставляя между ними пробел
				//вставляем разделитель в последовательность буквы-цифры
				this->insert_syllable_alpha_num( s );
				//вставляем разделитель в последовательность цифры-буквы
				this->insert_syllable_num_alpha( s );
			}
		}

		QString s_tmp{this->_syllables.join(" " )};
		this->swap( s_tmp );
		this->_syllables.clear( );
	}

    /// ------------------------------------------------------------------------
	///	replace_spec( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::replace_spec( QString &s )
	{
		QRegExp rx( QString::fromStdWString( L"^([1-9])(H?[PЗ])$" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		int pos = -1;
		if( (pos = rx.indexIn( s ))!= -1 )
		{
			s.replace(
					pos, rx.matchedLength( ),
					QString::fromStdWString(L"Q") + rx.cap(1) + rx.cap(2)
					//QString::fromStdWString(L"Q") + QString("\\1") + QString("\\2")
						 );
		}
	}

    /// ------------------------------------------------------------------------
	///	insert_syllable_alpha_num( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::insert_syllable_alpha_num( QString &s )
	{
		QRegExp rx( QString::fromStdWString( L"(\\D+)(?=\\d+)" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		if( rx.indexIn( s ) != -1 )
		{
			//вставляем разделитель между последовательностью нецифр и цифр
			s.replace( rx, QString("\\1") + QString::fromStdWString( L" " ) );
		}
	}

    /// ------------------------------------------------------------------------
	///	insert_syllable_num_alpha( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::insert_syllable_num_alpha( QString &s )
	{
		QRegExp rx( QString::fromStdWString( L"(\\d+)(?=\\D+)" ), Qt::CaseSensitive, QRegExp::RegExp2 );
		if( rx.indexIn(s) != -1 )
		{
			//вставляем разделитель между последовательностью цифр и нецифр
			s.replace( rx, QString("\\1") + QString::fromStdWString( L" " )  );
		}
	}

    /// ------------------------------------------------------------------------
	///	remove_duplicates( )
    /// ------------------------------------------------------------------------
	void ware_name_text2::remove_duplicates( )
	{
		this->_syllables = this->split( QString::fromStdWString( L" " ), QString::SkipEmptyParts );
		this->_syllables.removeDuplicates( );
		this->_syllables.sort( );

		//собираем строку без дубликатов
		this->clear( );
		for( QString &syl :this->_syllables )
		{
			//обрезаем слог, если требуется
			if( syl.length( ) > this->_MAX_SYLLABLE_LEN )
			{
				syl.remove( this->_MAX_SYLLABLE_LEN, syl.length( ) - this->_MAX_SYLLABLE_LEN );
			}
			//добавляем обрезанный слог
			this->append( syl.prepend(this->_SYLLABLE_DELIMETER) );
		}
		if( this->endsWith(this->_SYLLABLE_DELIMETER) )
		{
			//удаляем разделитель в конце
			this->remove( this->length( )-1, 1 );
		}
	}
    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	operator=( const ware_name_text2 &rhs )
    /// ------------------------------------------------------------------------
    ware_name_text2& ware_name_text2::operator=( const ware_name_text2 &rhs )
    {
		if( this == &rhs )
		{
			return *this;
		}
		this->clear( );
		this->append( rhs );

		this->_MAX_SYLLABLE_LEN = rhs._MAX_SYLLABLE_LEN;
		this->_SYLLABLE_DELIMETER = rhs._SYLLABLE_DELIMETER;

		this->_syllables.clear( );
		this->_syllables.append( rhs._syllables );

		return *this;
    }
    /// ------------------------------------------------------------------------
	///	operator=( const QString &rhs )
    /// ------------------------------------------------------------------------
    ware_name_text2& ware_name_text2::operator=( const QString &rhs )
    {
		if( this == &rhs )
		{
			return *this;
		}
		this->clear( );
		this->append( rhs );
		this->prepare( );

		return *this;
    }
    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	atom_keys_text( ) const
    /// ------------------------------------------------------------------------
	QString ware_name_text2::atom_keys_text( ) const
	{
		return this->_syllables.join( QString( " " ) );
	}

/// ############################################################################
}//namespace rele_auto
