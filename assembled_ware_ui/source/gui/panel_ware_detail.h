/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 31-05-2016
///		Date update	: 31-05-2016
///		Comment		:
/// ============================================================================
#ifndef __PANEL_WARE_DETAIL_H__
#define __PANEL_WARE_DETAIL_H__

#include <QWidget>

namespace assembled_ware
{

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

	};//class panel_ware_detail
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace assembled_ware

#endif // __PANEL_WARE_DETAIL_H__
