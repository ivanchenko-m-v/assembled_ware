/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 15-06-2016
///		Date update	: 15-06-2016
///		Comment		:
/// ============================================================================
#ifndef __PANEL_WARE_DETAIL_EDITOR_H__
#define __PANEL_WARE_DETAIL_EDITOR_H__

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>

namespace assembled_ware
{

/// ############################################################################
///			class panel_ware_detail_editor
/// ############################################################################
    class panel_ware_detail_editor : public QWidget
    {
    Q_OBJECT
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        panel_ware_detail_editor( const panel_ware_detail_editor &rhs );

	public:
        /// --------------------------------------------------------------------
        explicit panel_ware_detail_editor(QWidget *parent = 0);
        /// --------------------------------------------------------------------
        virtual ~panel_ware_detail_editor( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        void initialize( );
        void init_layout();
        void init_connections( );
        QWidget* widget_ware_detail_name( );
        QWidget* widget_qty( );
        QWidget* widget_buttons( );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    private:

	public:

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        panel_ware_detail_editor& operator=( const panel_ware_detail_editor &rhs );

    /// ========================================================================
    ///		EVENTS
    /// ========================================================================
	protected:
        virtual void keyPressEvent ( QKeyEvent * event );

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    public slots:
        /// --------------------------------------------------------------------

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
		const int _MARGIN_ALL = 5;
		const int _STRETCH_CONTROL = 1000;
		const int _STRETCH_LABEL = 10;
		const int _STRETCH_NAME = 750;
		const int _STRETCH_QTY = 250;

		QLineEdit	*_txt_ware_detail_name = nullptr;
		QSpinBox	*_num_qty = nullptr;

		QPushButton	*_btn_add = nullptr;
		QPushButton	*_btn_remove = nullptr;

	};//class panel_ware_detail_editor
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __PANEL_WARE_DETAIL_EDITOR_H__
