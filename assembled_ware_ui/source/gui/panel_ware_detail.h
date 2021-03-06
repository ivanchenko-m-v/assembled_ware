/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 15-06-2016
///		Comment		:
/// ============================================================================
#ifndef __PANEL_WARE_DETAIL_H__
#define __PANEL_WARE_DETAIL_H__

#include <QWidget>

namespace assembled_ware
{

class panel_ware_properties;
class panel_ware_detail_editor;
class listview_ware_detail;
/// ############################################################################
///			class panel_ware_detail
/// ############################################################################
    class panel_ware_detail : public QWidget
    {
    Q_OBJECT
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        panel_ware_detail( const panel_ware_detail &rhs );

	public:
        /// --------------------------------------------------------------------
        explicit panel_ware_detail(QWidget *parent = 0);
        /// --------------------------------------------------------------------
        virtual ~panel_ware_detail( );

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        void initialize( );
        void init_layout();
        void init_connections( );
        QWidget* widget_listview_detail( );
        QWidget* widget_ware_properties( );
        QWidget* widget_detail_editor( );

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
        panel_ware_detail& operator=( const panel_ware_detail &rhs );

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
		const int _STRETCH_LABEL = 10;
		const int _STRETCH_LIST = 1000;
		const int _STRETCH_PROPERTIES = 10;
		const int _STRETCH_DETAIL_EDITOR = 1;

		panel_ware_properties		*_panel_prop = nullptr;
		panel_ware_detail_editor	*_panel_detail_editor = nullptr;
		listview_ware_detail		*_lv_wd = nullptr;

	};//class panel_ware_detail
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __PANEL_WARE_DETAIL_H__
