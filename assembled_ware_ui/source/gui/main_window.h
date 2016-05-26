///$Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 24-05-2016
///		Date update	: 24-05-2016
///		Comment		:
/// ============================================================================
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <QMainWindow>
#include <QWidget>

namespace assembled_ware
{

    class widget_central;
/// ############################################################################
///			class main_window
/// ############################################################################
	class main_window : public QMainWindow
	{
		Q_OBJECT

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
	private:
		main_window( const main_window &rhs );

	public:
		explicit main_window( QWidget *parent = 0 );
		~main_window( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
	private:
		void initialize( );
		void normalize_size( );
		void window_center( );

	public:
        void append_title_text( const QString &text );

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
	private slots:

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
	private:

	public:

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
	private:
		main_window& operator=( const main_window &rhs );

	public:

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
		const int _MIN_WINDOW_HEIGHT = 768;
		const int _MIN_WINDOW_WIDTH = 1024;

        widget_central *_workspace;

	};//class main_window

/// ############################################################################
//-----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __MAIN_WINDOW_H__
